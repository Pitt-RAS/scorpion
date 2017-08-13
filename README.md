# Scorpion
----------
## Team Leads: Ben Bush and Vinayak Nesarikar
---------
Corresponding Mechanical CAD (SolidWorks) files can be found [here](https://drive.google.com/open?id=0ByX0XhLn-1k_elJDRl93ZmpBZ0E)

Corresponding Electrical CAD (Eagle) files can be found [here](https://drive.google.com/open?id=0ByX0XhLn-1k_cUFwWHl4MHVCSFE)

------------

### Components used:

1. [Feetech FR0115M 15KG Metal Gear Double Shaft Servo](https://www.alibaba.com/product-detail/Feetech-FR0115M-15KG-Metal-Gear-double_60246376896.html?spm=a2700.7724838.0.0.RA8L1h)

2. [Mini Maestro 24-Channel USB Servo Controller](https://www.pololu.com/product/1357/resources)

3. [Teensy 3.6](https://www.pjrc.com/store/teensy36.html)

4. [SparkFun Bluetooth Modem - BlueSMiRF Gold](https://www.sparkfun.com/products/12582)

5. [TURNIGY 8-15A UBEC for Lipoly](https://hobbyking.com/en_us/turnigy-8-15a-ubec-for-lipoly.html)

6. [Turnigy 2650mAh 3S 40C Lipo Pack](https://hobbyking.com/en_us/turnigy-2650mah-3s-40c-lipo-pack.html)

------------
### Useful Reference Guides

1. [Mini Maestro Arduino Reference](https://github.com/pololu/maestro-arduino)

2. [Teensydunio](https://www.pjrc.com/teensy/teensyduino.html)

3. [Bluetooth Module 1](https://learn.sparkfun.com/tutorials/using-the-bluesmirf)

4. [Bluetooth Module 2](https://learn.sparkfun.com/tutorials/bluetooth-basics)

------------
### How to Use The Robot

1. In Maestro's control panel ([Windows](https://www.pololu.com/file/0J266/maestro-windows-130422.zip) or [Linux](https://www.pololu.com/file/0J315/maestro-linux-150116.tar.gz)) make sure the lower target value is set to its lowest value and the higher target value is set to its highest value.

2. Connect the Maestro's ground to the Teensy's (I used an Arduino during the testing phase) ground.

3. Connect the Maestro's TX pin to the Teensy's 10th pin.

4. Connect the Maestro's RX pin to the Teensy's 11th pin.

5. Connect the Servos to the maestro as follows:

 | Part           | Foot (Bottom) | Leg (Middle) | Shoulder |
 |----------------|---------------|--------------|----------|
 | Front Left Leg |  0            |   1          |    2     |
 | Front Right Leg| 3             |4             |5         |
 | Mid Left Leg   | 6             |7             |8         |
 | Mid Right Leg  |9              |10            |11        |
 | Back Left Leg  |12             |13            |14        |
 | Back Right Leg |15             |16            |17        |

6. Only supply around 5v to maestro 
7. When you start up the robot lift, it up until all the legs have been set to their neutral position. The servo cannot hold the robot's weight unless they are powered. 
8. Use ardunio's serial monitor to control the robot (This should be replaced by bluetooth controls in the future). The controls are as follows:

'w'-up

's'-down

'a'-turn counter clockwise

'd'-turn clockwise

<b>Note: The robot moves best on a flat rough surface. </b> 

-------------
### Things That Still Need to be Done:

1. Test the circuit board.

2. Make a connector that connects the battery to two UBEC voltage regulators in parallel.

3. Write the code that allows a computer to control the robot through a bluetooth connection, using the bluetooth module.

4. Write the code that shuts the maestro off when the voltage comeing out of the op amp is above 3 volts.

