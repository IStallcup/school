<?php
$username = $_GET['login'];
echo '<head>';
echo '<title>';
	if ($_GET['page'] == 'home' || !$_GET['page'])
	{
		echo 'Home';
		echo '</title>';
		echo '<link rel="stylesheet" href="rockPaperScissors.css" />';
	}
	else if ($_GET['page'] == 'rps')
	{
		echo 'Rock Paper Scissors';
		echo '</title>';
		echo '<link rel="stylesheet" href="rockPaperScissors.css" />';
		echo '<script type="text/javascript" src="./rockPaperScissors.js"></script>';
	}
	else if ($_GET['page'] == 'blackjack')
	{
		echo 'Blackjack';
		echo '</title>';
		echo '<link rel="stylesheet" href="rockPaperScissors.css" />';
		echo '<script type="text/javascript" src="./blackjack.js"></script>';
	}
	else if ($_GET['page'] == 'about')
	{
		echo 'About';
		echo '</title>';
		echo '<link rel="stylesheet" href="rockPaperScissors.css" />';
		echo '<link rel="stylesheet" href="aboutrps.css" />';
	}
	else if ($_GET['page'] == 'signup')
	{
		echo 'Sign Up';
		echo '</title>';
		echo '<link rel="stylesheet" href="rockPaperScissors.css" />';
		echo '<link rel="stylesheet" href="signup.css" />';
		echo '<script type="text/javascript" src="./signup.js"></script>';
	}
	else if ($_GET['page'] == 'login')
	{
		echo 'Log In';
		echo '</title>';
		echo '<link rel="stylesheet" href="rockPaperScissors.css" />';
		echo '<link rel="stylesheet" href="login.css" />';
		echo '<script type="text/javascript" src="./login.js"></script>';
	}
	else if ($_GET['page'] == 'highscores')
	{
		echo 'High Scores';
		echo '</title>';
		echo '<link rel="stylesheet" href="rockPaperScissors.css" />';
		echo '<link rel="stylesheet" href="highScores.css" />';
	}
	else if ($_GET['page'] == 'myaccount')
	{
		echo 'My Account';
		echo '</title>';
		echo '<link rel="stylesheet" href="rockPaperScissors.css" />';
	}
	echo '</head>';
	
?>
