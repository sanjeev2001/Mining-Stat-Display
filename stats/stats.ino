#include <ArduinoJson.h>

//#define ARDUINOJSON_USE_LONG_LONG 1
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//const size_t capacity = JSON_ARRAY_SIZE(0) + 2*JSON_ARRAY_SIZE(1) + JSON_ARRAY_SIZE(2) + 9*JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(4) + 2*JSON_OBJECT_SIZE(13) + 2*JSON_OBJECT_SIZE(16) + 1790;
//DynamicJsonBuffer jsonBuffer(capacity);
//const char* json = "{'rigId': '0-OfzAmyEi2EC7vouaJSo3oQ', 'type': 'MANAGED', 'name': 'myPC', 'statusTime': 1619037471129, 'joinTime': 1619032444, 'minerStatus': 'MINING', 'groupName': '', 'unpaidAmount': '0.00000158', 'softwareVersions': 'NHQM_v0.5.1.3,Excavator_v1.7.1d_Build_880', 'devices': [{'id': '32', 'name': 'AMD Ryzen 5 3600 6-Core Processor', 'deviceType': {'enumName': 'CPU', 'description': 'CPU'}, 'status': {'enumName': 'DISABLED', 'description': 'Disabled'}, 'temperature': -1.0, 'load': 20.0, 'revolutionsPerMinute': -1.0, 'revolutionsPerMinutePercentage': -1.0, 'powerMode': {'enumName': 'UNKNOWN', 'description': 'Unknown'}, 'powerUsage': -1.0, 'speeds': [], 'intensity': {'enumName': 'LOW', 'description': 'Low power mode'}, 'nhqm': ''}, {'id': '0', 'name': 'GeForce RTX 2060', 'deviceType': {'enumName': 'NVIDIA', 'description': 'Nvidia'}, 'status': {'enumName': 'MINING', 'description': 'Mining'}, 'temperature': 4456500.0, 'load': 5374050.0, 'revolutionsPerMinute': 1828.0, 'revolutionsPerMinutePercentage': 59.0, 'powerMode': {'enumName': 'UNKNOWN', 'description': 'Unknown'}, 'powerUsage': 74.0, 'speeds': [{'algorithm': 'DAGGERHASHIMOTO', 'title': 'DaggerHashimoto', 'speed': '30.12', 'displaySuffix': 'MH'}], 'intensity': {'enumName': 'LOW', 'description': 'Low power mode'}, 'nhqm': 'V=1;CCC=1020;CVC=668;CCM=1020;MCC=7801;MCS=6801;MCD=1000;MT=196;PLW=170;HWF=9;KTUMED=35759;OP=3;OPA=High:3,Medium:2,Lite:1;'}], 'cpuMiningEnabled': False, 'cpuExists': True, 'stats': [{'statsTime': 1619037416000, 'market': 'USA_E', 'algorithm': {'enumName': 'DAGGERHASHIMOTO', 'description': 'DaggerHashimoto'}, 'unpaidAmount': '0.00000158', 'difficulty': 0.1, 'proxyId': 4, 'timeConnected': 1618996253154, 'xnsub': True, 'speedAccepted': 31.963668740745703, 'speedRejectedR1Target': 0.0, 'speedRejectedR2Stale': 0.0, 'speedRejectedR3Duplicate': 0.0, 'speedRejectedR4NTime': 0.0, 'speedRejectedR5Other': 0.0, 'speedRejectedTotal': 0.0, 'profitability': 7.776e-05}], 'profitability': 7.776e-05, 'localProfitability': 6.456875416915864e-05, 'rigPowerMode': 'UNKNOWN'}";
//JsonObject& root = jsonBuffer.parseObject(json);
//JsonObject& devices_1 = root["devices"][1];
//JsonObject& devices_1_speeds_0 = devices_1["speeds"][0];

//const char* devices_1_speeds_0_speed = devices_1_speeds_0["speed"];
//const char* unpaidAmount = root["unpaidAmount"]; // "0.00000958"
String readString;
String unpaid;

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.

  Serial.begin(9600);
  lcd.print("Hashrate: ");
  lcd.setCursor(0, 1);
  lcd.print("Unpaid: ");
}

void write(String s) {
  if (Serial.available() > 0)
    {
      char c = Serial.read(); //gets one byte from serial buffer
      
      s += c;        //makes the string readString
    } 
}

void loop()
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // print the number of seconds since reset:
  //  lcd.print(millis() / 1000);
  while (Serial.available()) // this will be skipped if no data present, leading to
                             // the code sitting in the delay function below
  {
    delay(30); //delay to allow buffer to fill
    if (Serial.available() > 0)
    {
      char c = Serial.read(); //gets one byte from serial buffer
      
      readString += c;        //makes the string readString
      if(readString.length() == 5 && c != '0') {
        lcd.setCursor(10, 0);
        lcd.print(readString);
        readString = "";
      } else if (readString.length() == 9) {
        lcd.setCursor(7, 1);
        lcd.print(readString);
        readString = "";
      }
    } 
    delay(30);
    
  }
  
}
