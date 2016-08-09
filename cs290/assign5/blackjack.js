function clearBoard()
{
	var p_hand = document.getElementById("p_hand");
	var p_log = document.getElementById("p_log");
	var d_hand = document.getElementById("d_hand");
	var d_log = document.getElementById("d_log");
	var error = document.getElementById("error");
	
	p_hand.innerHTML = "0";
	p_log.innerHTML = "";
	d_hand.innerHTML = "0";
	d_log.innerHTML = "";
	error.innerHTML = "";
}

function checkWager()
{
	var points = Number(document.getElementById("numPoints").innerHTML);
	var wField = document.getElementById("wager");
	var eField = document.getElementById("error");
	var wager = wField.value;
	wField.style.backgroundColor = "white";
	if (!wager)
	{
		wField.style.backgroundColor = "#E87979";
		event.preventDefault();
		return false;
	}
	else if (wager > points)
	{
		wField.style.backgroundColor = "#E87979";
		event.preventDefault();
		return false;
	}
	else return true;

}

function hitMe()
{
	if (!checkWager())
		return;

	var p_hand = document.getElementById("p_hand");
	var p_log = document.getElementById("p_log");
	var d_hand = document.getElementById("d_hand");
	var d_log = document.getElementById("d_log");
	var error = document.getElementById("error");
	var numPoints = document.getElementById("numPoints");

	//clear error after each time wager is checked
	error.innerHTML = "";
	
	var wager = Number(document.getElementById("wager").value);
	var points = Number(document.getElementById("numPoints").innerHTML);

	var cardChoice = Math.floor(Math.random() * 13) + 1; //pick random card, not limited by deck
	var currVal = Number(p_hand.innerHTML); //current value of player's hand

	//add up value of cards
	currVal += cardChoice;
	p_hand.innerHTML = currVal; //update value of hand
	p_log.innerHTML += cardChoice + " "; //log cards you have

	if (currVal == 21) //game generously lets user win if they hit 21 before staying
	{
		window.alert("You win! Your value: " + currVal + ". Press OK to continue.");
		points += wager;
		numPoints.innerHTML = points;
		clearBoard();
	}
	else if (currVal > 21)
	{
		window.alert("You went over 21. Your value: " + currVal + ". Press OK to continue.");
		points -= wager;
		numPoints.innerHTML = points;
		clearBoard();
	}
}

function stay()
{
	var p_hand = document.getElementById("p_hand");
	var p_log = document.getElementById("p_log");
	var d_hand = document.getElementById("d_hand");
	var d_log = document.getElementById("d_log");
	var error = document.getElementById("error");
	var numPoints = document.getElementById("numPoints");

	var wager = Number(document.getElementById("wager").value);
	var points = Number(document.getElementById("numPoints").innerHTML);

	var p_points = Number(p_hand.innerHTML);
	var d_points = Number(d_hand.innerHTML);

	while (d_points <= 16) //hit while current hand has <= 16 points
	{
		cardChoice = Math.floor(Math.random() * 13) + 1;
		d_points += cardChoice;
		d_hand.innerHTML = d_points;
		d_log.innerHTML += " " + cardChoice;
	}

	if (d_points > 21)
	{
		window.alert("You win! Your value: " + p_points + ". Computer's value " + d_points + ". Press OK to continue.");
		points += wager;
	}
	else if (p_points >= d_points)
	{
		window.alert("You win! Your value: " + p_points + ". Computer's value " + d_points + ". Press OK to continue.");
		points += wager;
	}
	else if (d_points > p_points)
	{
		window.alert("You lose. Your value: " + p_points + ". Computer's value " + d_points + ". Press OK to continue.");
		points -= wager;
	}
	numPoints.innerHTML = points;
	clearBoard();
	
}
