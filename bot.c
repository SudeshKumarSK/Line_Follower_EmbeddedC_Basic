#include<avr/io.h>
#include<util/delay.h>
void main()
{

DDRD=0b00000000; //PORTD of ATMEGA16 is input
DDRB=0b11111111; //PORTB is output
PORTD=0b11111111; //Pulling up PORTD to avoid floating values
int c;
 while(1)
 {
   c=PIND;  //Reading PORTD and storing in variable c

   if(c==0b11111010)     //right and left sensor is on white.
       PORTB=0b00001010;

   if(c==0b11111101)     //if center pin senses an obstacle.
     {
       PORTB=0b00010000;     //Robot stops and buzzer gets high
     }

   if(c==0b11111111)     //Both the sensors sense black.
     {
      PORTB=0b00011010;     //Move forward and buzzer gets high
     }

   if(c==0b11111110)     //left sensor senses black line.
     {
       PORTB=0b00000110;     //robot turns left 
     }

   if(c==0b11111011)     //right sensor is on black line.
      {
        PORTB=0b00001001;     //robot turns right 
      }

 }
}
