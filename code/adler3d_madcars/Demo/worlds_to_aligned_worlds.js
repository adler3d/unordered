var s=POST.data;
var arr=s.split("\n");
var jp=JSON.parse;
var f=(a,b)=>{
  if(typeof a!==typeof b)throw new Error("vars has differents types...");
  if(typeof a==='object'){
    if(a.constructor===Array)
    {
      if(b.constructor!==Array)throw new Error("objects constructor is no the same...");
      for(var i=0;i<Math.min(a.length,b.length);i++)b[i]=f(a[i],b[i]);
      return b;
    }
    var out={};
    if("button_poly" in a)if(!("squared_wheels" in a))a["squared_wheels"]=false;
    if("button_poly" in b)if(!("squared_wheels" in b))b["squared_wheels"]=false;
    for(var k in a){if(!["my_lives","enemy_lives","lives"].includes(k))continue;delete a[k];}
    for(var k in b){if(!["my_lives","enemy_lives","lives"].includes(k))continue;delete b[k];}
    if(mapkeys(a).sort().join(",")!=mapkeys(b).sort().join(","))throw new Error("objects keys is no the same..."+inspect([mapkeys(a).sort(),mapkeys(b).sort()]));
    for(var k in a){out[k]=f(a[k],b[k]);}
    return out;
  }
  return b;
}
for(var i=2;i<arr.length;i+=2){
  arr[i-0]=json(f(jp(arr[i-2]),jp(arr[i-0])));
  arr[i-2]=json(f(jp(arr[i-0]),jp(arr[i-2])));
}
return arr.filter((e,i)=>i%1==0).join("\n");