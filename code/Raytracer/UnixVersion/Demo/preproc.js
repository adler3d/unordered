var child_process=require('child_process');
var fs=require('fs');
var execSync=child_process.execSync;
var qs = require('querystring');
var http = require("http"),
    https = require("https"),
    url = require("url"),
    path = require("path"),
    fs = require("fs"),
    os = require("os"),
crypto = require('crypto');
const assert=require('assert');

var call_cb_on_err=(emitter,cb,...args)=>{
  emitter.on('error',err=>{
    cb("'inspect({args,err}) // stack': "+inspect({args:args,err:err})+" // "+err.stack.toString());
  });
}

var qap_log=s=>console.log("["+getDateTime()+"] "+s);

var qap_err=(context,err)=>context+" :: err = "+inspect(err)+" //"+err.stack.toString();
var log_err=(context,err)=>qap_log(qap_err(context,err));

var json=JSON.stringify;
var mapkeys=Object.keys;var mapvals=(m)=>mapkeys(m).map(k=>m[k]);
var inc=(m,k)=>{if(!(k in m))m[k]=0;m[k]++;return m[k];};

var FToS=n=>(n+0).toFixed(2);
var mapswap=(k2v)=>{var v2k={};for(var k in k2v){v2k[k2v[k]]=k;}return v2k;}
var qapavg=(arr,cb)=>{if(typeof cb=='undefined')cb=e=>e;return arr.length?arr.reduce((pv,ex)=>pv+cb(ex),0)/arr.length:0;}
var qapsum=(arr,cb)=>{if(typeof cb=='undefined')cb=e=>e;return arr.reduce((pv,ex)=>pv+cb(ex),0);}
var qapmin=(arr,cb)=>{if(typeof cb=='undefined')cb=e=>e;var out;var i=0;for(var k in arr){var v=cb(arr[k]);if(!i){out=v;}i++;out=Math.min(out,v);}return out;}
var qapmax=(arr,cb)=>{if(typeof cb=='undefined')cb=e=>e;var out;var i=0;for(var k in arr){var v=cb(arr[k]);if(!i){out=v;}i++;out=Math.max(out,v);}return out;}
var qapsort=(arr,cb)=>{if(typeof cb=='undefined')cb=e=>e;return arr.sort((a,b)=>cb(b)-cb(a));}
var mapdrop=(e,arr,n)=>{var out=n||{};Object.keys(e).map(k=>arr.indexOf(k)<0?out[k]=e[k]:0);return out;}
var mapsort=(arr,cb)=>{if(typeof cb=='undefined')cb=(k,v)=>v;var out={};var tmp=qapsort(mapkeys(arr),k=>cb(k,arr[k]));for(var k in tmp)out[tmp[k]]=arr[tmp[k]];return out;}

var qap_unique=arr=>{var tmp={};arr.map(e=>tmp[e]=1);return mapkeys(tmp);};var unique_arr=qap_unique;

var mapaddfront=(obj,n)=>{for(var k in obj)n[k]=obj[k];return n;}
var mapclone=obj=>mapaddfront(obj,{});

var getarr=(m,k)=>{if(!(k in m))m[k]=[];return m[k];};
var getmap=(m,k)=>{if(!(k in m))m[k]={};return m[k];};
var getdef=(m,k,def)=>{if(!(k in m))m[k]=def;return m[k];};

var qap_foreach_key=(obj,cb)=>{for(var k in obj)cb(obj,k,obj[k]);return obj;}

process.on('uncaughtException',err=>log_err('uncaughtException',err));

function getDateTime() {
  var now     = new Date(); 
  var year    = now.getFullYear();
  var f=v=>(v.toString().length==1?'0':'')+v;
  var month   = f(now.getMonth()+1); 
  var day     = f(now.getDate());
  var hour    = f(now.getHours());
  var minute  = f(now.getMinutes());
  var second  = f(now.getSeconds()); 
  var dateTime = year+'.'+month+'.'+day+' '+hour+':'+minute+':'+second;   
  return dateTime;
}

