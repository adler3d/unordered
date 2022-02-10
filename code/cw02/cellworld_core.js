//BEGIN OF COMPILE TYPE
var g_frag_func=null;
var g_func_es=null;
var g_step_id=0;
var g_scopes=[];
var g_field={w:64,h:64,arr:[]};
var g_stop=true;
var g_gen=false;
var g_onestep=false;
var start=function(){g_stop=false;}
var stop=function(){g_stop=true;}
var step=function(){g_onestep=true;}
var g_step_info={v:{},time_total:0};
var update_step_info=function(info,t)
{
  info.time_total+=t;
  var v=info.v;
  if(!("max" in v)){
    v.min=numeric_limits_jsint_max();
    v.max=numeric_limits_jsint_min();
  }
  v.min=Math.min(v.min,t);
  v.max=Math.max(v.max,t);
  v.avg=Math.round(info.time_total/g_step_id);
  v.step=g_step_id;
  v.cps=g_field.w*g_field.h/v.avg;v.cps=((v.cps=v.cps*1000)|0)/1000;
  byid('info').innerHTML="step time : "+t+"ms<br> g_step_info : "+JSON.stringify(v);
}
var do_step=function(){
  //setTimeout(do_step,128);
  if(!g_onestep)if(g_stop)return setTimeout(do_step,16);g_onestep=false;
  if(!g_gen){gen();}
  g_step_id++;//if(g_step_id>100)return;
  //console.log(b);
  var bef_time=Date.now();
  update_v3(g_scopes,g_field);
  field_draw_to_canvas(g_field);
  var aft_time=Date.now();
  update_step_info(g_step_info,aft_time-bef_time);
  setTimeout(do_step,16);
};
setTimeout(do_step,128);
function field_clone(field){var out={w:field.w,h:field.h,arr:[]};out.arr.length=field.arr.length;return out;}
function norm_point(field,x,y)
{
  return [safe_mod(x,field.w),safe_mod(y,field.h)];
}
function get_depends_cells(scopes,field,x,y)
{
  var cells=[];
  var view_at=function(dx,dy){cells.push(norm_point(field,x+dx,y+dy));return field_get_cell(field,x+dx,y+dy);}
  func_es_full(scopes,view_at);
  return GetUniquePoints(cells);
}
var g_update_obj={};
function find_pos(arr,pos)
{
  for(var i=0;i<arr.length;i++){var ex=arr[i];if(ex[0]==pos[0])if(ex[1]==pos[1])return i;}
  return -1;
}
function find_id(arr,id)
{
  //return arr.indexOf(id);
  for(var i=0;i<arr.length;i++){if(arr[i]==id)return i;}
  return -1;
}
function GetUniquePoints(arr)
{
  var out=[];
  var n=arr.length;
  for(var i=0;i<n;i++){
    var ex=arr[i];
    if(find_pos(out,ex)<0)out.push(ex);
  }
  return out;
}
var g_log=[];function addlog(o){g_log.push(JSON.stringify(o));}
function update2(scopes,field)
{
  var out_field=field_clone(field);
  var env=g_update_obj;
  var w=field.w;
  var h=field.h;
  if(!("old" in env)){env.old=[];var arr=env.old;var n=w*h;arr.length=n;for(var i=0;i<n;i++)arr[i]=1;}
  if(!("sub" in env)){env.sub=[];var arr=env.sub;var n=w*h;arr.length=n;for(var i=0;i<n;i++)arr[i]=[];}
  if(!("dep" in env)){env.dep=[];var arr=env.dep;var n=w*h;arr.length=n;for(var i=0;i<n;i++)arr[i]=[];}
  var old=env.old;
  var cur=[];cur.length=w*h;for(var i=0;i<cur.length;i++)cur[i]=old[i];
  var sub=env.sub;
  var dep=env.dep;
  var on_n=0;var off_n=0;
  var cell_enable=function(x,y){
    x=safe_mod(x,w);
    y=safe_mod(y,h);
    var pos=x+y*w;
    var arr=dep[pos];
    for(var i=0;i<arr.length;i++){
      var px=arr[i][0];var py=arr[i][1];
      if(px==x)if(py==y)continue;
      var id=px+py*w;
      var ex=sub[id];
      var e=find_id(ex,pos);
      if(e<0){
        addlog(["enable:no",{x:x,y:y,pos:pos,px:px,py:py,id:id,e:e,ex:ex}]);
        return;
      }else{
        //addlog(["enable:ok",{x:x,y:y,pos:pos,px:px,py:py,id:id,e:e,ex:ex}]);
      }
      ex.splice(e,1);
    }
    arr.length=0;
  }
  var cell_disable=function(x,y){
    var arr=get_depends_cells(scopes,field,x,y);
    x=safe_mod(x,w);
    y=safe_mod(y,h);
    var pos=x+y*w;
    dep[pos]=arr;
    for(var i=0;i<arr.length;i++){
      var px=arr[i][0];var py=arr[i][1];
      if(px==x)if(py==y)continue;
      var id=px+py*w;
      var ex=sub[id];
      var e=find_id(ex,pos);
      if(e>=0){
        addlog(["disable:no",{pos:pos,id:id,x:x,y:y,px:px,py:py,e:e,ex:ex}]);addlog(arr);
        return;
      }else{
        //addlog(["disable:ok",{x:x,y:y,pos:pos,px:px,py:py,id:id,e:e,ex:ex}]);
      }
      ex.push(pos);
    }
  }
  //g_log=[];
  //addlog("bef");
  for(var y=0;y<h;y++)for(var x=0;x<w;x++)
  {
    var id=x+y*w;
    if(!old[id])continue;//addlog(["on",[x,y]]);
    var arr=get_depends_cells(scopes,field,x,y);
    for(var i=0;i<arr.length;i++){
      var px=arr[i][0];var py=arr[i][1];
      cell_enable(px,py);
      cur[px+py*w]=1;
    }
  }
  (function(){var tmp=cur;cur=old;old=tmp;}());
  //addlog("main");
  for(var y=0;y<h;y++)for(var x=0;x<w;x++)
  {
    var id=x+y*w;
    if(old[id])
    {
      on_n++;
      var view_at=function(dx,dy){return field_get_cell(field,x+dx,y+dy);}
      var ret=func_es_full(scopes,view_at);
      if(ret[0]>1)addlog({fail:[x,y]});
      cur[id]=ret[0];
      if(ret[0]){
        field_set_cell(out_field,x,y,ret[1]);addlog({ok:[x,y]});
      }else{
        field_set_cell(out_field,x,y,field_get_cell(field,x,y));//addlog({no:[x,y]});
      }
    }else{
      off_n++;
      field_set_cell(out_field,x,y,field_get_cell(field,x,y));
    }
  }
  //addlog("aft");
  for(var y=0;y<h;y++)for(var x=0;x<w;x++)
  {
    var id=x+y*w;
    if(!old[id])continue;
    if(cur[id])continue;
    //addlog(["off",{x:x,y:y}]);
    cell_disable(x,y);
  }
  //addlog({alive:on_n,off:off_n});
  env.old=cur;g_update_obj=env;
  //document.getElementById("data").value=g_log.join("\n");
  return out_field;
}
var swap_by_f=(a,b)=>{var tmp=a.f;a.f=b.f;b.f=tmp;};var gen_swap_by=f=>eval((swap_by_f+"").split("f").join(f));
var swap_by_arr=gen_swap_by("arr");
function update_v3(scopes,field){
  //var tmp=field_clone(field);update_impl(tmp,scopes,field);g_field=tmp;return;
  var f=field;
  var init=()=>{
    f.v3=field_clone(f);
  };
  if(!('v3' in f))init();
  var n=f.v3;
  if(n.arr.length!=f.arr.length)init();
  //clear(n.arr);
  n.w=f.w;n.h=f.h;
  update_impl(n,scopes,f);
  swap_by_arr(f,n);
}
function update_old_with_extracopy(scope,field){var out_field=field_clone(field);return update_impl(out_field,scopes,field);}
function update_impl(out_field,scopes,field)
{
  //var out_field=field_clone(field);
  //var pre_field=field_clone(field);
  var passed=[];
  if(1)
  {
    for(var y=0;y<field.h;y++)for(var x=0;x<field.w;x++)
    {
      var view_at=function(dx,dy){return field_get_cell(field,x+dx,y+dy);}
      var retval=func_prepare_as(scopes,view_at);
      if(retval){passed.push([x,y]);}else{field_set_cell(out_field,x,y,view_at(0,0));}
      //var color=retval>0?0xffffffff:0xff000000;
      //field_set_cell(out_field,x,y,color);
    }
  }
  if(1)
  {
    for(var i in passed)
    {
      var x=passed[i][0];
      var y=passed[i][1];
      var view_at=function(dx,dy){return field_get_cell(field,x+dx,y+dy);}
      var retval=g_frag_func(scopes,view_at);
      field_set_cell(out_field,x,y,retval);
    }
  }
  if(0)
  {
    for(var y=0;y<field.h;y++)for(var x=0;x<field.w;x++)
    {
      var view_at=function(dx,dy){return field_get_cell(field,x+dx,y+dy);}
      var retval=g_frag_func(scopes,view_at);
      //if(view_at(0,0)!=retval){console.log([x,y,retval]);alert(1);}
      field_set_cell(out_field,x,y,retval);
    }
  }
  return out_field;
}
function unfreeze(){g_update_obj={}}
var g_rules=[];
function rule2js(r){
  return [".......",r[0],r[1].split("\n"),r[2].split("\n")];
}
function rules_as_json(n){return JSON.stringify({c2t:makemap_celltype2color(),rules:g_rules.map(rule2js)},0,n|0?n:2);}
function show_rules(){var e=byid("rules");e.value=rules_as_json();e.parentElement.style.display="";}
function gen()
{
  unfreeze();
  g_gen=true;
  g_rules=[];
  var scopes=[];
  var add_rule=function(level,from,to){
    var scope=makeRuleScopeFromTwoStrAndLevel(level,from,to);
    upadte_usefullmodes(scope);
    scopes.push(scope);
    g_rules.push([level,from,to]);
    //if(scopes.length>1)throw new Error("no way");
  };
  var zs=(s,a,b)=>s.split("1").join(a).split("2").join(b);
  var transfer_light=(LVL,str,types)=>{
    if(typeof types=='undefined')types="GO";
    var f=(bef,aft)=>add_rule(LVL,zs(str,bef[0],bef[1]),zs(str,aft[0],aft[1]));
    var g=(bef,aft)=>f(zs(bef,types[0],types[1]),zs(aft,types[0],types[1]));
    g("12","11");g("21","22");
  }
  var add_two=(LVL,bef,aft,types)=>{
    if(typeof types=='undefined')types="GO";
    types.split("").map(e=>add_rule(LVL,bef.split("1").join(e),aft.split("1").join(e)));
  }
  eval(document.getElementById("code").value);
  scopes=scopes.sort(function(a,b){return a.level==b.level?0:a.level<b.level?-1:+1;});
  g_scopes=scopes;
  if(1)if(g_frag_func==null){
    g_frag_func=func_es;
  }
  if(g_frag_func==null){
    gen_functions(scopes);
    g_frag_func=function(scopes,view_at){return g_func_es(view_at);};
  }
}
function makemap_celltype2color(c)
{
  var map={};
  var add=function(id,s,r,g,b){map[s]=/*(0xff<<24)|*/((b&0xff)<<16)|((g&0xff)<<8)|((r&0xff)<<0);map[s]+=0xff000000;}
  add(0x0,' ',0xff,0xff,0xff);
  add(0x1,'R',0xff,0x00,0x00);
  add(0x2,'G',0x00,0xff,0x00);
  add(0x3,'B',0x00,0x00,0xff);
  add(0x4,'N',0x00,0x00,0x00);
  add(0x5,'#',0x80,0x80,0x80);
  add(0x6,'Y',0xff,0xff,0x00);
  add(0x7,'O',0xff,0x80,0x00);
  add(0x8,'T',0xff,0x80,0xff);
  add(0x9,'H',0xff,0x40,0x00);
  add(0xA,'+',153,217,234);
  return map;
}
function field_to_text(field){
  var r={};var w=makemap_celltype2color();Object.keys(w).map(e=>r[w[e]]=e);
  var f=field.arr.map(e=>e in r?r[e]:".").join("");
  var z=[];
  for(var i=0;i<field.h;i++)z.push(f.slice(i*field.w,(i+1)*field.w));
  return z.join("\n")
}
function user_code(){
  document.body.innerHTML='<pre style="line-height:0.8">'+field_to_text(g_field);//.split("X").join(" ");//.split("O").join(".");
}
function safe_CharToCellType(c)
{
  var map=makemap_celltype2color();
  if(c in map)return [true,map[c]];
  return [false];
}
function safe_UintToRGBA(t)
{
  var tmp=t;
  var r=(tmp%0x100)|0;
  tmp/=0x100;
  var g=(tmp%0x100)|0;
  tmp/=0x100;
  var b=(tmp%0x100)|0;
  tmp/=0x100;
  var a=(tmp%0x100)|0;
  return [r,g,b,a];
}
function makeRuleScopeFromTwoStrAndLevel(level,inp,out)
{
  var arr=[];
  var x=0;
  var y=0;
  if(inp.length!=out.length)throw new Error();
  for(var i in inp)
  {
    var a=inp[i];
    var b=out[i];
    var next_line='\n'==a;
    if(next_line)
    {
      if('\n'!=b)throw new Error();
      y++;x=0;
      continue;
    }
    if('.'==a)
    {
      if('.'!=b)throw new Error();
      x++;
      continue;
    }
    var code={a:0,b:0};
    {var ret=safe_CharToCellType(a);if(!ret[0])throw new Error();code.a=ret[1];}
    {var ret=safe_CharToCellType(b);if(!ret[0])throw new Error();code.b=ret[1];}
    arr.push({from:code.a,to:code.b,x:x,y:y});
    x++;
  }
  return JSON.parse(JSON.stringify({arr:arr,level:level}));
}
function numeric_limits_jsint_min(){
  if((Math.pow(2,53))!=(Math.pow(2,53)+1))throw new Error();
  return -Math.pow(2,53);
}
function numeric_limits_jsint_max(){
  if((Math.pow(2,53))!=(Math.pow(2,53)+1))throw new Error();
  return +Math.pow(2,53);
}
function scope_get_size(scope)
{
  var minx=numeric_limits_jsint_max();
  var miny=numeric_limits_jsint_max();
  var maxx=numeric_limits_jsint_min();
  var maxy=numeric_limits_jsint_min();
  var arr=scope.arr;
  for(var i in arr)
  {
    var ex=arr[i];
    minx=Math.min(minx,ex.x);
    miny=Math.min(miny,ex.y);
    maxx=Math.max(maxx,ex.x);
    maxy=Math.max(maxy,ex.y);
  }
  return {minx:minx,miny:miny,maxx:maxx,maxy:maxy};
}
function make_empty_field(scope,dir)
{
  var s=scope_get_size(scope);
  var field={};
  field.w=s.maxx-s.minx+1;
  field.h=s.maxy-s.miny+1;
  var p=use_dir(dir,field.w,field.h);
  field.w=Math.abs(p.x);
  field.h=Math.abs(p.y);
  field.arr=[];
  for(var i=0;i<(field.w*field.h);i++)field.arr.push(0);
  return field;
}
function safe_mod(a,mod)
{
  if(mod<=0)throw new Error(JSON.stringify(["no way : ",mod]));
  while(a<0)a+=mod;
  return a%mod;
}
function field_get_cellid(field,x,y){return field.w*safe_mod(y,field.h)+safe_mod(x,field.w);}
function field_get_cell(field,x,y)
{
  var id=field_get_cellid(field,x,y);
  return field.arr[id];
}
function field_set_cell(field,x,y,value)
{
  var id=field_get_cellid(field,x,y);
  field.arr[id]=value;
}
//convert("empty_field" to "rot_field").from("scope with dir")
function empty_field_to_rot_field_from_scope_with_dir(field,scope,dir)
{
  var arr=scope.arr;
  var s=scope_get_size(scope);
  var out=JSON.parse(JSON.stringify(field));
  for(var i in arr)
  {
    var ex=arr[i];
    var dx=ex.x-s.minx;
    var dy=ex.y-s.miny;
    var p=!RotModeToRotFlags(dir).swap?invuse_dir(dir,dx,dy,field.w,field.h):invuse_dir(dir,dx,dy,field.h,field.w);
    field_set_cell(out,p.x,p.y,ex.from);
  }
  //console.log(JSON.stringify(out));
  return out;
}
function upadte_usefullmodes(scope)
{
  var usefullmodes=[];
  for(var i=0;i<8;i++)usefullmodes.push(true);
  var fields=[];
  for(var dir=0;dir<8;dir++)
  {
    fields[dir]=make_empty_field(scope,dir);
  }
  for(var dir=0;dir<8;dir++)
  {
    fields[dir]=empty_field_to_rot_field_from_scope_with_dir(fields[dir],scope,dir);
  }
  for(var i=0;i<8;i++)
  {
    var a=fields[i];
    for(var j=i+1;j<8;j++)
    {
      var b=fields[j];
      if(JSON.stringify(a)===JSON.stringify(b))
      {
        usefullmodes[j]=false;//if(i==3)throw new Error(JSON.stringify(b));
      }
    }
  }
  //console.log(JSON.stringify(usefullmodes));
  scope.usefullmodes=usefullmodes;
  scope.dirs=usefullmodes;
}

