// ==UserScript==
// @name        system_zz_mu ( money.yandex.ru )
// @description more fast
// @include     https://money.yandex.ru/oauth/token?system
// @autor       Adler
// @version     0.1 (28.10.2015)
// @grant       none
// ==/UserScript==
function make_global(arr)
{
  document["g_funcs"]={};
  var out=[];for(var i=0;i<arr.length;i++){var ex=arr[i];var exn=arr[i].name;document.g_funcs[exn]=arr[i];out.push("var "+exn+"=document.g_funcs."+exn);}
  var code=out.join("\n");var s=document.createElement('script');s.innerHTML=code;document.body.appendChild(s);
}
function PrintMyTable(table)
{
  function skip_field(field){
    var ignore=[];//["user_agent","request_uri","referrer"];
    for(var key in ignore)if(ignore[key]==field){return true;}
    return false;
  };
  var def_table=[{'id':1,'nick':'Owen'},{'id':2,'nick':'Kyle'}];
  if(!table.length){return 'table is empty';}
  if(!Object.keys(table[0]).length){return 'table is empty';}
  var km={};for(var i=0;i<table.length;i++){var ex=table[i];for(var k in ex){inc(km,k);}}
  var arr=Object.keys(km);
  var out="";var head="";
  for(var i in arr)
  {
    if(skip_field(arr[i]))continue;
    out+='<td>'+escapeHtml(arr[i])+'</td>';
  }
  var head='<thead><tr>'+out+'</tr></thead>';
  out="";
  for(var i=0;i<table.length;i++)
  {
    var tmp="";
    //var tmp_arr=table[table.length-i-1];
    var tmp_arr=table[i];
    for(var j=0;j<arr.length;j++){
      //if(skip_field(key))continue;
      var k=arr[j];var v="<b>0</b>";var bg="";
      if(k in tmp_arr){v=escapeHtml(tmp_arr[k]);}else{/*bg='class="bgw"';*/}
      tmp+='<td>'+v+'</td>';
    }
    out+='<tr>'+tmp+'</tr>';
  }
  out='<table>'+head+'<tbody>'+out+'</tbody></table>';
  return out;
}
function byid(name){return document.getElementById(name);}
function params_to_uri(params){var out=[];for (var k in params)out.push(encodeURIComponent(k)+'='+encodeURIComponent(params[k]));return out.join("&");}
function xhr_post_ex(url,content,callback)
{
  var x=new XMLHttpRequest();
  x.onreadystatechange=function(){if(x.readyState===4){callback(x.responseText);}};
  x.open("post",url);
  x.setRequestHeader('Content-Type','application/x-www-form-urlencoded');
  var token={"access_token":"*"};
  x.setRequestHeader('Authorization','Bearer '+token["access_token"]);
  x.send(content);return x;
}
function escapeHtml(text)
{
  if("string"!=(typeof text)){return text;}
  return text
      .replace(/&/g, "&amp;")
      .replace(/</g, "&lt;")
      .replace(/>/g, "&gt;")
      .replace(/"/g, "&quot;")
      .replace(/'/g, "&#039;");
}
function inc(map,key){if(!(key in map)){map[key]=0;}map[key]++;}
function set_url(url){byid('url').value=url;}
function showdata(data){byid('area').value=data;}
var style='<style type="text/css">table{border-collapse:collapse;font-size:10pt;}thead,thead tr td{background:#ccc;text-align:center;font-weight:bold;}td,thead{border:1px solid #800;padding:4px;}textarea[readonly="readonly"]{background-color:#e8e8e8;}tr td{background-color:#FFF}</style>';
document.body.innerHTML=style+"<pre><b>url: </b><input id='url' type='text' style='width:40%'>   <b>params:</b><input id='params' type='text' style='width:40%'>\n<div id='p'></div>\n<div id='ta'><textarea id='area' style='height:500;width:100%'></textarea></div><div id='end'></div></pre>";

var apis=["/api/account-info","/api/operation-history","/api/operation-details"];
function btn(s){return "<button onclick='set_url(this.innerHTML)'>"+s+"</button>";}
var out=[];for(var i=0;i<apis.length;i++){out.push(btn(apis[i]));}byid('p').innerHTML=out.join("  ");
function toggle(el){el.style.display=(el.style.display=='none')?'block':'none';}
function ToggleArea(){toggle(byid('ta'));}
function POAT(){
  byid('ta').style.display='none';
  xhr_post_ex('/api/operation-history','',function(data){
    byid('end').innerHTML=PrintMyTable(JSON.parse(data)['operations']);
  });
}
var next="\n\n<button id='btn'>call</button>   <button onclick='POAT()'>PrintOperationAsTable</button>   <button onclick='ToggleArea()'>ToggleArea</button>";


byid('p').innerHTML+=next;

byid('url').value="/api/account-info";
byid('btn').onclick=function(){xhr_post_ex(byid('url').value,byid('params').value,showdata);}


make_global([ToggleArea,POAT,inc,showdata,escapeHtml,xhr_post_ex,params_to_uri,byid,set_url,PrintMyTable]);



