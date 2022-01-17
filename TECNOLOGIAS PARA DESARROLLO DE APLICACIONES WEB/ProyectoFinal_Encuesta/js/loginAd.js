$(document).ready(()=>{
  $('.fixed-action-btn').floatingActionButton();
  $('.tooltipped').tooltip();

  $("form#formLogin").validetta({
    bubblePosition: 'bottom',
    bubbleGapTop: 10,
    bubbleGapLeft: -5,
    onValid:(e)=>{
      e.preventDefault();
      let idAdministrador = $("input#idAdministrador").val();
      let Clave = $("input#Clave").val();
      $.ajax({
        method:"POST",
        url:"./phpAd/loginAd.php",
        data:{idAdministrador:idAdministrador, Clave:Clave},
        cache:false,
        success:(respAX)=>{
          console.log(respAX);
          let AX = JSON.parse(respAX);
          let icono;
          AX.cod == 1 ? icono = "success" : icono = "error";
          Swal.fire({
            title: "Acceso permitido",
            html: AX.msj,
            icon: icono,
            confirmButtonText: "Ingresar",
            didDestroy:()=>{
              if(AX.cod == 1) window.location.href = "./phpAd/privadoAd.php";
            }
          });
        }
      });
    }
  });
});