<?php
$unsupported_file = false;
$unsupported_cover_pic = false;
$uploaded_successfully = false;

$filename = mysqli_real_escape_string($mysql, $_FILES['filename']['name']);
$title = mysqli_real_escape_string($mysql, $_POST['title']);
$author = mysqli_real_escape_string($mysql, $_POST['author']);
$description = mysqli_real_escape_string($mysql, $_POST['description']);
$language = mysqli_real_escape_string($mysql, $_POST['language']);
$category = mysqli_real_escape_string($mysql, $_POST['category']);

// check the filename
$file_type = strtolower(substr($filename, (strlen($filename) - 3)));
if($file_type != "pdf" && $file_type != "pub"){
	$unsupported_file = true;
}

if(strlen($_FILES['cover_pic']['name']) != 0){
	$cover_pic_name = $_FILES['cover_pic']['name'];
	$file_type = strtolower(substr($cover_pic_name, (strlen($cover_pic_name) - 3)));
	if($file_type != "png" && $file_type != "jpg" && $file_type != "gif" && $file_type != "peg"){
		$unsupported_cover_pic = true;
	}
}

if(!$unsupported_file && !$unsupported_cover_pic){
	$file_path_name = $_FILES['filename']['tmp_name'];
	$filename = rand().$filename;
	$destination = "../content/books/".$filename;
	if(move_uploaded_file($file_path_name, $destination)){
		if(strlen($_FILES['cover_pic']['name']) != 0){
			$file_path_name = $_FILES['cover_pic']['tmp_name'];
			$cover_pic = rand().$_FILES['cover_pic']['name'];
			$destination = "../img/book_cover/".$cover_pic;
			if(!move_uploaded_file($file_path_name, $destination)){
			}
		}
		else{
			$cover_pic = 'default.jpg';
		}
		perform_query_perform($mysql, "insert into book (title, description, author, category, language, cover_pic, filename, uploader) values('$title', '$description', '$author', '$category', '$language', '$cover_pic', '$filename', '$admin_id')");
		$uploaded_successfully = true;
		echo "<script>alert('Uploaded successfully')</script>";
	}
	else{
		echo "<script>alert(\"Couldn't upload book\")</script>";
	}

}
?>