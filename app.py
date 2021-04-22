import StatScript
import json
from time import time, sleep
from SECRET import host, organisation_id, key, secret

private_api = StatScript.private_api(host, organisation_id, key, secret, True)

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
