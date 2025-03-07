<?php
  function hint($msg){echo "<pre>".$msg."\n</pre>";}
  function prepare($msg)
  {
    return str_replace("\n","<br />",str_replace(" ","&nbsp;",htmlspecialchars($msg)));
  }
  function PrintMyTable($answer)
  {
    $def_answer=array(array('id'=>1,'nick'=>'Owen'),array('id'=>2,'nick'=>'Kyle'));
    if(!count($answer)){hint('table is empty');return;}
    if(!count($answer[0])){hint('table is empty');return;}
    $arr=array();
    foreach($answer as $k=>$v){$qa=array_keys((array)$v);foreach($qa as $qk=>$qv){$arr[$qv]=0;}}
    $arr=array_keys($arr);
    $out="";
    foreach($arr as $key=>$value)
    {
      $out.='<th>'.prepare($value).'</th>';
    }
    $out='<tr>'.$out.'</tr>';
    foreach($answer as $row)
    {
      $tmp="";
      $row=(array)$row;
      foreach($arr as $id=>$key){
        $tmp.='<td>'.prepare(array_key_exists($key,$row)?$row[$key]:"").'</td>';
      }
      $out.='<tr>'.$tmp.'</tr>';
    }
    $out='<table>'.$out.'</table>';
    return $out;
  }
  function group($arr,$field)
  {
    $buff=array();
    foreach($arr as $rec)
    {
      $recarr=(array)$rec;
      $value=$recarr[$field];
      $buff[$value]++;
    }
    foreach($buff as $key=>$value)
    {
      if($field=='time')if($value<=1){continue;}
      $outarr[]=array('value'=>$key,'count'=>$value);
    }
    return $outarr;
  }
  function CMD_Stats($logs)
  {
    $arr=array_keys((array)$logs[0]);
    $output="";
    foreach($arr as $key=>$value)
    {
      $group=group($logs,$value);
      $group=count($group)?$group:array(array("table"=>"empty"));
      $table=PrintMyTable($group);
      $output.="<b>$value</b>\n".$table."\n";
    }
    hint($output);
  }
  $log_file_name=gmdate("Y-m-d").".log";
  if(isset($_GET['file'])){$log_file_name=$_GET['file'];}
  $filename=dirname(__FILE__)."/post_logs/".$log_file_name;
  if(!file_exists($filename)){hint(PrintMyTable(array(array('file'=>$filename,'status'=>'file not exists'))));return;}
  $content="[\n".implode(",\n",explode("\n",file_get_contents($filename)))."\n]";
  //hint($content);
  $logs=json_decode($content);
  if(array_key_exists('posts',$_GET))
  {
    $all=array_key_exists('all',$_GET);
    $out=array();
    foreach($logs as $i=>$v)
    {
      $t=array();$v=(array)$v;
      $t["notify_time"]=$v['time'];
      $post=json_decode($v['post'],true);
      $m=array_merge($t,$post);
      if(!$all)if($v['method']!='post'||$t['test_notification'])continue;
      $out[$i]=$m;
    }
    $logs=$out;
  }
  if(array_key_exists('json',$_GET)){header("content-type:text/plain");echo $content;exit;}
  //hint(print_r($logs,true));
?><style type="text/css">
  table{border-collapse:collapse;font-family:Consolas;font-size:10pt;}th{background:#ccc;text-align:center;}td,th{border:1px solid #800;padding:4px;}
</style><?php
  CMD_Stats($logs);
  hint(PrintMyTable($logs));
  //hint("<h1>Stats</h1>");
?>