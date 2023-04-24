#include <Wire.h>
#define expander 0x38



byte Seg_HEX_Table[16] = 
{
//ABCDEFG-
0b00000011, //0
0b10011111, //1
0b00100101, //2
0b00001101, //3
0b10011001, //4
0b01001001, //5
0b01000001, //6
0b00011111, //7
0b00000001, //8
0b00001001, //9
0b00010001, //D
0b11000001, //B
0b01100011, //C
0b10000101, //D
0b01100001, //E
0b01110001 //F
};


void setup()
{
Wire.begin(); 
Serial.begin(9600);


pinMode(3, INPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);

digitalWrite(10, 0);
digitalWrite(11, 0);
digitalWrite(12, 0);


}

int counter = 0;

void loop()
{
  Wire.beginTransmission(expander);
  Wire.write(Seg_HEX_Table[counter]);
  Wire.endTransmission();
  delay(1000);
  counter++; if(counter==16) counter= 0;
}
