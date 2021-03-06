// Include the Wire library for I2C
#include <Wire.h>
#include <VirtualWire.h>
 int transmit ;
 int x =50;
// LED on pin 13
const int buzzer = 3;
const int viber = 4;  
int VRx = A0;
int VRy = A1;
int SW = 5;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;
int z=0;
void setup() {
  Serial.begin(9600);
  // Join I2C bus as slave with address 8
  Wire.begin(0x10);
  
  // Call receiveEvent when data received                
  Wire.onReceive(receiveEvent);
   vw_setup(2000);
  // Setup pin 13 as output and turn LED off
  pinMode(buzzer, OUTPUT);
  pinMode(viber, OUTPUT);
  digitalWrite(buzzer, LOW);
  digitalWrite(viber, LOW);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
}
 
// Function that executes whenever data is received from master
void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);
        switch (c) {
case 0x0: //OFF
x=0;
Serial.println("off");
break;
case 0x1://RIGHT
x=1;
Serial.println("Right");
break;
case 0x2: //LEFT
x=2;
break;
case 0x3: //FOWERWARD 
x=3;
Serial.println("Forword");
break;
case 0x4: //BACK
 x=4;
Serial.println("Back");
break;
case 0x5: // LUNCH1
Serial.println("Rocket 1");
x=5;
break;

case 0x6: // LUNCH2
Serial.println("Rocket 2");
x=6;
break;

case 0x7: // LUNCH3
Serial.println("Rocket 3");
x=7;
break;

case 0x8: // LUNCH4
Serial.println("Rocket 4");
x=8;
break;

case 0x9: // LUNCH ALL
Serial.println("All Rockets");
x=9;
break;

case 0x10: // LUNCH 30S
Serial.println("Rocket 30s");
x=10;
break;

case 0x11: // LUNCH 1M
Serial.println("Rocket 1m");
x=11;
break;

case 0x12: // LUNCH 2M
Serial.println("Rocket 2m");
x=12;
break;

case 0x13: // LUNCH 5M
Serial.println("Rocket 5m");
x=13;
break;

case 0x15: // up
x=15;
Serial.println("UP");
break;


case 0x17: // MAX up
x=17;
Serial.println("MAX up");
break;

case 0x18: // MIN linear
x=18;
Serial.println("MAX dowen");
break;
 // 8000
case 0x19: // -90
x=19;
Serial.println("-90");
break;

case 0x20: // -60
x=20;
Serial.println("-60");
break;

case 0x24: // -30
x=24;
Serial.println("-30");
break;

case 0x21: //0
x=21;
Serial.println("0");
break;

case 0x22: // 30
x=22;
Serial.println("30");
break;

case 0x25: // 60
x=25;
Serial.println("60");
break;

case 0x23: // 90
x=23;
Serial.println("90");
break;

case 0x26: // LED ON
x=26;
Serial.println("LED ON");
break;

case 0x27: // LED OFF
x=27;
Serial.println("LED OFF");
break;

case 0x28: // viberation
x=28;
break;

case 0x29: // viberation
x=29;
break;

}
    
    }
  }

void loop() {
  
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);

  
  Serial.print("x= ");
  Serial.println(x);
        switch (x) {
case 0: //OFF
transmit = 0;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
Serial.println("off");
break;
case 1://RIGHT
transmit = 1;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
Serial.println("Right");
break;
case 2: //LEFT
transmit = 2;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
break;
case 3: //FOWERWARD 
 transmit = 3;
vw_send((byte *) &transmit, sizeof(transmit)); 
  vw_wait_tx(); 
Serial.println("Forword");
break;
case 4: //BACK
 transmit = 4;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
Serial.println("Back");
break;
case 5: // LUNCH1
Serial.println("Rocket 1");
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
transmit = 5;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
break;

case 6: // LUNCH2
Serial.println("Rocket 2");
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
 transmit = 6;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
break;

case 7: // LUNCH3
Serial.println("Rocket 3");
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
 transmit = 7;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
break;

case 8: // LUNCH4
Serial.println("Rocket 4");
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
 transmit = 8;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
break;

case 9: // LUNCH ALL
Serial.println("All Rockets");
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
 transmit = 9;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
break;

case 10: // LUNCH 30S
Serial.println("Rocket 30s");
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
 transmit = 10;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
break;

case 11: // LUNCH 1M
Serial.println("Rocket 1m");
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
transmit = 11;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
break;

case 12: // LUNCH 2M
Serial.println("Rocket 2m");
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
 transmit = 12;
vw_send((byte *) &transmit, sizeof(transmit)); 
  vw_wait_tx(); 
break;

case 13: // LUNCH 5M
Serial.println("Rocket 5m");
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
 transmit = 14;
vw_send((byte *) &transmit, sizeof(transmit)); 
  vw_wait_tx(); 
break;

case 15: // up
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
transmit = 15;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
Serial.println("UP");
break;


case 17: // MAX up
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
 transmit = 17;
vw_send((byte *) &transmit, sizeof(transmit)); 
  vw_wait_tx(); 
Serial.println("MAX up");
break;

case 18: // MIN linear
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
 transmit = 18;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
Serial.println("MAX dowen");
break;
 // 8000
case 19: // -90
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
 transmit = 19;
vw_send((byte *) &transmit, sizeof(transmit)); 
  vw_wait_tx(); 
Serial.println("-90");
break;

case 20: // -60
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
 transmit = 20;
vw_send((byte *) &transmit, sizeof(transmit)); 
  vw_wait_tx(); 
Serial.println("-60");
break;

case 24: // -30
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
 transmit = 24;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
Serial.println("-30");
break;

case 21: //0
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
 transmit = 21;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
Serial.println("0");
break;

case 22: // 30
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
 transmit = 22;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
Serial.println("30");
break;

case 25: // 60
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
 transmit = 25;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
Serial.println("60");
break;

case 23: // 90
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
 transmit = 23;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
Serial.println("90");
break;

case 26: // LED ON
transmit = 26;
vw_send((byte *) &transmit, sizeof(transmit));
  vw_wait_tx(); 
Serial.println("LED ON");
break;

case 27: // LED OFF

 transmit = 27;
vw_send((byte *) &transmit, sizeof(transmit)); 
  vw_wait_tx(); 
Serial.println("LED OFF");
break;

case 28: // viberation
Serial.println("LED OFF");
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
delay(500);
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
break;

case 29: // viberation
Serial.println("LED OFF");
digitalWrite(buzzer, HIGH);
digitalWrite(viber, HIGH);
delay(500);
digitalWrite(buzzer, LOW);
digitalWrite(viber, LOW);
break;

}
//
//if (mapX>=450){
//    Serial.println("Up");
//    Wire.beginTransmission(8); // transmit to device #8
//    Wire.write("0x30");        // send 30
//    Wire.endTransmission();    // stop transmitting
//    
//  }
//  else if (mapX<= 390){
//    Serial.println("Dowen");
//    Wire.beginTransmission(8); // transmit to device #8
//    Wire.write("0x31");        // send 31
//    Wire.endTransmission();    // stop transmitting
//  }
//  else if (mapY >= 500){
//    Serial.println("Righ");
//    Wire.beginTransmission(8); // transmit to device #8
//    Wire.write("0x32");        // send 32
//    Wire.endTransmission();    // stop transmitting
//  }
//  else if (mapY <= 496){
//    Serial.println("Left");
//    Wire.beginTransmission(8); // transmit to device #8
//    Wire.write("0x33");        // send 33
//    Wire.endTransmission();    // stop transmitting
//  }
  

}