//END OF COMPILE TYPE

//BEGIN OF PREPARE
var func_spe_fast=function(scopes,view_at,scope_id,id,dir){
  var arr=scopes[scope_id].arr;
  var n=arr.length;
  var o=arr[id];
  for(var i=0;i<n;i++)
  {
    var ex=arr[i];
    var p=get_point(dir,ex,o);
    if(ex.from!=view_at(p.x,p.y))return 0;
  }
  return 1;
}

var func_prepare=function(color,scopes,view_at,scope_id){
  var arr=scopes[scope_id].arr;
  var n=arr.length;
  var dirs=scopes[scope_id].dirs;
  var count=0;
  var result=exec_result_t(false,0);
  for(var id=0;id<n;id++)
  {
    if(arr[id].from!=color)continue;
    for(var dir=0;dir<8;dir++)
    {
      if(!dirs[dir])continue;
      count+=func_spe_fast(scopes,view_at,scope_id,id,dir);
    }
  }
  return count;
}

var func_prepare_as=function(scopes,view_at){
  var count=0;
  var n=scopes.length;
  var color=view_at(0,0);
  for(var i=0;i<n;i++){
    var ret=func_prepare(color,scopes,view_at,i);if(ret>0)count+=ret;
    //if(n==(i+1))continue;
    //if(scopes[i+1].level==scopes[i].level)continue;
    //if(count==1)break;
  }
  return count;
}
//END OF PREPARE

