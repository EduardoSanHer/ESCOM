<?php
    $idAdministrador = $_SESSION["idAdministrador"];

    $conexion = mysqli_connect("localhost","root","","tdaweb_proyecto");
    mysqli_set_charset($conexion, "utf8");
    
    $sqlCheckAdmin = "SELECT * FROM administrador WHERE idAdministrador = '$idAdministrador'";
    $resCheckAdmin = mysqli_query($conexion, $sqlCheckAdmin);
    $infAdmin= mysqli_fetch_row($resCheckAdmin);

    $sqlPreguntas = "SELECT * FROM pregunta";
    $resCheckPreguntas = mysqli_query($conexion, $sqlPreguntas);
    //$TotalEncuestas = mysqli_num_rows($resCheckTE);
    $listPreguntas = "";
    while($infPregunta = mysqli_fetch_array($resCheckPreguntas, MYSQLI_BOTH)){
        $listPreguntas .= "
            <th>$infPregunta[1]</th>
        ";
    }

    $sqlTotalAlumnos = "SELECT NumBoleta FROM ALUMNO";
    $resCheckTA = mysqli_query($conexion, $sqlTotalAlumnos);
    $TotalAlumnos= mysqli_num_rows($resCheckTA);

    $sqlTotalEncuestas = "SELECT DISTINCT Alumno_NumBoleta_Encuesta FROM encuesta";
    $resCheckTE = mysqli_query($conexion, $sqlTotalEncuestas);
    $TotalEncuestas = mysqli_num_rows($resCheckTE);

    $sqlPromP1 = "SELECT AVG(Respuesta1) FROM encuesta";
    $resCheckPromP1 = mysqli_query($conexion, $sqlPromP1);
    $infP1= mysqli_fetch_row($resCheckPromP1);
    $PromedioP1 = $infP1[0];

    $sqlPromP2 = "SELECT AVG(Respuesta2) FROM encuesta";
    $resCheckPromP2 = mysqli_query($conexion, $sqlPromP2);
    $infP2= mysqli_fetch_row($resCheckPromP2);
    $PromedioP2 = $infP2[0];

    $sqlPromP3 = "SELECT AVG(Respuesta3) FROM encuesta";
    $resCheckPromP3 = mysqli_query($conexion, $sqlPromP3);
    $infP3= mysqli_fetch_row($resCheckPromP3);
    $PromedioP3 = $infP3[0];

    $sqlPromP4 = "SELECT AVG(Respuesta4) FROM encuesta";
    $resCheckPromP4 = mysqli_query($conexion, $sqlPromP4);
    $infP4= mysqli_fetch_row($resCheckPromP4);
    $PromedioP4 = $infP4[0];

    $sqlPromP5 = "SELECT AVG(Respuesta5) FROM encuesta";
    $resCheckPromP5 = mysqli_query($conexion, $sqlPromP5);
    $infP5= mysqli_fetch_row($resCheckPromP5);
    $PromedioP5 = $infP5[0];


    $sqlComentarios = "SELECT comentariocol FROM comentario WHERE LENGTH(comentariocol)>0";
    $resCheckComentarios = mysqli_query($conexion, $sqlComentarios);
    //$TotalEncuestas = mysqli_num_rows($resCheckTE);
    $listComentarios = "";
    while($infComentario = mysqli_fetch_array($resCheckComentarios, MYSQLI_BOTH)){
        $listComentarios .= "
            <tr class=\"center-align\">
            <td>$infComentario[0]</td>
            </tr>
        ";
    }

    //select comentariocol from comentario where length(comentariocol)>0;
    //SELECT AVG(Respuesta1) FROM encuesta;
    //SELECT DISTINCT Alumno_NumBoleta_Encuesta FROM encuesta
    //$infAlumno2= mysqli_fetch_row($resCheckAlumno);
  
    /* $sqlCheckMaterias = "SELECT nombremateria, idmateria FROM materia WHERE IDMATERIA in (SELECT MATERIA_IDMATERIA_INSCRIPCION FROM inscripcion WHERE ALUMNO_NUMBOLETA_INSCRIPCION = '$NumBoleta');";
    $resCheckMaterias = mysqli_query($conexion,$sqlCheckMaterias);
    //$infMaterias = mysqli_fetch_array($resCheckMaterias, MYSQLI_BOTH);
    $resCheckMaterias2 = mysqli_query($conexion,$sqlCheckMaterias); */
?>