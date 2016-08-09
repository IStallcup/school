<!DOCTYPE HTML>
<html lang="en">
<?php include 'header.php';?>
<body>
<?php include 'nav.php';?>
	<h1>
		Log In
	</h1>

	<form method="post" onsubmit="checkLogin()" action="loginProcess.php?login=" name="loginform">
	<fieldset>
		<h2>Please enter your username and password.</h2>
		<table>
			</tr>
				<td>
					Username: <input type="text" name="username" id="usrnme"/>
				</td>
			</tr>
			</tr>
				<td>
					Password: <input type="text" name="password" id="pw"/>
				</td>
			</tr>
		</table>
		<p id="err"></p>
		<button type="submit">Login</button>
	</fieldset>	
</form>

<?php include 'footer.php'; ?>

</body>
</html>
