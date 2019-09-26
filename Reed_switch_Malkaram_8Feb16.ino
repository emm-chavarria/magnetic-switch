/* This program reads biogas tipping devices and counts pivoting events logging data every 15 minutes.
 *  When the magnet is within actuation range the switch is open.
 *  
 *  These biogas totalizers keep the magnetic switch regularly open. A pivoting event occurs when the magnet
 *  is removed. After each pivoting event, it takes about 3 seconds for the biogas container to go back to 
 *  its initial position.
 *  
 *  For logging data in the host computer Processing code is used sending data via serial communication.
 *  
 *  
 *  Created by E. Chavarria 18/Nov/2015
 *  Edited by E. Chavarria and S. Malkaram 9/Feb/2016
 */


// Define where the sensors are connected
const int counter1 = 12;
const int counter2 = 11;
const int counter3 = 10;
const int counter4 = 9;
const int counter5 = 8;
const int counter6 = 7;

int totalizer1 = 0;
int totalizer2 = 0;
int totalizer3 = 0;
int totalizer4 = 0;
int totalizer5 = 0;
int totalizer6 = 0;
int inByte = 0;
unsigned long previous_timer1 = 0;
unsigned long previous_timer2 = 0;
unsigned long previous_timer3 = 0;
unsigned long previous_timer4 = 0;
unsigned long previous_timer5 = 0;
unsigned long previous_timer6 = 0;

void setup() {
  pinMode(counter1, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  establishContact();
}

void loop() {
  digitalWrite(13, LOW); // Built-in LED turns ON when biogas container pivots
  unsigned long timer1 = millis();
  unsigned long timer2 = timer1;
  unsigned long timer3 = timer1;
  unsigned long timer4 = timer1;
  unsigned long timer5 = timer1;
  unsigned long timer6 = timer1;


  //******* Counter 1 **********
  if(digitalRead(counter1) == LOW){ // If magnet is far away
    digitalWrite(13, HIGH); // Built-in LED turns ON when biogas container pivots
    if(timer1 - previous_timer1 >= 1500){ // Wait for 1.5 seconds
         previous_timer1 = timer1;
      totalizer1++; // Count one pivoting event
   }
  }

  //******* Counter 2 **********
  if(digitalRead(counter2) == LOW){ // If magnet is far away
//    digitalWrite(13, HIGH); // Built-in LED turns ON when biogas container pivots
    if(timer2 - previous_timer2 >= 1500){ // Wait for 1.5 seconds
         previous_timer2 = timer2;
      totalizer2++; // Count one pivoting event
   }
  }
  
  //******* Counter 3 **********
  if(digitalRead(counter3) == LOW){ // If magnet is far away
//   digitalWrite(13, HIGH); // Built-in LED turns ON when biogas container pivots
   if(timer3 - previous_timer3 >= 1500){ // Wait for 1.5 seconds
         previous_timer3 = timer3;
      totalizer3++; // Count one pivoting event
   }
  }

    //******* Counter 4 **********
  if(digitalRead(counter4) == LOW){ // If magnet is far away
    digitalWrite(13, HIGH); // Built-in LED turns ON when biogas container pivots
    if(timer4 - previous_timer4 >= 1500){ // Wait for 1.5 seconds
         previous_timer4 = timer4;
      totalizer4++; // Count one pivoting event
   }
  }

    //******* Counter 5 **********
  if(digitalRead(counter5) == LOW){ // If magnet is far away
    digitalWrite(13, HIGH); // Built-in LED turns ON when biogas container pivots
    if(timer5 - previous_timer5 >= 1500){ // Wait for 1.5 seconds
         previous_timer5 = timer5;
      totalizer5++; // Count one pivoting event
   }
  }

    //******* Counter 6 **********
  if(digitalRead(counter6) == LOW){ // If magnet is far away
    digitalWrite(13, HIGH); // Built-in LED turns ON when biogas container pivots
    if(timer6 - previous_timer6 >= 1500){ // Wait for 1.5 seconds
         previous_timer6 = timer6;
      totalizer6++; // Count one pivoting event
   }
  }

  // Listen to serial port, send counts and reset counters
  if(Serial.available()>0){
    inByte = Serial.read();
    Serial.print(totalizer1);
    Serial.print("\t");
    Serial.print(totalizer2);
    Serial.print("\t");
    Serial.print(totalizer3);
    Serial.print("\t");
    Serial.print(totalizer4);
    Serial.print("\t");
    Serial.print(totalizer5);
    Serial.print("\t");
    Serial.println(totalizer6);
    totalizer1 = 0;
    totalizer2 = 0;
    totalizer3 = 0;
    totalizer4 = 0;
    totalizer5 = 0;
    totalizer6 = 0;
    }
    delay(10);
}


// Establishes first contact by sending an "A" until host computer replies with an "A" 
void establishContact(){
  while(Serial.available() <= 0){
    Serial.println("A");
    delay(100);
  }
}

