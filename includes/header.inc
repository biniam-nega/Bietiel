<?php 
session_start();
include("../includes/db_connect.inc");
include("../includes/functions.inc");
if($page_type == 'book'){
  if(!isset($_GET['id'])){
    header("location: home.php");
    exit;
  }
}
if($page_type == "admin"){
  if(!isset($_SESSION['admin_id'])){
    header("location: ../index.php");
  }
  else{
    $admin_id = $_SESSION['admin_id'];
    $admin_info = mysqli_fetch_array(perform_query_return($mysql, "select * from admin where id=$admin_id", "result"));
  }
}

// upload content
$tried_to_upload = false;
if(isset($_POST['upload_button'])){
  $tried_to_upload = true;
  include("validate_upload.php");
}

// login
$tried_to_login = false;
if (isset($_POST['login_button'])){
  $tried_to_login = true;
  include("validate_login.php");
}

// add admin
$tried_to_add_admin = false;
if (isset($_POST['add_admin_button'])){
  $tried_to_add_admin = true;
  include("validate_add_admin.php");
}

// add verse
if (isset($_POST['add_verse_button'])){
  $verse_text = mysqli_real_escape_string($mysql, $_POST['verse_text']);
  $verse = mysqli_real_escape_string($mysql, $_POST['verse']);

  if(perform_query_perform($mysql, "insert into verse(poster, verse_text, verse) values($admin_id, '$verse_text', '$verse')")){
    echo "<script>alert('verse added successfully')</script>";
  }
}

// delete post
$post_deleted = false;
if (isset($_POST['delete_button'])){
  $delete_book_id = $_POST['book_id'];
  if(perform_query_perform($mysql, "delete from book where id=$delete_book_id")){
    $post_deleted = true;
  }
}

// delete video
$video_deleted = false;
if (isset($_POST['delete_video_button'])){
  $delete_video_id = $_POST['video_id'];
  if(perform_query_perform($mysql, "delete from video where id=$delete_video_id")){
    $video_deleted = true;
  }
}

// upload video
$tried_to_upload = false;
if(isset($_POST['add_video_button'])){
  include('validate_upload_video.php');
  $tried_to_upload = true;
}
?>
<?php
$categories =get_categories();
if(isset($_GET['search'])){
  $search = mysqli_real_escape_string($mysql, $_GET['search']);
  $books = perform_query_return($mysql, "select * from book where title like '%$search%' or author like '%$search%' or category like '%$search%' order by id desc", "all");
}

else{
  if(isset($_GET['category'])){
    $category = mysqli_real_escape_string($mysql, $_GET['category']);
    $books = perform_query_return($mysql, "select * from book where category='$category' order by id desc", "all");
  }
  else{
    $books = perform_query_return($mysql, "select * from book order by id desc", "all");
  }
}
if(isset($_GET['page'])){
  $page = $_GET['page'];
}
else{
  $page = 1;
}
?>

<!DOCTYPE html>
<html lang="en">
<title>ቤቲኤል- ቁምስና ደብረ በኣታ ለማርያም</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="../css/w3.css">
<link rel="stylesheet" href="../css/w3-theme-blue-grey.css">
<link rel="shortcut icon" href="../img/icons/Screenshot_20210615-201104.png"/>
<style>
.w3-sidebar a {font-family: "Roboto", sans-serif}
body,h1,h2,h3,h4,h5,h6,.w3-wide {font-family: "Montserrat", sans-serif;}
.bgimg-1, .bgimg-2, .bgimg-3 {
  background-attachment: fixed;
  background-position: center;
  background-repeat: no-repeat;
  background-size: cover;
}

/* background image */
.bgimg-1 {
  background-position: center;
  background-size: cover;
  background-image: url("../img/icons/Screenshot_20210615-201104.png");
}
@media only screen and (max-device-width: 1600px) {
  .bgimg-1, .bgimg-2, .bgimg-3 {
    background-attachment: scroll;
    min-height: 250px;
  }
}
.search{
  background-image: url("../img/icons/doc_search.png");
  height: 50px;
  width: 50px;
}
.nav_button{
  padding: 5px;
  margin: 10px;
  background-image: url("../img/icons/nav_button.png");
  height: 50px;
  width: 200px;
}
</style>
<body class="w3-content" style="max-width:1200px">

