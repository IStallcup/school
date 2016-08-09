<?php
	include 'connectvars.php';

	//TODO: clean up connections, results of queries

	$CONNECTION = mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
	if (!$CONNECTION)
		die('Could not connect (update.php): ' . mysql_error());
	if ($_GET["login"] != "false")		
	{
		if ($_SERVER["REQUEST_METHOD"] == "POST")
		{
			$points_h = $_POST["points_hidden"];
			$wins_h = $_POST["wins_hidden"];
			$loss_h = $_POST["loss_hidden"];
			$username_h = $_POST["username_hidden"];
			//echo 'Submit detected </br>';
			//echo 'points in database will be ' . $_POST["points_hidden"];
			//echo 'player wins are ' . $_POST["wins_hidden"];
			//echo 'comp wins are ' . $_POST["loss_hidden"];
			//echo '</br>';
			$sql_query_set_points = "UPDATE Scores SET score='$points_h' WHERE username='$username_h' ";
			$result_points = mysqli_query($CONNECTION, $sql_query_set_points);
			$sql_query_set_wins = "UPDATE Scores SET wins='$wins_h' WHERE username='$username_h' ";
			$result_wins = mysqli_query($CONNECTION, $sql_query_set_wins);
			$sql_query_set_loss = "UPDATE Scores SET loses='$loss_h' WHERE username='$username_h' ";
			$result_loss = mysqli_query($CONNECTION, $sql_query_set_loss);
	
		}
	}
	else if ($_SERVER["REQUEST_METHOD"] == "POST")
	{
		echo '<div id="loginerror">Error: user not logged in</div>';
	}	

	//clear stuff goes here
?>
