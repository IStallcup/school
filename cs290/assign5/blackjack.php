<html>
<?php
	include 'header.php';
//	include 'update.php';
	echo '<body>';
	include 'nav.php';
	echo '<h1>Blackjack</h1>';
	echo '<div id="container">';
?>

	<input type="number" id="wager"/>
	</br>
	<button type="button" onclick="hitMe()">Hit</button>
	<button type="button" onclick="stay()">Stay</button>
	<h3>Your hand:</h3>
	<div id="p_log">
		0
	</div>
	<h3>Your hand's value:</h3>	
	<div id="p_hand">
		0
	</div>
	<h3>Dealer hand:</h3>
	<div id="d_log">
		0
	</div>
	<h3>Dealer hand's value:</h3>
	<div id="d_hand">
		0
	</div>

<?php
	include 'connectvars.php';		
?>

	<div id="points">
		Number of Points: 
		<div id="numPoints">
			100
		</div>
	</div>
	<div id="error">
	</div>

<?php	


	echo '</div>';
	include 'footer.php';
	echo '</body>';
?>
</html>
