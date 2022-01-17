$(document).ready(()=>{
  $('.fixed-action-btn').floatingActionButton();
  $('.tooltipped').tooltip();


  $("form#formLogin").validetta({
    bubblePosition: 'bottom',
    bubbleGapTop: 10,
    bubbleGapLeft: -5,
    onValid:(e)=>{
      e.preventDefault();
      let NumBoleta = $("input#NumBoleta").val();
      let Clave = $("input#Clave").val();
      $.ajax({
        method:"POST",
        url:"./php/loginA.php",
        data:{NumBoleta:NumBoleta, Clave:Clave},
        cache:false,
        success:(respAX)=>{
          console.log(respAX);
          let AX = JSON.parse(respAX);
          let icono;
          //AX.cod == 1 ? icono = "success" : icono = "error";
          if(AX.cod == 1 || AX.cod == 2){
            icono = "success";
          }
          else{
            icono = "error";
          }
          Swal.fire({
            title: "Encuesta - Proyecto Web",
            html: AX.msj,
            icon: icono,
            confirmButtonText: "Ok",
            didDestroy:()=>{
              if(AX.cod == 1) window.location.href = "./php/privadoA.php?NumBol=NumBoleta";
              if(AX.cod == 2){
                window.location.href ="./../PWeb/php/pdf.php?NumBoleta="+NumBoleta;
                /* $.ajax({
                  method:"GET",
                  url:"./php/pdf.php?NumBoleta=NumBoleta"
                }); */
              }
            }
          });
        }
      });
    }
  });
});

