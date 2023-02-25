<?php 
$page_type = "admin";
include("../includes/header.inc");
$min_page = 1;
$max_page = ceil($books[0] / 10);
if(isset($_GET['page'])){
  $page_no = mysqli_real_escape_string($mysql, $_GET['page']);
}
?>
      <h1 class="w3-animate-bottom">ቤቲኤል ዲጂታል ላይብረሪ</h1>
      <div class="w3-panel w3-leftbar w3-rightbar w3-light-grey">
        <h5 class="w3-padding-32">Welcome to Bietiel Digital Library <?php echo $admin_info['username']; ?>. This is your page where you manage contents and upload new contents.
          <p class="w3-text-blue-gray">As of now, you have uploaded <?php echo perform_query_return($mysql, "select * from book where uploader=$admin_id", "count"); ?> books to our database.</p>
      </h5>
      </div>
      
      <?php if ($books[0] != 0){ ?>
      <?php if(isset($search)){ ?>
      <div >
        <h3>ውጽኢት: <?php echo $books[0]; ?> መጻሕፍቲ</h3>
      </div>
      <?php }else{ ?>
      <div >
        <h3>ዝሓደሱ መጻሕፍቲ <?php if (isset($category)){ ?> ናይ <?php  echo $category; } ?></h3>
      </div>
      <?php } ?>
      <?php
      if (isset($page_no)){
        $counter = (10 * ($page_no - 1)) + 1;
        $holder = $counter + 10;
        while($book = mysqli_fetch_array($books[1])){
          if($counter < $holder){
            generate_book_admin($book);
          }
          else{
            continue;
          }
          $counter ++;
        }
      }
      else{
        while($book = mysqli_fetch_array($books[1])){
          generate_book_admin($book);
        }
      }
      ?>
      <!-- <?php?>
      <div class="w3-bar">
        <?php
        if(isset($page_no)){
          if($page_no == $max_page && $max_page != 1){
        ?>
        <a href="?page=<?php echo $page_no-1 ?>" class="w3-button">&#10094; Previous</a>
        <?php
          }else if($page_no == $min_page && $max_page != 1){
        ?>
        <a href="?page=<?php echo $page_no+1 ?>" class="w3-button w3-right">Next &#10095;</a>
        <?php
        }else{
        ?>
        <a href="?page=<?php echo $page_no-1 ?>" class="w3-button">&#10094; Previous</a>
        <a href="?page=<?php echo $page_no+1 ?>" class="w3-button w3-right">Next &#10095;</a>
        <?php
          }
        }else if($max_page != 1){
        ?>
        <a href="?page=2" class="w3-button w3-right">Next &#10095;</a>
        <?php
        }
        ?> -->
      </div>
    </div>
  </div>
  <?php
  }
  ?>

  
<?php include("../includes/footer.inc") ?>
</body>
</html>
