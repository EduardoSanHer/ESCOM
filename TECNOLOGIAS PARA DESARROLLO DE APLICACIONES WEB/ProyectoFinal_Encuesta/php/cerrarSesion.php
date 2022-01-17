<?php
	session_start();
	//session_destroy() no funciona aquí porque como ya vimos destruye TODAS las sesiones activas y en este caso solo nos interesa eliminar una de posiblemente varias sesiones; aprovechando el concepto de que una sesion no deja de ser una variable, usamos la funcion unset() de PHP https://www.w3schools.com/php/func_var_unset.asp
	
	//$_REQUEST[] es otro de los arreglos asociativos globales de PHP que contine toda la información relacionada a los arreglos $_POST[], $_GET[] y $_SESSION[]
	$temp = $_REQUEST["nombreSesion"];
	//eliminanos especificamente esta variable de sesion
	unset($_SESSION[$temp]);
	//redireccionamos a la pantalla del login
	header("location:./../loginA.html");
?>