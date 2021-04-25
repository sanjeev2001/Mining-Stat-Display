import StatScript
import json
import serial
from time import time, sleep
from SECRET import host, organisation_id, key, secret

private_api = StatScript.private_api(host, organisation_id, key, secret, True)
ser = serial.Serial('COM3', 9600, timeout=5)
print(ser.name)

while True:
    sleep(60 - time() % 60)
    my_rig = private_api.getRigID()
    del my_rig['rigId']
    del my_rig['type']
    del my_rig['name']
    del my_rig['statusTime']
    del my_rig['joinTime']
    del my_rig['minerStatus']
    del my_rig['groupName']
    del my_rig['softwareVersions']
    del my_rig['cpuMiningEnabled']
    del my_rig['cpuExists']
    del my_rig['stats']
    del my_rig['profitability']
    del my_rig['localProfitability']
    del my_rig['rigPowerMode']
    del my_rig['devices'][0]

    with open('data.json', 'w') as f:
        f.truncate(0)
        print(json.dumps(my_rig, indent=4), file=f)

    sleep(2)  # wait for Arduino

    with open('data.json') as f:
        data = json.load(f)

    speed = data['devices'][0]['speeds'][0]['speed']
    unpaid = data['unpaidAmount'][1:]
    if(len(speed) != 5):
        speed = speed + " "*(5-len(speed))
    if (len(unpaid) != 9):
        unpaid = unpaid + " "*(9-len(unpaid))

    print("Speed: " + speed)
    print("Unpaid: " + unpaid)

    ser.flush()
    ser.write(str(speed).encode('ascii'))
    ser.write(str(unpaid).encode('ascii'))
    
    ser.flush()
