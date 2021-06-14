 <?php

      echo $_GET["s3"]; 
      $ch = curl_init();
      curl_setopt($ch, CURLOPT_URL,"http://127.0.0.1:8000/qrcode/take");
      curl_setopt($ch, CURLOPT_POST, 1);
      curl_setopt($ch, CURLOPT_POSTFIELDS,
            $_GET["bucket"]."=".$_GET["s3"]);

      curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

      $server_output = curl_exec($ch);
      curl_close ($ch);  
     
?>



