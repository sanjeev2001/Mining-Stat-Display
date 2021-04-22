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
  unpaid = data['unpaidAmount'][1:]
  fixedSpeed = speed + " "*(5-len(speed))
  fixedUnpaid = unpaid + " "*(9-len(unpaid))
 
  print(speed)
  print(unpaid)
  print(fixedSpeed)
  print(fixedUnpaid)
  
  ser.flush()
  if(len(speed) == 5):
    ser.write(str(speed).encode('ascii'))
  else:
    ser.write(str(speed + fixedSpeed).encode('ascii'))
    
  if (len(unpaid) == 9):
    ser.write(str(unpaid).encode('ascii'))
  else:
    ser.write(str(unpaid + fixedUnpaid).encode('ascii'))
  time.sleep(5)
  ser.flush()

exit()

