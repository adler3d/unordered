const fs = require('fs').promises;
const path = require('path');

const targetDir = 'unordered'; // <-- укажите путь к таргет-репозиторию
const IGNORED_DIRS = ['.git'];

async function updateFolderMtime(folderPath) {
  let latestMtime = null;

  // Читаем содержимое папки
  const entries = await fs.readdir(folderPath, { withFileTypes: true });

  for (const entry of entries) {
    if (IGNORED_DIRS.includes(entry.name)) continue;

    const fullPath = path.join(folderPath, entry.name);

    if (entry.isDirectory()) {
      // Рекурсивно обновляем подпапку
      const subfolderMtime = await updateFolderMtime(fullPath);
      if (subfolderMtime && (!latestMtime || subfolderMtime > latestMtime)) {
        latestMtime = subfolderMtime;
      }
    } else if (entry.isFile()) {
      // Получаем время изменения файла
      const stat = await fs.stat(fullPath);
      if (!latestMtime || stat.mtime > latestMtime) {
        latestMtime = stat.mtime;
      }
    }
  }

  if (latestMtime) {
    // Устанавливаем время изменения папки равным latestMtime
    // atime тоже ставим равным mtime для согласованности
    await fs.utimes(folderPath, latestMtime, latestMtime);
    console.log(`Updated folder mtime: ${folderPath} -> ${latestMtime.toISOString()}`);
  } else {
    // Если папка пустая (нет файлов и папок), можно пропустить или выставить текущее время
    // await fs.utimes(folderPath, new Date(), new Date());
    console.log(`Folder empty or no files: ${folderPath}`);
  }

  return latestMtime;
}

(async () => {
  try {
    await updateFolderMtime(targetDir);
    console.log('All folders updated.');
  } catch (err) {
    console.error('Error:', err);
  }
})();