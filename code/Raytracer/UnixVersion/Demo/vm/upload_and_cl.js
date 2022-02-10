var qap_async_for=(arr,elem2obj,ok,err)=>{
  var tasks=[];var tasks_n=arr.length;
  var on=(ex,mode)=>(data=>{
    tasks.push({mode:mode,ex:ex,data:data});if(tasks_n!=tasks.length)return;
    if(tasks.filter(e=>e.mode=='ok').length==tasks_n){
      ok(tasks);
    }else err(tasks);
  });
  if(!tasks_n)QapNoWay();
  arr.map(ex=>xhr_post("http://qap.atwebpages.com/deploy.php",elem2obj(ex),on(ex,'ok'),on(ex,'fail')));
};


var xhr_blob_upload_and_cl=(method,URL,ok,err)=>{
  var fromR=(z,msg)=>{if(z in z2func)z2func[z](msg);};
  var z2func={
    out:msg=>process.stdout.write(msg),
    err:msg=>process.stderr.write(msg),
    qap_log:msg=>qap_log("formR :: "+msg),
    exit:msg=>process.exit()
  };
  var req=qap_http_request_decoder(method,URL,fromR,()=>{process.exit();});
  
  var toR=z=>stream_write_encoder(req,z);
  toR("eval")(
    (()=>{
      var q=a=>toR("qap_log")("["+getDateTime()+"] :: "+a);
      var stream=false;var off=s=>{if(!s)return;s.destroy();}
      Object.assign(z2func,{
        fn:(msg,buf)=>{off(stream);stream=fs.createWriteStream(msg);q("fn = "+msg);},
        data:(msg,buf)=>{stream.write(buf);q(msg.length);},
        end:msg=>{q("done!");on_exit();}
      });
      
      var sh=spawn('nice',['-n19','bash','-i'],{detached:true});on_exit_funcs.push(()=>sh.kill('SIGHUP'));
      var finish=msg=>{
        q(msg);
        toR("exit")();
        on_exit();
      }
      
      on_exit_funcs.push(()=>off(stream));
    }).toString().split("\n").slice(1,-1).join("\n")
  );
  
  var ping=toR("ping");var iter=0;var ping_interval=set_interval(()=>ping(""+(iter++)),500);
  var on_exit_funcs=[];
  var on_exit=()=>{
    if(!ping_interval)return;
    clear_interval(ping_interval);ping_interval=false;
    on_exit_funcs.map(f=>f());
    req.destroy();
  }
    
  var tasks=[];var task_id=-1;var task_done=false;
  var task_upload_file=fn=>{
    toR("fn")(fn);
    fs.createReadStream("../../Release/"+fn).on('data',toR("data")).on('end',()=>{task_done=true;});
  }
  var worker_interval=set_interval(()=>{
    if(task_done){task_id++;task_done=false;}
    if(task_id<0)return;
    if(task_id>=tasks.length){qap_log("done!");toR("end")();return;}
    var func=tasks[task_id];
    if(typeof func!=="function")QapNoWay();
    func();
  },100);on_exit_funcs.push(()=>{clear_interval(worker_interval);});
  var upload_all=arr=>{
    arr.map(fn=>tasks.push(eval("()=>{/*"+json({fn:fn})+"*/+task_upload_file(fn);}")));
  };
  var spawn_and_do_stream_outputs_to_remote=(cmd)=>{
    toR("eval")(
      (()=>{
        Object.assign(z2func,{
          end:msg=>{q("done!");on_exit();}
        });
        
        var sh=spawn('nice',['-n19','bash','-i'],{detached:true});on_exit_funcs.push(()=>sh.kill('SIGHUP'));
        var finish=msg=>{
          q(msg);
          toR("exit")();
          on_exit();
        }
        
        sh.stderr.on("data",toR("err")).on('end',()=>q("end of stderr"));
        sh.stdout.on("data",toR("out")).on('end',()=>q("end of stdout"));
        sh.on('close',code=>finish("proc exited with code "+code));
        call_cb_on_err(sh,qap_log,'sh');
        z2func['inp']=msg=>sh.stdin.write(msg);
        on_exit_funcs.push(()=>{delete z2func['inp'];});
        q("begin");
      
        on_exit_funcs.push(()=>off(stream));
      }).toString().split("\n").slice(1,-1).join("\n")
    );
    z2func
  }
  var files=[
    "view.html","like_top.js","lodepng.cpp","lodepng.h","sphere4096.bin","proj_info.bin"
  ];
  upload_all(files);
  spawn_and_do_stream_outputs_to_remote("g++ -O2 main.cpp");
  spawn_and_do_stream_outputs_to_remote("./a.out");

  return req;
}
// look like not work :(
// under construction...



































