<?php
$unsupported_video_file = false;
$uploaded_successfully = false;

$filename = mysqli_real_escape_string($mysql, $_FILES['filename']['name']);
$title = mysqli_real_escape_string($mysql, $_POST['title']);
$description = mysqli_real_escape_string($mysql, $_POST['description']);

// check the filename
$file_type = strtolower(substr($filename, (strlen($filename) - 3)));
if($file_type != "mp4"){
	$unsupported_video_file = true;
}

if(!$unsupported_video_file){
	$file_path_name = $_FILES['filename']['tmp_name'];
	$filename = rand().$filename;
	$destination = "../content/videos/".$filename;
	if(move_uploaded_file($file_path_name, $destination)){
		perform_query_perform($mysql, "insert into video (title, description, filename, uploader) values('$title', '$description', '$filename', '$admin_id')");
		$uploaded_successfully = true;
		echo "<script>alert('Uploaded successfully')</script>";
	}
	else{
		echo "<script>alert('Couldn't upload video')</script>";
	}

}
?>