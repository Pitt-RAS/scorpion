/* You should go to the Serial Settings
tab in the Maestro Control Center and apply these settings:
* Serial mode: UART, fixed baud rate
* Baud rate: 9600
* CRC disabled
*/

#include <PololuMaestro.h>

/* On boards with a hardware serial port available for use, use
that port to communicate with the Maestro. For other boards,
create a SoftwareSerial object using pin 10 to receive (RX) and
pin 11 to transmit (TX). */
#ifdef SERIAL_PORT_HARDWARE_OPEN
  #define maestroSerial SERIAL_PORT_HARDWARE_OPEN
#else
  #include <SoftwareSerial.h>
  SoftwareSerial maestroSerial(10, 11);
#endif

/* Next, create a Maestro object using the serial port.
Uncomment one of MicroMaestro or MiniMaestro below depending
on which one you have. */
//MicroMaestro maestro(maestroSerial);
int counter;
int used=0;
MiniMaestro maestro(maestroSerial);
//Converts your chosen angle to the correct target value for the maestro
int convertangletotarget(double angle){
  double target = ((12480*angle)/190);
  return target;
}
//Converts your small (<20 degrees) chosen angle to the correct target value for the maestro
int convertsmallangletotarget(double angle){
  double target = 2*((12480*angle)/190);
  return target;
}
//Moves the chosen foot and leg to the correct angles to move the leg down 
void movedown(int foot,int leg){
  int targetval = (int) convertangletotarget(130);
  if(foot ==6){
    targetval = (int) convertangletotarget(130);
    maestro.setTarget(foot, targetval);
  }else if(foot==9){
    targetval = (int) convertangletotarget(139);
    maestro.setTarget(foot, targetval);
  }else if(foot==15){
    targetval = (int) convertangletotarget(132);
    maestro.setTarget(foot, targetval);
  }else if(foot==3){
    targetval = (int) convertangletotarget(136);
    maestro.setTarget(foot, targetval);
  }else {
  maestro.setTarget(foot, targetval);
  }
  delay(300);
  if(leg==10){
   targetval = (int) convertangletotarget(145);
   maestro.setTarget(leg, targetval);
  }else if (leg == 16){
   targetval = (int) convertangletotarget(141);
   maestro.setTarget(leg, targetval);
  }else if (leg == 4){
   targetval = (int) convertangletotarget(140);
   maestro.setTarget(leg, targetval);
  }
  else{
  targetval = (int) convertangletotarget(137);
  maestro.setTarget(leg, targetval);
  }
  delay(200);
}
//moves the shoulder to the correct center angle
void movecenter(int shoulder){
  int targetval=0;
  if (shoulder == 8 || shoulder == 11 ){
    targetval = (int) convertangletotarget(90);
  }
  else if (shoulder == 17 || shoulder==5){
    targetval = (int) convertangletotarget(126);
  }
  else{
    targetval = (int) convertangletotarget(69);
  }
  maestro.setTarget(shoulder, targetval);
}

