<?php 
$page_type = "admin";
include("../includes/header.inc");
if(isset($_GET['video_id'])){
  $video_id = $_GET['video_id'];
}
else{
  $videos = perform_query_return($mysql, "select * from video order by id desc", "all");

}
?>

<h1 class="w3-animate-bottom">ቤቲኤል ዲጂታል ላይብረሪ</h1>
      <div class="w3-panel w3-leftbar w3-rightbar w3-light-grey">
        <h5 class="w3-padding-32">Welcome to Bietiel Digital Library <?php echo $admin_info['username']; ?>. This is your page where you manage videos and upload new videos.
          <p class="w3-text-blue-gray">As of now, you have uploaded <?php echo perform_query_return($mysql, "select * from video where uploader=$admin_id", "count"); ?> videos to our database.</p>
      </h5>
      </div>
      <?php if ($videos[0] != 0){ ?>
      <?php if(isset($search)){ ?>
      <div >
        <h3>ውጽኢት: <?php echo $videos[0]; ?> ቪድዮታት</h3>
      </div>
      <?php }else{ ?>
      <div >
        <h3>ዝሓደሱ ቪድዮታት <?php if (isset($category)){ ?> ናይ <?php  echo $category; } ?></h3>
      </div>
      <?php } ?>
      <?php
      while($video = mysqli_fetch_array($videos[1])){
        generate_video_admin($video);
      }
      ?>
      <?php } ?>

<?php
include("../includes/footer.inc");
?>

<!-- delete modal -->
<div id="delete_modal" style="<?php if($video_deleted){echo "display:block"; } ?>" class="w3-modal">
    <div class="w3-modal-content w3-animate-zoom w3-green">
      <div class="w3-container w3-white w3-center">
        <a onclick="document.getElementById('delete_modal').style.display='none'" class="w3-display-topright w3-button w3-red w3-large">X</a>
        <h2 class="w3-wide">Video Deleted Successfully</h2>
      </div>
    </div>
</div>
