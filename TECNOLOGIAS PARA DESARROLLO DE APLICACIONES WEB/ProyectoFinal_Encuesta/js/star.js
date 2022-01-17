jQuery(document).ready(function($) {
    $('.rating .star').hover(function() {
      $(this).addClass('to_rate');
      $(this).parent().find('.star:lt(' + $(this).index() + ')').addClass('to_rate');
      $(this).parent().find('.star:gt(' + $(this).index() + ')').addClass('no_to_rate');
    }).mouseout(function() {
      $(this).parent().find('.star').removeClass('to_rate');
      $(this).parent().find('.star:gt(' + $(this).index() + ')').removeClass('no_to_rate');
    }).click(function() {
      $(this).removeClass('to_rate').addClass('rated');
      $(this).parent().find('.star:lt(' + $(this).index() + ')').removeClass('to_rate').addClass('rated');
      $(this).parent().find('.star:gt(' + $(this).index() + ')').removeClass('no_to_rate').removeClass('rated');
      /*Save your rate*/
      /*TODO*/
    });
  });