var fs=require('fs');
var qap_header=(fs.readFileSync("shell.js")+"").split("var xhr_post_with_to")[0];
eval(qap_header);
var get_tick_count=()=>new Date().getTime();
var get_ms=()=>{var a=process.hrtime();return a[0]*1e3+a[1]/1e6;}
var unixtime=()=>(new Date()/1000);

var bef=get_ms();
var yazl=require("yazl");
var zipfile=new yazl.ZipFile();
try{fs.unlinkSync("build.zip");}catch(e){}
//var host="http://140.82.34.102";
var host="http://nwg-nwg.193b.starter-ca-central-1.openshiftapps.com";
zipfile.outputStream.pipe(fs.createWriteStream("build.zip")).on("close",()=>{
  var ms=get_ms()-bef;
  qap_log('time = '+ms+' ms');
  qap_log(execSync("node shell.js host=nwg api=upload fn=build.zip"));
  execSync("sleep 1");
  var cmd='echo "fromVultr ::";rm -rf build;ls -l;mkdir -p build;mv build.zip build;cd build;unzip build.zip;ls -l;ls -l|grep out;ps -aux|grep "app.out\\|PID"|grep -v grep';
  var done=()=>{}
  xhr_post(host+"/eval?nolog&code=exec_post_data()",{data:cmd.split(";").join("\n")},x=>done(x),qap_log);
  var done=msg=>{
    qap_log(msg);
    var build_script=(`
      cd build
      ls -l
      unlink main 2>/dev/null
      echo ------------------------------------------------BEG_BUILD---------------------------------------------
      g++ -std=c++11 --verbose main.cpp -O2 -DUNIX_WITH_FS -fopenmp -pthread -o main
      echo ------------------------------------------------END_BUILD---------------------------------------------
      pwd
      ls -l main
    `);
    xhr_post(host+"/eval?nolog&code=exec_post_data()",{data:build_script},qap_log,qap_log);
  }
});
var add=fn=>zipfile.addFile(fn,fn);
var dir='rapidjson';

var WL=e=>{
  var arr="fwd.h,example,schema.h".split(",");
  if(!(e.includes(".h")||e.includes(".c")))return false;
  for(var i=0;i<arr.length;i++)if(e.includes(arr[i]))return false;
  return true;
}
var TF=expr=>e=>e.slice(expr.length).trim();
var all_from_dir=dir=>{
  var expr='./'+dir+'/';
  return (execSync('find -type f|grep '+expr)+"").split("\r").join("").split("\n").map(TF(expr)).map(fn=>dir+'/'+fn);
}
//qap_log(all_from_dir("chipmunk").filter(WL).join("\n"));return;

all_from_dir("rapidjson").filter(WL).map(e=>{qap_log(e);return e;}).map(add);
all_from_dir("chipmunk").filter(WL).map(e=>{qap_log(e);return e;}).map(add);
var commit=(""+execSync("git log -n 1|grep commit")).split("\r").join("").split("\n").join("");
var main_cpp=fs.readFileSync("main.cpp").toString("binary").split("###_BUILD_TIME_###").join(getDateTime()+" "+commit);
zipfile.addBuffer(Buffer.from(main_cpp,"binary"),"main.cpp"); //add("main.cpp");
add("chipmunk/chip_fix.inl");
add("chipmunk.inl");
add("cfix_undef_all_c.inl");
add("cfix_undef_all_h.inl");
add("defprovar_v2.inl");
add("defprovar_v3a.inl");
add("defprovar_v3c.inl");
add("defprovar_v3g.inl");
add("qaplite/vector_view.inl");
add("qaplite/qap_show_floats.inl");
add("allworlds.json");
add("versions.inl");
add("t_plan_generator_old.inl");

//add("mechanic.h");
//add("logger.h");
//add("constants.h");
//add("inp_log.txt");
//all_from_dir("entities").filter(WL).map(e=>{qap_log(e);return e;}).map(add);
//all_from_dir("strategies").filter(WL).map(e=>{qap_log(e);return e;}).map(add);

zipfile.end();




/*
cd build
ls -l
unlink main 2>/dev/null
echo ------------------------------------------------BEG_BUILD---------------------------------------------
g++ -std=c++11 -O2 --verbose main.cpp -o main
echo ------------------------------------------------END_BUILD---------------------------------------------
pwd
ls -l main
*/

























