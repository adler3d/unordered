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

var qap_log=s=>console.log("["+getDateTime()+"] "+s);
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

var file_exist=fn=>{try{fs.accessSync(fn);return true;}catch(e){return false;}}
var rand=()=>(Math.random()*1024*64|0);


var xhr=(method,URL,data,ok,err)=>{
  var up=url.parse(URL);var secure=up.protocol=='https';
  var options={
    hostname:up.hostname,port:up.port?up.port:(secure?443:80),path:up.path,method:method.toUpperCase(),
    headers:{'Content-Type':'application/x-www-form-urlencoded','Content-Length':Buffer.byteLength(data)}
  };
  var req=(secure?https:http).request(options,(res)=>{
    var statusCode=res.statusCode;var contentType=res.headers['content-type'];var error;
    if(statusCode!==200){error=new Error('Request Failed.\nStatus Code: '+statusCode);}
    if(error){err(error.message,res);res.resume();return;}
    //res.setEncoding('utf8');
    var rawData='';res.on('data',(chunk)=>rawData+=chunk.toString("binary"));
    res.on('end',()=>{try{ok(rawData,res);}catch(e){err(e.message,res);}});
  }).on('error',e=>{err('Got error: '+e.message,null);});
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

[
  "agile-eyrie-44522.herokuapp.com",
  "vm50.herokuapp.com",
  "vm51.herokuapp.com",
  "vm52.herokuapp.com",
  "vm-vm.193b.starter-ca-central-1.openshiftapps.com",
  "vm10-vm10.1d35.starter-us-east-1.openshiftapps.com",
  "vm20-vm20.1d35.starter-us-east-1.openshiftapps.com",
  "vm30-vm30.193b.starter-ca-central-1.openshiftapps.com"
].map((e,i)=>{//qap_log(e)
  var on_fail=s=>{qap_log(e+" - failed with msg: "+s);doit();}
  var doit=()=>{
    xhr("get","http://"+e+"/mask_pix_log_p700.txt","",s=>{
      fs.writeFileSync("p700_"+i+".bin",new Buffer(s,'binary'));
      qap_log(e+" - is done! ["+s.length+"]");
    },on_fail);
  };
  doit();
}
);


















