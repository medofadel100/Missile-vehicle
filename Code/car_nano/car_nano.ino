/*
  Arduino Slave for Raspberry Pi Master
  i2c_slave_ard.ino
  Connects to Raspberry Pi via I2C

*/
 
// Include the Wire library for I2C
#include <Wire.h>
 

const int right1 = 3; 
const int right2 = 2; 
const int left1 = 5; 
const int left2 = 4; 
const int led = 6; 
const int alarm = 7;
const int up = 8; 
const int dowen = 9; 
const int lunch3 = 10; 
const int lunch1 = 11; 
const int lunch4 = 12; 
const int lunch2 = 13; 


const int ena = A0; //habilita o motor
const int dir = A1; //determina a direção
const int dir1= A3; //determina a direção
const int pul = A2; //executa um passo
const int intervalo = 50;   //intervalo entre as 
boolean pulso = LOW; //estado do pulso
int x=8000;
int y=8000;
int ir =0;
int IR =A7;
void setup() {
  // Join I2C bus as slave with address 8
  Wire.begin(0x8);
  Serial.begin(9600);
  // Call receiveEvent when data received                
  Wire.onReceive(receiveEvent);
 
  pinMode(led , OUTPUT);
  pinMode(alarm , OUTPUT);
  pinMode(dowen, OUTPUT);
  pinMode(up, OUTPUT);
  pinMode(lunch1, OUTPUT);
  pinMode(lunch2, OUTPUT);
  pinMode(lunch3, OUTPUT);
  pinMode(lunch4, OUTPUT);
  pinMode(right1, OUTPUT);
  pinMode(left1, OUTPUT);
  pinMode(right2, OUTPUT);
  pinMode(left2, OUTPUT);
  
  digitalWrite(led, HIGH);
  digitalWrite(right1, LOW);
  digitalWrite(right2, LOW);
  digitalWrite(alarm, LOW);
  digitalWrite(left1, LOW);
  digitalWrite(left1, LOW);
  digitalWrite(lunch1, LOW);
  digitalWrite(lunch2, LOW);
  digitalWrite(lunch3, LOW);
  digitalWrite(lunch4, LOW);
  digitalWrite(up, LOW);
  digitalWrite(dowen, LOW);


pinMode(ena, OUTPUT);
pinMode(dir, OUTPUT);
pinMode(dir1, OUTPUT);
pinMode(pul, OUTPUT);


pinMode(IR, INPUT);


}
 
