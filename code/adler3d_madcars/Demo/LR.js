var fs=require('fs');
var exec=require('child_process').exec;
//var qap_header=(fs.readFileSync("shell.js")+"").split("var xhr_post_with_to")[0];
//eval(qap_header);

var net=require('net');
var process=require('process');
//var check_pid=pid=>{try{return process.kill(pid,0);}catch(e){return e.code==='EPERM'};}

//process.stdout.write(process.argv.join("\n"));
//var done=()=>process.exit();
//'close,exit,end,error,uncaughtException,unhandledRejection,disconnect'.split(",").map(event=>[process.stdout,process.stdin].map(e=>e.on(event,done)));
//
//setInterval(()=>{if(!check_pid(process.ppid))process.exit();},512);

var rb=process.argv[2]=='rb'; //mean c++ app want read from our process.stdout

process.on('uncaughtException',()=>process.exit(0));

if( rb)process.stdout.on('close',()=>process.exit(0));
if(!rb)process.stdin.on('close',()=>process.exit(0));
  
var port=rb?1337:1338;
var server = net.createServer(function(socket) {
  //socket is LR_proxy.js
	if( rb)socket.pipe(process.stdout); //process.stdout is Demo.exe::pstream->p
  if(!rb)process.stdin.pipe(socket);  //process.stdin  is Demo.exe::pstream->pout
  socket.on('close',()=>process.exit(0));
});

var mapset="";
//mapset="-m PillHillMap,Buggy PillHubbleMap,SquareWheelsBuggy PillCarcassMap,Buggy IslandMap,Bus PillMap,Buggy";
var part01=" PillHillMap,Buggy PillHubbleMap,SquareWheelsBuggy PillCarcassMap,Buggy IslandMap,Bus PillMap,Buggy";
mapset="-m PillMap,SquareWheelsBuggy IslandMap,SquareWheelsBuggy IslandMap,Buggy PillCarcassMap,SquareWheelsBuggy PillCarcassMap,Bus"+part01;
//mapset="-m PillCarcassMap,SquareWheelsBuggy IslandMap,SquareWheelsBuggy IslandHoleMap,Bus PillHillMap,Buggy";
//mapset="-m PillHillMap,Bus";
//mapset="-m PillCarcassMap,Bus";
//mapset="-m IslandHoleMap,Buggy";
//mapset="-m PillCarcassMap,SquareWheelsBuggy";
//mapset="-m Map,Bus IslandMap,Bus IslandMap,Buggy IslandMap,SquareWheelsBuggy PillHillMap,Bus PillHillMap,Buggy";
if(!rb)exec('py C:/Users/Adler/Desktop/aicups3/miniaicups/madcars/Runners/localrunner.py --sp "node ../Demo/LR_proxy.js" '+mapset).on('close',()=>process.exit(0));;

server.listen(port,'127.0.0.1');

/*

py C:\Users\Adler\Desktop\aicups3\miniaicups\madcars\Runners\localrunner.py --fp C:\Users\Adler\Desktop\aicups3\adler3d_madcars\Release\Demo.exe
C:\Users\Adler\Desktop\aicups3\miniaicups\madcars\Runners\run.sh
*/

/*
wget -nc https://github.com/adler3d/miniaicups/raw/patch-1/madcars/tools/visio_to_stdin.js
cd build
unlink main.cpp
unlink build.zip
ls -lht
node ../visio_to_stdin.js 2 370966 nope>log.txt
cat log.txt|./main
*/

/*
return POST.data.split("\n").map(e=>eval("var u={"+e.split("old_")[0]+"};u")).map(e=>e.plan_id).map(e=>"get_by_id("+e+',"SEED ML_v2 N=300000",1,"nope");').join("\n");
*/

/*
ps -aux
ls -lht
cat wins9999.log.cpp
exit
this_app=./app9999
wget -nc http://nwg-nwg.193b.starter-ca-central-1.openshiftapps.com/allworlds.json
curl http://nwg-nwg.193b.starter-ca-central-1.openshiftapps.com/build/main>$this_app
chmod +x $this_app
$this_app>$this_app.log&
ps -aux
ls -lht
*/