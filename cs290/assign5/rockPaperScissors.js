//Author: Isaac Stallcup
//Date: 7/13/2016
//Javascript to go with rockPaperScissors.html for CS290 Summer 2016 Assign 3



window.onload = function() //function for on load
{
	//function prints the number of wins for comp, player formatted appropriately

	function numWins() 
	{
		//get # wins, # comp wins, output to wins div
		document.getElementById("wins").innerHTML = "comp wins: " + compWins + " | player wins: " + playerWins;
	}

	//function called if the player wins the current round
	function youWin()
	{
		document.getElementById("results").innerHTML = "You win!"; //tells user
		playerWins++; //iterates # player wins
		document.getElementById("hid_wins").value = playerWins;
		document.getElementById("hid_loss").value = compWins;
		numPoints += parseInt(wager); //adds wager to # points
		document.getElementById("hid_points").value = numPoints;
		displayPoints(); //calls function to display # points [to update the HTML]
	}

	//function called if the computer wins the current round
	function iWin()
	{
		document.getElementById("results").innerHTML = "You lose :("; //tells user
		compWins++; //iterates # computer wins
		document.getElementById("hid_wins").value = playerWins;
		document.getElementById("hid_loss").value = compWins;
		numPoints -= parseInt(wager); //subtracts wager form # points
		document.getElementById("hid_points").value = numPoints;
		displayPoints() //calls function to update HTML for # points
		if (numPoints <= 0) //if the # of points the player has is < or = to 0...
			window.alert("Out of points. Refresh page to restart game."); //they lose
	}

	//function to determine who wins the current round
	function whoWon(playerChoice, computerChoice, wager)
	{
		var rDiv = document.getElementById("results");
		if (computerChoice == playerChoice) //if choices are same, tie
			rDiv.innerHTML = "You tie.";

		//"logic tree" that determines game result based
		//on computer and player choices.
		else if (computerChoice == "rock")
		{
			if (playerChoice == "paper")
				youWin(); //computer choice rock, player choice paper, player wins
			else if (playerChoice == "scissors")
				iWin(); //computer choice rock, player choice scissors, computer wins, etc.
		}
		else if (computerChoice == "paper")
		{
			if (playerChoice == "scissors")
				youWin();
			else if (playerChoice == "rock")
				iWin();
		}
		else if (computerChoice == "scissors")
		{
			if (playerChoice == "rock")
				youWin();
			else if (playerChoice == "paper")
				iWin();
		}
		numWins(); //update HTML for # of wins for player, computer
	}

	//function randomly chooses computer's choice, then proceeds with game
	function playRPS(playerChoice, computerChoice, playerWins, compWins)
	{
		var randomChoice = Math.floor(Math.random() * 3); //random integer between 0 and 2 [conclusive]
		if (randomChoice == 0) //if random # is 0, computer chooses rock
		{
			computerChoice = "rock";
			whoWon(playerChoice, computerChoice, compWins, playerWins); //function to determine who won
		}
		else if (randomChoice == 1) //if random choice is 1, computer chooses paper
		{
			computerChoice = "paper";
			whoWon(playerChoice, computerChoice, compWins, playerWins); //determine who wins
		}
		else if (randomChoice == 2) //random choice 2, computer chooses scissors
		{
			computerChoice = "scissors";
			whoWon(playerChoice, computerChoice, compWins, playerWins); //determine who wins
		}
		createImgComp(computerChoice); //display the image for the computer's choice
	}

	//function displays the # of points the user has
	function displayPoints()
	{
		var pDiv = document.getElementById("points");
		pDiv.innerHTML = "Number of Points: " + numPoints;
	}

	var numPoints = Number(document.getElementById("numPoints").innerHTML); 
	//get # points from HTML; this is in turn updated from databae each time page loads

	//legacy call to displayPoints() from assign 3/4
	//displayPoints();

	//same deal with # wins
//	numWins();
	var text = "";
	var playerChoice = "";
	var computerChoice = "";
	var compWins = Number(document.getElementById("cWins").innerHTML);
	var playerWins = Number(document.getElementById("pWins").innerHTML);
	var wager = 0;	

	//displays the image for the computer's choice
	function createImgComp(computerChoice)
	{
		var img = document.createElement("IMG"); //create image element
		//if-else structure sets the src attribute of the image based on the computer's choice
		if (computerChoice == "rock")
			img.setAttribute("src", "rock.jpg");
		else if (computerChoice == "paper")
			img.setAttribute("src","paper2.jpg");
		else if (computerChoice == "scissors")
			img.setAttribute("src","scissors.png");
		img.setAttribute("id","comps");
		//replaces the 1-index cell in the 1-index row of the table displaying image choices (physically, 2nd row and 2nd image)
		document.getElementById("imgtable").rows[1].cells[1].replaceChild(img,document.getElementById("compImg").childNodes[0]);
	}

	//display image choice for player; identical to above function to display computer image
	function createImgPlayer()
	{
		var img = document.createElement("IMG");
		if (playerChoice == "rock")
			img.setAttribute("src", "rock.jpg");
		else if (playerChoice == "paper")
			img.setAttribute("src","paper2.jpg");
		else if (playerChoice == "scissors")
			img.setAttribute("src","scissors.png");
		img.setAttribute("id","yours");
		document.getElementById("imgtable").rows[1].cells[0].replaceChild(img,document.getElementById("yourImg").childNodes[0]);
	}


	//gets the player's wager
	function getWager()
	{
		var wField = document.getElementById("wager");
		var eField = document.getElementById("error");
		wager = wField.value;
		if (wager > numPoints) //if user tries to wager too many points
		{
			eField.innerHTML = "Wager too high. Try again."; //display error msg
			wField.style.backgroundColor = "#E87979"; //turn red
			wField.style.color = "#FFFFFF"; //text is white for readability
			return false; //return failure
		}
		else if (!wager) //if there is no wager input
		{
			eField.innerHTML = "Please enter a wager."; //ask for one
			wField.style.backgroundColor = "#E87979"; //turn red
			wField.style.color = "#FFFFFF"; //text is white for readability
			return false; //return failure
		}
		//if we've had no failure, reset the background and text colors to white and black respectively
		wField.style.backgroundColor ="#FFFFFF";
		wField.style.color = "#000000";
		return true; //return success
	}

	//function is called when the player selects rock
	document.getElementById("rockbutton").onclick = function()
	{
		if (getWager() == false) //check whether the wager is valid or not
			return false; //if wager is invalid, do nothing else. Error message is already displayed in the getWager() function
		else document.getElementById("error").innerHTML = ""; //if there is no error, remove the text in the error div
		playerChoice = "rock"; //set player choice
		createImgPlayer(); //display image for player
		//proceed with game (chooses comp choice, sees who won, modifies appropriately)
		playRPS(playerChoice, computerChoice, compWins, playerWins); 
	}

	//function behaves similarly to rock function above; executes when paper button is clicked
	document.getElementById("paperbutton").onclick = function()
	{
		if (getWager() == false)
			return false;
		else document.getElementById("error").innerHTML = "";
		playerChoice = "paper";
		createImgPlayer();
		playRPS(playerChoice, computerChoice, compWins, playerWins);
	}
	
	//function behaves similarly to rock function above; executes when scissors button is clicked
	document.getElementById("scissorsbutton").onclick = function()
	{
		if (getWager() == false)
			return false;
		else document.getElementById("error").innerHTML = "";
		playerChoice = "scissors";
		createImgPlayer();
		playRPS(playerChoice, computerChoice, compWins, playerWins);
	}
}
