// Included Libraries
#include <Wire.h>
#include <TinyMPU6050.h>
#include <LiquidCrystal.h>
//#include <WiFi.h>
//#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

MPU6050 mpu (Wire);

// Create An LCD Object. Signals: [ RS, EN, D4, D5, D6, D7 ]
LiquidCrystal My_LCD(13, 12, 14, 27, 26, 25);

// Wifi network station credentials
//#define WIFI_SSID "Honor View10"
//#define WIFI_PASSWORD "315f8fd4fecc"

//#define BOT_TOKEN "5229736615:AAEE_BXGakya-njp7A82FAidLQq32CNUw2I"
//#define CHAT_ID "1100859595"

//WiFiClientSecure secured_client;
//UniversalTelegramBot bot(BOT_TOKEN, secured_client);

// These constants won't change:
const int sensorPinTHUMB = A0;    // pin that the THUMB flex sensor is attached to
const int sensorPinINDEX = A3;    // pin that the INDEX flex sensor is attached to
const int sensorPinMIDDLE = A6;    // pin that the MIDDLE flex sensor is attached to
const int sensorPinRING = A7;    // pin that the RING flex sensor is attached to
const int sensorPinPINKEY = A4;    // pin that the PINKEY flex sensor is attached to
// variables:
int sensorValueTHUMB = 0;         // the sensor value
int sensorValueINDEX = 0;         // the sensor value
int sensorValueMIDDLE = 0;         // the sensor value
int sensorValueRING = 0;         // the sensor value
int sensorValuePINKEY = 0;         // the sensor value
int sensorMinTHUMB = 1023;        // minimum sensor value
int sensorMinINDEX = 1023;        // minimum sensor value
int sensorMinMIDDLE = 1023;        // minimum sensor value
int sensorMinRING = 1023;        // minimum sensor value
int sensorMinPINKEY = 1023;        // minimum sensor value
int sensorMaxTHUMB = 0;           // maximum sensor value
int sensorMaxINDEX = 0;           // maximum sensor value
int sensorMaxMIDDLE = 0;           // maximum sensor value
int sensorMaxRING = 0;           // maximum sensor value
int sensorMaxPINKEY = 0;           // maximum sensor value
void setup() 
{
  Serial.begin (115200);
    // Initialize The LCD. Parameters: [ Columns, Rows ]
  My_LCD.begin(16, 2);
  // Clears The LCD Display
  My_LCD.clear();

  // attempt to connect to Wifi network:
  delay(1000);
  //Serial.print("Connecting to Wifi SSID ");
  //Serial.print(WIFI_SSID);
  //WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  //secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  //while (WiFi.status() != WL_CONNECTED)
  //{
  //  delay(500);
   // Serial.print(".");
 // }
  //Serial.println("");
  //Serial.println("WiFi connected");
   
  //bot.sendMessage(CHAT_ID, "Bot started up", "");

  // Initialization
  mpu.Initialize();
  // Calibration (wait for about 20s to calibrate)
  mpu.Calibrate();

  //start up
  Serial.println("Done Clabration");

 // calibrate during the first five seconds 
 while (millis() < 5000) 
 {
     sensorValueTHUMB = analogRead(sensorPinTHUMB);
     sensorValueINDEX = analogRead(sensorPinINDEX);
     sensorValueMIDDLE = analogRead(sensorPinMIDDLE);
     sensorValueRING = analogRead(sensorPinRING);
     sensorValuePINKEY = analogRead(sensorPinPINKEY);
//--------------------------------------------------
   // record the maximum sensor value
   if (sensorValueTHUMB > sensorMaxTHUMB) 
   {
     sensorMaxTHUMB = sensorValueTHUMB;
   }
      // record the maximum sensor value
   if (sensorValueINDEX > sensorMaxINDEX) 
   {
     sensorMaxINDEX = sensorValueINDEX;
   }
  // record the maximum sensor value
   if (sensorValueMIDDLE > sensorMaxMIDDLE) 
   {
     sensorMaxMIDDLE = sensorValueMIDDLE;
   }
   // record the maximum sensor value
   if (sensorValueRING > sensorMaxRING) 
   {
     sensorMaxRING = sensorValueRING;
   }
   // record the minimum sensor value
   if (sensorValueRING < sensorMinRING) 
   {
     sensorMinRING = sensorValueRING;
   }
    // record the maximum sensor value
   if (sensorValuePINKEY > sensorMaxPINKEY) 
   {
     sensorMaxPINKEY = sensorValuePINKEY;
   }
   //--------------------------------------------------------
   // record the minimum sensor value
   if (sensorValueTHUMB < sensorMinTHUMB) 
   {
     sensorMinTHUMB = sensorValueTHUMB;
   }
      // record the minimum sensor value
   if (sensorValueINDEX < sensorMinINDEX) 
   {
     sensorMinINDEX = sensorValueINDEX;
   }
       // record the minimum sensor value
   if (sensorValueMIDDLE < sensorMinMIDDLE) 
   {
     sensorMinMIDDLE = sensorValueMIDDLE;
   }
   // record the minimum sensor value
   if (sensorValueRING < sensorMinRING) 
   {
     sensorMinRING = sensorValueRING;
   }
   // record the minimum sensor value
   if (sensorValuePINKEY < sensorMinPINKEY) 
   {
     sensorMinPINKEY = sensorValuePINKEY;
   }
 }
  Serial.print ("LowTHUMB = ");
  Serial.println (sensorMinTHUMB);
  Serial.print ("HighTHUMB = ");
  Serial.println (sensorMaxTHUMB);
  Serial.println ("             ");
  Serial.print ("LowINDEX = ");
  Serial.println (sensorMinINDEX);
  Serial.print ("HighINDEX = ");
  Serial.println (sensorMaxINDEX);
  Serial.println ("             "); 
  Serial.print ("LowMIDDLE = ");
  Serial.println (sensorMinMIDDLE);
  Serial.print ("HighMIDDLE = ");
  Serial.println (sensorMaxMIDDLE);
  Serial.println ("             "); 
  Serial.print ("LowRING = ");
  Serial.println (sensorMinRING);
  Serial.print ("HighRING = ");
  Serial.println (sensorMaxRING);
  Serial.println ("             "); 
  Serial.print ("LowPINKEY = ");
  Serial.println (sensorMinPINKEY);
  Serial.print ("HighPINKEY = ");
  Serial.println (sensorMaxPINKEY);
  Serial.println ("             ");
  delay (1000);
}

 void loop() {
// read the sensor:
 sensorValueTHUMB = analogRead(sensorPinTHUMB);
 sensorValueINDEX = analogRead(sensorPinINDEX);
 sensorValueMIDDLE = analogRead(sensorPinMIDDLE);
 sensorValueRING = analogRead(sensorPinRING);
 sensorValuePINKEY = analogRead(sensorPinPINKEY);
 
 // apply the calibration to the sensor reading
 sensorValueTHUMB = map(sensorValueTHUMB, sensorMinTHUMB, sensorMaxTHUMB, 1, 255);
 sensorValueINDEX = map(sensorValueINDEX, sensorMinINDEX, sensorMaxINDEX, 1, 255);
 sensorValueMIDDLE = map(sensorValueMIDDLE, sensorMinMIDDLE, sensorMaxMIDDLE, 1, 255);
 sensorValueRING = map(sensorValueRING, sensorMinRING, sensorMaxRING, 1, 255);
 sensorValuePINKEY = map(sensorValuePINKEY, sensorMinPINKEY, sensorMaxPINKEY, 1, 255);
 
 // in case the sensor value is outside the range seen during calibration
 sensorValueTHUMB = constrain(sensorValueTHUMB, 1, 255);
 sensorValueINDEX = constrain(sensorValueINDEX, 1, 255);
 sensorValueMIDDLE = constrain(sensorValueMIDDLE, 1, 255);
 sensorValueRING = constrain(sensorValueRING, 1, 255);
 sensorValuePINKEY = constrain(sensorValuePINKEY, 1, 255);
 
 Serial.println ("-------------------");
 Serial.print ("sensorValue-THUMB = ");
 Serial.println (sensorValueTHUMB);
 Serial.print ("sensorValue-INDEX = ");
 Serial.println (sensorValueINDEX);
 Serial.print ("sensorValue-MIDDLE = ");
 Serial.println (sensorValueMIDDLE);
 Serial.print ("sensorValue-RING = ");
 Serial.println (sensorValueRING);
 Serial.print ("sensorValue-PINKEY = ");
 Serial.println (sensorValuePINKEY);
 Serial.println ("   ");
 Serial.println (" ");

 mpu.Execute();
 int message;
  
 //gesture commands
 if (sensorValueINDEX <5  && sensorValueMIDDLE <50 && sensorValueRING <5 && sensorValuePINKEY <5 ) 
 {
   Serial.println  ("\n");
   Serial.println ("Need Help !!!"); 
   Serial.println  ("        ");
   My_LCD.print("Need Help !!!");
   Serial.println  ("        ");
   
   //bot.sendMessage(CHAT_ID, "Need Help !!!" , "");
   if (mpu.GetRawAccX() <= -8000) 
  {
    //send msg to move bottom
    message = 1;
     Serial.println(" ");
     My_LCD.setCursor(1, 1);
     My_LCD.print(" ");
     delay (3000);
     My_LCD.clear();
     //bot.sendMessage(CHAT_ID, " " , "");
     mpu.Execute();
  }

  if (mpu.GetRawAccX() >= 8000) 
  {
    //send msg to move top
    message = 2;
    Serial.println(" Feeling Thirsty !");
    My_LCD.setCursor(1, 1);
    My_LCD.print("Feeling Thirsty  !");
    delay (3000);
    My_LCD.clear();
    //bot.sendMessage(CHAT_ID, "Feeling Thursty  !" , "");
    mpu.Execute();
  }

  if (mpu.GetRawAccY() <= -8000) 
  {
    //send msg to move left
    message = 3;
    Serial.println("Medicine Time");
    My_LCD.setCursor(1, 1);
    My_LCD.print("Medicine Time");
    delay (3000);
    My_LCD.clear();
    //bot.sendMessage(CHAT_ID, "Medicine Time" , "");
    mpu.Execute();
  }

  if (mpu.GetRawAccY() >= 8000) 
  {
    //send msg to move right
    message = 4;
    Serial.println("Feeling Hungry !");
    My_LCD.setCursor(1, 1);
    My_LCD.print("Feeling Hungry !");
    delay (3000);
    My_LCD.clear();
    //bot.sendMessage(CHAT_ID, "Feeling Hungry !" , "");
    mpu.Execute();
  }
  if (mpu.GetRawAccX() < 8000 and mpu.GetRawAccX() > -8000 and mpu.GetRawAccY() < 8000 and mpu.GetRawAccY() > -8000) 
  {

    //send msg to stop
    message = 0;
    Serial.println("Fall Suddenly ");
    My_LCD.setCursor(1, 1);
    My_LCD.print("Fall Suddenly");
    delay (3000);
    My_LCD.clear();
    mpu.Execute();
    //bot.sendMessage(CHAT_ID, "Fall Suddenly" , "");

  }
 delay(500);
 mpu.Execute();   
 }
 else 
 {
 } 
 if (sensorValueINDEX >30 && sensorValueMIDDLE >20 &&  sensorValuePINKEY >20 && sensorValueRING <20 ) 
 {
   Serial.println ("Call Mom"); 
   Serial.println  ("        ");
   My_LCD.print(" Call Mom");
   delay (3000);
   My_LCD.clear();
   //bot.sendMessage(CHAT_ID, "Call Mom" , "");
  }
 else 
 {
 }
  if (sensorValueINDEX >20  && sensorValueMIDDLE  <50 && sensorValueRING <10 && sensorValuePINKEY >20 ) 
  {
   Serial.println ("Turn on Lights"); 
   Serial.println  ("        ");
   My_LCD.print(" Turn ON Lights ");
   delay (3000);
   My_LCD.clear();
   //bot.sendMessage(CHAT_ID, "Turn ON Lights" , "");
 }
 else 
 {
 }
  if (sensorValueINDEX >20  && sensorValueMIDDLE >20 && sensorValueRING <10 && sensorValuePINKEY <5) 
 {
   Serial.println ("Turn OFF Lights"); 
   Serial.println  ("        ");
   My_LCD.print("Turn OFF Lights");
   delay (3000);
   My_LCD.clear();
   //bot.sendMessage(CHAT_ID, "Turn OFF Lights" , "");
 }
 else 
 {
 }
  if (sensorValueINDEX >20  && sensorValueMIDDLE <50 && sensorValueRING <10 && sensorValuePINKEY <10 )  
 {
   Serial.println ("Go to washroom"); 
   Serial.println  ("        ");
   My_LCD.print("Want to go");
   My_LCD.setCursor(0,1);
   My_LCD.print("to washroom");
      delay (3000);
   My_LCD.clear();
   //bot.sendMessage(CHAT_ID, "Go to washroom" , "");
 }
 else 
 {
 }
 delay (1000);
}
