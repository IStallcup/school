<!DOCTYPE HTML>
<html lang="en">
<?php include 'header.php';?>
<?php include 'update.php';?>
<body>
<?php include 'nav.php';?>
	<h1>
		Rock, Paper, Scissors
	</h1>

	<div id="container">

<?php 
	include 'connectvars.php';
	$CONNECTION = mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
	if (!$CONNECTION)
		die('Could not connect: ' . mysql_error());
?>
	
	<form id="submitresults" method="post">
		<input type="hidden" name="points_hidden" id="hid_points" value="0"/>
		<input type="hidden" name="wins_hidden" id="hid_wins" value="0"/>
		<input type="hidden" name="loss_hidden" id="hid_loss" value="0"/>
		<input type="hidden" name="username_hidden" id="hid_username" value="<?php echo $_GET["login"];?>"/>
		<input type="submit" name="submit scores" value="Submit to Server"/>
	</form>

	<h2>Your wager:</h2>
	<input id="wager" type="number"/>
	<br>

	<div id="points">
		Number of Points: <div id="numPoints">
<?php
//FUNCTIONALITY: OUTPUTS # OF POINTS FOR LOGGED IN USER
	if ($username != "false") //if there is a user logged in...
	{
		$sql_query_get_user = "SELECT * FROM Scores where username='$username' ";
		$record = mysqli_query($CONNECTION, $sql_query_get_user);
		$user_record = mysqli_fetch_row($record);
		echo $user_record[2]; //more elegant solution?
	}
	else echo '100'; //if nobody logged in, give 100 points
?>
	</div>
	</div> <!-- display # points -->
	<h2>Choose one:</h2>
	<br>
	<input id="rockbutton" type="image" src="rock.jpg" alt="rock"/>
	<input id="paperbutton" type="image" src="paper2.jpg" alt="paper"/>
	<input id="scissorsbutton" type="image" src="scissors.png" alt="scissors"/>
	<div id="error"></div> <!-- error messages go here -->
	<div id="wins">
<?php
	if ($_GET["login"] != "false" && $_GET["login"])
	{
		echo "player wins: ";
			echo '<div id="pWins">' . $user_record[3] . '</div>';
		echo " | computer wins: ";
		echo '<div id="cWins">' . $user_record[4] . '</div>';
	}
	else echo "player wins: <div id='pWins'>0</div> | computer wins: <div id='cWins'>0</div> ";
?>
	</div> <!-- number of wins for each player -->
	<div id="images">
		<table id="imgtable">
			<tr>
				<th>
					Your choice:
				</th>
				<th>
					Comp choice:
				</th>
			</tr>
			<tr>
				<td id="yourImg">
				</td>
				<td id="compImg">
				</td>
			</tr>
		</table>
	</div>
	<div id="results"></div>

	</div> <!-- close to container div -->

	<?php include 'footer.php'; ?>

</body>
</html>
