window.onload = function()
{
	var str = document.getElementById("str");
	var dex = document.getElementById("dex");
	var con = document.getElementById("con");
	var _int = document.getElementById("int"); //"int" is reserved by JS
	var wis = document.getElementById("wis");
	var cha = document.getElementById("cha");
	var race;
	var gender;
	var alignment;
	var speed = 30; //most common choice

	var debug = document.getElementById("debug");
	document.getElementById("chooseRace").disabled = true;
	document.getElementById("demoConfirm").disabled = true;
}

function raiseScore(num)
{
	var temp = Number(num.value);
	var pointsRem = Number(document.getElementById("pointsRem").value);
	if (pointsRem <= 0)
		return;
	if (num.value <= 12)
		pointsRem--;
	else if (num.value < 15)
		pointsRem -= 2;
	else if (num.value == 15)
		return;
	document.getElementById("pointsRem").value = pointsRem;
	temp++;
	num.value = temp;
}

function lowerScore(num)
{
	var temp = Number(num.value);
	var pointsRem = Number(document.getElementById("pointsRem").value);
	if (num.value <= 8)
		return;
	else if (num.value <= 13)
		pointsRem++;
	else if (num.value <= 15)
		pointsRem += 2;
	document.getElementById("pointsRem").value = pointsRem;
	temp--;
	num.value = temp;
}

function disableButtons()
//disable buttons to start with except for score generation buttons
{
	document.getElementById("str+").disabled = true;
	document.getElementById("str-").disabled = true;
	document.getElementById("dex+").disabled = true;
	document.getElementById("dex-").disabled = true;
	document.getElementById("con+").disabled = true;
	document.getElementById("con-").disabled = true;
	document.getElementById("int+").disabled = true;
	document.getElementById("int-").disabled = true;
	document.getElementById("wis+").disabled = true;
	document.getElementById("wis-").disabled = true;
	document.getElementById("cha+").disabled = true;
	document.getElementById("cha-").disabled = true;
	document.getElementById("san+").disabled = true;
	document.getElementById("san-").disabled = true;
}

function enableButtons()
{
	document.getElementById("str+").disabled = false;
	document.getElementById("dex+").disabled = false;
	document.getElementById("con+").disabled = false;
	document.getElementById("int+").disabled = false;
	document.getElementById("wis+").disabled = false;
	document.getElementById("cha+").disabled = false;
	document.getElementById("san+").disabled = false;

}

function acceptScores()
{
	if (Number(document.getElementById("pointsRem").value) != 0)
	{
		document.getElementById("confirmStats").innerHTML = "Use all your points, fool.";
		return;
	}

	disableButtons();

	document.getElementById("confirmStats").innerHTML = "Stats assigned. Proceed.";

	document.getElementById("chooseRace").disabled = false;
}


function racials()
{
	race = setRadio("raceOpt");
	
	var temp;

	if (race == "hillDwarf") //+2 con, +1 wis
	{
		con.value++;
		con.value++;
		wis.value++;
		speed = 25;
	}
	else if (race == "mtnDwarf") //+2 con, +2 str
	{
		con.value++;
		con.value++;
		str.value++;
		str.value++;
		speed = 25;
	}
	else if (race == "highElf") //+2 dex, +1 int
	{
		dex.value++;
		dex.value++;
		_int.value++;
	}
	else if (race == "woodElf") //+2 dex, +1 wis
	{
		dex.value++;
		dex.value++;
		wis.value++;
		speed = 35;
	}
	else if (race == "darkElf") //+2 dex, +1 cha
	{
		dex.value++;
		dex.value++;
		cha.value++;
	}
	else if (race == "lightfootHalfling") //+2 dex, +1 cha
	{
		dex.value++;
		dex.value++;
		cha.value++;
		speed = 25;
	}
	else if (race == "stoutHalfling") //+2 dex, +1 con
	{
		dex.value++;
		dex.value++;
		con.value++;
		speed = 25;
	}
	else if (race == "human")
	{
		str.value++;
		dex.value++;
		con.value++;
		_int.value++;
		wis.value++;
		cha.value++;
	}
	else if (race == "dragonborn")
	{
		str.value++;
		str.value++;
		cha.value++;
	}
	else if (race == "forestGnome")
	{
		_int.value++;
		_int.value++;
		dex.value++;
		speed = 25;
	}
	else if (race == "rockGnome")
	{
		_int.value++;
		_int.value++;
		con.value++;
		speed = 25;
	}
	else if (race == "halfOrc")
	{
		str.value++;
		str.value++;
		con.value++;
	}
	else if (race == "tiefling")
	{
		_int.value++;
		cha.value++;
		cha.value++;
	}
	else if (race == "halfElf")
	{
		cha.value++;
		cha.value++;
		document.getElementById("confirmRace").innerHTML = "Two chosen ability scores not yet implemented. Please make a note of this and complete your sheet accordingly. Your fault for choosing a half-elf, SUCKAAA";
	}
	document.getElementById("chooseRace").disabled = true;
	document.getElementById("demoConfirm").disabled = false;

}

function setRadio(name)
{
	var tempArry = document.getElementsByName(name);
	for (var i = 0; i < tempArry.length; i++)
		if (tempArry[i].checked)
			return tempArry[i].value;
}

function confirmDemographics()
{
	var genders = document.getElementsByName("genderOpt");
	if (genders[0].checked)
		gender = genders[0].value;
	else if (genders[1].checked)
		gender = genders[1].value;

	alignment = setRadio("alignOpt");
	window.alert(alignment);
}
