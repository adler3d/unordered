var fs=require("fs");var json=JSON.stringify;
log=console.log;log("no way");throw new Error("stop it");
var s=""+require('child_process').execSync("find -type f");
var fn2stat={};
  var f2s=JSON.parse(fs.readFileSync("fn2stat_backup2.json")+"");
var f=fn=>{
  var i=fs.statSync(fn);
  fn2stat[fn]=i;
  var s=fs.readFileSync(fn)+"";
  var postfix="";
  if(!fn.includes(".mtl")){
    var mtl="./"+s.split("\n").filter(e=>e.includes("mtllib"))[0].split(" ").slice(-1)[0];
    var fail=mtl!="./tank.mtl"&&mtl!="./obj.mtl"&&mtl.split(".mtl")[0]+".obj"!=fn;
    postfix=" // mtllib = "+mtl+(fail?"   // [--- fail? ---]   "+json({atime:i.atime,mtime:i.mtime,size:i.size}):"");
    if(0)if(fail){
      var e=f2s[fn];
      var nfn=mtl.split(".mtl")[0]+".obj";
      fs.renameSync(fn,nfn);
      fs.utimesSync(nfn,(e.atimeMs/1000)|0,(e.mtimeMs/1000)|0);
    }
  }
  return fn+postfix;
};
log(s.split("\n").filter(e=>e.includes(".obj")).map(f).join("\n"));
log(s.split("\n").filter(e=>e.includes(".mtl")).map(f).join("\n"));
//log(json(fn2stat));
fs.writeFileSync("fn2stat.json",json(fn2stat));
var sync_time=()=>{
  var f2s=JSON.parse(fs.readFileSync("fn2stat_backup2.json")+"");
  for(var fn in f2s){
    var e=f2s[fn];
    fs.utimesSync(fn,e.atime,e.mtime);
  }
};
if(0)sync_time();