echo "run node with this filename"
cat rt_proc_log_fn.txt
echo "or just read content of rt_proc_log_fn.txt in node js and use it as file name"
echo "in case when we need od smt on nodejs side with that"

cat empty.txt|node tee_with_pid25839.js|tee mask_pix_log(p505).streem.txt|node netsocket_write.js

#not shell but need

//simlink *from* *to*
simlink mask_pix_log(p505).txt /proc/25839/stdin

node proc25839.js>mask_pix_log(p505).streem.txt

inside "proc25839.js":

var out=fs.fileWriteStream("mask_pix_log(p505).streem.txt");
stdin.pipe(out);
stdin.on('data',chunk=>netsock.write(chunk));

or...

stdin.on('data',chunk=>netsock.write(chunk));
stdin.pipe(stdout);
or...


cat empty.txt|node tee_with_pid25839.js|tee mask_pix_log(p505).streem.txt|node netsocket_write.js




if("/rt_sh.nameserver.or_linkserver"==URI_or_URL){
  return inspect(g_links.filter(is_about_raytracer));
}