//BEGIN OF RUN TIME
function RotModeToRotFlags(mode)
{
  return {
    invx:(mode>>0)%2,
    invy:(mode>>1)%2,
    swap:(mode>>2)%2
  };
}
function RotFlagsToRotMode(flags)
{
  var value=0;
  if(flags.invx)value+=1<<0;
  if(flags.invy)value+=1<<1;
  if(flags.swap)value+=1<<2;
  return value;
}
function use_dir(dir,dx,dy)
{
  var flags=RotModeToRotFlags(dir);
  if(flags.invx)dx=-dx;
  if(flags.invy)dy=-dy;
  if(flags.swap){var tmp=dx;dx=dy;dy=tmp;}
  return {x:dx,y:dy};
}

function invuse_dir(dir,dx,dy,w,h)
{
  var flags=RotModeToRotFlags(dir);
  if(flags.invx)dx=w-dx-1;
  if(flags.invy)dy=h-dy-1;
  if(flags.swap){var tmp=dx;dx=dy;dy=tmp;}
  return {x:dx,y:dy};
}

function get_point(dir,ex,o)
{
  var dx=ex.x-o.x;
  var dy=ex.y-o.y;
  return use_dir(dir,dx,dy);
}

var t_scope_result=function(count,value){return {count:count,value:value};}
var exec_result_t=function(ok,value){return {ok:ok,value:value};}

