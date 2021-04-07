#include "DHT.h"
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

int redLed = 8;
int smokeA0 = A0;
int sensorThres = 300;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 13, d7 = 10;
LiquidCrystal lcd(rs,en , d4, d5, d6, d7);

int buzz = 9;

#define dhtDataPin 7                      

#define dhtModel DHT11                  

String WriteApiKey = "VMCDAP51YFQU2HLC";    

String Wifi_Name = "ENDGAME";         

String wifiPassword = "hisben101";        

SoftwareSerial ser(2, 3);              

DHT dht(dhtDataPin, dhtModel); 

void setup() { 

pinMode(redLed, OUTPUT);
pinMode(smokeA0, INPUT);

  
Serial.begin(115200);                

ser.begin(115200);                     

ser.println("AT+RST");               

dht.begin();     

char  k='"';

String s1 = "AT+CWJAP";

       s1+= "=";

       s1+= k;

       s1+= Wifi_Name;

       s1+= k;

       s1+= ",";

       s1+= k;

       s1+= wifiPassword;

       s1+= k;

ser.println(s1);

    lcd.begin(16, 2);

    lcd.print("Temperature:" );

   lcd.setCursor(0,1);

    lcd.print("Humidity:" );

}

void loop() { 

int analogSensor = analogRead(smokeA0);

  
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
  }
  else
  {
    digitalWrite(redLed, LOW);
  }
  delay(100);

int humidity =  dht.readHumidity();             
  int temperature = dht.readTemperature();       


  String state1=String(humidity);                 
  String state2=String(temperature);
  String state3=String(analogSensor);             

  Serial.print("Temperature = ");
  Serial.println(temperature);
 
  Serial.print("Humidity = ");
  Serial.println(humidity);

  Serial.print("Gas Concentration: ");
  Serial.println(analogSensor);


  lcd.setCursor(13, 0);

  if (isnan(humidity) || isnan(temperature)) {
     lcd.print("Failed to Read");
    return;
  }


  lcd.print(temperature);

    lcd.setCursor(10,1);

   lcd.print(humidity);



pinMode(buzz, OUTPUT);

  if(temperature >=40 || humidity >=70)
  {

 	int i=0;
	
	do{
	   i++;
	  tone(buzz, 1000);
	    delay(200);
	  noTone(buzz);
 	    delay(200);
	  }while(i<2);

  }


  String s2 = "AT+CIPSTART=\"TCP\",\"";          

  s2 += "184.106.153.149";                       

  s2 += "\",80";                                 

  ser.println(s2);

 if(ser.find((char*)"Error")){

    return;

  }

String s3 = "GET /update?api_key=";           

  s3 += WriteApiKey;

  s3 +="&field1=";

  s3 += String(state1);                       

  s3 +="&field2=";

  s3 += String(state2);

  s3 +="&field3=";

  s3 += String(state3);

  s3 += "\r\n\r\n";
  

  s2 = "AT+CIPSEND=";

  s2 += String(s3.length());                

  ser.println(s2);

  if(ser.find((char*)">")){

    ser.print(s3);

  }

  else{

    ser.println("AT+CIPCLOSE");                  

  }



}
