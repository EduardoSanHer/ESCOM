<?php
  session_start();
  if(isset($_SESSION["NumBoleta"])){
    require("./../mpdf/vendor/autoload.php");
    $NumBoleta = $_GET["NumBoleta"];
    
    $conexion = mysqli_connect("localhost","root","","tdaweb_proyecto");
    mysqli_set_charset($conexion, "utf8");

    $sql = "SELECT * FROM alumno WHERE NumBoleta = '$NumBoleta'";
    $res = mysqli_query($conexion,$sql);
    $inf = mysqli_fetch_row($res);

    $sql2 = "SELECT * FROM encuesta WHERE Alumno_NumBoleta_Encuesta = '$NumBoleta'";
    $res2 = mysqli_query($conexion,$sql2);
    $inf2 = mysqli_fetch_row($res2);
    
    $stylesheet = file_get_contents('./../css/pdf.css');
    //$mpdf->useDefaultCSS2 = true;

    $Boleta= $inf[0];
    $nombreCompleto = $inf[2]." ".$inf[3]." ".$inf[4];

    $sqlPreguntas = "SELECT * FROM pregunta";
    $resCheckPreguntas = mysqli_query($conexion, $sqlPreguntas);
    //$TotalEncuestas = mysqli_num_rows($resCheckTE);
    $listPreguntas = "";
    $i = 0;
    while($infPregunta = mysqli_fetch_array($resCheckPreguntas, MYSQLI_BOTH)){
        $i = $i+1;
        $listPreguntas .= "
            <tr>
              <td>Pregunta ".$i.": $infPregunta[1]</td>
            </tr>
        ";
    }


    $fechaRegistro = $inf2[8];

    
    $header = "
      <!--<img src='./../imgs/header.png' style='max-width:100%;'>-->
      <header class=\"header\">
        <h1 height=\"30px\"></h1>
      </header>
    ";


    $sqlCheckMaterias = "SELECT * FROM encuesta WHERE alumno_NumBoleta_encuesta = $NumBoleta";
    $resCheckMaterias = mysqli_query($conexion,$sqlCheckMaterias);
    $listRPM = "";
    while($infEncuesta = mysqli_fetch_array($resCheckMaterias, MYSQLI_BOTH)){
      $idMateriaActual = $infEncuesta[1];
      $idGrupoActual = $infEncuesta[2];
      $sqlCheckMateria = "SELECT nombremateria FROM materia where idmateria = '$idMateriaActual'";
      $resCheckMateria = mysqli_query($conexion, $sqlCheckMateria);
      $infMateriaActual = mysqli_fetch_row($resCheckMateria);
      $listRPM .= "
        <tr>
          <th>".$infMateriaActual[0]."-".$idMateriaActual."<br>".$idGrupoActual."</th>
          <td>$infEncuesta[3]</td>
          <td>$infEncuesta[4]</td>
          <td>$infEncuesta[5]</td>
          <td>$infEncuesta[6]</td>
          <td>$infEncuesta[7]</td>
        </tr>
      ";
    }

    $html = "
    
      <link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css\">
      <script src=\"https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/js/materialize.min.js\"></script>
      <link rel=\"stylesheet\" href=\"./../css/general.css\">
      <link rel=\"stylesheet\" href=\"./../css/generalEstilos.css\">
      <style>
        body{text-align='center';}
      </style>
      <style type=\"text/css\">
        ".$stylesheet."
      </style>
      <body>
        
      <main class=\"valign-wrapper\">
        <div class=\"container\">
          <div class=\"row\">
          <div>
              <h1>$Boleta</h1>
              <h1>$nombreCompleto</h2>
          </div>
            <table class=\"centered responsive-table\">
              <thead>
                <tr>
                  <th></th>
                  <th>Pregunta 1</th>
                  <th>Pregunta 2</th>
                  <th>Pregunta 3</th>
                  <th>Pregunta 4</th>
                  <th>Pregunta 5</th>
                </tr>
              </thead>
              <tbody>
                <tr>
                  <th></th>
                    ".$listRPM."
                </tr>
              </tbody>
            </table>
            <table class=\"centered responsive-table\">
              <thead>
                <tr>
                  <th></th>
                </tr>
              </thead>
              <tbody>
                ".$listPreguntas."
              </tbody>
            </table>
            <h4> Fecha de registro del alumno: $Boleta fue el día $fechaRegistro</h4>
            
          <div>
        </div>
      </main>
    ";
    $footer = "
      <table class=\"centered responsive-table\">
        <tr style='background-color:#CCCCCC;'>
          <td>{DATE Y-m-j}</td>
          <td>PROYECTO WEB</td>
        </tr>
      </table>
    ";
    
    
    $mpdf = new \Mpdf\Mpdf([
      "orientation"=>"L",
      "format"=>"Letter",
      "margin_top"=>35
    ]);
    $mpdf->setHTMLHeader($header);
    $mpdf->writeHTML($html);
    $mpdf->setHTMLFooter($footer);
    $mpdf->setWatermarkText("Proyecto Web - Alumno",0.1);
    $mpdf->showWatermarkText = true;
    $mpdf->output("./../archsPdfs/".$NumBoleta.".pdf","F");
    //$mpdf->output("./../archsPdfs/".$NumBoleta.".pdf","D");
    $temp = $_REQUEST["$NumBoleta"];
    unset($_SESSION[$temp]);
    //header("location:./../php/cerrarSesion.php?NumBoleta=$NumBoleta");
    header("location:./../php/cerrarSesion.php?NumBoleta=".$NumBoleta."");
    
  }else{
    header("location:./../loginA.html");
  }
?>