import serial
import time

import json

ser = serial.Serial('COM3', 9600, timeout=5)
print(ser.name)

while(True):
    time.sleep(2)  # wait for Arduino

    with open('data.json') as f:
        data = json.load(f)

    speed = data['devices'][0]['speeds'][0]['speed']
    unpaid = data['unpaidAmount'][1:]
    # speed = "30"
    # unpaid = ".0000101"
    if(len(speed) != 5):
        speed = speed + " "*(5-len(speed))
    if (len(unpaid) != 9):
        unpaid = unpaid + " "*(9-len(unpaid))
    # fixedSpeed = speed + "1"*(5-len(speed))
    # fixedUnpaid = unpaid + "1"*(9-len(unpaid))

    print("Speed: " + speed)
    print("Unpaid: " + unpaid)

    ser.flush()
    # if(len(speed) == 5):
    ser.write(str(speed).encode('ascii'))
    # else:
    #     ser.write(str(speed + "1"*(5-len(speed))).encode('ascii'))
    time.sleep(1)
    # if (len(unpaid) == 9):
    ser.write(str(unpaid).encode('ascii'))
    # else:
    #     ser.write(str(unpaid + fixedUnpaid).encode('ascii'))
    time.sleep(3)
    ser.flush()

exit()