var json_once=(obj,replacer,indent,limit)=>{
  var objs=[];var keys=[];if(typeof(limit)=='undefined')limit=2048;
  return json(obj,(key,v)=>{
    if(objs.length>limit)return 'object too long';
    var id=-1;objs.forEach((e,i)=>{if(e===v){id=i;}});
    if(key==''){objs.push(obj);keys.push("root");return v;}
    if(id>=0){
      return keys[id]=="root"?"(pointer to root)":
        ("\1(see "+((!!v&&!!v.constructor)?v.constructor.name.toLowerCase():typeof(v))+" with key "+json(keys[id])+")");
    }else{
      if(v!==null&&typeof(v)==="object"){var qk=key||"(empty key)";objs.push(v);keys.push(qk);}
      return replacer?replacer(key,v):v;
    }
  },indent);
};
var json_once_v2=(e,v,lim)=>json_once(e,v,2,lim);
var inspect=json_once_v2;

var file_exist=fn=>{try{fs.accessSync(fn);return true;}catch(e){return false;}}
var rand=()=>(Math.random()*1024*64|0);

var ee_logger_v2=(emitter,name,cb,events)=>{
  events.split(',').map(event=>emitter.on(event,e=>cb(name+' :: Got '+event)));
  call_cb_on_err(emitter,cb,name);
}


var xhr_get=(URL,ok,err)=>{
  if((typeof ok)!="function")ok=()=>{};
  if((typeof err)!="function")err=()=>{};
  var secure=['https:','https'].includes(url.parse(URL).protocol);
  var req=(secure?https:http).get(URL,(res)=>{
    var cb=ok;
    if(res.statusCode!==200){cb=(s,res)=>err('Request Failed.\nStatus Code: '+res.statusCode+'\n'+s);}
    //res.setEncoding('utf8');
    var rawData='';res.on('data',(chunk)=>rawData+=chunk.toString("binary"));
    res.on('end',()=>{try{cb(rawData,res);}catch(e){err(qap_err('xhr_get.mega_huge_error',e),res);}});
  });
  call_cb_on_err(req,qap_log,'xhr_get');
  return req;
}

var xhr=(method,URL,data,ok,err)=>{
  if((typeof ok)!="function")ok=()=>{};
  if((typeof err)!="function")err=()=>{};
  var up=url.parse(URL);var secure=['https:','https'].includes(up.protocol);
  var options={
    hostname:up.hostname,port:up.port?up.port:(secure?443:80),path:up.path,method:method.toUpperCase(),
    headers:{'Content-Type':'application/x-www-form-urlencoded','Content-Length':Buffer.byteLength(data)}
  };
  var req=(secure?https:http).request(options,(res)=>{
    var cb=ok;
    if(res.statusCode!==200){cb=(s,res)=>err('Request Failed.\nStatus Code: '+res.statusCode+'\n'+s);}
    //res.setEncoding('utf8');
    var rawData='';res.on('data',(chunk)=>rawData+=chunk.toString("binary"));
    res.on('end',()=>{try{cb(rawData,res);}catch(e){err(qap_err('xhr.mega_huge_error',e),res);}});
  });
  call_cb_on_err(req,qap_log,'xhr');
  req.end(data);
  return req;
}

var xhr_add_timeout=(req,ms)=>req.on('socket',sock=>sock.on('timeout',()=>req.abort()).setTimeout(ms));

var xhr_post=(url,obj,ok,err)=>xhr('post',url,qs.stringify(obj),ok,err);
var xhr_post_with_to=(url,obj,ok,err,ms)=>xhr_add_timeout(xhr('post',url,qs.stringify(obj),ok,err),ms);

var clock=(start)=>{
  var f=(e)=>((e[0]*1000)+(e[1]/1000000));
  if(!start)return f(process.hrtime());
  if(typeof start==="number")return f(process.hrtime())-start;
  var end=process.hrtime(start);return f(end);
}

bef=clock();

// for((;;));do echo 'Hit CTRL+C';sleep 1;done;

qap_log("before cl.exe");
  
var clout=execSync("cl /nologo /EP /P -DUNIX -DPREPROC -DSERV main.cpp");

qap_log("cl.exe output:\n"+clout);

qap_log("cl time: "+clock(bef).toFixed(2)+" ms");

