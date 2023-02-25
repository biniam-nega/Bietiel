<?php
$username = mysqli_real_escape_string($mysql, $_POST['username']);
$password = mysqli_real_escape_string($mysql, $_POST['password']);

$info_error = false;

$get_admin = perform_query_return($mysql, "select id from admin where username='{$username}' and password = '{$password}'", "all");
if($get_admin[0] == 0){
	$info_error = true;
}
else{
	$admin_info = mysqli_fetch_array($get_admin[1]);
	$admin_id = $admin_info['id'];
	$_SESSION['admin_id'] = $admin_id;
	header("Location: ../admin/home.php");
	exit;
}
?>