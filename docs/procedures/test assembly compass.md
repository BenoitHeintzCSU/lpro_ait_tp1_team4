# test of the assembly compass

## Summary
1. Hardware
2. Process
3. result

## 1) Hardware
- assembly compass
- arduino IDE

## 2) Process
- Connect arduino to the laptop
- Check if the LED on the octopus module is ON if not turn of the arduino and verify the cable
- Open the linked test software (../sources/hmc5883L/hmc5883L.ino)
- In tool select the Arduino UNO card and the right COM port
- Download this software in the Arduino
- Open serial port on arduino IDE and verify if the value are between -1000 and 1000
-check with a compas if the assembly point the north


## 3) Result

| Action|Passed|Failed|Annotation|
|-|-|-|-|
| Module LED ON||||
| Serial communication work||||
| value between -1000 and 1000||||
| assembly point north||||