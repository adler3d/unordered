const zlib = require('zlib');
const gzip = zlib.createGzip();
const fs = require('fs');
const inp = fs.createReadStream('rayenv_L128_scene_v22.bin');
const out = fs.createWriteStream('rayenv_L128_scene_v22.bin.def.gz');

inp.pipe(gzip).pipe(out);

/*
toR('gz.cmd')('begin');
inp.pipe(gzip).pipe(out).on('data',toR('gz')).on('end',toR('gz.cmd')('end'));

*/