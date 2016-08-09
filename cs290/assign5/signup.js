//Author: Isaac Stallcup
//Date: 7/24/2016
//Javascript to confirm account registration for CS 290 Summer 2016 Assign 4

function checkRegistration()
{

	var err = document.getElementById("error");
	var info = document.getElementById("pwinfo");
	var pWord = document.getElementById("pword");
	var conf = document.getElementById("confpword");
	var i;
	
	err.innerHTML = "";
	info.style.color = "black";
	
	for (i = 1; i < document.forms["regform"].length-1; i++)
	{
		var check = document.forms["regform"][i];
		if (check.value == null || check.value == "")
		{
			check.style.backgroundColor = "#FABEBE";
			err.innerHTML = "Please fill in missing fields.";
			event.preventDefault();
		}
		else check.style.backgroundColor = "white";
	}

	if (pWord.value != conf.value)
	{
		err.innerHTML = "Passwords must match.";
		event.preventDefault();
	}
	else
	{
		var str = pWord.value;
		var pwRegex = new RegExp("[A-Z]+[a-z]*[0-9]+");
		if (!pwRegex.test(str))
		{
			info.style.color = "red";
			event.preventDefault();
		}
	}

	if (document.getElementById("check").checked == false)
	{
		err.innerHTML = "Please agree to privacy policy.";
		event.preventDefault();
	}
	document.forms['regform'].action += document.getElementById("usrname").value;

	return true;

}