//sets each servo's speed and acceleration. And sets the robot to its neutral position.
void setup()
{
  // Set the serial baud rate.
  int counter=0;
  Serial.begin(9600);
  maestroSerial.begin(9600);  
  maestro.goHome();
  maestro.reset();
  maestro.setSpeed(0, 60);
  maestro.setSpeed(1, 60);
  maestro.setSpeed(2, 60);
  maestro.setAcceleration(0,0);
  maestro.setAcceleration(1,0);
  maestro.setAcceleration(2,0);
  maestro.setSpeed(3, 60);
  maestro.setSpeed(4, 60);
  maestro.setSpeed(5, 60);
  maestro.setAcceleration(3,0);
  maestro.setAcceleration(4,0);
  maestro.setAcceleration(5,0);
  maestro.setSpeed(6, 60);
  maestro.setSpeed(7, 60);
  maestro.setSpeed(8, 60);
  maestro.setAcceleration(6,0);
  maestro.setAcceleration(7,0);
  maestro.setAcceleration(8,0);
  maestro.setSpeed(9, 60);
  maestro.setSpeed(10, 60);
  maestro.setSpeed(11, 60);
  maestro.setAcceleration(9,0);
  maestro.setAcceleration(10,0);
  maestro.setAcceleration(11,0);
  maestro.setSpeed(12, 60);
  maestro.setSpeed(13, 60);
  maestro.setSpeed(14, 60);
  maestro.setAcceleration(12,0);
  maestro.setAcceleration(13,0);
  maestro.setAcceleration(14,0);
  maestro.setSpeed(15, 60);
  maestro.setSpeed(16, 60);
  maestro.setSpeed(17, 60);
  maestro.setAcceleration(15,0);
  maestro.setAcceleration(16,0);
  maestro.setAcceleration(17,0);
  movedown(0,1);
  movedown(3,4);
  movedown(6,7);
  movedown(9,10);
  movedown(12,13);
  movedown(15,16);
  movecenter(2);
  movecenter(5);
  movecenter(8);
  movecenter(11);
  movecenter(14);
  movecenter(17);
}
//Moves the chosen leg to the correct angles to move the leg up 
void moveup(int leg){
  int targetval = (int) convertangletotarget(153);
  maestro.setTarget(leg, targetval);
  delay(300);
}
//Moves the chosen shoulder to the correct angle to move the leg right
void moveright(int shoulder){
  int targetval=0;
  if (shoulder==8 || shoulder==11){
    targetval = (int) convertangletotarget(105);
  } 
  else if(shoulder == 17 || shoulder==5){
    targetval = (int) convertangletotarget(141);
  }
  else{
    targetval = (int) convertangletotarget(84);
  }
  maestro.setTarget(shoulder, targetval);
  delay(300);
}
//Moves the chosen shoulder to the correct angle to move the leg left
void moveleft(int shoulder){
  int targetval=0;
  if (shoulder==8 || shoulder==11){
  targetval = (int) convertangletotarget(75);
  } 
  else if(shoulder == 17 || shoulder==5){
    targetval = (int) convertangletotarget(111);
  }
  else{
  targetval = (int) convertangletotarget(54);
  }
  maestro.setTarget(shoulder, targetval);
  delay(300);
}
//Turns the robot counter clockwise
void turncounterclockwise(){
  moveup(1);
  moveright(2);
  movedown(0,1);
  moveup(4);
  moveright(5);
  movedown(3,4);
  moveup(7);
  moveright(8);
  movedown(6,7);
  moveup(10);
  moveright(11);
  movedown(9,10);
  moveup(13);
  moveright(14);
  movedown(12,13);
  moveup(16);
  moveright(17);
  movedown(15,16);
  moveleft(2);
  moveleft(5);
  moveleft(8);
  moveleft(11);
  moveleft(14);
  moveleft(17);
  moveup(1);
  movecenter(2);
  movedown(0,1);
  moveup(4);
  movecenter(5);
  movedown(3,4);
  moveup(7);
  movecenter(8);
  movedown(6,7);
  moveup(10);
  movecenter(11);
  movedown(9,10);
  moveup(13);
  movecenter(14);
  movedown(12,13);
  moveup(16);
  movecenter(17);
  movedown(15,16);
}
//Turns the robot clockwise
void turnclockwise(){
  moveup(1);
  moveleft(2);
  movedown(0,1);
  moveup(4);
  moveleft(5);
  movedown(3,4);
  moveup(7);
  moveleft(8);
  movedown(6,7);
  moveup(10);
  moveleft(11);
  movedown(9,10);
  moveup(13);
  moveleft(14);
  movedown(12,13);
  moveup(16);
  moveleft(17);
  movedown(15,16);
  moveright(2);
  moveright(5);
  moveright(8);
  moveright(11);
  moveright(14);
  moveright(17);
  moveup(1);
  movecenter(2);
  movedown(0,1);
  moveup(4);
  movecenter(5);
  movedown(3,4);
  moveup(7);
  movecenter(8);
  movedown(6,7);
  moveup(10);
  movecenter(11);
  movedown(9,10);
  moveup(13);
  movecenter(14);
  movedown(12,13);
  moveup(16);
  movecenter(17);
  movedown(15,16);
}
//Not needed
void correctstart(){
  int targetval = (int) convertangletotarget(84);
  if(maestro.getPosition(2)!=targetval){
    moveup(1);
    maestro.setTarget(2, targetval);
    movedown(0,1);
  }
  targetval = (int) convertangletotarget(111);
  if(maestro.getPosition(5)!=targetval){
    moveup(4);
    maestro.setTarget(5, targetval);
    movedown(3,4);
  }
   targetval = (int) convertangletotarget(141);
   if(maestro.getPosition(17)!=targetval){
    moveup(16);
    maestro.setTarget(17, targetval);
    movedown(15,16);
  }
   targetval = (int) convertangletotarget(54);
   if(maestro.getPosition(14)!=targetval){
    moveup(13);
    maestro.setTarget(14, targetval);
    movedown(12,13);
  }
}
//Moves the robot forward
void moveforward(){
  correctstart();
   moveup(1);
   movecenter(2);
   movedown(0,1);
   int targetval = (int) convertangletotarget(84);
   maestro.setTarget(2, targetval);
   moveup(4);
   movecenter(5);
   movedown(3,4);
   targetval = (int) convertangletotarget(111);
   maestro.setTarget(5, targetval);
   moveup(7);
   moveleft(8);
   movedown(6,7);
   movecenter(8);
   moveup(10);
   moveright(11);
   movedown(9,10);
   movecenter(11);
   moveup(13);
   targetval = (int) convertangletotarget(44);
   maestro.setTarget(14, targetval);
   movedown(12,13);
   moveleft(14);
   moveup(16);
   targetval = (int) convertangletotarget(152);
   maestro.setTarget(17, targetval);
   movedown(15,16);
   moveright(17);
}
//Moves the robot backwards
void movebackwards(){
  correctstart();
   moveup(1);
   int targetval = (int) convertangletotarget(100);
   maestro.setTarget(2, targetval);
   movedown(0,1);
   targetval = (int) convertangletotarget(84);
   maestro.setTarget(2, targetval);
   moveup(4);
   targetval = (int) convertangletotarget(100);
   maestro.setTarget(5, targetval);
   movedown(3,4);
   targetval = (int) convertangletotarget(111);
   maestro.setTarget(5, targetval);
   moveup(7);
   moveright(8);
   movedown(6,7);
   movecenter(8);
   moveup(10);
   moveleft(11);
   movedown(9,10);
   movecenter(11);
   moveup(13);
   movecenter(14);
   movedown(12,13);
   moveleft(14);
   moveup(16);
   movecenter(17);
   movedown(15,16);
   moveright(17);
}
//Sets the robot back to its neutral position. It also is used to keep servos from stalling to much.
void cleanup(){
  moveup(10);
  moveright(11);
  movecenter(11);
  delay(200);
  int targetval = (int) convertangletotarget(145);
  maestro.setTarget(10, targetval);
   delay(200);
   moveup(7);
   moveright(8);
     movecenter(8);
     delay(200);
  targetval = (int) convertangletotarget(137);
  maestro.setTarget(7, targetval);
  delay(200);
  moveup(4);
  moveright(5);
   movecenter(5);
   delay(200);
   targetval = (int) convertangletotarget(140);
  maestro.setTarget(4, targetval);
  delay(200);
  moveup(13);
  moveright(14);
   movecenter(14);
   delay(200);
  targetval = (int) convertangletotarget(137);
  maestro.setTarget(13, targetval);
  delay(200);
    moveup(1);
    moveright(2);
    movecenter(2);
    delay(200);
  targetval = (int) convertangletotarget(137);
  maestro.setTarget(1, targetval);
  delay(200);
  moveup(16);
  moveright(17);
  movecenter(17);
  delay(200);
  targetval = (int) convertangletotarget(141);
  maestro.setTarget(16, targetval);
  delay(200);
  maestro.setTarget(10, 0);
  maestro.setTarget(7, 0);
  maestro.setTarget(4, 0);
  maestro.setTarget(13, 0);
  maestro.setTarget(1, 0);
  maestro.setTarget(16, 0);
}
//Use the w,a,s,d to move the robot.
void loop()
{
  // Parts:
  //                Foot | Leg | Shoulder
  // Front Left Leg:  0     1     2
  // Front Right Leg: 3     4     5
  // Mid Left Leg:    6     7     8
  // Mid Right Leg:   9     10     11  
  // Back Left Leg:   12    13     14
  // Back Right Leg:  15    16     17 
  
  if (Serial.available()) { 
    char ch = Serial.read();
    if (ch=='w'){
      moveforward();
      counter =0;
    } else if(ch=='s'){
      movebackwards();
      counter=0;
    } else if(ch=='a'){
      turncounterclockwise();
      counter=0;
    } else if(ch=='d'){
      turnclockwise();
      counter=0;
    }

    if(ch=='q'){
      exit(0);
    }
    used=1;
 }
 if (!Serial.available()){
    if (counter>=5 && used==1){
       cleanup(); 
       used=0;
     }
     counter=counter+1;
 }
}
