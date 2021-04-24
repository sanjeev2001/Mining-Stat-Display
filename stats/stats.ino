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
      if (readString.length() == 5 && ((isdigit(c) && c!='0') || c == ' ')) //Once the speed is fully sent over serial it prints onto the first line
      {
        lcd.setCursor(10, 0);
        lcd.print(readString);
        readString = "";
      }
      else if (readString.length() == 9 && ((isdigit(c) && c!='0') || c == ' ')) //Once the unpaid is fully sent over serial it prints onto the second line
      {
        lcd.setCursor(7, 1);
        lcd.print(readString);
        readString = "";
      }
    }
    delay(30);
  }
  
}
