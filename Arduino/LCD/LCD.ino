#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(10, 9, 5, 4, 3, 2);  //Create Liquid Crystal Object called LCD
int myCounter=0;  //declare your variable myCounter and set to 0
 
void setup() {
 
LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD
LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
LCD.print("My Timer:");  //Print Message on First Row
}
 
void loop() {
  for (myCounter=1; myCounter<=10; myCounter=myCounter+1) {
     LCD.setCursor(0,1); //Go to 1st column(column 0) and 2nd row(row 1)
     LCD.print(myCounter); 
     LCD.print(" Seconds");  
     delay(1000);
    }
 
  for (myCounter=10;myCounter>=0;myCounter=myCounter-1) {
     LCD.setCursor(0,1); //Go to 1st column(column 0) and 2nd row(row 1)
     LCD.print(myCounter); 
     LCD.print(" Seconds");  
     delay(1000);
  }  
}