var func_spe=function(scopes,view_at,scope_id,id,dir,x,y){
  var arr=scopes[scope_id].arr;
  var n=arr.length;
  var o=arr[id];
  for(var i=0;i<n;i++)
  {
    var ex=arr[i];
    var p=get_point(dir,ex,o);
    if(ex.from!=view_at(x+p.x,y+p.y))return 0;
  }
  return 1;
}

var func_speadap=function(scopes,view_at,scope_id,x,y){
  var arr=scopes[scope_id].arr;
  var n=arr.length;
  var dirs=scopes[scope_id].dirs;
  var count=0;
  for(var id=0;id<n;id++)
  {
    for(var dir=0;dir<8;dir++)
    {
      if(!dirs[dir])continue;
      count+=func_spe(scopes,view_at,scope_id,id,dir,x,y);
    }
  }
  return count;
}

var func_cc=function(scopes,view_at,scope_id,x,y){
  var count=0;
  var level=scopes[scope_id].level;
  for(var other_scope_id=0;other_scope_id<scopes.length;other_scope_id++){
    if(scopes[other_scope_id].level>level)continue;
    count+=func_speadap(scopes,view_at,other_scope_id,x,y);
  }
  return 1==count;
}

var func_ep=function(scopes,view_at,scope_id,id,dir){
  var arr=scopes[scope_id].arr;
  var n=arr.length;
  if(0==func_spe(scopes,view_at,scope_id,id,dir,0,0))return exec_result_t(false,0);
  var o=arr[id];
  if(o.to==o.from)return exec_result_t(false,0);
  for(var i=0;i<n;i++)
  {
    var ex=arr[i];
    if(ex.from==ex.to)continue;
    var p=get_point(dir,ex,o);
    if(!(func_cc(scopes,view_at,scope_id,p.x,p.y)))return exec_result_t(false,0);
  }
  return exec_result_t(true,o.to);
}

