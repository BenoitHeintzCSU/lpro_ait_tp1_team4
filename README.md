# LPro AIT 2019 - TP1

All **procedures** will be written as a *.md* file in a folder `/procedures/assembly`, or `/procedures/test`.

All **reports** will be written as a *.md* file in a folder `/reports/...`.

**Don't forget to `commit` and `push` every time you completed a task.**

## 1. Hardware

1. [Arduino Uno](https://store.arduino.cc/)
2. Motor: [EMG30](https://www.gotronic.fr/art-motoreducteur-encodeur-emg30-866.htm)
3. Motor driver: [Pololu DRV8835 Dual Motor Driver Shield for Arduino](https://www.pololu.com/product/2511)
    - [How to install the library](https://github.com/pololu/drv8835-motor-shield)
4. Digital compass HMC5883L from [Octopus 9DOF module](https://www.elecfreaks.com/estore/octopus-9dof-module.html)

## 2. Motor assembly

1. Write a detailed assembly procedure to mount the motor to the blue support.
    - Pictures might help
    - An anomaly report about the too-small-holes in the blue support might be necessary

2. Write a detailed assembly procedure to mount the motor driver on the Arduino and connect the motor.
    - Connect only *+ Motor* and *- Motor*. The speed sensor won't be used.

3. Use the provided code to control the motor and propose and write a test procedure of the assembly.

**Don't forget to `commit` and `push` every time you completed a task.**

## 3. Octopus 9DOF module assembly - Compass only (HMC5883L)

1. Same exercice as previously. Complete previous assembly and test procedures.
    - Use power supply on the motor driver blue connectors.
    - <span style="color:red">**Double check you plugged power supply properly. I don't have spare modules!! If the red LED does not turn on, unplug the USB cable.**</span>
    - The compass might not have its 0 value aligned with the magnetic North. We won't mind about this during this TP. (In real life an offset has to be foud and applied... ask Augustin and François if you want to know more.)

## 4. System control

1. Develop a programm aligning the Y-axis of the digital compass to the measured North (with a proper P/PD/PI/PID controler).
2. Propose a test procedure of the assembled system.

## 5. Finished?

There's more! Ask.