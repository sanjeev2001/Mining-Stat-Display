import serial
import time

import json

ser = serial.Serial('COM3', 9600, timeout = 5)
print(ser.name)

while(True):
  time.sleep(2) # wait for Arduino

  with open('data.json') as f:
    data = json.load(f)

  speed = data['devices'][0]['speeds'][0]['speed']
  print(speed)
  # Serial write section
  ser.flush()
  ser.write(str(speed + " ").encode('ascii'))
  time.sleep(4) # I shortened this to match the new value in your Arduino code
exit()