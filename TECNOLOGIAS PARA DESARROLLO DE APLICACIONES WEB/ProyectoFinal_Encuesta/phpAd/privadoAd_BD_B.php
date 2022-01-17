<?php
    $idAdministrador = $_SESSION["idAdministrador"];

    $conexion = mysqli_connect("localhost","root","","tdaweb_proyecto");
    mysqli_set_charset($conexion, "utf8");
    
    $sqlCheckAdmin = "SELECT * FROM administrador WHERE idAdministrador = '$idAdministrador'";
    $resCheckAdmin = mysqli_query($conexion, $sqlCheckAdmin);
    $infAdmin= mysqli_fetch_row($resCheckAdmin);

    $sqlCheckMaterias = "SELECT * FROM materia";
    $resCheckMaterias = mysqli_query($conexion,$sqlCheckMaterias);
    $resCheckMaterias2 = mysqli_query($conexion,$sqlCheckMaterias);
    $resCheckMaterias3 = mysqli_query($conexion,$sqlCheckMaterias);
    
    $listMaterias = "";
    while($infMateria = mysqli_fetch_array($resCheckMaterias, MYSQLI_BOTH)){
        $listMaterias .= "
        <option value=\"".$infMateria[0]."\">".$infMateria[1]." - ".$infMateria[0]."</option>
        ";
    }

    $sqlPreguntas = "SELECT * FROM pregunta";
    $resCheckPreguntas = mysqli_query($conexion, $sqlPreguntas);
    //$TotalEncuestas = mysqli_num_rows($resCheckTE);
    $listPreguntas = "";
    while($infPregunta = mysqli_fetch_array($resCheckPreguntas, MYSQLI_BOTH)){
        $listPreguntas .= "
            <th>$infPregunta[1]</th>
        ";
    }

    $onlylistPPM = "";
    while($infMateria2 = mysqli_fetch_array($resCheckMaterias2, MYSQLI_BOTH)){
        $idMateriaActual = $infMateria2[0];
        $nombreMateriaActual = $infMateria2[1];
        $sqlPPM = "SELECT AVG(Respuesta1), AVG(Respuesta2), AVG(Respuesta3), AVG(Respuesta4), AVG(Respuesta5) FROM encuesta WHERE Materia_idMateria_Encuesta = '$idMateriaActual'";
        $ResPPM = mysqli_query($conexion, $sqlPPM);
        $infMateriaActual = mysqli_fetch_row($ResPPM);
        $onlylistPPM .= "
                <tr style=\"\" class=\"TB1\" id=\"PPM".$idMateriaActual."\">
                    <th>".$nombreMateriaActual."-".$idMateriaActual."</th>
                    <td class=\"mt\">$infMateriaActual[0]</td>
                    <td class=\"mt\">$infMateriaActual[1]</td>
                    <td class=\"mt\">$infMateriaActual[2]</td>
                    <td class=\"mt\">$infMateriaActual[3]</td>
                    <td class=\"mt\">$infMateriaActual[4]</td>
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