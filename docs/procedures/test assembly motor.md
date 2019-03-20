# test of the assembly motor

all sens are in motor axis sight <span style="color:red">Not clear</span>

## Summary
1. Hardware
2. Process
3. result

## 1) Hardware
- assembly motor
- arduino IDE with the library (check in assembly driver motor part 3 arduino)

## 2) Process
- Connect arduino to the laptop
- Open the linked test software (../sources/motor_control_open_loop/motor_control_open_loop.ino)
- In tool select the Arduino UNO card and the right COM port
- Download this software in the Arduino
- Use the result sheet to verif:
    - the motor turn clockwise for 2s then turn anticlockwise for 2s 
    - anticlockwise LED ON, clockwise LED OFF
    - after the mortor accelerate in one direction for 3.75s then accelerate in the other direction 

## 3) result

| action |Passed  |Failed| annotation|
|----------------------|--------|-----------------|---------|
| motor turn clockwise for 2s||||
| motor turn anticlockwise for 2s||||
| LED OFF when clockwise||||
| LED ON when anticlockwise||||
| accelerate in clockwise for 3.75s||||
| accelerate in anticlockwise for 3.75s||||