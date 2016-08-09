<!DOCTYPE HTML>
<html lang="en">
<?php include 'header.php';?>
<body>
<?php include 'nav.php';?>
	<h1>
		Register Account
	</h1>


	<form method="post" onsubmit="checkRegistration()" action="accountProcess.php?login=" name="regform">
		<fieldset>
	<h2>
		If you already have an account with us, please login at the login page.
	</h2>
			<table>
				<tr>
					<td>
						First Name<br>
						<input type="text" name="first"/>
					</td>
					<td>
						Last Name<br>
						<input type="text" name="last"/>
					</td>
				</tr>
				<tr>
					<td colspan="2">
						Username<br>
						<input type="text" name="username" id="usrname"/>
					</td>
				</tr>
				<tr>
					<td colspan="2">
						Email<br>
						<input type="email" name="email" />
					</td>
				</tr>
				<tr>
					<td colspan="2" id="pwinfo">
						Passwords must contain at least one upper-case letter and one digit.						
					</td>
				</tr>
				<tr>
					<td colspan="2" id="error">
					</td>
				</tr>
				<tr>
					<td>
						Password<br>
						<input type="text" name="password" id="pword"/>
					</td>
					<td>
						Confirm Password<br>
						<input type="text" name="confirm" id="confpword"/>
					</td>
				</tr>
			</table>	
			<input type="checkbox" name="privacy" value="privacy_agree" id="check">I agree to the <a href="">privacy policy</a>.</br>
			<button type="submit">Register</button>

		</fieldset>
	</form>

	<?php include 'footer.php'; ?>

</body>
</html>
