<html id="js" class="i-ua_js_yes i-ua_css_quirks i-ua_svg_yes i-ua_inlinesvg_yes i-ua_svg_yes i-ua_inlinesvg_yes pointerfocus"><head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <!--[if gt IE 9]><!-->
    <link rel="stylesheet" href="//money.yandex.ru/lego/css/_money.css?build=328">
    <!--<![endif]-->
    <!--[if IE 6]><link rel=stylesheet href="https://money.yandex.ru/lego/css/_money.ie6.css?build=328"><![endif]-->
    <!--[if IE 7]><link rel=stylesheet href="https://money.yandex.ru/lego/css/_money.ie7.css?build=328"><![endif]-->
    <!--[if IE 8]><link rel=stylesheet href="https://money.yandex.ru/lego/css/_money.ie8.css?build=328"><![endif]-->
    <!--[if IE 9]><link rel=stylesheet href="//money.yandex.ru/lego/css/_money.ie9.css?build=328"><![endif]-->
    <!--[if gt IE 7]><!-->
    <link rel="stylesheet" href="//money.yandex.ru/lego/css/_lego.css?build=328">
    <!--<![endif]-->
    <!--[if lt IE 9]><link rel=stylesheet href="//money.yandex.ru/lego/css/_lego.ie.css?build=328"><![endif]-->
    <!--[if gt IE 9]><!-->
    <link rel="stylesheet" href="//money.yandex.ru/b/_old-site.css?v=">
    <!--<![endif]-->
    <!--[if IE 7]><link rel=stylesheet href="//money.yandex.ru/b/_old-site.ie7.css?v="><![endif]-->
    <!--[if IE 8]><link rel=stylesheet href="//money.yandex.ru/b/_old-site.ie8.css?v="><![endif]-->
    <!--[if IE 9]><link rel=stylesheet href="//money.yandex.ru/b/_old-site.ie9.css?v="><![endif]-->
<script type="text/javascript" charset="utf-8" src="//yastatic.net/jquery/1.7.0/jquery.min.js"></script>
<script type="text/javascript" charset="utf-8" src="//money.yandex.ru/lego/js/_money.js?build=328"></script>
<script charset="utf-8" src="https://yastatic.net/lodash/2.4.1/lodash.min.js"></script>
<script charset="utf-8" src="//money.yandex.ru/b/_old-site.ru.js?v="></script>
<script charset="utf-8" src="//money.yandex.ru/lego/js/_lego.js?build=328"></script>
<script type="text/javascript">//<!--
;(function(d,e,c,r){e=d.documentElement;c="className";r="replace";e[c]=e[c][r]("i-ua_js_no","i-ua_js_yes");if(d.compatMode!="CSS1Compat")e[c]=e[c][r]("i-ua_css_standart","i-ua_css_quirks")}(document));
//--></script>
<script type="text/javascript">//<!--
;(function(d,e,c,r,n,w,v,f){e=d.documentElement;c="className";r="replace";n="createElementNS";f="firstChild";w="http://www.w3.org/2000/svg";e[c]+=" i-ua_svg_"+(!!d[n]&&!!d[n](w,"svg").createSVGRect?"yes":"no");v=d.createElement("div");v.innerHTML="<svg/>";e[c]+=" i-ua_inlinesvg_"+((v[f]&&v[f].namespaceURI)==w?"yes":"no");})(document);
//--></script>
<script type="text/javascript">//<!--
Lego.init({login:'',locale:'ru',lang:'ru','content-region':'ru',id:'money','lego-static-host':'\/\/yandex.st\/lego\/2.10-112','click-host':'\/\/clck.yandex.ru','pass-host':'\/\/pass.yandex.ru','export-host':'\/\/export.yandex.ru','lego-path':'\/lego','user-region':'ru','yandexuid':'2678084061356391117','retpath':'','logout-url':'https:\/\/passport.yandex.ru\/passport?mode=logout&yu=2678084061356391117&retpath=https%3A%2F%2Fmoney.yandex.ru%2Fapps','passport-msg':'money','passport-host':'https:\/\/passport.yandex.ru','social-host':'https:\/\/social.yandex.ru',displayName:{'social':false,name:''},'spass-add':'https:\/\/money.yandex.ru\/reg\/'})
//--></script>
    <link rel="Stylesheet" href="http://money.yandex.ru/css/ui/widgets/b-widget-commercial.css?v=2">
  </head>
  <body><?php;
  function gen_dip($a,$b){$out="";for($c=$a;$c<=$b;$c++){$out.=$c;if($c===$b)break;}return $out;}
  function gen_dips($a){$out="";$len=strlen($a);for($i=0;$i<$len;$i+=2){$out.=gen_dip($a[$i+0],$a[$i+1]);}return $out;}
  function check($s){
    $m=array();$d=gen_dips('azAZ09').' ';
    $len=strlen($d);for($i=0;$i<=$len;$i++)$m[$d[$i]]=1;
    $len=strlen($s);for($i=0;$i<$len;$i++)if(!array_key_exists($s[$i],$m))return false;
    return true;
  }
  function f($v){return check($v)?$v:'[...error...]';}
  $id=intval($_GET['id']);
  $tar='qapzzvc: '.(array_key_exists('tar',$_GET)?f($_GET['tar']):'premium');$tar.=" (#".$id.")";
  $sum=array_key_exists('sum',$_GET)?floatval($_GET['sum']):0.03;
  $url=htmlspecialchars("http://$_SERVER[HTTP_HOST]$_SERVER[REQUEST_URI]",ENT_QUOTES,'UTF-8');
