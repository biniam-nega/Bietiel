$(document).ready(function() {

	// validate login
	$('#login_btn').click(function($e) {
		var username = $('#username').val();
		var password = $('#password').val();
		if(username == '' || password == '') {
			$e.preventDefault();
			alert('please fill in the form');
		}
	});

	// validate upload
	// $('#upload_btn').click(function($e) {
	// 	var filename = $('#filename').val();
	// 	var cover_pic = $('#cover_pic').val();
	// 	var title = $('#title').val();
	// 	var author = $('#author').val();
	// 	var desc = $('#description').val();
	// 	var lang = $('.language:radio[checked]').val();
	// 	var category = $('.category:radio[checked]').val();
	// 	// $e.preventDefault();
	// 	console.log(lang);
	// });
});
