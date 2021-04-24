# Nicehash Stat Display
 
## Overview
This project lets you display your Nicehash mining statistics on a 16x2 LCD Display with an Arduino and the Nicehash API.

## How it works
First the app.py file is run and it performs a GET request to the Nicehash API. This creates a json file that contains some information about your mining rig. Then the serialSend.py file takes the data from this json and parses it such that it obtains the hashrate of your rig and the current unpaid amount. It sends these values to the connected Arduino over the serial com port where the stats.ino file takes the values byte by byte and displays it onto the LCD.



## How to run it yourself
 1. Pull the repository
 2. Create a file called SECRET.py in the root that contains the following information
	 
		host = 'https://api2.nicehash.com'
		organisation_id = 'Your organisation ID'
		key = 'Your API key'
		secret = 'Your secret key'
 3. In `serialSend.py` change the COM port in the `ser` variable if it is not COM3 already
 4. Upload the code to your Arduino
 5. Run `app.py` and `serialSend.py` one after the other in 2 different terminals

## What's next

 - Add total balance and other important information
 - Add scrolling to be able to display all this information