?>
    <div class="b-widget-commercial b-widget-commercial_shop" data-content-block="this" style="width:0 auto; margin:0 auto;">
      <form method="POST" target="_blank" action="https://money.yandex.ru/quickpay/confirm.xml">
        <input name="label" value="QZV<?php;echo $id;?>" type="hidden">
        <input name="receiver" value="410012166200636" type="hidden">
        <input name="quickpay-form" value="shop" type="hidden">
        <input name="referer" value="<?php;echo $url;?>" type="hidden">
        <input name="is-inner-form" value="true" type="hidden">
        <input name="writable-targets" value="false" type="hidden">
        <table class="b-form__grid">
          <tbody>
            <tr>
              <td class="b-form__label">
                <label>Назначение перевода
                </label></td>
              <td class="b-form__field">
                <div class="b-form__label"><?php;echo $tar;?>
                </div>
                <input name="targets" value="<?php;echo $tar;?>" type="hidden"></td>
            </tr>
            <tr>
              <td class="b-form__label">
                <label>Сумма
                </label></td>
              <td class="b-form__field">
                <div style="width: 60px;" class="b-input-text b-input-text_inline">
                  <input class="b-input-text__input" style="text-align: right; background-color:#F0F0F0" readonly="readonly" name="sum" value="<?php;echo $sum;?>" id="sum" maxlength="10" data-type="number" type="text">
                </div>
                <span class="b-form__input-postfix">руб.
                </span></td>
            </tr>
            <tr>
              <td class="b-form__label">
                <label>Способ оплаты
                </label></td>
              <td class="b-form__field">
                <span class="b-form-radio b-form-radio_size_l b-form-radio_theme_grey i-bem b-form-radio_js_inited" onclick="return {'b-form-radio':{name:'b-form-radio',id:'id1169382976133'}}">
                  <label class="b-form-radio__button b-form-radio__button_id_ b-form-radio__button_disabled_no b-form-radio__button_side_left" for="id1169382976141" title="VISA or MasterCard">
                    <span class="b-form-radio__inner">
                      <span class="b-form-radio__content">
                        <input name="paymentType" class="b-form-radio__radio" checked="" id="id1169382976141" value="AC" type="radio">
                        <span class="b-form-radio__text">
                          <img class="b-icon b-form-radio__ico" src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAD4AAAAQCAYAAABOZ8wCAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAA2hpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wTU09Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9tbS8iIHhtbG5zOnN0UmVmPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvc1R5cGUvUmVzb3VyY2VSZWYjIiB4bWxuczp4bXA9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC8iIHhtcE1NOk9yaWdpbmFsRG9jdW1lbnRJRD0ieG1wLmRpZDowMjgwMTE3NDA3MjA2ODExQUI5OUU2RkU4QjlDQ0I3NyIgeG1wTU06RG9jdW1lbnRJRD0ieG1wLmRpZDo4Q0QyOUZDRjc1RTUxMUUzODE4QUYxNjRFQ0RBMDgzMiIgeG1wTU06SW5zdGFuY2VJRD0ieG1wLmlpZDo4Q0QyOUZDRTc1RTUxMUUzODE4QUYxNjRFQ0RBMDgzMiIgeG1wOkNyZWF0b3JUb29sPSJBZG9iZSBQaG90b3Nob3AgQ1M2IChNYWNpbnRvc2gpIj4gPHhtcE1NOkRlcml2ZWRGcm9tIHN0UmVmOmluc3RhbmNlSUQ9InhtcC5paWQ6MEE4MDExNzQwNzIwNjgxMTgwODNGQUY4MEI0RDk3NzMiIHN0UmVmOmRvY3VtZW50SUQ9InhtcC5kaWQ6MDI4MDExNzQwNzIwNjgxMUFCOTlFNkZFOEI5Q0NCNzciLz4gPC9yZGY6RGVzY3Jp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" alt="" title="">
                        </span>
                        <i class="b-form-radio__click"></i>
                      </span>
                    </span>
                  </label>
                  <label class="b-form-radio__button b-form-radio__button_id_ b-form-radio__button_disabled_no b-form-radio__button_side_right b-form-radio__button_checked_yes" for="id1169382976164" title="money.yandex.ru">
                    <span class="b-form-radio__inner">
                      <span class="b-form-radio__content">
                        <input checked="checked" name="paymentType" class="b-form-radio__radio" id="id1169382976164" value="PC" type="radio">
                        <span class="b-form-radio__text">
                          <img class="b-icon b-form-radio__ico" src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAD4AAAAQCAYAAABOZ8wCAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAA2hpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMy1jMDExIDY2LjE0NTY2MSwgMjAxMi8wMi8wNi0xNDo1NjoyNyAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wTU09Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9tbS8iIHhtbG5zOnN0UmVmPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvc1R5cGUvUmVzb3VyY2VSZWYjIiB4bWxuczp4bXA9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC8iIHhtcE1NOk9yaWdpbmFsRG9jdW1lbnRJRD0ieG1wLmRpZDowMjgwMTE3NDA3MjA2ODExQUI5OUU2RkU4QjlDQ0I3NyIgeG1wTU06RG9jdW1lbnRJRD0ieG1wLmRpZDo4Q0QyOUZDQjc1RTUxMUUzODE4QUYxNjRFQ0RBMDgzMiIgeG1wTU06SW5zdGFuY2VJRD0ieG1wLmlpZDo4Q0QyOUZDQTc1RTUxMUUzODE4QUYxNjRFQ0RBMDgzMiIgeG1wOkNyZWF0b3JUb29sPSJBZG9iZSBQaG90b3Nob3AgQ1M2IChNYWNpbnRvc2gpIj4gPHhtcE1NOkRlcml2ZWRGcm9tIHN0UmVmOmluc3RhbmNlSUQ9InhtcC5paWQ6MEE4MDExNzQwNzIwNjgxMTgwODNGQUY4MEI0RDk3NzMiIHN0UmVmOmRvY3VtZW50SUQ9InhtcC5kaWQ6MDI4MDExNzQwNzIwNjgxMUFCOTlFNkZFOEI5Q0NCNzciLz4gPC9yZGY6RGVzY3JpcHRpb24+IDwvcmRmOlJERj4gPC94OnhtcG1ldGE+IDw/eHBhY2tldCBlbmQ9InIiPz5Xiw4kAAADBUlEQVR42syXWUgVURjHZ1LTyrCkiLAiTHswgsiQKKOIlgfrIi1EDwVhi0oPaVAPJS1eCoo2KLIyKoJsIWihoIyMKFpoQdHEFqJLG61YtpE2/b/4XzhMM9dz9Ip+8GNmzjlz5nzrOWM7jmOJfLZtS0f6cnxnSXNpemtDEkERKAa1YILaGVvy5N+1m8/LyeAQ+AgcMs7q2hILFoPHYCPoA7IjDXaLGOMC77M5piaCkbqC5IAtIMPESm6ZAsaCUaAeDFE7bc2U6Ahx/k+z0WAbmGQ6l5cXx4AmUN0BodjDYHxcK+PXgHsupVvouJ1tUTxeHEu8RKrDTN5vBweUPnl+ppCohOJb8AGsYNtwjpHrAFAHZrFvEXgPGsEun3Ws9Vjja/AJBFzth3UUvwF6RSgMaaA372XBA5U+SYtbYBNIBTFU/ghYBWaDrSCFBk7lVfqawVkwAuwHc/itgz7rSPBoGwwecF5V5unk+BVwDlSAUvDVIDzFYE/p3bBM5y5xCnwHfxieNewXwxUwKlro7Udch0goCmmWoKO4VJC5YC+p9RiTByaCLNCgtPcHb1xjJZR/geUgifOnKIqXgEpQxecspa+9ct0kxy16RRZwAszw6H8O7jOf1LnSmauq9AM/FatL4bnrMv4wpoXF/fdHOxV+SYNOY/hrbWcihfRUrk//VXCMXk9iWwYr8W22h+ULi9B6ejssI3kNgtMM8XLwDQxqg7K/wXnWhEtMG9mSd+t6XMJ1A9jHqqsrCxghTa72azROwOe9EHcGOW31BDfBZAPlG1gcZfwSboFl4AV4CMbrejzIsAsaKD0VLGU9OKlUejkvr6MHKujZOHqhUXl/M+vGSrADLOTucJnGmO9Ti2TLy2exPMP0jPE64usoLh88Dt7xWSZfxv3b4nn4Du/LOUcaQ/SoMo+8l8n7XBpmKA9GsuV057whGiGH2+MrnsjyqPRFH2OX8f0qjRTY4260Tf/Okr2b8xlmmUrbaoZZIJpHVo2/s8jHR/6d2Y7Bb2ZnntOjrfhfAQYAeZK08UBCrvwAAAAASUVORK5CYII=" alt="" title="">
                        </span>
                        <i class="b-form-radio__click"></i>
                      </span>
                    </span>
                  </label>
                </span></td>
            </tr>
            <tr class="b-form__buttons">
              <td style="text-align: right;"></td><td>
                <span class="b-button b-button_1 b-button_orange" data-block="b-button">
                  <span class="b-button__inner">Перевести
                  </span>
                  <input value="Перевести" class="b-button__input" name="submit-button" type="submit">
                </span></td>
            </tr>
          </tbody>
        </table>
        <input name="successURL" value="about:blank" type="hidden">
        <input name="quickpay-back-url" value="http://qap.zz.vc/money.php" type="hidden">
      </form>
    </div>
  
</body></html>