var data=fs.readFileSync("main.i");
data=(
`
#include <unistd.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <cstring>
#include <csignal>

#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <array>
#include <bitset>
#include <time.h>
#include <math.h>

#if(__cplusplus!=201402L&&__cplusplus!=201103L||__GNUC__<5)
  struct t_gcc_nullptr_t{};
  #define nullptr_t t_gcc_nullptr_t
  #define nullptr 0
#endif

#ifndef PREPROC
  #if(defined(_DEBUG)||defined(QAP_DEBUG))
    #ifdef WIN32
    #else
      #define __FUNCSIG__ __PRETTY_FUNCTION__
    #endif //WIN32
    #ifdef WIN32
      #define QapDbgBreak(){struct t_open_mp_workaround{static void crash(){__builtin_trap();}};t_open_mp_workaround::crash();/*_CrtDbgBreak();*/}
    #else
      #define QapDbgBreak()printf("__builtin_trap();");
    #endif
    #define QapAssert(_Expression)if(!bool(_Expression)){static bool ignore=false;if(SysQapAssert((#_Expression),ignore,__FILE__,__LINE__,__FUNCSIG__))QapDbgBreak();}  
    #define QapDebugMsg(_Message){static bool ignore=false;if(SysQapDebugMsg((_Message),ignore,__FILE__,__LINE__,__FUNCSIG__))QapDbgBreak();}
    #define QapNoWay(){QapDebugMsg("no way!");}
  #else
    #define QapAssert(_Expression)if(bool(_Expression)){};
    #define QapDebugMsg(_Message)
    #define QapNoWay()
  #endif
#endif //PREPROC//

#include "lodepng.cpp"

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>

#include <thread>
#include <netinet/tcp.h>

`+data
);

data=data.split("\r").join("").split("#pragma once\n").join("");//.split(";}").join(";}\n");
var out=data.split("\n").filter(e=>e.split(" ").join("").length).join("\n");
fs.writeFileSync("main.i.cpp",out);
qap_log("done!");

var code=(
  //"return cl_and_exec_cpp(POST.cpp_code,false,' -fopenmp ');"
  (()=>{
    //resp_off();
    var clock=(start)=>{
      var f=(e)=>((e[0]*1000)+(e[1]/1000000));
      if(!start)return f(process.hrtime());
      if(typeof start==="number")return f(process.hrtime())-start;
      var end=process.hrtime(start);return f(end);
    }
    var bef=clock();
    var dest_dir='dest_dir' in qp?qp.dest_dir+"/":"";
    if(dest_dir.length)execSync("set -e;mkdir -p "+dest_dir+";cd "+dest_dir+";");
    var files=JSON.parse(POST.files);files.map(e=>fs.writeFileSync(dest_dir+e.fn,new Buffer(e.data,'binary')));
    var write_ms="write files time:"+clock(bef)+" ms\n";
    var cl_and_exec_cpp2=(code,async_cb,flags)=>{
      //var rnd=rand()+"";rnd="00000".substr(rnd.length)+rnd;
      //var fn="main["+getDateTime().split(":").join("-").split(" ").join("_")+"]_"+rnd+".cpp";
      fn="app.cpp";
      var out="./app.out";
      //fn=json(fn);out=json(out);
      var gbef=clock();
      var gcc_ver=(execSync("g++ --version")+"").split("\n")[0].split("\r")[0];
      if(gcc_ver.split("(GCC) 4.8.5").length==1)flags+=" -static "
      var get_bts=()=>getDateTime()+"    rnd_"+rand()+"_rnd    "+gcc_ver;
      var build_timestamp=get_bts();
      fs.writeFileSync(dest_dir+fn,code.split("$build_timestamp").join(build_timestamp));
      //return ""+exec("nice -n15 node cl_and_run.js "+fn);
      var cmdline=(
        "set -e;mkdir -p "+dest_dir+";cd "+dest_dir+";"+
        "timestamp="+json(build_timestamp)+";"+
        "nice -n15 g++ "+(flags?flags:"")+"-Wmultichar -fpermissive -DQAP_DEBUG -DSERV -O2 -std=c++11 "+fn+" -o "+out+" 2>&1|tee cl_log.txt;"+
        "echo $timestamp>>cl_log.txt;echo $timestamp"
      );
      var cl_out=""+execSync(cmdline);
      var gcc_ms="g++ time:"+clock(gbef).toFixed(2)+" ms\n";
      var cb=(err,stdout,stderr)=>{
        if(err)return txt(stderr+"");
        //cmdline="cd "+dest_dir+";nice -n19 "+out;
        var prev="\n"+stdout+"\n"+stderr;
        txt(write_ms+gcc_ms+cl_out+"\n"+prev);
        //exec(cmdline);
        //if((typeof async_cb)!="function")async_cb=(err,stdout,stderr)=>{txt(prev+"\n"+stdout+"\n"+stderr);};
        //var proc=exec(cmdline,async_cb);
      }
      exec(cmdline,cb);
      return write_ms+gcc_ms+cl_out;
    };
    return cl_and_exec_cpp2(POST.cpp_code,false,' -fopenmp -s ');
  }).toString().split("\n").slice(1,-1).join("\n")
);
var files=[
  "lodepng.cpp","lodepng.h","sphere4096.bin","proj_info.bin","tb5.obj","tb5_obj.mtl"
].map(e=>{return {fn:e,data:fs.readFileSync("../Release/"+e).toString("binary")};});