var func_epadap=function(color,scopes,view_at,scope_id){
  var arr=scopes[scope_id].arr;
  var n=arr.length;
  var dirs=scopes[scope_id].dirs;
  var count=0;
  var result=exec_result_t(false,0);
  for(var id=0;id<n;id++)
  {
    if(arr[id].from!=color)continue;
    for(var dir=0;dir<8;dir++)
    {
      if(!dirs[dir])continue;
      {var ret=func_ep(scopes,view_at,scope_id,id,dir);if(ret.ok){count++;result=ret;}}
    }
  }
  if(count==1)return t_scope_result(count,result.value);
  return t_scope_result(count,0);
}

var func_es=function(scopes,view_at){
  var count=0;
  var result=exec_result_t(false,0);
  var n=scopes.length;
  var color=view_at(0,0);
  for(var i=0;i<n;i++){
    var ret=func_epadap(color,scopes,view_at,i);if(ret.count>0){count+=ret.count;result.value=ret.value;}
    //if(n==(i+1))continue;
    //if(scopes[i+1].level==scopes[i].level)continue;
    //if(count==1)break;
  }
  if(count==1)return result.value;
  if(count==0)return view_at(0,0);
  return 0xff000000;
}

var func_es_full=function(scopes,view_at){
  var count=0;
  var value=0;
  var n=scopes.length;
  var color=view_at(0,0);
  for(var i=0;i<n;i++){
    var ret=func_epadap(color,scopes,view_at,i);if(ret.count>0){count+=ret.count;value=ret.value;}
  }
  return [count,value];
}
//END OF RUN TIME
//BEGIN OF CODE GEN
var pad=function(str,max){return str.length<max?pad("0"+str,max):str;};
function hexpad(x){if(typeof x==="string")x=JSON.parse(x);return pad(x.toString(16),4);}
var add_func_call=function(func,code,params){
  var index=null;
  for(var i in func_map_decl)if(func_map_decl[i][0]===func){index=i;break;}
  if(index===null)throw new Error();
  var ex=func_map_decl[index];
  var key=ex[2];
  if(!(4 in ex))ex[4]={};
  var codearr=ex[4];
  if(code in codearr){if(undefined == codearr[code])throw new Error();return [codearr[code],"(",params.join(","),")"].join("");}
  if(!(3 in ex))ex[3]=[];
  var arr=ex[3];
  var id=JSON.stringify(arr.length);
  arr.push(code);
  var callstr=["func_",key,"0x",hexpad(id)].join("");
  codearr[code]=callstr;
  return [callstr,"(",params.join(","),")"].join("");
}
var g_func_es=null;
var gen_functions=function(scopes)
{
  for(var i in func_map_decl){
    func_map_decl[i][3]=[];
    func_map_decl[i][4]={};
  }
  console.log("before execute_scopes");
  var call_func_es=execute_scopes(scopes,"view_at");
  console.log("after execute_scopes");
  var out="";
  for(var i in func_map_decl)
  {
    var ex=func_map_decl[i];
    var arr=ex[3];
    var params=(5 in ex)?ex[5]:"()";
    for(var id in arr){
      out+=["var func_",ex[2],"0x",hexpad(id),"=function",params,"{\n",add_ident(arr[id]),"}\n"].join("");
    }
  }
  console.log("before eval");
  eval(out+";g_func_es=func_es0x"+hexpad(0)+";");
  console.log("after eval");
  document.getElementById("data").value=out;
}
var ident=function(arr,skip)
{
  var out="";
  for(var i in arr)
  {
    var ex=arr[i];
    if(typeof ex=="string"){out+=(skip?"":"  ")+ex+"\n";continue;}
    if(skip){out+=add_ident(ident(ex,true));continue;}
    if(!skip){out+=add_ident(ident(ex,true));continue;}
  }
  while(out.length&&(out[out.length-1]=="\n"))out=out.substr(0,out.length-1);
  return out+(skip?"\n":"");
}
var add_ident=function(s){var arr=s.split("\n");for(var i in arr)if(arr[i].length)arr[i]="  "+arr[i];return arr.join("\n");}
var view_at=function(x,y){
  return "view_at("+x+","+y+");";
}
var scope_pre_execute=function(scopes,view_at,scope_id,id,dir,x,y){
  var arr=scopes[scope_id].arr;
  var n=arr.length;
  var dev=[];
  var o=arr[id];
  for(var i=0;i<n;i++)
  {
    var ex=arr[i];
    var p=get_point(dir,ex,o);
    dev.push("if("+ex.from+"!=view_at("+[x+p.x,y+p.y].join(",")+"))return 0;");
  }
  dev.push("return 1;");
  var code=ident(dev,true);
  return add_func_call(scope_pre_execute,code,["view_at"]);
}

