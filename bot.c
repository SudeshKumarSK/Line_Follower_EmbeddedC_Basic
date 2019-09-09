#include<avr/io.h>
#include<util/delay.h>
int main()
{

DDRD=0b00000000;
DDRB=0b11111111;
PORTD=0b11111111;
int c;
while(1)
{
c=PIND;
if(c==0b11111010)     //right and left sensor is on white.
PORTB=0b00001010;

if(c==0b11111101)     //if center pin senses an obstacle.
{
PORTB=0b00001010;     //the robot reverses.
_delay_ms(300);

 PORTB=0b00001001;    //robot turns right.
_delay_ms(300);

PORTB=0b00001010;     //robot moves forward.
_delay_ms(300);

PORTB=0b00000110;    //robot turns left.
_delay_ms(300);

PORTB=0b00001010;    //robot moves further.
_delay_ms(200);

PORTB=0b00000110;    //robot moves right.
}

if(c==0b11111111)     //Both the sensors sense black.
{
PORTB=0b00001001;     //robot should turn right and move forward.
_delay_ms(300);
PORTB=0b00001010;
}

if(c==0b11111110)     //left sensor senses black line.
{
PORTB=0b00000110;     //robot turns left and moves forward.
_delay_ms(300);
PORTB=0b00000101;
}

if(c==0b11111011)     //right sensor is on black line.
{
PORTB=0b00001001;     //robot turns right and moves forward.
_delay_ms(300);
PORTB=0b00001010;
}
}

}
