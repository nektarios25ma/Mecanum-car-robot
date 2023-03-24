//Viral Science www.viralsciencecreativity.com www.youtube.com/c/viralscience
//Arduino Bluetooth App Control Mecanum Wheel Robot

#include <AFMotor.h>   //Download and Install AFMotor.h Library
//AF_DCMotor motor1(1, MOTOR12_1KHZ);
//AF_DCMotor motor2(2, MOTOR12_1KHZ);
//AF_DCMotor motor3(3, MOTOR34_1KHZ);
//AF_DCMotor motor4(4, MOTOR34_1KHZ);
   
AF_DCMotor motor1(1); //Front Left Wheel
AF_DCMotor motor2(2); //Back Left Wheel
AF_DCMotor motor3(3); //Front Right Wheel
AF_DCMotor motor4(4); //Back Right Wheel

String readString;
char c = 0;
void setup() {
  Serial.begin(9600);
//motor1.setSpeed(197);   //Set Motor Speed
//motor2.setSpeed(243);
//  motor3.setSpeed(254);
//  motor4.setSpeed(253);  
motor1.setSpeed(185);   //Set Motor Speed
motor2.setSpeed(217);
motor3.setSpeed(238);
motor4.setSpeed(253);


}
//must change LEFT<->RIGHT


void loop() {
  while(Serial.available()){
    delay(50);
  c=Serial.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    if (readString =="FORWARD"){      // MOVE FORWARD
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
    }
    if (readString =="BACKWARD"){     // MOVE BACKWARD
      motor1.run (BACKWARD);
      motor2.run (BACKWARD);
      motor3.run (BACKWARD);
      motor4.run (BACKWARD);
    }
    if (readString =="RIGHT"){     // MOVE LEFT SIDE
      motor1.run (BACKWARD);
      motor2.run (FORWARD);
      motor4.run (FORWARD);
      motor3.run (BACKWARD);
    }
    if (readString =="LEFT"){     // MOVE RIGHT SIDE
      motor1.run (FORWARD);
      motor2.run (BACKWARD);
      motor4.run (BACKWARD);
      motor3.run (FORWARD);
    }
    if (readString =="FORWARDRIGHT"){     // MOVE FORWARD LEFT FORWARDLEFT
      motor1.run (RELEASE);
      motor2.run (FORWARD);
      motor4.run (FORWARD);
      motor3.run (RELEASE);
    }
    if (readString =="FORWARDLEFT"){     // MOVE FORWARD RIGHT FORWARDRIGHT
      motor1.run (FORWARD);
      motor2.run (RELEASE);
      motor4.run (RELEASE);
      motor3.run (FORWARD);
    }
    if (readString =="BACKWARDRIGHT"){     // MOVE BACKWARD LEFT  BACKWARDLEFT
      motor1.run (BACKWARD);
      motor2.run (RELEASE);
      motor4.run (RELEASE);
      motor3.run (BACKWARD);
    }
    if (readString =="BACKWARDLEFT"){     // MOVE BACKWARD RIGHT BACKWARDRIGHT
      motor1.run (RELEASE);
      motor2.run (BACKWARD);
      motor4.run (BACKWARD);
      motor3.run (RELEASE);
    }
    if (readString =="ROTATERIGHT"){     // ROTATE LEFT SIDE ROTATELEFT
      motor1.run (BACKWARD);
      motor2.run (BACKWARD);
      motor4.run (FORWARD);
      motor3.run (FORWARD);
    }
    if (readString =="ROTATELEFT"){     // ROTATE RIGHT SIDE ROTATERIGHT
      motor1.run (FORWARD);
      motor2.run (FORWARD);
      motor4.run (BACKWARD);
      motor3.run (BACKWARD);
    }
    if (readString =="STOP"){     // STOP
      motor1.run (RELEASE);
      motor2.run (RELEASE);
      motor4.run (RELEASE);
      motor3.run (RELEASE);
    }

    readString="";
  }
}
