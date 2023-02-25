<?php 
$page_type = "user";
include("../includes/header.inc");
$book_num = perform_query_return($mysql, "select * from book", "count");
?>

      <h1 class="w3-animate-bottom">ቤቲኤል ዲጂታል ላይብረሪ</h1>
      <div class="w3-panel w3-leftbar w3-rightbar w3-light-grey">
        <h5 class="w3-padding-32">Welcome to Bietiel Digital Library. Bietiel Digital Library is an online directory where you access numerous digitalized books on different topics. No annoying ads and limitless download. Enjoy!!!!!!
          <p class="w3-text-blue-gray">As of now, we have <?php echo $book_num; ?> books in our database.</p>
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
      while($book = mysqli_fetch_array($books[1])){
        generate_book_user($book);
      }
      ?>
      <?php } ?>
<?php include("../includes/footer.inc") ?>
</body>
</html>