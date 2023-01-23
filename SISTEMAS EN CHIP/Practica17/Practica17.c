/*******************************************************
This program was created by the CodeWizardAVR V3.48b 
Automatic Program Generator
� Copyright 1998-2022 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro

Project : 
Version : 
Date    : 23/11/2022
Author  : 
Company : 
Comments: 


Chip type               : ATmega8535
Program type            : Application
AVR Core Clock frequency: 1.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 128
*******************************************************/

// I/O Registers definitions
#include <mega8535.h>
#include <delay.h>
#include <math64.h>

//char fila = 1;
//char columna = 0x01;

//char secuencia1[7] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff};
int i = 0;
int j = 0;
int k = 0;
long cont = 0;
const char secuencia3_columna[5] = {0x01,0x02,0x04,0x08,0x10};
const char secuencia3_fila[7] = {0x7e,0x7d,0x7b,0x77,0x6f,0x5f,0x3f};
//const char zero[5] = {0x41,0x2e,0x36,0x3a,0x41};
const char numeros[10][5] = {
      {0x41,0x2e,0x36,0x3a,0x41},
      {0X3F,0X3D,0X00,0X3F,0X3F},
      {0X3D,0X1E,0X2E,0X36,0X39},
      {0X5D,0X3E,0X36,0X36,0X49},
      {0X67,0X6B,0X6D,0X00,0X7F},
      {0X58,0X3A,0X3A,0X3A,0X46},
      {0X43,0X35,0X36,0X36,0X4F},
      {0X7C,0X7E,0X0E,0X76,0X78},
      {0X49,0X36,0X36,0X36,0X49},
      {0X79,0X36,0X36,0X36,0X41}
};

const char escom[5][5] = {
      {0x00,0x36,0x36,0x36,0x36},
      {0x31,0x36,0x36,0x36,0x46},
      {0X41,0X3e,0X3e,0X3e,0X3e},
      {0X41,0X3e,0X3e,0X3e,0X41},
      {0x00,0x7d,0x7b,0x7d,0x00}
};

const char escum[30] = {0x00,0x36,0x36,0x36,0x36,0x7f,0x31,0x36,0x36,0x36,0x46,0x7f,0X41,0X3e,0X3e,0X3e,0X3e,0x7f,0X41,0X3e,0X3e,0X3e,0X41,0x7f,0x00,0x7d,0x7b,0x7d,0x00,0x7f};

// Declare your global variables here

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=P Bit6=P Bit5=P Bit4=P Bit3=P Bit2=P Bit1=P Bit0=P 
PORTA=(1<<PORTA7) | (1<<PORTA6) | (1<<PORTA5) | (1<<PORTA4) | (1<<PORTA3) | (1<<PORTA2) | (1<<PORTA1) | (1<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=P Bit6=P Bit5=P Bit4=P Bit3=P Bit2=P Bit1=P Bit0=P 
PORTB=(1<<PORTB7) | (1<<PORTB6) | (1<<PORTB5) | (1<<PORTB4) | (1<<PORTB3) | (1<<PORTB2) | (1<<PORTB1) | (1<<PORTB0);

// Port C initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRD=(1<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
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

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0<<AS2;
TCCR2=(0<<WGM20) | (0<<COM21) | (0<<COM20) | (0<<WGM21) | (0<<CS22) | (0<<CS21) | (0<<CS20);
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

while (1)
      {
      // Place your code here
      
      //Primera secuencia
      PORTD = 0x00;
      for(j = 0; j < 5; j++){
            PORTC = secuencia3_columna[j];
            delay_ms(100);
      }

      //Segunda secuencia
      PORTC = 0x1f;
      for(j = 0; j < 7; j++){
            PORTD = secuencia3_fila[j];
            delay_ms(100);
      }

      //Tercera secuencia
      for(j = 0; j < 7; j++){
            PORTD = secuencia3_fila[j];
            for(i = 0; i < 5; i++){
                  PORTC = secuencia3_columna[i];
                  delay_ms(100);
            } 
      }

      //Cuarta secuencia
      for(i = 0; i < 10; ){
            for(j = 0; j < 5; j++){
                  PORTC = secuencia3_columna[j];
                  PORTD = numeros[i][j];
                  delay_ms(5);
            }
            cont++;
            if (cont == 10){
                  i++;
                  cont = 0;
            }
      }

      //Quinta secuencia
      for(i = 0; i < 25; ){
            for(j = 0; j < 5; j++){
                  PORTC = secuencia3_columna[j];
                  PORTD = escum[j+k];
                  delay_ms(5);
            }
            cont++;
            if (cont == 10){
                  i++;
                  k++;
                  cont = 0;
            }
            if(k == 25)
                  k = 0;
      }
      
      

      }
}