<!-- Sidebar/menu -->
<nav class="w3-sidebar w3-bar-block w3-white w3-collapse w3-top" style="z-index:3;width:250px" id="mySidebar">
  <div class="w3-padding-64 w3-large w3-text-grey" style="font-weight:bold">
    <a onclick="spiritualcategory()" class="w3-button w3-block w3-white w3-left-align">መንፈሳዊ</a>
    <div id="spiritualcategory" class="w3-bar-block w3-hide w3-padding-large w3-medium">
      <?php
      foreach($categories['spiritual'] as $name => $link){
       ?>
      <a href="home.php?category=<?php echo $link; ?>" class="w3-bar-item w3-button"><?php echo $name; ?></a>
      <?php
        }   
      ?>
    </div>
    <a onclick="worldcategory()" class="w3-button w3-block w3-white w3-left-align">ዓለማዊ</a>
    <div id="worldcategory" class="w3-bar-block w3-hide w3-padding-large w3-medium">
      <?php
      foreach($categories['world'] as $name => $link){
      ?>
      <a href="home.php?category=<?php echo $link; ?>" class="w3-bar-item w3-button"><?php echo $name; ?></a>
      <?php
      }
      ?>

    </div>
    <a href="video.php" class="w3-button w3-block w3-white w3-left-align">ቤቲኤል ብቪድዮ</a>  
    </div>
    <?php
    if ($page_type == "user" || $page_type == 'book' || $page_type == 'video'){
    ?>
    <a href="javascript:void(0)" class="w3-bar-item w3-button w3-padding" onclick="document.getElementById('feedback').style.display='block'">Feedback</a> 
    <a href="javascript:void(0)" class="w3-bar-item w3-button w3-padding" onclick="document.getElementById('admin_login').style.display='block'">Admin Login</a>
    <?php
    }
    else if ($page_type == "admin"){
  ?>
  <a href="javascript:void(0)" class="w3-bar-item w3-button w3-padding" onclick="document.getElementById('upload_content').style.display='block'">&plus; Add book</a> 
  <a href="javascript:void(0)" class="w3-bar-item w3-button w3-padding" onclick="document.getElementById('add_admin').style.display='block'">&plus; Add admin</a>
  <a href="javascript:void(0)" class="w3-bar-item w3-button w3-padding" onclick="document.getElementById('add_verse').style.display='block'">&plus; Add verse</a>
  <a href="javascript:void(0)" class="w3-bar-item w3-button w3-padding" onclick="document.getElementById('add_video').style.display='block'">&plus; Add video</a>
  <a href="logout.php" class="w3-bar-item w3-button w3-padding w3-text-red">logout</a>
  <?php
  }
  ?> 
  <!-- <a href="../about.php" class="w3-bar-item w3-button w3-padding">About</a>  -->
</nav>

<!-- Top menu on small screens -->

<div class="w3-bar w3-top w3-hide-large w3-black w3-xlarge">
  <div class="w3-bar-item w3-padding-24 w3-wide">ቤቲኤል</div>
  <a class="w3-bar-item w3-button w3-padding-24 w3-right nav_button" onclick="sidebar_open()"></a>
</div>

<!-- Overlay effect when opening sidebar on small screens -->
<div class="w3-overlay w3-hide-large" onclick="sidebar_close()" style="cursor:pointer" title="close side menu" id="myOverlay"></div>
<!-- !PAGE CONTENT! -->
<div class="w3-main" style="margin-left:250px">
  <!-- Push down content on small screens -->
  <div class="w3-hide-large" style="margin-top:83px"></div>
  

<!-- Add a background color and large text to the whole page -->
<div class="w3-sand w3-large">

  <!-- About Container -->
    <div class="w3-content" style="max-width:100%">
      <div class="bgimg-1 w3-display-container w3-opacity-min" id="home">
        <?php
        //if($page_type != "video"){
        ?>
        <a  onclick="document.getElementById('search_modal').style.display='block'" class="w3-bar-item w3-button w3-right w3-hover-black search">
        </a>
        <?php //} ?>
      </div>
    </div>
  <div class="w3-row-padding w3-light-grey w3-padding-64 w3-container">
  <div class="w3-content">
    <div>