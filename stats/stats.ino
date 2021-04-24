#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

String readString;
String unpaid;

void setup()
{
  lcd.begin(16, 2);

  Serial.begin(9600);
  lcd.print("Hashrate: ");
  lcd.setCursor(0, 1);
  lcd.print("Unpaid: ");
}

void loop()
{
  
  while (Serial.available())     
  {
    delay(30); 
    if (Serial.available() > 0)
    {
      char c = Serial.read(); 

      readString += c;
      if (readString.length() == 5 && ((isdigit(c) && c!='0') || c == ' '))
      {
        lcd.setCursor(10, 0);
        lcd.print(readString);
        readString = "";
      }
      else if (readString.length() == 9 && (readString.charAt(8) == '1' || readString.charAt(8) == '2' || readString.charAt(8) == '3' || readString.charAt(8) == '4' || readString.charAt(8) == '5' || readString.charAt(8) == '6' || readString.charAt(8) == '7' || readString.charAt(8) == '8' || readString.charAt(8) == '9' || readString.charAt(8) == ' '))
      {
        lcd.setCursor(7, 1);
        lcd.print(readString);
        readString = "";
      }
    }
    delay(30);
  }
  
}
