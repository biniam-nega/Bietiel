<?php
function get_categories(){
	$categories = array("spiritual" =>array("መጽሓፍ ቅዱስ" => "bible", "መጸሄት ቤቲኤል" => "bietiel magazine", "ትምህርቲ ክርስቶስ" => "christ teachings", "ጸሎት" => "prayer", "ፍልስፍና" => "philosophy", "ታሪኽ" => "history", "ሃዋርያዊ መልአኽትታት" => "apostle messages", "ስርዓታት/ሊጡርግያ" => "rules", "መጽሄታት" => "magazine", "መዝሙር" =>"songs", "ግእዝ" => "geez", "Theology"=> "theology", "Catacism" => "catacism"), "world" => 
		array("Psychology" => "psychology", "Philosophy" => "philosophy", "Arts" => "arts", "Fiction" => "fiction", "Magazines" => "magazines", "Newspaper" => "newspaper", "Politics" => "politics", "History" => "history", "English" => "english", "Mathematics" => "mathematics", "Chemistry" => "chemistry", "Physics" => "physics", "Biology" => "biology", "Economics" => "economics", "Geography" => "geography", "Technology" => "technology"));
	return $categories;
}
function perform_query_return($mysql_connection, $query, $return){
	$result = mysqli_query($mysql_connection, $query);
	if (!$result){
		die("<h1>Query failed" . mysqli_error($mysql_connection) . "</h1>");
	}
	$count = mysqli_num_rows($result);
	switch($return){
		case "result":
			return $result;
			break;
		case "count":
			return $count;
			break;
		default:
			return array($count, $result);
	}
}

function perform_query_perform($mysql_connection, $query){
	$result = mysqli_query($mysql_connection, $query);
	if(!$result){
		die("<h1>Query failed " . mysqli_error($mysql_connection) . "</h1>");
	}
	return true;
}

function generate_book_user($book){
?>
<div class="w3-card-4 w3-margin-top w3-margin-bottom">
	<div class="w3-container w3-light-grey">
        <h3><a href="book.php?id=<?php echo $book['id']; ?>"><?php echo $book['title']; ?></h3></a> ብ <a href="books.php?author='cal Newport'"><?php echo $book['author']; ?></a> : <?php echo $book['category'] ?>
    </div>

	<div class="w3-container">
        <img src="../img/book_cover/<?php echo $book['cover_pic'] ?>" alt="Avatar" class="w3-left" height="60px" width="50px">
        <p>
        <?php 
        $desc = $book['description']; 
        if (strlen($desc) > 100){
	        $desc = substr($desc, 0, 100);
        }
        echo $desc;
        ?>
        </p>
    </div>
    <div class="w3-center">
	    <a href="book.php?id=<?php echo $book['id']; ?>" class="w3-button w3-margin-bottom w3-teal w3-center" style="width: 50%">View</a>
	</div>
</div>
<?php }

function generate_video_user($video){
?>
<div class="w3-card-4 w3-margin-top w3-margin-bottom">
	<div class="w3-container w3-light-grey">
        <h3><a href="../content/videos/<?php echo $video['filename']; ?>" target=_blank ><?php echo $video['title']; ?></h3></a>
    </div>

	<div class="w3-container">
        <video muted loop controls="controls" style="width:100%">
		  <source src="../content/videos/<?php echo $video['filename']; ?>" type="video/mp4">
		</video>
        <p>
        <?php 
        $desc = $video['description']; 
        if (strlen($desc) > 100){
	        $desc = substr($desc, 0, 100);
        }
        echo $desc;
        ?>
        </p>
    </div>
    <div class="w3-center">
    	<a href="../content/videos/<?php echo $video['filename']; ?>" class="w3-button w3-margin-bottom w3-blue w3-center" style="width: 40%" target=_blank download>Download</a>
	    <a href="../content/videos/<?php echo $video['filename']; ?>" class="w3-button w3-margin-bottom w3-teal w3-center" style="width: 40%" target=_blank>View</a>
	</div>
</div>
<?php
}

function generate_book_admin($book){
?>
<div class="w3-card-4 w3-margin-top w3-margin-bottom">
	<div class="w3-container w3-light-grey">
        <h3><a href="../content/books/<?php echo $book['filename']; ?>" target=_blank ><?php echo $book['title']; ?></h3></a> ብ <?php echo $book['author']; ?> : <?php echo $book['category'] ?>
    </div><br/>

	<div class="w3-container">
        <img src="../img/book_cover/<?php echo $book['cover_pic'] ?>" alt="Avatar" class="w3-left" height="60px" width="50px">
        <p>
        <?php 
        $desc = $book['description']; 
        if (strlen($desc) > 100){
	        $desc = substr($desc, 0, 100);
        }
        echo $desc;
        ?>
        </p>
    </div>
    <div class="w3-center">
    	<form method="post" action="">
    		<input type="hidden" value="<?php echo $book['id']; ?>" name="book_id"/>
    		<a href="../content/books/<?php echo $book['filename'] ?>" target="_blank" class="w3-button w3-margin-bottom w3-teal w3-center" style="width: 40%">Preview</a>
	    	<button name="delete_button" type="submit" class="w3-button w3-red w3-margin-bottom" style="width: 40%">Delete</button>
	    </form>
	</div>
</div>
<?php
}
function generate_video_admin($video){
?>
<div class="w3-card-4 w3-margin-top w3-margin-bottom">
	<div class="w3-container w3-light-grey">
        <h3><a href="../content/videos/<?php echo $video['filename']; ?>" target=_blank ><?php echo $video['title']; ?></h3></a>
    </div>

	<div class="w3-container">
        <video muted loop controls="controls" style="width:100%">
		  <source src="../content/videos/<?php echo $video['filename']; ?>" type="video/mp4">
		</video>
        <p>
        <?php 
        $desc = $video['description']; 
        if (strlen($desc) > 100){
	        $desc = substr($desc, 0, 100);
        }
        echo $desc;
        ?>
        </p>
    </div>
    <div class="w3-center">
    	<form method="post" action="">
    		<input type="hidden" name="video_id" value="<?php echo $video['id']; ?>" />
			<a href="../content/videos/<?php echo $video['filename']; ?>" class="w3-button w3-margin-bottom w3-teal w3-center" style="width: 40%" target=_blank>View</a>
    		<button type="submit" name="delete_video_button" class="w3-button w3-margin-bottom w3-red w3-center" style="width: 40%">Delete</button>
    	</form>
	</div>
</div>
<?php
}
?>
