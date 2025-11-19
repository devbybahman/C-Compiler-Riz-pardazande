
#include <mega16.h>
#include <delay.h>

// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables hereint i;
int i;
int j;
int k;
typedef unsigned char byte;
flash byte char0[8]={0,0,0,0,0,0,0,0};
flash byte char1[8]={16,16,16,16,16,16,16,16};
flash byte char2[8]={24,24,24,24,24,24,24,24};
flash byte char3[8]={28,28,28,28,28,28,28,28};
flash byte char4[8]={31,31,31,31,31,31,31,31};
flash byte char5[8]={7,7,7,7,7,7,7,7};
flash byte char6[8]={3,3,3,3,3,3,3,3};
flash byte char7[8]={1,1,1,1,1,1,1,1};


void define_char(byte flash *pc, byte char_code)
{
    byte i,a;
    a=(char_code<<3 | 0x40);
    for (i=0; i<8; i++)
    {
        lcd_write_byte(a++, *pc++);
    }
}



void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00;
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);

// USART initialization
// USART disabled
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTA Bit 0
// RD - PORTA Bit 1
// EN - PORTA Bit 2
// D4 - PORTA Bit 4
// D5 - PORTA Bit 5
// D6 - PORTA Bit 6
// D7 - PORTA Bit 7
// Characters/line: 20
lcd_init(20);
define_char(char0,0);
define_char(char1,1);
define_char(char2,2);
define_char(char3,3);
define_char(char4,4);
define_char(char5,5);
define_char(char6,6);
define_char(char7,7);

while (1)
      {  
          //BA YE HALGHE NEVESHTAN:
//            J=19;
//            for(i=0;i<=9;i++)
//               {
//                 lcd_gotoxy(i,0)
//                 lcd_putchar(1) 
//                 lcd_gotoxy(j,0)
//                 lcd_putchar(7)
//                 
//                 lcd_gotoxy(i,1)
//                 lcd_putchar(1) 
//                 lcd_gotoxy(j,1)
//                 lcd_putchar(7)
//                 delay_ms(20)  
//                 .
//                 .
//                 .
//                 .
//                 ....
//               
//               }
      
      
      
      
      
      
      
      
      
      
         for(k=0; k<=9; k++)   //raftan ta nesf
          { 
            for(j=1; j<=4; j++) //HAR SOTON RO 4 GHESMAT KARDIM 
             {
               for(i=0; i<=1; i++)//SATRE 0 OR 1 
                {
                  lcd_gotoxy(k,i);
                  lcd_putchar(j);
                  lcd_gotoxy(19-k,i);
                  lcd_putchar(8-j);
                }
                delay_ms(10);   
             } 
          }
          
          for(k=9; k>=0; k--)
          { 
            for(j=4; j>=0; j--)   
             {
               for(i=0; i<=1; i++)
                {
                  lcd_gotoxy(k,i);
                  lcd_putchar(j);
                  lcd_gotoxy(19-k,i);
                  lcd_putchar(8-j);
                }
                delay_ms(10);   
             } 
          }
          
  }
}
