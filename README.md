# HazGuard-System
Hazardous Gases Detection System
# Components:

1. Arduino Uno (or any other compatible Arduino board)
2. MQ-2 Gas Sensor (or MQ-5 for more specific LPG detection)
3. Buzzer or LED for alert
4. Relay Module (optional, for turning off a device in case of leakage)
5. Jumper wires and breadboard
6. Power supply for Arduino

# Steps:
1. Gas Sensor Setup:
Connect the MQ-2 or MQ-5 sensor to the Arduino. The sensor typically has pins for VCC, GND, and A0 (for analog output).
For digital output, use the D0 pin.

2. Arduino Code:
Read values from the gas sensor and check if the detected gas concentration exceeds a threshold.
If the threshold is exceeded, trigger an alert (using a buzzer or LED).

3. Optional Tweaks:
You could integrate a relay module to cut off the gas supply or activate a ventilation system if leakage is detected.

Consider adding a display (LCD/OLED) to show gas levels or status.
