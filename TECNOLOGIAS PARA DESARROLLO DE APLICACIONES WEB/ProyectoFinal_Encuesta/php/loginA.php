<?php
  session_start();
  $NumBoleta = $_POST["NumBoleta"];
  $Clave = md5($_POST["Clave"]);
  $conexion = mysqli_connect("localhost","root","","tdaweb_proyecto");
  $sql = "SELECT * FROM alumno WHERE Numboleta = '$NumBoleta' AND Clave = '$Clave'";
  $sqlCheckEncuesta = "SELECT * FROM encuesta WHERE Alumno_NumBoleta_Encuesta = '$NumBoleta'";
  $resCheckEncuesta = mysqli_query($conexion,$sqlCheckEncuesta);
  $res = mysqli_query($conexion,$sql);
  $infAlumno = mysqli_fetch_row($res);
  $respAX = [];
  if(mysqli_num_rows($resCheckEncuesta) == 0){
    if(mysqli_num_rows($res) == 1){
      $respAX["cod"] = 1;
      $respAX["msj"] = "<h5>Bienvenido $infAlumno[2]</h5>";
      $_SESSION["NumBoleta"] = $NumBoleta;
    }else{
      $respAX["cod"] = 0;
      $respAX["msj"] = "<h5>Error. Favor de intentarlo nuevamente.</h5>";
    }
  }else{
    if(mysqli_num_rows($res) == 1){
      $respAX["cod"] = 2;
      $respAX["msj"] = "<h5>Usted ya ha contestado la encuesta<br>Su comprobante se ha descargado</h5>";
    }else{
      $respAX["cod"] = 0;
      $respAX["msj"] = "<h5>Error. Favor de intentarlo nuevamente.</h5>";
    }
  }
  echo json_encode($respAX);
?>