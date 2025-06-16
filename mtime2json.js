const fs = require('fs').promises;
const path = require('path');
const crypto = require('crypto');

const IGNORED_DIRS = ['.git'];

// ¬ычисление sha256 файла
async function hashFile(filePath) {
  return new Promise((resolve, reject) => {
    const hash = crypto.createHash('sha256');
    const stream = require('fs').createReadStream(filePath);
    stream.on('error', reject);
    stream.on('data', chunk => hash.update(chunk));
    stream.on('end', () => resolve(hash.digest('hex')));
  });
}

// —бор дат и хешей
async function collectModificationDates(dir, baseDir) {
  let results = {};

  async function recurse(currentPath) {
    const entries = await fs.readdir(currentPath, { withFileTypes: true });
    for (const entry of entries) {
      if (IGNORED_DIRS.includes(entry.name)) continue;
      const fullPath = path.join(currentPath, entry.name);
      const relPath = path.relative(baseDir, fullPath).replace(/\\/g, '/');
      if (entry.isDirectory()) {
        await recurse(fullPath);
        const stat = await fs.stat(fullPath);
        results[relPath + '/'] = { mtime: stat.mtime.toISOString() };
      } else if (entry.isFile()) {
        const stat = await fs.stat(fullPath);
        const sha256 = await hashFile(fullPath);
        results[relPath] = { mtime: stat.mtime.toISOString(), sha256 };
      }
    }
  }

  await recurse(dir);
  return results;
}

// «апись JSON с форматированием
async function writeJsonFormatted(data, file) {
  const entries = Object.entries(data);
  const lines = ['{'];

  for (let i = 0; i < entries.length; i++) {
    const [key, value] = entries[i];
    const comma = i < entries.length - 1 ? ',' : '';
    lines.push(`  ${JSON.stringify(key)}: ${JSON.stringify(value)}${comma}`);
  }

  lines.push('}');

  await fs.writeFile(file, lines.join('\n'), 'utf8');
}

// ѕрименение дат с проверкой sha256
async function applyModificationDates(dir, jsonFile) {
  const content = await fs.readFile(jsonFile, 'utf8');
  let data;
  try {
    data = JSON.parse(content);
  } catch (e) {
    console.error('Error parsing JSON file:', e);
    return;
  }

  for (const [relPath, info] of Object.entries(data)) {
    const fullPath = path.join(dir, relPath);
    try {
      await fs.access(fullPath);
    } catch {
      console.warn(`Warning: path does not exist, skipping: ${relPath}`);
      continue;
    }

    const savedMtime = new Date(info.mtime);

    if (relPath.endsWith('/')) {
      // ѕапка Ч выставл€ем дату всегда
      try {
        await fs.utimes(fullPath, savedMtime, savedMtime);
        console.log(`Updated folder mtime: ${relPath}`);
      } catch (e) {
        console.error(`Failed to update mtime for folder ${relPath}:`, e);
      }
    } else {
      // ‘айл Ч провер€ем sha256
      try {
        const currentHash = await hashFile(fullPath);
        if (currentHash === info.sha256) {
          // ’еш совпадает Ч выставл€ем дату
          await fs.utimes(fullPath, savedMtime, savedMtime);
          console.log(`Updated file mtime: ${relPath}`);
        } else {
          // ’еш не совпадает Ч содержимое изменилось, дату не мен€ем
          console.log(`File changed, skipping mtime update: ${relPath}`);
        }
      } catch (e) {
        console.error(`Error processing file ${relPath}:`, e);
      }
    }
  }
}

async function main() {
  const args = process.argv.slice(2);
  if (args.length < 2) {
    console.log('Usage: node mtime2json.js <save|apply> <targetDir> [jsonFile]');
    process.exit(1);
  }

  const mode = args[0];
  const targetDir = args[1];
  const jsonFile = args[2] || 'modification_dates.json';

  if (mode === 'save') {
    const data = await collectModificationDates(targetDir, targetDir);
    await writeJsonFormatted(data, jsonFile);
    console.log(`Modification dates and hashes saved to ${jsonFile}`);
  } else if (mode === 'apply') {
    await applyModificationDates(targetDir, jsonFile);
    console.log('Modification dates applied where content matched.');
  } else {
    console.log('Unknown mode. Use "save" or "apply".');
  }
}

main().catch(err => {
  console.error('Error:', err);
});
