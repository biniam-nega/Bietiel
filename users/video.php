<?php
$page_type = "video";
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
        <h5 class="w3-padding-32">Welcome to Bietiel Digital Library. Bietiel Digital Library is an online directory where you access numerous digitalized books on different topics. This is a page where you access to videos by Bietiel. No annoying ads and limitless download. Enjoy!!!!!!
          <p class="w3-text-blue-gray">As of now, we have <?php echo perform_query_return($mysql, "select * from video", "count"); ?> videos in our database.</p>
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
        generate_video_user($video);
      }
      ?>
      <?php } ?>

<?php
include("../includes/footer.inc");
?>