<?php
  session_start();
  if(isset($_SESSION["NumBoleta"])){
    include("./privadoA_BD.php");

?>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
<title>Privado / Sem 20221</title>
<meta name='viewport' content='width=device-width,initial-scale=1,minimum-scale=1,maximum-scale=1,user-scalable=no'/>
<meta name="description" content="">
<meta name="keywords" content="">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.4/css/all.min.css" />
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css">
<link rel="stylesheet" href="//maxcdn.bootstrapcdn.com/font-awesome/4.3.0/css/font-awesome.min.css">
<link rel="stylesheet" href="./../css/general.css">
<link rel="stylesheet" href="./../css/generalEstilos.css">
<link rel="stylesheet" href="./../css/star-rating.css">
<script src="./../js/jquery-3.6.0.min.js"></script>
<link href="./../js/validetta/validetta.min.css" rel="stylesheet">
<script src="./../js/validetta/validetta.min.js"></script>
<script src="./../js/validetta/validettaLang-es-ES.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/js/materialize.min.js"></script>
<script src="//cdn.jsdelivr.net/npm/sweetalert2@11"></script>
<script src="https://canvasjs.com/assets/script/canvasjs.min.js"></script>
<script async custom-element="amp-form" src="https://cdn.ampproject.org/v0/amp-form-0.1.js"></script>
<script async custom-template="amp-mustache" src="https://cdn.ampproject.org/v0/amp-mustache-0.2.js"></script>
<script src="./../js/privadoA.js"></script>
<script src="./../js/privadoA_Materias.js"></script>
<script src="./../js/encuesta.js"></script>



<style>
  .icoEliminar:hover,
  .icoEditar:hover,
  .icoPDF:hover,
  .icoCorreo:hover{
    cursor:pointer;
  }
</style>
</head>
<body>
  <header>
    <div class="col s12 m6 l4 header">
      <h2 class="tituloAlumno">Bienvenido Alumno  <?php echo "$infAlumno[2] - $infAlumno[0]";  ?></h2>
      <p class="contestar">Contestar la encuesta sobre la percepción en la impartición de clases</p>
    </div> 
    <div class="fixed-action-btn">
      <a class="btn-floating btn-large teal">
        <i class="large fas fa-bars"></i>
      </a>
      <ul>
        <li><a href="./cerrarSesion.php?nombreSesion=NumBoleta" class="btn-floating tooltipped green" data-position="left" data-tooltip="Cerrar Sesión"><i class="fas fa-sign-out-alt"></i></a></li>
      </ul>
    </div>
  </header>
  <main class="valign-wrapper">
    <div class="container">
      <div class="row" class="col s12 m12 l12">
          <div class="col s12 m12 l4 input-field">
            <div class="row"><label>Materias del alumno <?php echo "$infAlumno[0]"; ?></label></div>
              <select class= "selectedmat" name="selectedmat" id="selectedmat">
                <option value="" disabled selected>--Selecciona una Materia--</option>
                <?php 
                  while ($row = $resCheckMaterias->fetch_assoc()){
                  echo "<option value=\"".$row['idmateria']."\">".$row['nombremateria']." - ".$row['idmateria']."</option>";
                  }
                  ?>
              </select>
          </div>

          <form id="formEncuesta" autocomplete="off">
          <div class="col s12 m12 l8 input-field">
            <table> 
              <thead>
                <tr>
                  <th>Preguntas</th>
                  <th>Calificación</th>
                  <?php echo "<input value=\"".$infAlumno[0]."\" style=\"display:none\" id=\"NB\" data-validetta=\"required\">".""."</option>";?>
                </tr>
              </thead>
              <?php
              while($infMaterias = $resCheckMaterias2->fetch_assoc())
              echo "<tbody style=\"display:none\" class=\"tbodygeneral\" id=\"tbody".$infMaterias['idmateria']."\">
                <tr style=\"display:\">
                  <td class=\"tablefont\" width=80%>¿Los contenidos fundamentales del programa de la asignatura se tratan suficientemente a lo largo del curso?</td>
                    <th>
                      
                      <div class=\"col s12 m12 l12 input-field star-rating\">
                        <div class=\"star-rating__wrap clasificacion\">
                          <input class=\"star-rating__input starP1".$infMaterias['idmateria']."\" id=\"starRating5P1".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP1".$infMaterias['idmateria']."\" value=\"5\" data-validetta=\"required\">
                          <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating5P1".$infMaterias['idmateria']."\" title=\"5 out of 5 stars\"></label>
                          <input class=\"star-rating__input starP1".$infMaterias['idmateria']."\" id=\"starRating4P1".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP1".$infMaterias['idmateria']."\" value=\"4\" data-validetta=\"required\">
                          <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating4P1".$infMaterias['idmateria']."\" title=\"4 out of 5 stars\"></label>
                          <input class=\"star-rating__input starP1".$infMaterias['idmateria']."\" id=\"starRating3P1".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP1".$infMaterias['idmateria']."\" value=\"3\" data-validetta=\"required\">
                          <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating3P1".$infMaterias['idmateria']."\" title=\"3 out of 5 stars\"></label>
                          <input class=\"star-rating__input starP1".$infMaterias['idmateria']."\" id=\"starRating2P1".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP1".$infMaterias['idmateria']."\" value=\"2\" data-validetta=\"required\">
                          <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating2P1".$infMaterias['idmateria']."\" title=\"2 out of 5 stars\"></label>
                          <input class=\"star-rating__input starP1".$infMaterias['idmateria']."\" id=\"starRating1P1".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP1".$infMaterias['idmateria']."\" value=\"1\" data-validetta=\"required\">
                          <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating1P1".$infMaterias['idmateria']."\" title=\"1 out of 5 stars\"></label>
                        </div>
                      </div>
                      
                    </th>
                </tr>
                <tr>
                  <td class=\"tablefont\" width=80%>¿El profesor promueve la participación en clase?</td>
                  <th>
                  <div class=\"col s12 m12 l12 input-field star-rating\">
                    <div class=\"star-rating__wrap clasificacion\">
                      <input class=\"star-rating__input starP2".$infMaterias['idmateria']."\" id=\"starRating5P2".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP2".$infMaterias['idmateria']."\" value=\"5\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating5P2".$infMaterias['idmateria']."\" title=\"5 out of 5 stars\"></label>
                      <input class=\"star-rating__input starP2".$infMaterias['idmateria']."\" id=\"starRating4P2".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP2".$infMaterias['idmateria']."\" value=\"4\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating4P2".$infMaterias['idmateria']."\" title=\"4 out of 5 stars\"></label>
                      <input class=\"star-rating__input starP2".$infMaterias['idmateria']."\" id=\"starRating3P2".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP2".$infMaterias['idmateria']."\" value=\"3\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating3P2".$infMaterias['idmateria']."\" title=\"3 out of 5 stars\"></label>
                      <input class=\"star-rating__input starP2".$infMaterias['idmateria']."\" id=\"starRating2P2".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP2".$infMaterias['idmateria']."\" value=\"2\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating2P2".$infMaterias['idmateria']."\" title=\"2 out of 5 stars\"></label>
                      <input class=\"star-rating__input starP2".$infMaterias['idmateria']."\" id=\"starRating1P2".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP2".$infMaterias['idmateria']."\" value=\"1\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating1P2".$infMaterias['idmateria']."\" title=\"1 out of 5 stars\"></label>
                    </div>
                  </div>
                </th>
                </tr>
                <tr>
                  <td class=\"tablefont\" width=80%>¿Se utilizan las herramientas de interacción de las tecnologías actuales de la información para el aprendizaje?</td>
                  <th>
                  <div class=\"col s12 m12 l12 input-field star-rating\">
                    <div class=\"star-rating__wrap clasificacion\">
                      <input class=\"star-rating__input starP3".$infMaterias['idmateria']."\" id=\"starRating5P3".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP3".$infMaterias['idmateria']."\" value=\"5\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating5P3".$infMaterias['idmateria']."\" title=\"5 out of 5 stars\"></label>
                      <input class=\"star-rating__input starP3".$infMaterias['idmateria']."\" id=\"starRating4P3".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP3".$infMaterias['idmateria']."\" value=\"4\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating4P3".$infMaterias['idmateria']."\" title=\"4 out of 5 stars\"></label>
                      <input class=\"star-rating__input starP3".$infMaterias['idmateria']."\" id=\"starRating3P3".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP3".$infMaterias['idmateria']."\" value=\"3\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating3P3".$infMaterias['idmateria']."\" title=\"3 out of 5 stars\"></label>
                      <input class=\"star-rating__input starP3".$infMaterias['idmateria']."\" id=\"starRating2P3".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP3".$infMaterias['idmateria']."\" value=\"2\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating2P3".$infMaterias['idmateria']."\" title=\"2 out of 5 stars\"></label>
                      <input class=\"star-rating__input starP3".$infMaterias['idmateria']."\" id=\"starRating1P3".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP3".$infMaterias['idmateria']."\" value=\"1\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating1P3".$infMaterias['idmateria']."\" title=\"1 out of 5 stars\"></label>
                    </div>
                  </div>
                </th>
                </tr>
                <tr>
                  <td class=\"tablefont\" width=80%>¿La evaluación se ajusta a los contenidos trabajados durante el curso?</td>
                  <th>
                  <div class=\"col s12 m12 l12 input-field star-rating\">
                    <div class=\"star-rating__wrap clasificacion\">
                      <input class=\"star-rating__input starP4".$infMaterias['idmateria']."\" id=\"starRating5P4".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP4".$infMaterias['idmateria']."\" value=\"5\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating5P4".$infMaterias['idmateria']."\" title=\"5 out of 5 stars\"></label>
                      <input class=\"star-rating__input starP4".$infMaterias['idmateria']."\" id=\"starRating4P4".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP4".$infMaterias['idmateria']."\" value=\"4\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating4P4".$infMaterias['idmateria']."\" title=\"4 out of 5 stars\"></label>
                      <input class=\"star-rating__input starP4".$infMaterias['idmateria']."\" id=\"starRating3P4".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP4".$infMaterias['idmateria']."\" value=\"3\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating3P4".$infMaterias['idmateria']."\" title=\"3 out of 5 stars\"></label>
                      <input class=\"star-rating__input starP4".$infMaterias['idmateria']."\" id=\"starRating2P4".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP4".$infMaterias['idmateria']."\" value=\"2\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating2P4".$infMaterias['idmateria']."\" title=\"2 out of 5 stars\"></label>
                      <input class=\"star-rating__input starP4".$infMaterias['idmateria']."\" id=\"starRating1P4".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP4".$infMaterias['idmateria']."\" value=\"1\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating1P4".$infMaterias['idmateria']."\" title=\"1 out of 5 stars\"></label>
                    </div>
                  </div>
                </th>
                </tr>
                <tr>
                  <td class=\"tablefont\" width=80%>¿El nivel exigido en la evaluación se corresponde con el que se imparte en clase?</td>
                  <th>
                  <div class=\"col s12 m12 l12 input-field star-rating\">
                    <div class=\"star-rating__wrap clasificacion\">
                      <input class=\"star-rating__input starP5".$infMaterias['idmateria']."\" id=\"starRating5P5".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP5".$infMaterias['idmateria']."\" value=\"5\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating5P5".$infMaterias['idmateria']."\" title=\"5 out of 5 stars\"></label>
                      <input class=\"star-rating__input starP5".$infMaterias['idmateria']."\" id=\"starRating4P5".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP5".$infMaterias['idmateria']."\" value=\"4\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating4P5".$infMaterias['idmateria']."\" title=\"4 out of 5 stars\"></label>
                      <input class=\"star-rating__input starP5".$infMaterias['idmateria']."\" id=\"starRating3P5".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP5".$infMaterias['idmateria']."\" value=\"3\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating3P5".$infMaterias['idmateria']."\" title=\"3 out of 5 stars\"></label>
                      <input class=\"star-rating__input starP5".$infMaterias['idmateria']."\" id=\"starRating2P5".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP5".$infMaterias['idmateria']."\" value=\"2\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating2P5".$infMaterias['idmateria']."\" title=\"2 out of 5 stars\"></label>
                      <input class=\"star-rating__input starP5".$infMaterias['idmateria']."\" id=\"starRating1P5".$infMaterias['idmateria']."\" type=\"radio\" name=\"ratingP5".$infMaterias['idmateria']."\" value=\"1\" data-validetta=\"required\">
                      <label class=\"star-rating__ico fa fa-star-o fa-lg\" for=\"starRating1P5".$infMaterias['idmateria']."\" title=\"1 out of 5 stars\"></label>
                    </div>
                  </div>
                </th>
                </tr>
              </tbody>";
              ?>
            </table>
          </div>

          </div> 
          
<!-----> <form id="formEncuesta" autocomplete="off">
          <div class="row">
            <div class="col s12 m12 l12 input-field">
              <i class="fas fa-edit prefix"></i>
              <!--<textarea id="Comentariocol" name="Comentariocol" class="materialize-textarea"></textarea>-->
              <label for="Comentariocol">Comentarios</label>
              <input type="text" id="Comentariocol" name="Comentariocol" maxlength="180" data-validetta="required,minLength[4],maxLength[180]">
            </div>
          </div>

          <div class="col s12 m12 l12 input-field center">
            <input type="submit" class="btn teal darken-1" style="width: 50%"  value="Enviar">
          </div>
      </form>            
    </div> <!--container --->
    






    <!-- <div class="row">
      <table class="striped centered responsive-table">
        <thead>
          <tr><th>Boleta</th><th>Nombre</th><th>correo</th><th>Opciones</th></tr>
        </thead>
        <tbody>
          <?php echo $trsGetAlumnos; ?>
        </tbody>
      </table>
    </div> -->
    <!-- <div class="row">
      <div class="col s12 m6">
        <div id="grafCanvas" style="height:200px !important; width:100%;"></div>
      </div>
      <div class="col s12 m6">
        <div id="grafCanvas2" style="height:200px !important; width:100%;"></div>
        <script>
          let datos2JSON = '<?php echo $json; ?>';
          let datos2 = JSON.parse(datos2JSON);
          var chart2 = new CanvasJS.Chart("grafCanvas2", {
            title:{
              text: "Alumnos x Carrera"              
            },
            data: [{
              type: "bar",
              dataPoints: datos2
            }]
          });
          chart2.render();
        </script>
      </div>
    </div> -->
  </main>
  <footer class="page-footer teal">
    <div class="footer-copyright">
      <div class="container">
      © 2021 Copyright Proyecto WEB 
      <a class="grey-text text-lighten-4 right" href="https://www.escom.ipn.mx">ESCOM</a>
      </div>
    </div>
  </footer>
</body>
</html>
<?php
  }else{
    header("location: ./../loginA.html");
  }
?>