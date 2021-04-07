.............................................Deployment Guideline..................................................

Prerequisite:  
1.	Operating System: Windows / OS /Linux   
2.	Arduino IDE
3.	Arduino Uno Board
4.	DHT11 sensor 
5.	ESP8266-01 wi-fi module 
6.	AMS1117-3.3V 
7.	Buzzer (3-9 V) 
8.	LCD Display (16*2) 
9.	A ThingSpeak Account 
10.	Consistent and Uninterrupted Internet connection  
11.	A consistent power supply from adapter
12. Gas Sensor-MQ2
13. RED LED
  
Installing Process:  
  
1.	Firstly, place the product in a convenient place where it can sense the Temperature, Humidity and Gas Concentration data easily and without interruption.  
2.	After that, create a ThingSpeak account and login to the account.  
3.	Then, create a private channel with temperature in 1st field ,humidity in 2nd field and Gas Concentration in 3rd field.  
4.	Now, enter into the channel and copy the Write API Key, paste it into the line [ String WriteApiKey = "//paste here………"; ] of the code.  
5.	Next, set your Wifi-Name and Wifi-Password into the line[ String Wifi_Name = "//set here………";String wifiPassword = "//set here………"; ]  of the code. 
6.	You can change the Temperature and Humidity and Gas Concentration value according to your threshold for alarm or buzzeras and RED LED for safety purposes. You can change the condition also (like less than or greater than).You can change the value into the line  
	[ if(temperature >=//set value || humidity >=//set value){…… //code}] and [int sensorThres = //set value;]  of the code. 
7.	Before upload the code into Arduino-UNO board through Arduino-IDE, following library must be installed in the IDE:  
			a.	DHT library  
			b.	SoftwareSerial library  
			c.	LiquidCrystal library  
8.	Now, upload the code.  
9.	Power up the product using adapter. 
