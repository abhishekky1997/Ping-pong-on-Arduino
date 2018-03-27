// This code is Developed by Raebel Christo.
// This code is simple as compared other complicated large programs
// on the internet.
//
// You can have fun with this ping pong game code.
// If you have any problems with the game, please email me at raebel.christo@yahoo.com
// Remember, you need an 8x8 LED Matrix and the LedControl library to be able to use it.

 
#include<LedControl.h>
LedControl lc = LedControl(12,11,10,1);
int ButtonL1=2; // player 1 Left button on pin 2
int ButtonR1=3; // player 1 Right button on pin 3
int ButtonL2=4; // player 2 Left button on pin 4
int ButtonR2=5; // player 2 Right button on pin 5
int x = 2; // Ball x coordinate
int y = 4; // Ball y coordinate
boolean gravity = true; // Makes the ball go up and down
boolean wind = false; // Makes the ball go right and left
int p1lx = 3;
int p1rx = 4;
int p2lx = 3;
int p2rx = 4;

byte New[]= {
  B00000000,
  B01111110,
  B00010010,
  B00011110,
  B00000000,
  B01111110,
  B01000000,
  B01000000
};

void setup(){
  pinMode(ButtonL1,INPUT);
  pinMode(ButtonR1,INPUT);
  pinMode(ButtonL2,INPUT);
  pinMode(ButtonR2,INPUT);
  lc.shutdown(0,false);
  lc.setIntensity(0,3);
  lc.clearDisplay(0);
  newGame();
}

void loop(){
  lc.setLed(0,x,y,true);
  lc.setLed(0,p1lx,0,true);
  lc.setLed(0,p1rx,0,true);
  lc.setLed(0,p2lx,7,true);
  lc.setLed(0,p2rx,7,true);
  delay(300);
  if(digitalRead(ButtonL1) == HIGH){
    p1lx--;
    p1rx--;
  }
  if(digitalRead(ButtonR1) == HIGH){
    p1lx++;
    p1rx++;
  }
  if(digitalRead(ButtonL2) == HIGH){
    p2lx--;
    p2rx--;
  }
  if(digitalRead(ButtonR2) == HIGH){
    p2lx++;
    p2rx++;
  }
  if(y>5){
    if(x == p2rx && y==6){
   gravity = true;
    }
    if(x == p2lx && y==6){
      gravity = true;
    }
    if(wind == false && x == p2lx){wind = true;}
    if(wind == true && x == p2rx){wind = false;}
  }
  if(x<1){wind = false;}
  if(wind == false){
    x++;
  }
  if(x>7){wind = true; x--;}
  if(wind == true){
    x--;
  }
 
  if(gravity == false){
    y++;
  }
  if(gravity == true){
    y--;
  }
  if(y==-1 || y==8){
    delay(100);
    x=2;
    y=4;
    p1lx = 3;
    p1rx = 4;
    p2rx = 4;
    p2lx = 3;
    Fail();
  }
  if(y<2){
    if(x == p1rx && y==1){
   gravity = false;
    }
    if(x == p1lx && y==1){
      gravity = false;
    }
    if(wind == false && x == p1lx){wind = true;}
    if(wind == true && x == p1rx){wind = false;}
  }
  
  lc.clearDisplay(0);
}

void Fail(){
  lc.clearDisplay(0);
  lc.setColumn(0,7,B11111111);
  delay(10);
  lc.setColumn(0,6,B11111111);
  delay(10);
  lc.setColumn(0,5,B11111111);
  delay(10);
  lc.setColumn(0,4,B11111111);
  delay(10);
  lc.setColumn(0,3,B11111111);
  delay(10);
  lc.setColumn(0,2,B11111111);
  delay(10);
  lc.setColumn(0,1,B11111111);
  delay(10);
  lc.setColumn(0,0,B11111111);
  delay(10);
  lc.setColumn(0,7,B00000000);
  delay(10);
  lc.setColumn(0,6,B00000000);
  delay(10);
  lc.setColumn(0,5,B00000000);
  delay(10);
  lc.setColumn(0,4,B00000000);
  delay(10);
  lc.setColumn(0,3,B00000000);
  delay(10);
  lc.setColumn(0,2,B00000000);
  delay(10);
  lc.setColumn(0,1,B00000000);
  delay(10);
  lc.setColumn(0,0,B00000000);
  delay(10);
}

void snew(){
  for(int i=0;i<8;i++){
    lc.setRow(0,i,New[i]);
  }
}

void newGame(){
  snew();
  while(digitalRead(ButtonL1) == false){
    ;
  }
}