// Function that executes whenever data is received from master
void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
   
    char c = Wire.read(); // receive byte as a character
  Serial.print(c);
    switch (c) {
case 0x0: //OFF
digitalWrite(alarm, LOW);
digitalWrite(right1, LOW);
digitalWrite(right2, LOW);
digitalWrite(left1, LOW);
digitalWrite(left1, LOW);
digitalWrite(lunch1, LOW);
digitalWrite(lunch2, LOW);
digitalWrite(lunch3, LOW);
digitalWrite(lunch4, LOW);
Serial.println("off");
break;
case 0x1://RIGHT
digitalWrite(right1, LOW);
digitalWrite(right2, LOW);
digitalWrite(left1, HIGH);
digitalWrite(left2, LOW);
Serial.println("Right");
break;
case 0x2: //LEFT
digitalWrite(right1, HIGH);
digitalWrite(right2, LOW);
digitalWrite(left1, LOW);
digitalWrite(left2, LOW);
Serial.println("Left");
break;
case 0x3: //FOWERWARD 
digitalWrite(right1, HIGH);
digitalWrite(right2, LOW);
digitalWrite(left1, HIGH);
digitalWrite(left2, LOW);
Serial.println("Forword");
break;
case 0x4: //BACK
digitalWrite(right1, LOW);
digitalWrite(right2, HIGH);
digitalWrite(left1, LOW);
digitalWrite(left2, HIGH);
Serial.println("Back");
break;
case 0x5: // LUNCH1
digitalWrite(alarm, HIGH);
Serial.println("Rocket 1");
delay (5000);
digitalWrite(lunch1, HIGH);
digitalWrite(alarm, LOW);
delay (50000);
digitalWrite(lunch1, LOW);

break;

case 0x6: // LUNCH2
digitalWrite(alarm, HIGH);
delay (5000);
digitalWrite(lunch2, HIGH);
digitalWrite(alarm, LOW);
Serial.println("Rocket 2");
delay (50000);
digitalWrite(lunch2, LOW);

break;

case 0x7: // LUNCH3
digitalWrite(alarm, HIGH);
delay (5000);
digitalWrite(lunch3, HIGH);
digitalWrite(alarm, LOW);
Serial.println("Rocket 3");
delay (50000);
digitalWrite(lunch3, LOW);
break;

case 0x8: // LUNCH4
digitalWrite(alarm, HIGH);
delay (5000);
digitalWrite(lunch4, HIGH);
digitalWrite(alarm, LOW);
Serial.println("Rocket 4");
delay (50000);
digitalWrite(lunch4, LOW);
break;

case 0x9: // LUNCH ALL
digitalWrite(alarm, HIGH);
delay (5000);
digitalWrite(lunch1, HIGH);
digitalWrite(lunch2, HIGH);
digitalWrite(lunch3, HIGH);
digitalWrite(lunch4, HIGH);

Serial.println("All Rockets");
delay (50000);
digitalWrite(lunch1, LOW);
digitalWrite(lunch2, LOW);
digitalWrite(lunch3, LOW);
digitalWrite(lunch4, LOW);
digitalWrite(alarm, LOW);
break;

case 0x10: // LUNCH 30S
x=10;
break;

case 0x11: // LUNCH 1M
x=11;
break;

case 0x12: // LUNCH 2M
x=12;
break;


case 0x13: // LUNCH 5M
x=13;
break;





case 0x15: // up
digitalWrite(up, HIGH);
digitalWrite(dowen, LOW);
Serial.println("up 40");
delay(600000);
digitalWrite(up,LOW);
break;


case 0x17: // MAX up
digitalWrite(up, HIGH);
digitalWrite(dowen, LOW);
Serial.println("MAX up");
delay(1100000);
Serial.println("MAX UP STOP");
digitalWrite(up, LOW);
break;

case 0x18: // MIN linear
digitalWrite(up, LOW);
digitalWrite(dowen, HIGH);
Serial.println("MAX dowen");
delay(1100000);
Serial.println("MAX DOWEN STOP");
digitalWrite(dowen, LOW);

break;
 // 8000
case 0x19: // -45
Serial.println("-45");
x=1;

break;

case 0x20: // -35
Serial.println("-35");
x=2;

break;

case 0x24: // -20
Serial.println("-20");
x=3;

break;

case 0x21: //0
Serial.println("0");
x=4;
break;

case 0x22: // 20
Serial.println("20");
x=5;

break;

case 0x25: // 35
Serial.println("35");
x=6;

break;

case 0x23: // 45
Serial.println("45");
x=7;

break;

case 0x26: // LED ON
Serial.println("LED ON");
digitalWrite(led, HIGH);

break;

case 0x27: // LED OFF
Serial.println("LED OFF");
digitalWrite(led, LOW);

break;

case 0x30: // UP ++
digitalWrite(up, HIGH);
digitalWrite(dowen, LOW);
Serial.println("up ++");
delay(5000);
break;


case 0x31: // Dowen ++
digitalWrite(up, LOW);
digitalWrite(dowen, HIGH);
Serial.println("Dowen ++");
delay(5000);
break;


case 0x32: // Right ++
Right();
Serial.println("Right ++");
delay(1000);
break;


case 0x33: // Left ++
Serial.println("Left ++");
Left();
delay(1000);
break;

}

  }
}
void loop() {
  
//if ( x < 2500 ){
//    x++;
//     Serial.println(x);
//
//digitalWrite(ena, LOW); //habilita em low invertida 
//digitalWrite(dir, HIGH); // low CW / high CCW 
//digitalWrite(dir1, LOW); // low CW / high CCW 
//digitalWrite(pul, HIGH); //borda de descida    
//pulso = !pulso; //inverte o estado da variável
//digitalWrite(pul, pulso); //atribui o novo estado à porta
//delayMicroseconds(intervalo); 
//
//}
//else if ( y< 2500 ){
//    y++;
//     Serial.println(x);
//
//digitalWrite(ena, LOW); //habilita em low invertida 
//digitalWrite(dir, LOW); // low CW / high CCW 
//digitalWrite(dir1, HIGH); // low CW / high CCW 
//digitalWrite(pul, HIGH); //borda de descida    
//pulso = !pulso; //inverte o estado da variável
//digitalWrite(pul, pulso); //atribui o novo estado à porta
//delayMicroseconds(intervalo); 
//
//}
if ( x == 1){
   
   
  
  if(ir==3){
    Stop();
    delay(3000);
    ir=0;
    x=50;
    Serial.println("Stop");
  }
  else if (ir < 3){
    Right();
   // Serial.println("Right");
   if( analogRead(A7) <= 800){
    Serial.println("ir HIGH");
    if ( analogRead(A7) >= 800){
      Serial.println("ir LOW");
      ir++;
    Serial.println("ir count");
    Serial.println(ir);
    
    }
  }}
    
}
else if ( x == 2){
   
   
  
  if(ir==2){
    Stop();
    delay(3000);
    ir=0;
    x=50;
    Serial.println("Stop");
  }
  else if (ir < 2){
    Right();
   // Serial.println("Right");
   if( analogRead(A7) <= 800){
    Serial.println("ir HIGH");
    if ( analogRead(A7) >= 800){
      Serial.println("ir LOW");
      ir++;
    Serial.println("ir count");
    Serial.println(ir);
    
    }
  }}
    
}

else if ( x == 3){
   
   
  
  if(ir==1){
    Stop();
    delay(3000);
    ir=0;
    x=50;
    Serial.println("Stop");
  }
  else if (ir < 1){
    Right();
   // Serial.println("Right");
   if( analogRead(A7) <= 800){
    Serial.println("ir HIGH");
    if ( analogRead(A7) >= 800){
      Serial.println("ir LOW");
      ir++;
    Serial.println("ir count");
    Serial.println(ir);
    
    }
  }}
    
}

else if ( x == 5){
   
   
  
  if(ir==1){
    Stop();
    delay(3000);
    ir=0;
    x=50;
    Serial.println("Stop");
  }
  else if (ir < 1){
    Left();
   // Serial.println("Right");
   if( analogRead(A7) <= 800){
    Serial.println("ir HIGH");
    if ( analogRead(A7) >= 800){
      Serial.println("ir LOW");
      ir++;
    Serial.println("ir count");
    Serial.println(ir);
    
    }
  }}
    
}

else if ( x == 6){
   
   
  
  if(ir==2){
    Stop();
    delay(3000);
    ir=0;
    x=50;
    Serial.println("Stop");
  }
  else if (ir < 2){
    Left();
   // Serial.println("Right");
   if( analogRead(A7) <= 800){
    Serial.println("ir HIGH");
    if ( analogRead(A7) >= 800){
      Serial.println("ir LOW");
      ir++;
    Serial.println("ir count");
    Serial.println(ir);
    
    }
  }}
    
}

else if ( x == 7){
   
   
  
  if(ir==3){
    Stop();
    delay(3000);
    ir=0;
    x=50;
    Serial.println("Stop");
  }
  else if (ir < 3){
    Left();
   // Serial.println("Right");
   if( analogRead(A7) <= 800){
    Serial.println("ir HIGH");
    if ( analogRead(A7) >= 800){
      Serial.println("ir LOW");
      ir++;
    Serial.println("ir count");
    Serial.println(ir);
    
    }
  }}
    
}
else if ( x==10){
  Serial.println("Rocket 30");
digitalWrite(alarm, HIGH);
digitalWrite(lunch1, HIGH);

delay (3000);
digitalWrite(lunch1, HIGH);
Serial.println("Rocket1");
delay (3000);
digitalWrite(lunch2, HIGH);
Serial.println("Rocket2");
delay (3000);
digitalWrite(lunch3, HIGH);
Serial.println("Rocket3");
delay (3000);
digitalWrite(lunch4, HIGH);
Serial.println("Rocket4");
delay (1000);
digitalWrite(alarm, LOW);
digitalWrite(lunch1, LOW);
digitalWrite(lunch2, LOW);
digitalWrite(lunch3, LOW);
digitalWrite(lunch4, LOW);
x=50;
}
else if ( x==11){
  Serial.println("Rocket 1m");
digitalWrite(alarm, HIGH);
digitalWrite(lunch1, HIGH);

delay (600000);
digitalWrite(lunch1, HIGH);
Serial.println("Rocket1");
delay (600000);
digitalWrite(lunch2, HIGH);
digitalWrite(lunch1, LOW);
Serial.println("Rocket2");
delay (60000);
digitalWrite(lunch3, HIGH);
digitalWrite(lunch2, LOW);
Serial.println("Rocket3");
delay (600000);
digitalWrite(lunch4, HIGH);
digitalWrite(lunch2, LOW);
Serial.println("Rocket4");
delay (60000);

digitalWrite(alarm, LOW);
digitalWrite(lunch4, LOW);
x=50;
}

else if ( x==12){
  Serial.println("Rocket 2m");
digitalWrite(alarm, HIGH);
digitalWrite(lunch1, HIGH);

delay (1200000);
digitalWrite(lunch1, HIGH);
Serial.println("Rocket1");
delay (1200000);
digitalWrite(lunch2, HIGH);
digitalWrite(lunch1, LOW);
Serial.println("Rocket2");
delay (120000);
digitalWrite(lunch3, HIGH);
digitalWrite(lunch2, LOW);
Serial.println("Rocket3");
delay (1200000);
digitalWrite(lunch4, HIGH);
digitalWrite(lunch3, LOW);
Serial.println("Rocket4");
delay (1000);
digitalWrite(alarm, LOW);


digitalWrite(lunch4, LOW);
x=50;
}

else if ( x==13){
  Serial.println("Rocket 5m");
digitalWrite(alarm, HIGH);
digitalWrite(lunch1, HIGH);

delay (3000000);
digitalWrite(lunch1, HIGH);
Serial.println("Rocket1");
delay (3000000);
digitalWrite(lunch2, HIGH);
Serial.println("Rocket2");
delay (3000000);
digitalWrite(lunch3, HIGH);
Serial.println("Rocket3");
delay (3000000);
digitalWrite(lunch4, HIGH);
Serial.println("Rocket4");

digitalWrite(alarm, LOW);
digitalWrite(lunch1, LOW);
digitalWrite(lunch2, LOW);
digitalWrite(lunch3, LOW);
digitalWrite(lunch4, LOW);
x=50;
}
}
void Stop(){
digitalWrite(dir, LOW); // low CW / high CCW 
digitalWrite(dir1, LOW); // low CW / high CCW 
digitalWrite(pul, LOW); //borda de descida  
}
void Right(){
digitalWrite(ena, LOW); //habilita em low invertida 
digitalWrite(dir, HIGH); // low CW / high CCW 
digitalWrite(dir1, LOW); // low CW / high CCW 
digitalWrite(pul, HIGH); //borda de descida    
pulso = !pulso; //inverte o estado da variável
digitalWrite(pul, pulso); //atribui o novo estado à porta
delayMicroseconds(intervalo); 
Serial.println("Right Void");

}

void Left(){
digitalWrite(ena, LOW); //habilita em low invertida 
digitalWrite(dir, LOW); // low CW / high CCW 
digitalWrite(dir1, HIGH); // low CW / high CCW 
digitalWrite(pul, HIGH); //borda de descida    
pulso = !pulso; //inverte o estado da variável
digitalWrite(pul, pulso); //atribui o novo estado à porta
delayMicroseconds(intervalo);   
}