var scope_pre_execute_any_dir_any_point=function(scopes,view_at,scope_id,x,y){
  var arr=scopes[scope_id].arr;
  var n=arr.length;
  var dirs=scopes[scope_id].dirs;
  var dev=[];
  dev.push("var count=0;");
  for(var id=0;id<n;id++)
  {
    for(var dir=0;dir<8;dir++)
    {
      if(!dirs[dir])continue;
      dev.push("count+="+scope_pre_execute(scopes,view_at,scope_id,id,dir,x,y)+";");
    }
  }
  dev.push("return count;");
  var code=ident(dev,true);
  return add_func_call(scope_pre_execute_any_dir_any_point,code,["view_at"]);
}

var check_conflicts=function(scopes,view_at,scope_id,x,y){
  var dev=[];
  dev.push("var count=0;");
  var level=scopes[scope_id].level;
  for(var other_scope_id=0;other_scope_id<scopes.length;other_scope_id++){
    if(scopes[other_scope_id].level>level)continue;
    dev.push("count+="+scope_pre_execute_any_dir_any_point(scopes,"view_at",other_scope_id,x,y)+";");
  }
  dev.push("return 1==count;");
  var code=ident(dev,true);
  return add_func_call(check_conflicts,code,[view_at]);
}

var execute_point=function(scopes,view_at,scope_id,id,dir){
  var arr=scopes[scope_id].arr;
  var n=arr.length;
  var dev=[];
  dev.push("if(0=="+scope_pre_execute(scopes,"view_at",scope_id,id,dir,0,0)+")return exec_result_t(false,0);");
  var o=arr[id];
  if(o.to==o.from)dev.push("return exec_result_t(false,0);");
  for(var i=0;i<n;i++)
  {
    var ex=arr[i];
    if(ex.from==ex.to)continue;
    var p=get_point(dir,ex,o);
    dev.push("if(!("+check_conflicts(scopes,"view_at",scope_id,p.x,p.y)+"))return exec_result_t(false,0);");
  }
  dev.push("return exec_result_t(true,"+o.to+");");
  var code=ident(dev,true);
  return add_func_call(execute_point,code,[view_at]);
}

