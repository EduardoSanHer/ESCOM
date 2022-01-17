<?php
  $NumBoleta = $_SESSION["NumBoleta"];

  $conexion = mysqli_connect("localhost","root","","tdaweb_proyecto");
  mysqli_set_charset($conexion, "utf8");
  
  $sqlCheckAlumno = "SELECT * FROM alumno WHERE NumBoleta = '$NumBoleta'";
  $resCheckAlumno = mysqli_query($conexion, $sqlCheckAlumno);
  $infAlumno= mysqli_fetch_row($resCheckAlumno);
  $infAlumno2= mysqli_fetch_row($resCheckAlumno);

  $sqlCheckMaterias = "SELECT nombremateria, idmateria FROM materia WHERE IDMATERIA in (SELECT MATERIA_IDMATERIA_INSCRIPCION FROM inscripcion WHERE ALUMNO_NUMBOLETA_INSCRIPCION = '$NumBoleta');";
  $resCheckMaterias = mysqli_query($conexion,$sqlCheckMaterias);
  //$infMaterias = mysqli_fetch_array($resCheckMaterias, MYSQLI_BOTH);
  $resCheckMaterias2 = mysqli_query($conexion,$sqlCheckMaterias);
  /* $listGetMaterias = "";
  while($infMaterias = mysqli_fetch_array($resCheckMaterias2, MYSQLI_BOTH)){
    $i=1;
    $listGetMaterias .= "
                <tr style=\"display:\">
                  <td class=\"tablefont\" width=80%>¿Los contenidos fundamentales del programa de la asignatura se tratan suficientemente a lo largo del curso?</td>
                    <th>
                      <div class=\"col s12 m12 l12 input-field star-rating\">
                        <div class=\"star-rating__wrap\">
                          <input class=\"star-rating__input starP1\" id=\"starRating5P1\" type=\"radio\" name=\"ratingP1\" value=\"5\" data-validetta=\"required\">
                          <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating5P1\" title=\"5 out of 5 stars\"></label>
                          <input class=\"star-rating__input starP1\" id=\"starRating4P1\" type=\"radio\" name=\"ratingP1\" value=\"4\" data-validetta=\"required\">
                          <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating4P1\" title=\"4 out of 5 stars\"></label>
                          <input class=\"star-rating__input starP1\" id=\"starRating3P1\" type=\"radio\" name=\"ratingP1\" value=\"3\" data-validetta=\"required\">
                          <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating3P1\" title=\"3 out of 5 stars\"></label>
                          <input class=\"star-rating__input starP1\" id=\"starRating2P1\" type=\"radio\" name=\"ratingP1\" value=\"2\" data-validetta=\"required\">
                          <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating2P1\" title=\"2 out of 5 stars\"></label>
                          <input class=\"star-rating__input starP1\" id=\"starRating1P1\" type=\"radio\" name=\"ratingP1\" value=\"1\" data-validetta=\"required\">
                          <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating1P1\" title=\"1 out of 5 stars\"></label>
                        </div>
                      </div>
                    <!--</form>-->
                    </th>
                </tr>";
    $i = $i+1;
  } */

  //$i = 0;
  //while($infMaterias = mysqli_fetch_array($resCheckMaterias, MYSQLI_BOTH)){
  //  $listGetMaterias .= "<p>$infMaterias[0]</p>";
  //  $i++;
  //}

  // $sqlGetMaterias = "SELECT * FROM alumno WHERE boleta NOT IN($boleta)";

  // $resGetAlumnos = mysqli_query($conexion, $sqlGetAlumnos);
  // $trsGetAlumnos = "";
  // while($filas = mysqli_fetch_array($resGetAlumnos, MYSQLI_BOTH)){
  //   $trsGetAlumnos .= "
  //   <tr>
  //     <td>$filas[0]</td>
  //     <td>$filas[1] $filas[2] $filas[3]</td>
  //     <td>$filas[4]</td>
  //     <td>
  //       <i class='fas fa-times icoEliminar' data-boleta='$filas[0]'></i>&nbsp;&nbsp;&nbsp;<i class='fas fa-edit icoEditar' data-boleta='$filas[0]'></i>&nbsp;&nbsp;&nbsp;<i class='fas fa-file-pdf icoPDF' data-boleta='$filas[0]'></i>&nbsp;&nbsp;&nbsp;<i class='fas fa-envelope icoCorreo' data-boleta='$filas[0]'></i>
  //     </td>
  //   </tr>";
  // }

  // $sqlGraf = "SELECT COUNT(*) AS numAlumnos,programa FROM alumno GROUP BY programa";
  // $resGraf = mysqli_query($conexion, $sqlGraf);
  // $datosJSON = [];
  // while($filas = mysqli_fetch_array($resGraf, MYSQLI_BOTH)){
  //   $tempJSON["label"] = $filas[1];
  //   $tempJSON["y"] = (int)$filas[0];
  //   array_push($datosJSON,$tempJSON);
  // }

  // $json = json_encode($datosJSON);
?>