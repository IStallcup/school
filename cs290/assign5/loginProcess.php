<?php
	include 'header.php';
	echo '<body>';
	include 'nav.php';
	echo '<h1>My Account</h1>';
	echo '<div id="container">';
	echo 'Welcome ' . $_POST["username"] . '</br>';
	echo '</div>';
	echo '</body>';
?>
