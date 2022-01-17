<?php
  session_start();
  if(isset($_SESSION["idAdministrador"])){
    include("./privadoAd_BD_B.php");
?>

<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
<title>Administracion B / Sem 20221</title>
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
<script src= "https://cdnjs.cloudflare.com/ajax/libs/Chart.js/3.6.2/chart.js"> </script>
<script src="./../js/privadoAd_B.js"></script>
<link rel="stylesheet" href="./../css/tablaAdminB.css">

<script type="text/javascript">

  let PromedioP1 = 0, PromedioP2 = 0, PromedioP3 = 0, PromedioP4 = 0, PromedioP5 = 0;

</script>

<style>
  
</style>
</head>
<body>
  <header>
    <div class="col s12 m6 l4 header">
      <p>Administracion B</p>
      <h2 class="tituloAlumno">Bienvenido Administrador  <?php echo "$infAdmin[2] - $infAdmin[0]";  ?></h2>
    </div> 
    <div class="fixed-action-btn">
      <a class="btn-floating btn-large teal">
        <i class="large fas fa-bars"></i>
      </a>
      <ul>
        <li><a href="./../php/cerrarSesionAdmin.php?nombreSesion=idAdministrador" class="btn-floating tooltipped green" data-position="left" data-tooltip="Cerrar Sesión"><i class="fas fa-sign-out-alt"></i></a></li>
        <li><a href="./../phpAd/privadoAd_C.php?idAdministrador=idAdministrador" class="btn-floating tooltipped green" data-position="left" data-tooltip="Adiministracion C"><i class="fab fa-cuttlefish"></i></a></li>
        <li><a href="./../phpAd/privadoAd.php?idAdministrador=idAdministrador" class="btn-floating tooltipped green" data-position="left" data-tooltip="Adiministracion A"><i class="fab fa-adn"></i></a></li>
      </ul>
    </div>
  </header>
  <main class="valign-wrapper">
    <div class="container col s12 m12 l12">
      <div class="row" class="col s12 m12 l12">
        <h4 class="center-align">Resumen Por Materias</h4>

        <table class="centered highlight responsive-table" id="tabla-materia">
        <thead class="T1">
          <tr>
              <th> </th>
              <!-- <th>Encuestas contestadas</th> -->
              <?php echo $listPreguntas; ?>
          </tr>
        </thead>
        <tbody class="TB">
          <?php echo $onlylistPPM; ?>
        </tbody>
        </table>
      </div>
    </div>


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

  <script>

</script>
</html>

<?php
  }else{
    header("location: ./../loginAdmin.html");
  }
?>