fs=require('fs');
var log=console.log;
var dir="./chipmunk/";
var woc=s=>s.split(".")[0];

var h=fn=>{
  var content=fs.readFileSync(dir+fn)+"";
  var bef="Class klass = {";
  var to="class_"+woc(fn);
  var aft="Class "+to+" = {";
  var out=content.split(bef).join(aft).split("&klass").join("&"+to);
  fs.writeFileSync(dir+fn,out);
};

var qapcount=(arr,cb)=>{
  var n=0;
  arr.map(e=>{if(cb(e))n++;});
  return n;
};

var g_defs={};var g_defs_out=[];var g_defs_add=s=>{log(s);g_defs_out.push(s);}

var fix=fn=>{
  var content=fs.readFileSync(dir+fn)+"";content=content.split("\r").join("");
  fs.writeFileSync(dir+fn,content);
  var need_initial_fix=1;
  if(need_initial_fix)
  {
    var triggers=[
      "static void\npreStep",
      "static inline void\nrecycleBin",
      "typedef struct eachContext {"
    ];
    if(qapcount(triggers,e=>content.includes(e))){
      var skip=content.includes("chip_fix.inl");
      var s=skip?" with chip_fix.inl":"";
      log(fn+" - preStep found"+s);
      if(!skip){
        var bef0='#include "chipmunk/chipmunk_private.h"\n';
        var bef='#include "chipmunk_private.h"\n';
        content=content.split(bef0).join(bef);
        var to=woc(fn);
        var inc='#include "chip_fix.inl"';
        var aft=bef+"#define DEF_UNIT_NAME "+to+"\n"+inc+"\n";
        var out=content.split(bef).join(aft)+"\n"+inc;
        fs.writeFileSync(dir+fn,out);
      }
    }
    if(content.includes("klass = {")){
      log(fn);
      h(fn);
    }
  }
  if(content.includes('#include "chipmunk/')){
    log(fn);
    content.split('#include "chipmunk/').slice(1).map(e=>e.split('"')[0]).map(e=>log("  "+e));
    var out=content.split('#include "chipmunk/').join('#include "');
    fs.writeFileSync(dir+fn,out);
    //log(fn+" - with include chip");
  }
  var need_undef_all_defines=0;
  if(need_undef_all_defines)if(fn.split(".")[1]=='h')
  {
    g_defs_add(fn.split(".")[1]=='c'?'#include "chipmunk/'+fn+'"  ':'// '+dir+fn);
    content.split('#define ').slice(1).map(e=>e.split(/[\s(]+/)[0]).map(e=>{if(e in g_defs)return;g_defs[e]=1;g_defs_add("#undef "+e);});
    //g_defs
  }
};


var q=arr=>arr.map(fix);
q(fs.readdirSync(dir));

fs.writeFileSync("cfix_undef_all.inl",g_defs_out.join("\n"));

//
//var f=s=>'#include "chipmunk/src/'+s+'"';
//var woc=s=>s.split(".")[0];
//var g=s=>f(s);  //"namespace /*cbs_"+woc(s)+"*/{\n"+f(s)+"\n};\n";
////DEF_INSERT_CPP_CODE(namespace bullshit_a{)
//var arr=POST.data.split("\n");
//var prefix='#include "chipmunk/chipmunk.h"\n'+'#include "chipmunk/chipmunk_private.h"\n';
//return prefix+arr.map(g).join('\n');//+arr.map(s=>"using namespace cbs_"+woc(s)+";").join("\n");
//

