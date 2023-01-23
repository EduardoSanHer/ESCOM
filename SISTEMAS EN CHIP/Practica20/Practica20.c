/*******************************************************
This program was created by the CodeWizardAVR V3.48b 
Automatic Program Generator
� Copyright 1998-2022 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro

Project : 
Version : 
Date    : 08/12/2022
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
#include <stdlib.h>
#define H 8
#define W 8

struct Player {
    unsigned char col;
    unsigned char row;
};

struct Ball {
    int col;
    int row;
    int col_vel;
    int row_vel;
};

// Declare your global variables here
const char display_table[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7c,0x07,0x7f,0x6f};
unsigned char player_1_score = 0;
unsigned char player_2_score = 0;
const int BALL_SPEED = 30;
bit pause = 1; 

struct Player player_1;
struct Player player_2;
struct Ball ball;

bit cu_left_1, la_left_1, cu_left_2, la_left_2;
bit cu_right_1, la_right_1, cu_right_2, la_right_2;
bit cu_pause, la_pause;
bit cu_reset, la_reset;

void set_ball_speed(int);
void set_game();
void paint();
void paint_scoreboard();
void check_changes();
void update_ball();
void check_pause_reset();

int i, j;

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=Out Bit6=Out Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(1<<DDA7) | (1<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=0 Bit6=0 Bit5=P Bit4=P Bit3=P Bit2=P Bit1=P Bit0=P 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (1<<PORTA5) | (1<<PORTA4) | (1<<PORTA3) | (1<<PORTA2) | (1<<PORTA1) | (1<<PORTA0);

// Port B initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRB=(1<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

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

set_game();
set_ball_speed(1);


while (1)
    {   
        if (pause == 0) {
            for (j = 0; j < BALL_SPEED; j++) {
                paint();
                check_changes();
            }
            update_ball();
        }
        paint();
        check_pause_reset();
    }
}

void set_ball_speed(int speed){
    ball.col_vel = speed;
    ball.row_vel = speed;
}

void set_game(){
    player_1_score = 0;
    player_2_score = 0;
    player_1.col = 6;
    player_1.row = H - 1;

    pause = 1;

    player_2.col = 0;
    player_2.row = 0;

    ball.col = 3;
    ball.row = 3;
}


void update_ball() {
    
    ball.col += ball.col_vel;
    if (ball.col >= W || ball.col < 0) {
        ball.col_vel *= -1;
        ball.col += 2 * ball.col_vel; 
    }
    
    ball.row += ball.row_vel;
    // If the ball is in the vertical borders, check if it bounces
    if (ball.row == H - 1) {
        if (ball.col == player_1.col || ball.col == player_1.col + 1) {
            ball.row_vel *= -1;
            ball.col_vel *= (1 - 2*(rand() % 2)); 
            ball.row += ball.row_vel;
        } else {
            player_2_score++;
            ball.col = 3;
            ball.row = 3;
            ball.col_vel = -1;
            ball.row_vel = -1;
        }
    } 
    if (ball.row == 0) {
        if (ball.col == player_2.col || ball.col == player_2.col + 1) {
            ball.row_vel *= -1;
            ball.row += ball.row_vel;
            ball.col_vel *= (1 - 2*(rand() % 2));
        } else {
            player_1_score++;
            ball.col = 4;
            ball.row = 4;
            ball.row_vel = 1;
            ball.col_vel = 1;
        }
    }
    //Check if one of the players has already gotten more than 9 points, if so, the games resets
    if (player_1_score > 9 || player_2_score > 9) {
        set_game();
    }
}

void paint_scoreboard() {
    //MUX
    PORTA.6 = 0;
    PORTA.7 = 1;
    PORTB = display_table[player_2_score];
    delay_ms(1);
    //MUX
    PORTA.6 = 1;
    PORTA.7 = 0;
    PORTB = display_table[player_1_score];
    delay_ms(1);
}

void check_pause_reset() {
    cu_pause = PINA.0;
    cu_reset = PINA.1;
    
    if (cu_pause == 0 && la_pause == 1) {
        pause = ~pause;
    }
    if (cu_reset == 0 && la_reset == 1) {
        set_game();
    }
    
    la_pause = cu_pause;
    la_reset = cu_reset;
    paint_scoreboard();
}

void check_changes() {
    cu_left_1 = PINA.2;
    cu_left_2 = PINA.4; 
    cu_right_1 = PINA.3;
    cu_right_2 = PINA.5;
    
    // Checking for player_1 movement
    if (cu_left_1 == 0 && la_left_1 == 1) {
        if (player_1.col - 1 >= 0) player_1.col -= 1;
    }
    if (cu_right_1 == 0 && la_right_1 == 1) {
        player_1.col++;
        if (player_1.col > W - 2) player_1.col = W - 2;
    }
    // Checking for player 2 movement
    if (cu_left_2 == 0 && la_left_2 == 1) {
        if (player_2.col - 1 >= 0) player_2.col -= 1;
    }
    if (cu_right_2 == 0 && la_right_2 == 1) {
        player_2.col++;
        if (player_2.col > W - 2) player_2.col = W - 2;
    }
    
    la_left_1 = cu_left_1;
    la_left_2 = cu_left_2; 
    la_right_1 = cu_right_1;
    la_right_2 = cu_right_2;
    check_pause_reset();
}

void paint() {
    const unsigned char columns_on = 0xFF;
    unsigned char curr_row = 0x00;
    for (i = 0; i < W; i++) {
        //PORTD = columns_on & ~(1 << i); //Protoboard
        PORTC = columns_on & ~(1 << i);   //Proteus
        curr_row = 0x00;
        if (i == player_1.col || i == player_1.col + 1) {
            curr_row |= 0x80;   
        }
        if (i == player_2.col || i == player_2.col + 1) {
            curr_row |= 0x01;   
        }
        if (i == ball.col) {
            curr_row |= (1 << ball.row);   
        }
        //PORTC = curr_row;       //Protoboard
        PORTD = curr_row;     //Proteus
        delay_ms(1);  
    } 
}