var g_conf={};
var with_protocol=host=>{
  //qap_log("with_protocol::host="+host);
  assert(!url.parse(host).protocol);
  var c=g_conf;
  if(!(host in c.host2vh))return host;
  var vh=c.host2vh[host];
  var a=['http://','https://'];
  return a[c.inp.without_https.includes(vh)?0:1]+host;
};

var main=h2dns=>{
  var dest_dir="test2";
  var api="preproc";var host=with_protocol(h2dns["nwg"]);
  
  var f=(key,val)=>{
    if(key==="api"){api=val;}
    if(key==="dest_dir"){dest_dir=val;}
    if(key==="host"){if(val in h2dns){host=with_protocol(h2dns[val]);}else{host=with_protocol(val);}}
  };

  process.argv.map(e=>{var t=e.split("=");if(t.length!=2)return;f(t[0],t[1]);});

  qap_log("host = "+host);

  var params={code:code,cpp_code:out,files:JSON.stringify(files),dest_dir:dest_dir};
  qap_log("deploy to "+host);
  xhr_post_with_to(host+"/eval?nolog&cl&from=preproc",params,qap_log,qap_log,60*60*1000);
}

var hosts={};var hosts_err_msg='';var need_coop_init=true;

var hosts_update=hosts=>{
  var conv=x=>{
    var out={power:{},host2vh:{},public:[]};
    for(var host in x.host2str){var a=x.host2str[host].split("|");out.host2vh[host]=a[0];out.power[a[0]]=a[1];}
    out.public=x.public.split("|").map(e=>mapswap(out.host2vh)[e]);
    mapkeys(x.host2str).map(k=>{if(out.public.includes(k))return;out.public.push(k);});
    return out;
  };
  hosts.main_out=conv(hosts.main);
  var src=hosts.main_out;
  src.inp=hosts.main;
  mapkeys(src).map(key=>g_conf[key]=src[key]);
  g_conf.vh2host=mapswap(src.host2vh);
  qap_log("mapkeys(g_conf.power) = "+mapkeys(g_conf.power).join(","));
  main(mapswap(hosts.main_out.host2vh));
  return hosts;
};

var hosts_sync=(cb)=>{
  if((typeof cb)!="function")cb=()=>{};
  xhr_get('https://raw.githubusercontent.com/adler3d/qap_vm/gh-pages/trash/test2017/hosts.json?t='+rand(),
    s=>{try{hosts=JSON.parse(s);hosts=hosts_update(hosts);}catch(e){cb('JSON.parse error:\n'+e+'\n\n'+s);}cb(s);},
    s=>{hosts_err_msg=s;cb(s);}
  );
};
hosts_sync(qap_log);

/*

var code="resp_off();JSON.parse(POST.files).map(e=>fs.writeFileSync(e.fn,new Buffer(e.data,'binary')));return async_cl_and_exec_cpp(POST.data);";
var files=["sphere4096.bin","proj_info.bin","rayenv_L8_scene_v22.bin"].map(e=>{return {fn:e,data:fs.readFileSync("../Release/"+e).toString("binary")};});
//qap_log(JSON.stringify(files),0,2);

var hosts=[
  "http://vm-vm.1d35.starter-us-east-1.openshiftapps.com/eval",
  "http://agile-eyrie-44522.herokuapp.com/eval"
];
qap_log("before_send");
if(0)xhr_post_with_to(hosts[0],{code:code,data:data,files:JSON.stringify(files)},qap_log,qap_log,60*60*1000);
qap_log(qs.stringify.toString());





*/






















