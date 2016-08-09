<html>

<?php

	include 'header.php';
	include 'nav.php';
	include 'connectvars.php';
	
	$CONNECTION = mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
	if (!$CONNECTION)
		die('Could not connect: ' . mysql_error());

	echo '<body>';

	echo '<h1>My Account</h1>';
	echo '<div id="container">';

	$username = $_GET["login"];
	
if ($username != "false")
{
	$sql_query_loggedin = "SELECT * FROM Users WHERE username='$username'  ;";
	$sql_query_scoreget = "SELECT * FROM Scores WHERE username='$username' ;";
	$res_loggedin = mysqli_query($CONNECTION, $sql_query_loggedin);
	$res_scoreget = mysqli_query($CONNECTION, $sql_query_scoreget);
	if (!$res_loggedin || !$res_scoreget)
		echo 'Fatal error.';
	else
	{
		
		$row = mysqli_fetch_row($res_loggedin);
		echo '<strong>Username:</strong> ' . $row[0] . '<br>';
		echo '<strong>First Name:</strong> ' . $row[2] . '<br>';	
		echo '<strong>Last Name:</strong> ' . $row[3] . '<br>';	
		echo '<strong>Email:</strong> ' . $row[4] . '<br>' . '<br>';
		while ($row = mysqli_fetch_row($res_scoreget))
		{
			echo '<strong>Score for ' . $row[1] . '</strong>: ' . $row[2] . '<br>';
			echo '<strong>Wins for ' . $row[1] . '</strong>: ' . $row[3] . '<br>';
			echo '<strong>Losses for ' . $row[1] . '</strong>: ' . $row[4] . '<br>' . '<br>';
		}
		
	}
}
	else echo 'Not logged in.';
	echo '</div>';
	echo '</body>';
	include 'footer.php';
?>

</html>
