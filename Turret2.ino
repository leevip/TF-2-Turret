#include <Servo.h>

char dataIn='S';char determinant;char det;int vel = 0;
int pos_aim = 90, pos_trig = 90; int fire = 0;
Servo aim, trig;

void setup() {
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
Serial.begin(9600);
}

void loop() {


  det = check();

if (det == 'L'){
  if (pos_aim < 180){
  aim.attach(2);
  aim.write(pos_aim);
  pos_aim = pos_aim + 1;
  delay(50);
  }
  det = check();
}
if (det == 'R') {
  if (pos_aim > 0){
    aim.attach(2);
    aim.write(pos_aim);
    pos_aim = pos_aim - 1;
    delay(50);
  }
  det = check();
}
if (det == 'X'){
  fire = 1;
  det = check();
}
if (det == 'x'){
  fire = 0;
  det = check();
}
if (fire == 1) {
  if (pos_trig < 145) {
   trig.attach(3);
   trig.write(pos_trig);
   pos_trig = pos_trig + 1;
   delay(10);
//   Serial.println(pos_trig);
  }
  else  {
    trig.detach();
  }
  det = check();
  }
if (fire == 0) {
  if (pos_trig > 75) {
    trig.attach(3);
    trig.write(pos_trig);
    pos_trig = pos_trig - 1;
    delay(10);
 //   Serial.println(pos_trig);
  }
  else  {
    trig.detach();
  }
  det = check();
}
if (det == 'S') {
  aim.detach();
  
  det = check();
}


}
 int check()
 {if (Serial.available() > 0) {dataIn = Serial.read(); 
Serial.println(dataIn);
if (dataIn == 'F'){determinant = 'F';} 
else if (dataIn == 'B'){determinant = 'B';}else if (dataIn == 'L'){determinant = 'L';}
else if (dataIn == 'R'){determinant = 'R';}else if (dataIn == 'I'){determinant = 'I';} 
else if (dataIn == 'J'){determinant = 'J';}else if (dataIn == 'G'){determinant = 'G';} 
else if (dataIn == 'H'){determinant = 'H';}else if (dataIn == 'S'){determinant = 'S';}
else if (dataIn == '0'){vel = 400;}else if (dataIn == '1'){vel = 380;}
else if (dataIn == '2'){vel = 340;}else if (dataIn == '3'){vel = 320;}
else if (dataIn == '4'){vel = 280;}else if (dataIn == '5'){vel = 240;}
else if (dataIn == '6'){vel = 200;}else if (dataIn == '7'){vel = 160;}
else if (dataIn == '8'){vel = 120;}else if (dataIn == '9'){vel = 80;}
else if (dataIn == 'q'){vel = 40;}else if (dataIn == 'U'){determinant = 'U';}
else if (dataIn == 'u'){determinant = 'u';}else if (dataIn == 'W'){determinant = 'W';}
else if (dataIn == 'w'){determinant = 'w';}else if (dataIn == 'X'){determinant = 'X';}
else if (dataIn == 'x'){determinant = 'x';}}return determinant;}
