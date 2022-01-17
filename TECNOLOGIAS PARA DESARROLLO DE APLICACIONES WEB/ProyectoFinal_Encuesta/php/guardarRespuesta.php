<?php
	//session_start();
	//$r=session_id();
	//$_SESSION['NumBoleta']=$NumBoleta;
	$selectecSubject = $_POST["selectecSubject"];
	$starValueP1 = $_POST["starValueP1"];
	$indice = $_POST["indice"];
	$conexion = mysqli_connect("localhost","root","","tdaweb_proyecto");
	$respAX = [];
	$checkSql = "SELECT RESPUESTA1 FROM ENCUESTA WHERE ALUMNO_NUMBOLETA_ENCUESTA = 2020630604 AND MATERIA_IDMATERIA_ENCUESTA = '$selectecSubject'";
	$respcheckSql = mysqli_query($conexion,$checkSql);
	if(mysqli_num_rows($respcheckSql) == 1){
		//$sqlUpdateResp = "UPDATE encuesta SET Respuesta$indice = $indice, Respuesta2 = $indice, Respuesta3 = $indice, Respuesta4 = $indice, Respuesta5 = $indice, Fecha = CURDATE() WHERE (Alumno_NumBoleta_Encuesta = 2020630604) and (Materia_idMateria_Encuesta = '$selectecSubject')";
		$sqlUpdateResp = "UPDATE `encuesta` SET `Respuesta$indice`='$starValueP1',`Respuesta2`='$starValueP1',`Respuesta3`='$starValueP1',`Respuesta4`='$starValueP1',`Respuesta5`='$starValueP1',`Fecha`=CURRENT_DATE WHERE Alumno_NumBoleta_Encuesta = 2020630604 AND Materia_idMateria_Encuesta = '$selectecSubject'";
		$resInsercion = mysqli_query($conexion,$sqlUpdateResp);
	}
	else{
	//$sqlInsertResp = "INSERT INTO encuesta (Alumno_NumBoleta_Encuesta, Materia_idMateria_Encuesta, Respuesta$indice) VALUES ('$NumBoleta', '$selectecSubject', '$starValueP1')";
	$sqlInsertResp = "INSERT INTO encuesta (Alumno_NumBoleta_Encuesta, Materia_idMateria_Encuesta, Respuesta$indice, Respuesta2, Respuesta3, Respuesta4, Respuesta5, Fecha) VALUES ('2020630604', '$selectecSubject', '$starValueP1', '$starValueP1', '$starValueP1', '$starValueP1', '$starValueP1', CURDATE())";
	$resInsercion = mysqli_query($conexion,$sqlInsertResp);
	}
	if(mysqli_affected_rows($conexion) == 1){
		$respAX["cod"] = 1;
		$respAX["msj"] = "<h5>Correcto</h5>";
	  }else{
		$respAX["cod"] = 0;
		$respAX["msj"] = "<h5>Error</h5>";
	  }
	echo json_encode($respAX);
?>