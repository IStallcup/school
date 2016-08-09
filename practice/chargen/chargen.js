window.onload = function()
{
	var statMethod = document.getElementById("statMethod");
	var statBox1 = document.getElementById("statBox1");
	var statBox2 = document.getElementById("statBox2");
	var statBox3 = document.getElementById("statBox3");
	var statBox4 = document.getElementById("statBox4");
	var statBox5 = document.getElementById("statBox5");
	var statBox6 = document.getElementById("statBox6");
	var statChoice1 = document.getElementById("statChoice1");
	var statChoice2 = document.getElementById("statChoice2");
	var statChoice3 = document.getElementById("statChoice3");
	var statChoice4 = document.getElementById("statChoice4");
	var statChoice5 = document.getElementById("statChoice5");
	var statChoice6 = document.getElementById("statChoice6");
	//idea: have statBox-es fill with numbers, user uses radio buttons to choose which stat is which,
	//then persistent header for page displays scores (also so JS can access them).
	var debug = document.getElementById("debug");
}

function genStats()
{
	debug.innerHTML = "";
	var scores = [0, 0, 0, 0, 0, 0];
	if (statMethod.value == "classic")
	{
		for (var i = 0; i < 6; i++)
		{		
			//if score is less than 8, reroll
			while (scores[i] < 8)
			{
				scores[i] = 0;
				//roll 4d6...
				var rolls = [];
				rolls[rolls.length] = Math.floor(Math.random() * 6) + 1;
				rolls[rolls.length] = Math.floor(Math.random() * 6) + 1;
				rolls[rolls.length] = Math.floor(Math.random() * 6) + 1;
				rolls[rolls.length] = Math.floor(Math.random() * 6) + 1;
				//...drop lowest
				//sort array, remove lowest (first) element
				rolls.sort();
				debug.innerHTML += " " + rolls;
				rolls.splice(0,1);
	
				//total up the remaining 3d6, set it as the generated ability score
				for (var j = 0; j < 3; j++)
					scores[i] += Number(rolls[j]);				
			
			}
		}
	}
	statBox1.value = scores[0];
	statBox2.value = scores[1];
	statBox3.value = scores[2];
	statBox4.value = scores[3];
	statBox5.value = scores[4];
	statBox6.value = scores[5];

		
}

function acceptScores()
{
	//CHECK THAT ALL SCORES ARE DIFFERENT
}
