<?php 
$page_type = "book";
include("../includes/header.inc"); 
$book_id = mysqli_real_escape_string($mysql, $_GET['id']);
$this_book = mysqli_fetch_array(perform_query_return($mysql, "select * from book where id=$book_id", "result"));
$book_category = $this_book['category'];
$similar_books = perform_query_return($mysql, "select * from book where category='$book_category' and id != $book_id order by id desc", "all");
?>
      <h1 class="w3-animate-bottom">ቤቲኤል ዲጂታል ላይብረሪ</h1>

      <div class="w3-panel w3-leftbar w3-rightbar w3-light-grey">
        <div class="w3-card-4">
			<div class="w3-container w3-center">
			  <h3><?php echo $this_book['title'] ?></h3>
			  <img src="../img/book_cover/<?php echo $this_book['cover_pic']; ?>" alt="Avatar" style="width:30%">
			  <p><?php echo $this_book['description']; ?></p>

			  <a href="../content/books/<?php echo $this_book['filename'] ?>" download title="<?php echo $this_book['title']?>" class="w3-button w3-green w3-margin-bottom" onclick="downloaded(<?php echo $this_book['id']; ?>)" >Download</a>
			  <a class="w3-button w3-pink w3-margin-bottom" href="../content/books/<?php echo $this_book['filename'] ?>" target="_blank">Preview</a>
			</div>
		</div>
      </h5>
      </div>
      <div>
        <h3>Similar books : <?php echo $similar_books[0] ?></h3>
      </div>
      <?php
      while($book = mysqli_fetch_array($similar_books[1])){
        generate_book_user($book);
      }
      ?>
    </div>
  </div>
  <?php
  include("../includes/footer.inc");
  ?>
<script>
// Used to toggle the menu on small screens when clicking on the menu button
function myFunction() {
  var x = document.getElementById("navDemo");
  if (x.className.indexOf("w3-show") == -1) {
    x.className += " w3-show";
  } else { 
    x.className = x.className.replace(" w3-show", "");
  }
}

function downloaded(id) {
  xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
    document.getElementById("txtHint").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "add_download.php?id="+id, true);
  xhttp.send();
}
</script>

</body>
</html>
