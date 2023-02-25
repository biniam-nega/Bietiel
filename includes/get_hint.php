<?php
// get the q parameter from URL
$q = $_REQUEST["q"];

$hint = "";

// lookup all hints from array if $q is different from ""
if ($q !== "") {
	$len = strlen($q);
	$books = perform_query_return($mysql, "select * from book where title like '%$q%' or author like '%$q%' or category like '%$q%' order by downloads desc", "all");
  	if($books[0] != 0){
?>
<div class="w3-container">
<?php
	  	while($book = mysqli_fetch_array($mysql, $books[1])){
?>
<p><?php echo $book['title']; ?></p>
<?php
	  	}
	}
	else{
		$hints[] = "no suggestion";
	}
}
?>
</div>
