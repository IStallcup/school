<html>

<?php
	include 'connectvars.php';
	$CONNECTION = mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
	
	//TODO:
	//Sanitize input
	
	
	if (!$CONNECTION)
		die('Could not connect: ' . mysql_error());

	if ($_SERVER["REQUEST_METHOD"] == "POST")
	{
		$username = $_POST["username"];
		$email = $_POST["email"];
		$firstName = $_POST["first"];
		$lastName = $_POST["last"];
		$password = $_POST["password"];
		$game = "rps";
		$score = "100";
		$wins = "0";
		$losses = "0";
	}

	include 'header.php';
	echo '<body>';
	include 'nav.php';
	echo '<h1>My Account</h1>';
	echo '<div id="container">';
	
	$sql_query_exist_users =  "SELECT * FROM Users where username='$username' ";
	$sql_query_exist_scores =  "SELECT * FROM Scores where username='$username' ";
	$exist_users = mysqli_query($CONNECTION, $sql_query_exist_users);
	$exist_scores = mysqli_query($CONNECTION, $sql_query_exist_scores);
	if (mysqli_num_rows($exist_users) > 0 || mysqli_num_rows($exist_scores) > 0)
		echo "Error: User already exists";
	else
	{
		$sql_query_users = "INSERT INTO Users (username, password, firstName, lastName, email) VALUES('$username','$password','$firstName','$lastName','$email')";
		if (!mysqli_query($CONNECTION, $sql_query_users))
			echo "Error adding user: " . mysqli_error($dbc);
	
		$sql_query_scores = "INSERT INTO Scores (username, game, score, wins, loses) VALUES('$username','$game','$score','$wins','$losses')";
		if (!mysqli_query($CONNECTION, $sql_query_scores))
			echo "Error adding user: " . mysqli_error($CONNECTION);
		echo 'Welcome ' . $username . '</br>';
		//div etc. to split this up
		echo 'Email: ' . $email . '</br>';
		echo 'First Name: ' . $firstName . '</br>';
		echo 'Last Name: ' . $lastName . '</br>';
		echo 'Password: ' . $password . '</br>';
		echo 'Agreed to privacy policy: ';
		if (isset($_POST["privacy"]))
			echo 'Yes</br>';
		else echo 'No</br>';
	}
	
	echo '</div>';
	echo '</body>';
?>

</html>
