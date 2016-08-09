<nav>
	<ul>
		<?php
			echo '<li';
			if ($_GET['page'] == 'home' || !$_GET['page'])
				echo ' id="highlight">';
			else echo '>';
			echo '<a href="./home.php?page=home';
			echo '&amp;login=';
			if ($_GET['login'] == 'false' || !$_GET['login'])
				echo 'false';
			else echo $_GET['login'];
			echo '">home</a></li>';

			echo '<li';
			if ($_GET['page'] == 'blackjack')
				echo ' id="highlight">';
			else echo'>';
			echo '<a href="./blackjack.php?page=blackjack';
			echo '&amp;login=';
			if ($_GET['login'] == 'false' || !$_GET['login'])
				echo 'false';
			else echo $_GET['login'];
			echo '">blackjack</a></li>';

			echo '<li';
			if ($_GET['page'] == 'rps')
				echo ' id="highlight">';
			else echo '>';
			echo '<a href="./rockPaperScissors.php?page=rps';
			echo '&amp;login=';
			if ($_GET['login'] == 'false' || !$_GET['login'])
				echo 'false';
			else echo $_GET['login'];
			echo '">rock paper scissors</a></li>';
	
			echo '<li';
			if ($_GET['page'] == 'about')
				echo ' id="highlight">';
			else echo '>';
			echo '<a href="./aboutrps.php?page=about';
			echo '&amp;login=';
			if ($_GET['login'] == 'false' || !$_GET['login'])
				echo 'false';
			else echo $_GET['login'];
			echo '">about</a></li>';

			//signup
			echo '<li';
			if ($_GET['page'] == 'signup')
				echo ' id="highlight">';
			else echo '>';
			echo '<a href="./signup.php?page=signup';
			echo '&amp;login=';
			if ($_GET['login'] == 'false' || !$_GET['login'])
				echo 'false';
			else echo $_GET['login'];
			echo '">signup</a></li>';

			//login
			echo '<li';
			if ($_GET['page'] == 'login')
				echo ' id="highlight">';
			else echo '>';
			echo '<a href="./login.php?page=login';
			echo '&amp;login=';
			if ($_GET['login'] == 'false' || !$_GET['login'])
				echo 'false';
			else echo $_GET['login'];
			echo '">login</a></li>';
			
			echo '<li';
			if ($_GET['page'] == 'highscores')
				echo ' id="highlight">';
			else echo '>';
			echo '<a href="./highScores.php?page=highscores';
			echo '&amp;login=';
			if ($_GET['login'] == 'false' || !$_GET['login'])
				echo 'false';
			else echo $_GET['login'];
			echo '">highscores</a></li>';
			
			echo '<li';
			if ($_GET['page'] == 'myaccount')
				echo ' id="highlight">';
			else echo '>';
			echo '<a href="./myAccount.php?page=myaccount';
			echo '&amp;login=';
			if ($_GET['login'] == 'false' || !$_GET['login'])
				echo 'false';
			else echo $_GET['login'];
			echo '">my account</a></li>';
			
			//logout page only displays if you're logged in
			if ($_GET['login'] != 'false' && $_GET['login'])
			{
				echo '<li>';
				echo '<a href="./rockPaperScissors.php?page=home&amp;login=false">logout</a></li>';
			}

			if ($_GET['login'] != 'false' && $_GET['login'])
			{
				echo '<li id="login">';
				echo 'Logged in as ' . $_GET['login'];
				echo '</li>';
			}
		?>
	</ul>
</nav>

