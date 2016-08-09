//Author: Isaac Stallcup
//Date: 7/24/2016
//Javascript to conform login for CS 290 Summer 2016 Assign 4

function checkLogin()
{
	var name = document.getElementById("usrnme");
	var pw = document.getElementById("pw");
	var err = document.getElementById("err");

	name.style.backgroundColor = "white";
	pw.style.backgroundColor = "white";

	if (name.value == null || name.value == "")
	{
		name.style.backgroundColor = "#FABEBE";
		err.innerHTML += "Please enter a username</br>";
		event.preventDefault();
	}
	if (pw.value == null || pw.value == "")
	{
		pw.style.backgroundColor = "#FABEBE";
		err.innerHTML += "Please enter a password</br>";
		event.preventDefault();
	}

	var str = pw.value;
	var pwRegex = new RegExp("[A-Z]+[a-z]*[0-9]+");
	if (!pwRegex.test(str))
	{
		err.innerHTML += "Password invalid";
		event.preventDefault();
	}

	document.forms['loginform'].action += name.value;
}