var execute_point_any_dir_any_point=function(scopes,view_at,scope_id){
  var arr=scopes[scope_id].arr;
  var n=arr.length;
  var dirs=scopes[scope_id].dirs;
  var dev=[];
  dev.push("var count=0;");
  dev.push("var result=exec_result_t(false,0);");
  for(var id=0;id<n;id++)
  {
    for(var dir=0;dir<8;dir++)
    {
      if(!dirs[dir])continue;
      dev.push("{var ret="+execute_point(scopes,"view_at",scope_id,id,dir)+";if(ret.ok){count++;result=ret;}}");
    }
  }
  dev.push("if(count==1)return t_scope_result(count,result.value);");
  dev.push("return t_scope_result(count,0);");
  var code=ident(dev,true);
  return add_func_call(execute_point_any_dir_any_point,code,[view_at]);
}

var execute_scopes=function(scopes,view_at){
  var dev=[];
  dev.push("var count=0;");
  dev.push("var result=exec_result_t(false,0);");
  //dev.push("do{");
  {
    //var parent_dev=dev;dev=[];
    for(var i=0;i<scopes.length;i++)
    {
      dev.push("{var ret="+execute_point_any_dir_any_point(scopes,"view_at",i)+";if(ret.count>0){count+=ret.count;result.value=ret.value;}}");
      //if(n==(i+1))continue;
      //if(scopes[i+1].level==scopes[i].level)continue;
      //dev.push("if(count==1)break;");
    }
    //parent_dev.push(dev);dev=parent_dev;
  }
  //dev.push("}while(false);");
  dev.push("if(count==1)return result.value;");
  dev.push("if(count==0)return view_at(0,0);");
  dev.push("return 0xff000000;");
  var code=ident(dev,true);
  return add_func_call(execute_scopes,code,[view_at]);
}
var func_map_decl=[
  [scope_pre_execute,"int","spe",[],{},"(view_at)"],
  [scope_pre_execute_any_dir_any_point,"int","speadap",[],{},"(view_at)"],
  [check_conflicts,"bool","cc",[],{},"(view_at)"],
  [execute_point,"exec_result_t","ep",[],{},"(view_at)"],
  [execute_point_any_dir_any_point,"t_scope_result","epadap",[],{},"(view_at)"],
  [execute_scopes,"uint","es",[],{},"(view_at)"],
];
//END OF CODE GEN