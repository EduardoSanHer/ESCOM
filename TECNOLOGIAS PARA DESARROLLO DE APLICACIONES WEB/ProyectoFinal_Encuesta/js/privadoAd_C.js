/* No funciona 'this' con funciones flecha https://tinyurl.com/yckmw9mh */
$(document).ready(()=>{
    $('.fixed-action-btn').floatingActionButton();
    $('.tooltipped').tooltip();
    $('select').formSelect();
    let selectecSubject;
  
    let ctx = document.getElementById('PromedioPreguntas');
    let myChart;

    $('#selectedmat').change(function(){
        selectecSubject = $(this).val();
        PromedioP1 = $("#PromedioP1"+selectecSubject).val();
        PromedioP2 = $("#PromedioP2"+selectecSubject).val();
        PromedioP3 = $("#PromedioP3"+selectecSubject).val();
        PromedioP4 = $("#PromedioP4"+selectecSubject).val();
        PromedioP5 = $("#PromedioP5"+selectecSubject).val();
        console.log("#PromedioP1"+selectecSubject);
        //PromedioP1 = 4;
        console.log(selectecSubject);
        let others = document.getElementsByClassName("TB1");
        for(let key of others){
          document.getElementById(key.id).style.display = 'none';
        }
        let ppm = "PPM";
        let modify = ppm + selectecSubject;
        console.log(modify);
        let ppmg = "TPFPMG";
        let modify2 = ppmg + selectecSubject;
        console.log(modify2);
        //let modify2 = ppmg + selectecSubject;
        document.getElementById(modify).style.display = '';
        let othersmg = document.getElementsByClassName(modify2);
        for(let key of othersmg){
          document.getElementById(key.id).style.display = '';
        }
        document.getElementById("tabla-materia").style.display = '';
        document.getElementById("tabla-grupos").style.display = '';
        
        /* 
        $('#PPP-M').load('./../phpAd/privadoAd_BD_C_getData.php'+'?idmateria='+selectecSubject);
         */
        /* let others = document.getElementsByClassName("tbodygeneral");
        console.log(others);
        for(let key of others){
          document.getElementById(key.id).style.display = 'none';
        }
        let tb = "tbody";
        let modify = tb + selectecSubject;
        console.log(modify);
        document.getElementById(modify).style.display = ''; */

        /* ctx = document.getElementById('PromedioPreguntas').getContext("2d");

        if(myChart){
          myChart.remove();
        } */

        document.getElementById('PromedioPreguntas').remove();
        let canvas = document.createElement("canvas");
        canvas.id = "PromedioPreguntas";
        document.getElementById("graph_mat").appendChild(canvas);

        ctx = document.getElementById('PromedioPreguntas').getContext("2d");

        myChart = new Chart(ctx, {
          type: 'bar',
          data: {
              labels: ['Pregunta 1', 'Pregunta 2', 'Pregunta 3', 'Pregunta 4', 'Pregunta 5'],
              datasets: [{
                  label: 'Promedio por pregunta',
                  data: [PromedioP1,PromedioP2,PromedioP3,PromedioP4,PromedioP5],
                  backgroundColor: [
                      'rgba(255, 99, 132, 0.2)',
                      'rgba(54, 162, 235, 0.2)',
                      'rgba(255, 206, 86, 0.2)',
                      'rgba(75, 192, 192, 0.2)',
                      'rgba(153, 102, 255, 0.2)'
                  ],
                  borderColor: [
                      'rgba(255, 99, 132, 1)',
                      'rgba(54, 162, 235, 1)',
                      'rgba(255, 206, 86, 1)',
                      'rgba(75, 192, 192, 1)',
                      'rgba(153, 102, 255, 1)'
                  ],
                  borderWidth: 1
              }]
          },
          options: {
              scales: {
                  y: {
                      beginAtZero: true
                  }
              }
          }
        });
        document.getElementById('PromedioPreguntas').style.height = "200px";
/* 
        myChart.style.height = 200;
        let canvas = document.getElementById('PromedioPreguntas');
         */
      });


      

});