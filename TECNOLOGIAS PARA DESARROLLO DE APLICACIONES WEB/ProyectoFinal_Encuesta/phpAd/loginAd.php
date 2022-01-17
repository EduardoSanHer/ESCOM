<?php
  session_start();
  $idAdministrador = $_POST["idAdministrador"];
  $Clave = md5($_POST["Clave"]);
  $conexion = mysqli_connect("localhost","root","","tdaweb_proyecto");
  $sql = "SELECT * FROM administrador WHERE idAdministrador = '$idAdministrador' AND Clave = '$Clave'";
  $res = mysqli_query($conexion,$sql);
  $infAdmin = mysqli_fetch_row($res);
  $respAX = [];
  if(mysqli_num_rows($res) == 1){
    $respAX["cod"] = 1;
    $respAX["msj"] = "<h5>Bienvenido administrador $infAdmin[2]</h5>";
    $_SESSION["idAdministrador"] = $idAdministrador;
  }else{
    $respAX["cod"] = 0;
    $respAX["msj"] = "<h5>Error. Favor de intentarlo nuevamente.</h5>";
  }
  echo json_encode($respAX);
?>