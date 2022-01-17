$(document).ready(()=>{
  $('.fixed-action-btn').floatingActionButton();
  $('.tooltipped').tooltip();
  $('select').formSelect();

  let selectecSubject;
  let NumBoleta = $("#NB").val();
  $('#selectedmat').change(function(){
    console.log(NumBoleta);
    selectecSubject = $(this).val();
    console.log(selectecSubject);
    let others = document.getElementsByClassName("tbodygeneral");
    console.log(others);
    for(let key of others){
      document.getElementById(key.id).style.display = 'none';
    }
    let tb = "tbody";
    let modify = tb + selectecSubject;
    console.log(modify);
    document.getElementById(modify).style.display = '';
    
    let ff = $("form#formEncuesta").serialize();
    console.log(ff);
  });

  $("form#formEncuesta").validetta({
    bubblePosition: 'bottom',
    bubbleGapTop: 10,
    bubbleGapLeft: -5,
    onValid:(e)=>{
      e.preventDefault();
      let Comentariocol = $("input#Comentariocol").val();
      console.log(Comentariocol);
      $.ajax({
        method:"POST",
        url:"./encuesta_.php", //AQUI
        //data:$("form#formEncuesta").serialize(),
        data:$("form#formEncuesta").serialize() + '&NumBoleta='+ NumBoleta,
        //data:{NumBoleta:NumBoleta},
        //data:{Comentariocol:Comentariocol},
        cache:false,
        success:(respAX)=>{
          //console.log(respAX);
          let AX = JSON.parse(respAX);
          let icono;
          AX.cod == 1 ? icono = "success" : icono = "error";
          Swal.fire({
            title: "TDAW - 2021/2",
            html: AX.msj,
            icon: icono,
            //icon: "success",
            confirmButtonText: "OK",
            didDestroy:()=>{
              //if(AX.cod == 1) window.location.href = "../loginA.html";
              //if(AX.cod == 1) window.location.href = "./cerrarSesion.php?nombreSesion=NumBoleta";
              if(AX.cod == 1){
                let NumBoleta = $("#NB").val();
                console.log(NumBoleta);
                window.location.href ="./pdf.php?NumBoleta="+NumBoleta;
                //window.open("./pdf.php?NumBoleta=NumBoleta","blank");
                //window.location.href = "./cerrarSesion.php?nombreSesion=NumBoleta";
              }
            }
          });
        }
      });
    },
    onError : function( event ){
      Swal.fire({
        title: "TDAW - 2021/2",
        html: "<h5>No has terminado de llenar el formulario</h5>",
        icon: "error",
        confirmButtonText: "OK",
      });
      //alert( 'Stop bro !! There are some errors.');
    }
  });
});