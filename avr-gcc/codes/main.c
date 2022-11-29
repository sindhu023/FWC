#include<avr/io.h>
#include<stdbool.h>
int main(void){

bool x,y,z=0;
DDRB = 0b00000011; //8&9 as inputs
PORTB= 0b11111100;
DDRD = 0b00000100; //2as output

//DDRB |= (1<<DDB5);


while(1)
   {
	   x= (PINB & (1<<PINB0)) == (1<<PINB0);	
	   y = (PINB & (1<<PINB1)) == (1<<PINB1);
	  
	   z = ((!x)&&(y)) || ((x)&&(!y)) ;
	   PORTD |= (z<<2);

   }

	return 0;
}
