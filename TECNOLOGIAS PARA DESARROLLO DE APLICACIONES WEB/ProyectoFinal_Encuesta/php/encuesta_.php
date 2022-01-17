<?php
  //session_start();
  $NumBoleta = $_POST["NumBoleta"];
  $Comentariocol = $_POST["Comentariocol"];
  $xd = 4;
  $conexion = mysqli_connect("localhost","root","","tdaweb_proyecto");
  $respAX = [];

  $sqlCheckMaterias = "SELECT idmateria FROM materia WHERE IDMATERIA in (SELECT MATERIA_IDMATERIA_INSCRIPCION FROM inscripcion WHERE ALUMNO_NUMBOLETA_INSCRIPCION = '$NumBoleta');";
  $resCheckMaterias = mysqli_query($conexion,$sqlCheckMaterias);
  while ($row = $resCheckMaterias->fetch_assoc()){
    $materia = $row['idmateria'];
    //$res1 = ${'ratingP1'.$materia};
    $res1 = $_POST["ratingP1".$materia];
    $res2 = $_POST["ratingP2".$materia];
    $res3 = $_POST["ratingP3".$materia];
    $res4 = $_POST["ratingP4".$materia];
    $res5 = $_POST["ratingP5".$materia];
    //$insertRespuestas = "INSERT INTO encuesta (Alumno_NumBoleta_Encuesta, Materia_idMateria_Encuesta, Respuesta1, Respuesta2, Respuesta3, Respuesta4, Respuesta5, Fecha) VALUES ('$NumBoleta','$row['idmateria']','${"ratingP1".$row['idmateria']}','${"ratingP2".$row['idmateria']}','${"ratingP3".$row['idmateria']}','${"ratingP4".$row['idmateria']}','${"ratingP5".$row['idmateria']}',CURDATE())";
    //Se le agrego la linea siguiente el 18-12-2021
    $sqlCheckGrupo = "SELECT Grupo_idGrupo_Inscripcion FROM inscripcion WHERE Alumno_NumBoleta_Inscripcion = '$NumBoleta' AND Materia_idMateria_Inscripcion = '$materia'";
    $resCheckGrupo = mysqli_query($conexion,$sqlCheckGrupo);
    $grupoRow = mysqli_fetch_row($resCheckGrupo);
    //$grupo = $grupoRow['Grupo_idGrupo_Inscripcion']:<-- Ya vi por qué no funcionaba ._.
    $insertRespuestas = "INSERT INTO encuesta (Alumno_NumBoleta_Encuesta, Materia_idMateria_Encuesta, Grupo_idGrupo_Encuesta, Respuesta1, Respuesta2, Respuesta3, Respuesta4, Respuesta5, Fecha) VALUES ('$NumBoleta','$materia','{$grupoRow[0]}','$res1','$res2','$res3','$res4','$res5',CURDATE())";
    
    //Primera optimizacion, funciona para la tabla de encuesta sin id de grupo
    //$insertRespuestas = "INSERT INTO encuesta (Alumno_NumBoleta_Encuesta, Materia_idMateria_Encuesta, Respuesta1, Respuesta2, Respuesta3, Respuesta4, Respuesta5, Fecha) VALUES ('$NumBoleta','$materia','$res1','$res2','$res3','$res4','$res5',CURDATE())";
    
    $resInsercion = mysqli_query($conexion,$insertRespuestas);
    //echo "<option value=\"".$row['idmateria']."\">".$row['nombremateria']." - ".$row['idmateria']."</option>";
  }

  $sqlInsertComment = "INSERT INTO comentario (Comentariocol) VALUES ('$Comentariocol')";
  //$sqlInsertComment = "INSERT INTO comentario (Comentariocol) VALUES ('$NumBoleta')";
  $resComment = mysqli_query($conexion,$sqlInsertComment);
  //$conexion = mysqli_connect("localhost","root","","sem20221");
    if(mysqli_affected_rows($conexion) == 1){
      $respAX["cod"] = 1;
      $respAX["msj"] = "<h5>Gracias por contestar la encuesta.<br>Su comprobante se ha descargado</h5>";
    }else{
      $respAX["cod"] = 0;
      $respAX["msj"] = "<h5>Error. Favor de intentarlo nuevamente.</h5>";
    }
  echo json_encode($respAX);
?>