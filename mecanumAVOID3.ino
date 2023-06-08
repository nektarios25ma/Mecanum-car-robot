//ΝΕΚΤΑΡΙΟΣ ΚΟΥΡΑΚΗΣ-ΚΑΘΗΓΗΤΗΣ 2022-23 ΓΕΛ ΛΥΚΕΙΟ ΣΟΥΔΑΣ
//ΜΑΘΗΤΕΣ: ΔΗΜΗΤΡΑ,ΔΗΜΗΤΡΗΣ ΚΑΙ ΓΙΑΝΝΗΣ απο Α και Β λυκείου
int echoPin = 9; // Echo Pin
int trigPin = 10; // Trigger Pin
int maximumRange = 200; // Maximum range needed
int minimumRange = 2; // Minimum range needed
long duration, distance; // Duration used to calculate distance
#include <AFMotor.h>   //Download and Install AFMotor.h Library
AF_DCMotor motor1(1); //Front Left Wheel
AF_DCMotor motor2(2); //Back Left Wheel
AF_DCMotor motor3(3); //Front Right Wheel
AF_DCMotor motor4(4); //Back Right Wheel

String readString;
char c = 0;

unsigned long start_time; // Δημιούργησε μια μεταβλητή τύπου unsigned long integer με όνομα start_time

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
motor1.setSpeed(185);   //Set Motor Speed
motor2.setSpeed(217);
motor3.setSpeed(238);
motor4.setSpeed(253);
}

void loop() {
  start_time=millis();
while(Serial.available()){
    delay(50);
  c=Serial.read();
    readString+=c;
  }
  digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);

//Υπολογισμός απόστασης (σε cm) βασιζόμενοι στην ταχύτητα του ήχου.
distance = duration/58.2;
Serial.println(distance);
motor1.setSpeed(185);   //Set Motor Speed
motor2.setSpeed(217);
motor3.setSpeed(238);
motor4.setSpeed(253);

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
    if (readString =="RIGHT"){     // MOVE LEFT SIDE------
      motor1.setSpeed(50); //92 //96 //Set Motor Speed
motor2.setSpeed(237);  //227
motor3.setSpeed(130);   //100//140
motor4.setSpeed(255);
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
    if (readString =="FORWARDRIGHT"){     // MOVE FORWARD LEFT FORWARDLEFT-------
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

    if (readString =="AVOID"){      // MOVE FREE
      motor1.run (RELEASE);
      motor2.run (RELEASE);
      motor4.run (RELEASE);
      motor3.run (RELEASE);


    digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);

//Υπολογισμός απόστασης (σε cm) βασιζόμενοι στην ταχύτητα του ήχου.
distance = duration/58.2;
Serial.println(distance); 
 // start_time=millis();
while ((millis() - start_time < 20000UL) && (distance > 5 )) { // Εφόσον δεν πέρασαν 20 δευτ και η απόσταση απο εμπόδιο είναι μεγαλύτερη απο 5cm κάνε:  //UL
       
if  (distance >= 35 )
{

      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
delay(100);
digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);

//Υπολογισμός απόστασης (σε cm) βασιζόμενοι στην ταχύτητα του ήχου.
distance = duration/58.2;
}
digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);

//Υπολογισμός απόστασης (σε cm) βασιζόμενοι στην ταχύτητα του ήχου.
distance = duration/58.2;
Serial.println(distance);
if (distance <35 )
{
      motor1.run (FORWARD); //left
      motor2.run (BACKWARD);
      motor4.run (BACKWARD);
      motor3.run (FORWARD);
      delay(1700); 
     // delay(1700);
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      delay(1000);
      motor1.run (RELEASE);
      motor2.run (FORWARD);
      motor4.run (FORWARD);
      motor3.run (RELEASE); 
      delay(2200);
      digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);

//Υπολογισμός απόστασης (σε cm) βασιζόμενοι στην ταχύτητα του ήχου.
distance = duration/58.2;
 //      motor1.setSpeed(50); //92 //96 //Set Motor Speed
 //      motor2.setSpeed(237);  //227
 //      motor3.setSpeed(130);   //100//140
 //      motor4.setSpeed(255);
 //     motor1.run (BACKWARD);
//     motor2.run (FORWARD);
 //     motor4.run (FORWARD);
 //     motor3.run (BACKWARD);
 //     delay(1000);
}
digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);

//Υπολογισμός απόστασης (σε cm) βασιζόμενοι στην ταχύτητα του ήχου.
distance = duration/58.2;
Serial.println(distance);
if (distance <= 5 )
{
      motor1.run (RELEASE);
      motor2.run (RELEASE);
      motor4.run (RELEASE);
      motor3.run (RELEASE);
      delay(100);
}
digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);

//Υπολογισμός απόστασης (σε cm) βασιζόμενοι στην ταχύτητα του ήχου.
distance = duration/58.2;
Serial.println(distance);
      motor1.run (RELEASE);
      motor2.run (RELEASE);
      motor4.run (RELEASE);
      motor3.run (RELEASE);
    }
    }    
      
   Serial.println(distance); 
    readString="";
  }

     

 
}
