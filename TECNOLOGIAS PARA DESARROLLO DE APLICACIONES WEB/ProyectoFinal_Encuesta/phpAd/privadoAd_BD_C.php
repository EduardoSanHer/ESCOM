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

    $trash = 100;

    $sqlTotalAlumnos = "SELECT NumBoleta FROM ALUMNO";
    $resCheckTA = mysqli_query($conexion, $sqlTotalAlumnos);
    $TotalAlumnos= mysqli_num_rows($resCheckTA);

    $sqlTotalEncuestas = "SELECT DISTINCT Alumno_NumBoleta_Encuesta FROM encuesta";
    $resCheckTE = mysqli_query($conexion, $sqlTotalEncuestas);
    $TotalEncuestas = mysqli_num_rows($resCheckTE);

    $listPPM = "";
    while($infMateria2 = mysqli_fetch_array($resCheckMaterias2, MYSQLI_BOTH)){
        $idMateriaActual = $infMateria2[0];
        $sqlPPM = "SELECT AVG(Respuesta1), AVG(Respuesta2), AVG(Respuesta3), AVG(Respuesta4), AVG(Respuesta5) FROM encuesta WHERE Materia_idMateria_Encuesta = '$idMateriaActual'";
        $ResPPM = mysqli_query($conexion, $sqlPPM);
        $infMateriaActual = mysqli_fetch_row($ResPPM);
        $listPPM .= "
                <tr style=\"display:none\" class=\"TB1\" id=\"PPM".$idMateriaActual."\">
                    <input style=\"display:none\" id=\"PromedioP1".$idMateriaActual."\" value=\"".$infMateriaActual[0]."\">
                    <input style=\"display:none\" id=\"PromedioP2".$idMateriaActual."\" value=\"".$infMateriaActual[1]."\">
                    <input style=\"display:none\" id=\"PromedioP3".$idMateriaActual."\" value=\"".$infMateriaActual[2]."\">
                    <input style=\"display:none\" id=\"PromedioP4".$idMateriaActual."\" value=\"".$infMateriaActual[3]."\">
                    <input style=\"display:none\" id=\"PromedioP5".$idMateriaActual."\" value=\"".$infMateriaActual[4]."\">
                    <th>Promedio por pregunta</th>
                    <td class=\"mt\">$infMateriaActual[0]</td>
                    <td class=\"mt\">$infMateriaActual[1]</td>
                    <td class=\"mt\">$infMateriaActual[2]</td>
                    <td class=\"mt\">$infMateriaActual[3]</td>
                    <td class=\"mt\">$infMateriaActual[4]</td>
                </tr>
        ";
    }

    //$sqlCheckGrupos = "SELECT * FROM grupo";
    //$resCheckGrupos = mysqli_query($conexion,$sqlCheckGrupos);
    $listPFPMG = "";
    while($infMateria3 = mysqli_fetch_array($resCheckMaterias3, MYSQLI_BOTH)){
        $idMateriaActual = $infMateria3[0];
        $sqlPPMG = "SELECT * FROM encuesta WHERE materia_idmateria_encuesta = '$idMateriaActual'";
        $ResPPMG = mysqli_query($conexion, $sqlPPMG);
        while($infGPM = mysqli_fetch_array($ResPPMG, MYSQLI_BOTH)){
            $idGrupoActual = $infGPM[2];
            $sqlPFPMG = "SELECT AVG(Respuesta1), AVG(Respuesta2), AVG(Respuesta3), AVG(Respuesta4), AVG(Respuesta5) FROM encuesta WHERE Materia_idMateria_Encuesta = '$idMateriaActual' AND Grupo_idGrupo_Encuesta = '$idGrupoActual'";
            $resPFPMG = mysqli_query($conexion, $sqlPFPMG);
            $infPFPMG = mysqli_fetch_row($resPFPMG);
            $listPFPMG .= "
                <tr style=\"display:none\" class=\"TB1 TPFPMG".$idMateriaActual."\" id=\"PPMG".$idMateriaActual."-".$idGrupoActual."\">
                    <input style=\"display:none\" id=\"PromedioP1".$idMateriaActual."-".$idGrupoActual."\" value=\"".$infMateriaActual[0]."\">
                    <input style=\"display:none\" id=\"PromedioP2".$idMateriaActual."-".$idGrupoActual."\" value=\"".$infMateriaActual[1]."\">
                    <input style=\"display:none\" id=\"PromedioP3".$idMateriaActual."-".$idGrupoActual."\" value=\"".$infMateriaActual[2]."\">
                    <input style=\"display:none\" id=\"PromedioP4".$idMateriaActual."-".$idGrupoActual."\" value=\"".$infMateriaActual[3]."\">
                    <input style=\"display:none\" id=\"PromedioP5".$idMateriaActual."-".$idGrupoActual."\" value=\"".$infMateriaActual[4]."\">
                    <th class=\"mt\">Promedio por grupo: ".$idGrupoActual."</th>
                    <td class=\"mt\">$infPFPMG[0]</td>
                    <td class=\"mt\">$infPFPMG[1]</td>
                    <td class=\"mt\">$infPFPMG[2]</td>
                    <td class=\"mt\">$infPFPMG[3]</td>
                    <td class=\"mt\">$infPFPMG[4]</td>
                </tr>
        ";
        }
    }

    /* $sqlPromP1 = "SELECT AVG(Respuesta1) FROM encuesta";
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
    $PromedioP5 = $infP5[0]; */


    /* $sqlComentarios = "SELECT comentariocol FROM comentario WHERE LENGTH(comentariocol)>0";
    $resCheckComentarios = mysqli_query($conexion, $sqlComentarios);
    //$TotalEncuestas = mysqli_num_rows($resCheckTE);
    $listComentarios = "";
    while($infComentario = mysqli_fetch_array($resCheckComentarios, MYSQLI_BOTH)){
        $listComentarios .= "
            <tr class=\"center-align\">
            <td>$infComentario[0]</td>
            </tr>
        ";
    } */

    //select comentariocol from comentario where length(comentariocol)>0;
    //SELECT AVG(Respuesta1) FROM encuesta;
    //SELECT DISTINCT Alumno_NumBoleta_Encuesta FROM encuesta
    //$infAlumno2= mysqli_fetch_row($resCheckAlumno);
  
    /* $sqlCheckMaterias = "SELECT nombremateria, idmateria FROM materia WHERE IDMATERIA in (SELECT MATERIA_IDMATERIA_INSCRIPCION FROM inscripcion WHERE ALUMNO_NUMBOLETA_INSCRIPCION = '$NumBoleta');";
    $resCheckMaterias = mysqli_query($conexion,$sqlCheckMaterias);
    //$infMaterias = mysqli_fetch_array($resCheckMaterias, MYSQLI_BOTH);
    $resCheckMaterias2 = mysqli_query($conexion,$sqlCheckMaterias); */
?>