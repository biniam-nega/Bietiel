<?php
$username_error = false;
$password_error = false;
$different_password = false;
$error_exists = false;

$username = mysqli_real_escape_string($mysql, $_POST['username']);
$password = mysqli_real_escape_string($mysql, $_POST['password']);
$re_password = mysqli_real_escape_string($mysql, $_POST['re_password']);

// check the username
if(strlen($username) < 6 || strlen($username) > 100){
	$username_error = true;
}

// check the password
if(strlen($password) < 6 || strlen($password) > 100){
	$password_error = true;
}

// check the passwords
if($password != $re_password){
	$different_password = true;
}

if (!$password_error && !$username_error && !$different_password){
	if(perform_query_perform($mysql, "insert into admin(username, password) values('$username', '$password')")){
		echo "<script>alert('admin added successfully')</script>";
	}
}
else{
	$error_exists = true;
}
?>
