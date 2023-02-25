<?php
include("../includes/db_connect.inc");
include("includes/functions.inc");
$id = $_GET["id"];
$book = perform_query_return($mysql, "select (downloads) from book where id=$id", "result");
$download = $book['download'] + 1;
echo "<script>alert($download)</script>";
perform_query_perform($mysql, "update book set downloads=$download where id=$id");
  
?>