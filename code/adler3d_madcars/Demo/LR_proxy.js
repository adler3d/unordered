var net = require('net');

process.stdout.on('close',()=>process.exit(0));
process.stdin.on('close',()=>process.exit(0));

var wb=new net.Socket();
wb.connect(1338,'127.0.0.1',function(){
  wb.pipe(process.stdout);
});

var rb=new net.Socket();
rb.connect(1337,'127.0.0.1',function(){
  process.stdin.pipe(rb);
});