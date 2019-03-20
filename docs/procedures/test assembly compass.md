# test of the assembly compass

all sens are in motor axis sight <span style="color:red">Not clear</span>

## Summary
1. Hardware
2. Process
3. result

## 1) Hardware
- assembly motor
- arduino IDE with the library (check in //////////)

## 2) Process
- Connect arduino to the laptop
- Open the linked test software (../sources/hmc5883L/hmc5883L.ino)
- In tool select the Arduino UNO card and the right COM port
- Download this software in the Arduino


## 3) result

| action |Passed  |Failed| annotation|
|----------------------|--------|-----------------|---------|
| motor turn clockwise for 2s||||
| motor turn anticlockwise for 2s||||
| LED OFF when clockwise||||
| LED ON when anticlockwise||||
| accelerate in clockwise for 3.75s||||
| accelerate in anticlockwise for 3.75s||||