const fs = require('fs').promises;
const path = require('path');
const crypto = require('crypto');

const repo1 = 'unordered'; // оригинальные даты изменения
const repo2 = 'code/unordered'; // даты последнего скачивания + дополнительная папка с оригинальными датами
const output = 'unordered_output';

const IGNORED_DIRS = ['.git'];

// Вычисление sha256 хеша файла
async function hashFile(filePath) {
  return new Promise((resolve, reject) => {
    const hash = crypto.createHash('sha256');
    const stream = require('fs').createReadStream(filePath);
    stream.on('error', reject);
    stream.on('data', chunk => hash.update(chunk));
    stream.on('end', () => resolve(hash.digest('hex')));
  });
}

// Рекурсивно получить список файлов (без .git)
async function getFiles(dir) {
  let files = [];
  const items = await fs.readdir(dir, { withFileTypes: true });
  for (const item of items) {
    if (IGNORED_DIRS.includes(item.name)) continue;
    const fullPath = path.join(dir, item.name);
    if (item.isDirectory()) {
      const subFiles = await getFiles(fullPath);
      files = files.concat(subFiles);
    } else if (item.isFile()) {
      files.push(fullPath);
    }
  }
  return files;
}

// Нормализовать путь файла относительно корня репозитория
function relativePath(root, filePath) {
  return path.relative(root, filePath).replace(/\\/g, '/');
}

// Копировать файл с установкой времени изменения
async function copyFileWithMtime(src, dest, mtime) {
  await fs.mkdir(path.dirname(dest), { recursive: true });
  await fs.copyFile(src, dest);
  const atime = mtime; // для простоты atime = mtime
  await fs.utimes(dest, atime, mtime);
}

async function main() {
  // Получаем файлы из обоих репозиториев
  const files1 = await getFiles(repo1);
  const files2 = await getFiles(repo2);

  // Создаем мапы: относительный путь -> полный путь
  const map1 = new Map(files1.map(f => [relativePath(repo1, f), f]));
  const map2 = new Map(files2.map(f => [relativePath(repo2, f), f]));

  // Объединяем ключи (относительные пути)
  const allKeys = new Set([...map1.keys(), ...map2.keys()]);

  for (const relPath of allKeys) {
    // Пропускаем если в пути есть .git (на всякий случай)
    if (relPath.split('/').includes('.git')) continue;

    const file1 = map1.get(relPath);
    const file2 = map2.get(relPath);

    if (file1 && file2) {
      // Есть в обоих репозиториях - сравниваем содержимое
      const [hash1, hash2] = await Promise.all([hashFile(file1), hashFile(file2)]);
      if (hash1 === hash2) {
        // Содержимое совпадает - копируем с датой старейшего файла
        const stat1 = await fs.stat(file1);
        const stat2 = await fs.stat(file2);
        const olderMtime = stat1.mtime < stat2.mtime ? stat1.mtime : stat2.mtime;
        const destPath = path.join(output, relPath);
        await copyFileWithMtime(file1, destPath, olderMtime);
        console.log(`Copied identical file with oldest mtime: ${relPath}`);
      } else {
        // Содержимое отличается - копируем самый свежий
        const stat1 = await fs.stat(file1);
        const stat2 = await fs.stat(file2);
        if (stat1.mtime > stat2.mtime) {
          await copyFileWithMtime(file1, path.join(output, relPath), stat1.mtime);
          console.log(`Copied newer file from repo1: ${relPath}`);
        } else {
          await copyFileWithMtime(file2, path.join(output, relPath), stat2.mtime);
          console.log(`Copied newer file from repo2: ${relPath}`);
        }
      }
    } else if (file1) {
      // Есть только в repo1
      const stat1 = await fs.stat(file1);
      await copyFileWithMtime(file1, path.join(output, relPath), stat1.mtime);
      console.log(`Copied file only in repo1: ${relPath}`);
    } else if (file2) {
      // Есть только в repo2
      const stat2 = await fs.stat(file2);
      await copyFileWithMtime(file2, path.join(output, relPath), stat2.mtime);
      console.log(`Copied file only in repo2: ${relPath}`);
    }
  }
}

main().catch(err => {
  console.error('Error:', err);
});
