<?php
session_start();
if(!isset($_SESSION['admin_id'])){
    header("location: index.php");
    exit;
}
unset($_SESSION['admin_id']);
session_destroy();
header("location: ../index.php");
exit;
?>
