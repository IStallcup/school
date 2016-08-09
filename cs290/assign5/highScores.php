<!DOCTYPE HTML>
<html lang="en">

<?php
	include 'header.php';
	include 'nav.php';
	include 'connectvars.php';
	echo '<body>';
	$CONNECTION = mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
	if (!$CONNECTION)
		die('Could not connect: ' . mysql_error());
	
	echo '<h1>High Scores</h1>';

	echo '<div id="container">';
	$sql_query_get_top_scores_rps = "SELECT username,score FROM Scores WHERE game = 'rps' ORDER BY score DESC LIMIT 5";
	$result_rps = mysqli_query($CONNECTION, $sql_query_get_top_scores_rps);
	
	echo '<h2>Rock Paper Scissors</h2>';
	echo '<table id="rpstable">';
	echo '<tr>';
	for ($i = 0; $i < 3; $i++)
	{
		$field = mysqli_fetch_field($result_rps);
		echo '<th>' . $field->name . '</th>';
	}
	echo '</tr>';
	while ($row = mysqli_fetch_row($result_rps))
	{
		echo '<tr>';
		foreach($row as $cell)
		{
			echo '<td';
			if ($cell == $_GET["login"])
				echo ' id="highlight"';
			echo '>' . $cell . '</td>';
		}
		echo '</tr>';
	}
	echo '</table>';

	$sql_query_get_top_scores_hilo = "SELECT username,score FROM Scores WHERE game = 'hilo' ORDER BY score DESC LIMIT 5";
	$result_hilo = mysqli_query($CONNECTION, $sql_query_get_top_scores_hilo);
	
	echo '<h2>Hilo</h2>';
	echo '<table id="hilotable">';
	echo '<tr>';
	for ($i = 0; $i < 3; $i++)
	{
		$field = mysqli_fetch_field($result_hilo);
		echo '<th>' . $field->name . '</th>';
	}
	echo '</tr>';
	while ($row = mysqli_fetch_row($result_hilo))
	{
		echo '<tr>';
		foreach($row as $cell)
		{
			echo '<td';
			if ($cell == $_GET["login"])
				echo ' id="highlight"';
			echo '>' . $cell . '</td>';
		}
		echo '</tr>';
	}
	echo '</table>';
	
	$sql_query_get_top_scores_ttt = "SELECT username,score FROM Scores WHERE game = 'tictactoe' ORDER BY score DESC LIMIT 5";
	$result_ttt = mysqli_query($CONNECTION, $sql_query_get_top_scores_ttt);
	
	echo '<h2>Tic Tac Toe</h2>';
	echo '<table id="ttt_table">';
	echo '<tr>';
	for ($i = 0; $i < 3; $i++)
	{
		$field = mysqli_fetch_field($result_ttt);
		echo '<th>' . $field->name . '</th>';
	}
	echo '</tr>';
	while ($row = mysqli_fetch_row($result_ttt))
	{
		echo '<tr>';
		foreach($row as $cell)
		{
			echo '<td';
			if ($cell == $_GET["login"])
				echo ' id="highlight"';
			echo '>' . $cell . '</td>';
		}
		echo '</tr>';
	}
	echo '</table>';
	

	echo '</div>';

	mysqli_free_result($result_rps);
	mysqli_free_result($result_hilo);
	mysqli_free_result($result_ttt);
	mysqli_close($CONNECTION);
	echo '</body>';
	include 'footer.php';
?>

</html>
