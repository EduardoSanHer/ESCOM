
;CodeVisionAVR C Compiler V3.48b 
;(C) Copyright 1998-2022 Pavel Haiduc, HP InfoTech S.R.L.
;http://www.hpinfotech.ro

;Build configuration    : Debug
;Chip type              : ATmega8535
;Program type           : Application
;Clock frequency        : 1.000000 MHz
;Memory model           : Small
;Optimize for           : Size
;(s)printf features     : int, width
;(s)scanf features      : int, width
;External RAM size      : 0
;Data Stack size        : 128 byte(s)
;Heap size              : 0 byte(s)
;Promote 'char' to 'int': Yes
;'char' is unsigned     : Yes
;8 bit enums            : Yes
;Global 'const' stored in FLASH: Yes
;Enhanced function parameter passing: Mode 2
;Enhanced core instructions: On
;Automatic register allocation for global variables: On
;Smart register allocation: On

	#define _MODEL_SMALL_

	#pragma AVRPART ADMIN PART_NAME ATmega8535
	#pragma AVRPART MEMORY PROG_FLASH 8192
	#pragma AVRPART MEMORY EEPROM 512
	#pragma AVRPART MEMORY INT_SRAM SIZE 512
	#pragma AVRPART MEMORY INT_SRAM START_ADDR 0x60

	.LISTMAC
	.EQU UDRE=0x5
	.EQU RXC=0x7
	.EQU USR=0xB
	.EQU UDR=0xC
	.EQU SPSR=0xE
	.EQU SPDR=0xF
	.EQU EERE=0x0
	.EQU EEWE=0x1
	.EQU EEMWE=0x2
	.EQU EECR=0x1C
	.EQU EEDR=0x1D
	.EQU EEARL=0x1E
	.EQU EEARH=0x1F
	.EQU WDTCR=0x21
	.EQU MCUCR=0x35
	.EQU SPMCSR=0x37
	.EQU GICR=0x3B
	.EQU SPL=0x3D
	.EQU SPH=0x3E
	.EQU SREG=0x3F

	.DEF R0X0=R0
	.DEF R0X1=R1
	.DEF R0X2=R2
	.DEF R0X3=R3
	.DEF R0X4=R4
	.DEF R0X5=R5
	.DEF R0X6=R6
	.DEF R0X7=R7
	.DEF R0X8=R8
	.DEF R0X9=R9
	.DEF R0XA=R10
	.DEF R0XB=R11
	.DEF R0XC=R12
	.DEF R0XD=R13
	.DEF R0XE=R14
	.DEF R0XF=R15
	.DEF R0X10=R16
	.DEF R0X11=R17
	.DEF R0X12=R18
	.DEF R0X13=R19
	.DEF R0X14=R20
	.DEF R0X15=R21
	.DEF R0X16=R22
	.DEF R0X17=R23
	.DEF R0X18=R24
	.DEF R0X19=R25
	.DEF R0X1A=R26
	.DEF R0X1B=R27
	.DEF R0X1C=R28
	.DEF R0X1D=R29
	.DEF R0X1E=R30
	.DEF R0X1F=R31

	.EQU __SRAM_START=0x0060
	.EQU __SRAM_END=0x025F
	.EQU __DSTACK_SIZE=0x0080
	.EQU __HEAP_SIZE=0x0000
	.EQU __CLEAR_SRAM_SIZE=__SRAM_END-__SRAM_START+1

	.EQU __FLASH_PAGE_SIZE=0x20

	.MACRO __CPD1N
	CPI  R30,LOW(@0)
	LDI  R26,HIGH(@0)
	CPC  R31,R26
	LDI  R26,BYTE3(@0)
	CPC  R22,R26
	LDI  R26,BYTE4(@0)
	CPC  R23,R26
	.ENDM

	.MACRO __CPD2N
	CPI  R26,LOW(@0)
	LDI  R30,HIGH(@0)
	CPC  R27,R30
	LDI  R30,BYTE3(@0)
	CPC  R24,R30
	LDI  R30,BYTE4(@0)
	CPC  R25,R30
	.ENDM

	.MACRO __CPWRR
	CP   R@0,R@2
	CPC  R@1,R@3
	.ENDM

	.MACRO __CPWRN
	CPI  R@0,LOW(@2)
	LDI  R30,HIGH(@2)
	CPC  R@1,R30
	.ENDM

	.MACRO __ADDB1MN
	SUBI R30,LOW(-@0-(@1))
	.ENDM

	.MACRO __ADDB2MN
	SUBI R26,LOW(-@0-(@1))
	.ENDM

	.MACRO __ADDW1MN
	SUBI R30,LOW(-@0-(@1))
	SBCI R31,HIGH(-@0-(@1))
	.ENDM

	.MACRO __ADDW2MN
	SUBI R26,LOW(-@0-(@1))
	SBCI R27,HIGH(-@0-(@1))
	.ENDM

	.MACRO __ADDW1FN
	SUBI R30,LOW(-2*@0-(@1))
	SBCI R31,HIGH(-2*@0-(@1))
	.ENDM

	.MACRO __ADDD1FN
	SUBI R30,LOW(-2*@0-(@1))
	SBCI R31,HIGH(-2*@0-(@1))
	SBCI R22,BYTE3(-2*@0-(@1))
	.ENDM

	.MACRO __ADDD1N
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	SBCI R22,BYTE3(-@0)
	SBCI R23,BYTE4(-@0)
	.ENDM

	.MACRO __ADDD2N
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	SBCI R24,BYTE3(-@0)
	SBCI R25,BYTE4(-@0)
	.ENDM

	.MACRO __SUBD1N
	SUBI R30,LOW(@0)
	SBCI R31,HIGH(@0)
	SBCI R22,BYTE3(@0)
	SBCI R23,BYTE4(@0)
	.ENDM

	.MACRO __SUBD2N
	SUBI R26,LOW(@0)
	SBCI R27,HIGH(@0)
	SBCI R24,BYTE3(@0)
	SBCI R25,BYTE4(@0)
	.ENDM

	.MACRO __ANDBMNN
	LDS  R30,@0+(@1)
	ANDI R30,LOW(@2)
	STS  @0+(@1),R30
	.ENDM

	.MACRO __ANDWMNN
	LDS  R30,@0+(@1)
	ANDI R30,LOW(@2)
	STS  @0+(@1),R30
	LDS  R30,@0+(@1)+1
	ANDI R30,HIGH(@2)
	STS  @0+(@1)+1,R30
	.ENDM

	.MACRO __ANDD1N
	ANDI R30,LOW(@0)
	ANDI R31,HIGH(@0)
	ANDI R22,BYTE3(@0)
	ANDI R23,BYTE4(@0)
	.ENDM

	.MACRO __ANDD2N
	ANDI R26,LOW(@0)
	ANDI R27,HIGH(@0)
	ANDI R24,BYTE3(@0)
	ANDI R25,BYTE4(@0)
	.ENDM

	.MACRO __ORBMNN
	LDS  R30,@0+(@1)
	ORI  R30,LOW(@2)
	STS  @0+(@1),R30
	.ENDM

	.MACRO __ORWMNN
	LDS  R30,@0+(@1)
	ORI  R30,LOW(@2)
	STS  @0+(@1),R30
	LDS  R30,@0+(@1)+1
	ORI  R30,HIGH(@2)
	STS  @0+(@1)+1,R30
	.ENDM

	.MACRO __ORD1N
	ORI  R30,LOW(@0)
	ORI  R31,HIGH(@0)
	ORI  R22,BYTE3(@0)
	ORI  R23,BYTE4(@0)
	.ENDM

	.MACRO __ORD2N
	ORI  R26,LOW(@0)
	ORI  R27,HIGH(@0)
	ORI  R24,BYTE3(@0)
	ORI  R25,BYTE4(@0)
	.ENDM

	.MACRO __DELAY_USB
	LDI  R24,LOW(@0)
__DELAY_USB_LOOP:
	DEC  R24
	BRNE __DELAY_USB_LOOP
	.ENDM

	.MACRO __DELAY_USW
	LDI  R24,LOW(@0)
	LDI  R25,HIGH(@0)
__DELAY_USW_LOOP:
	SBIW R24,1
	BRNE __DELAY_USW_LOOP
	.ENDM

	.MACRO __GETW1P
	LD   R30,X+
	LD   R31,X
	SBIW R26,1
	.ENDM

	.MACRO __GETD1S
	LDD  R30,Y+@0
	LDD  R31,Y+@0+1
	LDD  R22,Y+@0+2
	LDD  R23,Y+@0+3
	.ENDM

	.MACRO __GETD2S
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	LDD  R24,Y+@0+2
	LDD  R25,Y+@0+3
	.ENDM

	.MACRO __GETD1P_INC
	LD   R30,X+
	LD   R31,X+
	LD   R22,X+
	LD   R23,X+
	.ENDM

	.MACRO __GETD1P_DEC
	LD   R23,-X
	LD   R22,-X
	LD   R31,-X
	LD   R30,-X
	.ENDM

	.MACRO __PUTDP1
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __PUTDP1_DEC
	ST   -X,R23
	ST   -X,R22
	ST   -X,R31
	ST   -X,R30
	.ENDM

	.MACRO __PUTD1S
	STD  Y+@0,R30
	STD  Y+@0+1,R31
	STD  Y+@0+2,R22
	STD  Y+@0+3,R23
	.ENDM

	.MACRO __PUTD2S
	STD  Y+@0,R26
	STD  Y+@0+1,R27
	STD  Y+@0+2,R24
	STD  Y+@0+3,R25
	.ENDM

	.MACRO __PUTDZ2
	STD  Z+@0,R26
	STD  Z+@0+1,R27
	STD  Z+@0+2,R24
	STD  Z+@0+3,R25
	.ENDM

	.MACRO __CLRD1S
	STD  Y+@0,R30
	STD  Y+@0+1,R30
	STD  Y+@0+2,R30
	STD  Y+@0+3,R30
	.ENDM

	.MACRO __CPD10
	SBIW R30,0
	SBCI R22,0
	SBCI R23,0
	.ENDM

	.MACRO __CPD20
	SBIW R26,0
	SBCI R24,0
	SBCI R25,0
	.ENDM

	.MACRO __ADDD12
	ADD  R30,R26
	ADC  R31,R27
	ADC  R22,R24
	ADC  R23,R25
	.ENDM

	.MACRO __ADDD21
	ADD  R26,R30
	ADC  R27,R31
	ADC  R24,R22
	ADC  R25,R23
	.ENDM

	.MACRO __SUBD12
	SUB  R30,R26
	SBC  R31,R27
	SBC  R22,R24
	SBC  R23,R25
	.ENDM

	.MACRO __SUBD21
	SUB  R26,R30
	SBC  R27,R31
	SBC  R24,R22
	SBC  R25,R23
	.ENDM

	.MACRO __ANDD12
	AND  R30,R26
	AND  R31,R27
	AND  R22,R24
	AND  R23,R25
	.ENDM

	.MACRO __ORD12
	OR   R30,R26
	OR   R31,R27
	OR   R22,R24
	OR   R23,R25
	.ENDM

	.MACRO __XORD12
	EOR  R30,R26
	EOR  R31,R27
	EOR  R22,R24
	EOR  R23,R25
	.ENDM

	.MACRO __XORD21
	EOR  R26,R30
	EOR  R27,R31
	EOR  R24,R22
	EOR  R25,R23
	.ENDM

	.MACRO __COMD1
	COM  R30
	COM  R31
	COM  R22
	COM  R23
	.ENDM

	.MACRO __MULD2_2
	LSL  R26
	ROL  R27
	ROL  R24
	ROL  R25
	.ENDM

	.MACRO __LSRD1
	LSR  R23
	ROR  R22
	ROR  R31
	ROR  R30
	.ENDM

	.MACRO __LSLD1
	LSL  R30
	ROL  R31
	ROL  R22
	ROL  R23
	.ENDM

	.MACRO __ASRB4
	ASR  R30
	ASR  R30
	ASR  R30
	ASR  R30
	.ENDM

	.MACRO __ASRW8
	MOV  R30,R31
	CLR  R31
	SBRC R30,7
	SER  R31
	.ENDM

	.MACRO __LSRD16
	MOV  R30,R22
	MOV  R31,R23
	LDI  R22,0
	LDI  R23,0
	.ENDM

	.MACRO __LSLD16
	MOV  R22,R30
	MOV  R23,R31
	LDI  R30,0
	LDI  R31,0
	.ENDM

	.MACRO __CWD1
	MOV  R22,R31
	ADD  R22,R22
	SBC  R22,R22
	MOV  R23,R22
	.ENDM

	.MACRO __CWD2
	MOV  R24,R27
	ADD  R24,R24
	SBC  R24,R24
	MOV  R25,R24
	.ENDM

	.MACRO __SETMSD1
	SER  R31
	SER  R22
	SER  R23
	.ENDM

	.MACRO __ADDW1R15
	CLR  R0
	ADD  R30,R15
	ADC  R31,R0
	.ENDM

	.MACRO __ADDW2R15
	CLR  R0
	ADD  R26,R15
	ADC  R27,R0
	.ENDM

	.MACRO __EQB12
	CP   R30,R26
	LDI  R30,1
	BREQ PC+2
	CLR  R30
	.ENDM

	.MACRO __NEB12
	CP   R30,R26
	LDI  R30,1
	BRNE PC+2
	CLR  R30
	.ENDM

	.MACRO __LEB12
	CP   R30,R26
	LDI  R30,1
	BRGE PC+2
	CLR  R30
	.ENDM

	.MACRO __GEB12
	CP   R26,R30
	LDI  R30,1
	BRGE PC+2
	CLR  R30
	.ENDM

	.MACRO __LTB12
	CP   R26,R30
	LDI  R30,1
	BRLT PC+2
	CLR  R30
	.ENDM

	.MACRO __GTB12
	CP   R30,R26
	LDI  R30,1
	BRLT PC+2
	CLR  R30
	.ENDM

	.MACRO __LEB12U
	CP   R30,R26
	LDI  R30,1
	BRSH PC+2
	CLR  R30
	.ENDM

	.MACRO __GEB12U
	CP   R26,R30
	LDI  R30,1
	BRSH PC+2
	CLR  R30
	.ENDM

	.MACRO __LTB12U
	CP   R26,R30
	LDI  R30,1
	BRLO PC+2
	CLR  R30
	.ENDM

	.MACRO __GTB12U
	CP   R30,R26
	LDI  R30,1
	BRLO PC+2
	CLR  R30
	.ENDM

	.MACRO __CPW01
	CLR  R0
	CP   R0,R30
	CPC  R0,R31
	.ENDM

	.MACRO __CPW02
	CLR  R0
	CP   R0,R26
	CPC  R0,R27
	.ENDM

	.MACRO __CPD12
	CP   R30,R26
	CPC  R31,R27
	CPC  R22,R24
	CPC  R23,R25
	.ENDM

	.MACRO __CPD21
	CP   R26,R30
	CPC  R27,R31
	CPC  R24,R22
	CPC  R25,R23
	.ENDM

	.MACRO __BSTB1
	CLT
	TST  R30
	BREQ PC+2
	SET
	.ENDM

	.MACRO __LNEGB1
	TST  R30
	LDI  R30,1
	BREQ PC+2
	CLR  R30
	.ENDM

	.MACRO __LNEGW1
	OR   R30,R31
	LDI  R30,1
	BREQ PC+2
	LDI  R30,0
	.ENDM

	.MACRO __POINTB1MN
	LDI  R30,LOW(@0+(@1))
	.ENDM

	.MACRO __POINTW1MN
	LDI  R30,LOW(@0+(@1))
	LDI  R31,HIGH(@0+(@1))
	.ENDM

	.MACRO __POINTD1M
	LDI  R30,LOW(@0)
	LDI  R31,HIGH(@0)
	LDI  R22,BYTE3(@0)
	LDI  R23,BYTE4(@0)
	.ENDM

	.MACRO __POINTW1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	.ENDM

	.MACRO __POINTD1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	LDI  R22,BYTE3(2*@0+(@1))
	LDI  R23,BYTE4(2*@0+(@1))
	.ENDM

	.MACRO __POINTB2MN
	LDI  R26,LOW(@0+(@1))
	.ENDM

	.MACRO __POINTW2MN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	.ENDM

	.MACRO __POINTD2M
	LDI  R26,LOW(@0)
	LDI  R27,HIGH(@0)
	LDI  R24,BYTE3(@0)
	LDI  R25,BYTE4(@0)
	.ENDM

	.MACRO __POINTW2FN
	LDI  R26,LOW(2*@0+(@1))
	LDI  R27,HIGH(2*@0+(@1))
	.ENDM

	.MACRO __POINTD2FN
	LDI  R26,LOW(2*@0+(@1))
	LDI  R27,HIGH(2*@0+(@1))
	LDI  R24,BYTE3(2*@0+(@1))
	LDI  R25,BYTE4(2*@0+(@1))
	.ENDM

	.MACRO __POINTBRM
	LDI  R@0,LOW(@1)
	.ENDM

	.MACRO __POINTWRM
	LDI  R@0,LOW(@2)
	LDI  R@1,HIGH(@2)
	.ENDM

	.MACRO __POINTBRMN
	LDI  R@0,LOW(@1+(@2))
	.ENDM

	.MACRO __POINTWRMN
	LDI  R@0,LOW(@2+(@3))
	LDI  R@1,HIGH(@2+(@3))
	.ENDM

	.MACRO __POINTWRFN
	LDI  R@0,LOW(@2*2+(@3))
	LDI  R@1,HIGH(@2*2+(@3))
	.ENDM

	.MACRO __GETD1N
	LDI  R30,LOW(@0)
	LDI  R31,HIGH(@0)
	LDI  R22,BYTE3(@0)
	LDI  R23,BYTE4(@0)
	.ENDM

	.MACRO __GETD2N
	LDI  R26,LOW(@0)
	LDI  R27,HIGH(@0)
	LDI  R24,BYTE3(@0)
	LDI  R25,BYTE4(@0)
	.ENDM

	.MACRO __GETB1MN
	LDS  R30,@0+(@1)
	.ENDM

	.MACRO __GETB1HMN
	LDS  R31,@0+(@1)
	.ENDM

	.MACRO __GETW1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	.ENDM

	.MACRO __GETD1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	LDS  R22,@0+(@1)+2
	LDS  R23,@0+(@1)+3
	.ENDM

	.MACRO __GETBRMN
	LDS  R@0,@1+(@2)
	.ENDM

	.MACRO __GETWRMN
	LDS  R@0,@2+(@3)
	LDS  R@1,@2+(@3)+1
	.ENDM

	.MACRO __GETWRZ
	LDD  R@0,Z+@2
	LDD  R@1,Z+@2+1
	.ENDM

	.MACRO __GETD2Z
	LDD  R26,Z+@0
	LDD  R27,Z+@0+1
	LDD  R24,Z+@0+2
	LDD  R25,Z+@0+3
	.ENDM

	.MACRO __GETB2MN
	LDS  R26,@0+(@1)
	.ENDM

	.MACRO __GETW2MN
	LDS  R26,@0+(@1)
	LDS  R27,@0+(@1)+1
	.ENDM

	.MACRO __GETD2MN
	LDS  R26,@0+(@1)
	LDS  R27,@0+(@1)+1
	LDS  R24,@0+(@1)+2
	LDS  R25,@0+(@1)+3
	.ENDM

	.MACRO __PUTB1MN
	STS  @0+(@1),R30
	.ENDM

	.MACRO __PUTW1MN
	STS  @0+(@1),R30
	STS  @0+(@1)+1,R31
	.ENDM

	.MACRO __PUTD1MN
	STS  @0+(@1),R30
	STS  @0+(@1)+1,R31
	STS  @0+(@1)+2,R22
	STS  @0+(@1)+3,R23
	.ENDM

	.MACRO __PUTB1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	RCALL __EEPROMWRB
	.ENDM

	.MACRO __PUTW1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	RCALL __EEPROMWRW
	.ENDM

	.MACRO __PUTD1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	RCALL __EEPROMWRD
	.ENDM

	.MACRO __PUTBR0MN
	STS  @0+(@1),R0
	.ENDM

	.MACRO __PUTBMRN
	STS  @0+(@1),R@2
	.ENDM

	.MACRO __PUTWMRN
	STS  @0+(@1),R@2
	STS  @0+(@1)+1,R@3
	.ENDM

	.MACRO __PUTBZR
	STD  Z+@1,R@0
	.ENDM

	.MACRO __PUTWZR
	STD  Z+@2,R@0
	STD  Z+@2+1,R@1
	.ENDM

	.MACRO __GETW1R
	MOV  R30,R@0
	MOV  R31,R@1
	.ENDM

	.MACRO __GETW2R
	MOV  R26,R@0
	MOV  R27,R@1
	.ENDM

	.MACRO __GETWRN
	LDI  R@0,LOW(@2)
	LDI  R@1,HIGH(@2)
	.ENDM

	.MACRO __PUTW1R
	MOV  R@0,R30
	MOV  R@1,R31
	.ENDM

	.MACRO __PUTW2R
	MOV  R@0,R26
	MOV  R@1,R27
	.ENDM

	.MACRO __ADDWRN
	SUBI R@0,LOW(-@2)
	SBCI R@1,HIGH(-@2)
	.ENDM

	.MACRO __ADDWRR
	ADD  R@0,R@2
	ADC  R@1,R@3
	.ENDM

	.MACRO __SUBWRN
	SUBI R@0,LOW(@2)
	SBCI R@1,HIGH(@2)
	.ENDM

	.MACRO __SUBWRR
	SUB  R@0,R@2
	SBC  R@1,R@3
	.ENDM

	.MACRO __ANDWRN
	ANDI R@0,LOW(@2)
	ANDI R@1,HIGH(@2)
	.ENDM

	.MACRO __ANDWRR
	AND  R@0,R@2
	AND  R@1,R@3
	.ENDM

	.MACRO __ORWRN
	ORI  R@0,LOW(@2)
	ORI  R@1,HIGH(@2)
	.ENDM

	.MACRO __ORWRR
	OR   R@0,R@2
	OR   R@1,R@3
	.ENDM

	.MACRO __EORWRR
	EOR  R@0,R@2
	EOR  R@1,R@3
	.ENDM

	.MACRO __GETWRS
	LDD  R@0,Y+@2
	LDD  R@1,Y+@2+1
	.ENDM

	.MACRO __PUTBSR
	STD  Y+@1,R@0
	.ENDM

	.MACRO __PUTWSR
	STD  Y+@2,R@0
	STD  Y+@2+1,R@1
	.ENDM

	.MACRO __MOVEWRR
	MOV  R@0,R@2
	MOV  R@1,R@3
	.ENDM

	.MACRO __INWR
	IN   R@0,@2
	IN   R@1,@2+1
	.ENDM

	.MACRO __OUTWR
	OUT  @2+1,R@1
	OUT  @2,R@0
	.ENDM

	.MACRO __CALL1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	ICALL
	.ENDM

	.MACRO __CALL1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	RCALL __GETW1PF
	ICALL
	.ENDM

	.MACRO __CALL2EN
	PUSH R26
	PUSH R27
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	RCALL __EEPROMRDW
	POP  R27
	POP  R26
	ICALL
	.ENDM

	.MACRO __CALL2EX
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	RCALL __EEPROMRDD
	ICALL
	.ENDM

	.MACRO __GETW1STACK
	IN   R30,SPL
	IN   R31,SPH
	ADIW R30,@0+1
	LD   R0,Z+
	LD   R31,Z
	MOV  R30,R0
	.ENDM

	.MACRO __GETD1STACK
	IN   R30,SPL
	IN   R31,SPH
	ADIW R30,@0+1
	LD   R0,Z+
	LD   R1,Z+
	LD   R22,Z
	MOVW R30,R0
	.ENDM

	.MACRO __NBST
	BST  R@0,@1
	IN   R30,SREG
	LDI  R31,0x40
	EOR  R30,R31
	OUT  SREG,R30
	.ENDM


	.MACRO __PUTB1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __PUTB1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __PUTB1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __PUTB1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __PUTB1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __PUTB1RNS
	MOVW R26,R@0
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RNS
	MOVW R26,R@0
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RNS
	MOVW R26,R@0
	ADIW R26,@1
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __PUTB1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __PUTB1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM


	.MACRO __GETB1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R30,Z
	.ENDM

	.MACRO __GETB1HSX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R31,Z
	.ENDM

	.MACRO __GETW1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	RCALL __GETW1Z
	.ENDM

	.MACRO __GETD1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	RCALL __GETD1Z
	.ENDM

	.MACRO __GETB2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R26,X
	.ENDM

	.MACRO __GETW2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	RCALL __GETW2X
	.ENDM

	.MACRO __GETD2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	RCALL __GETD2X
	.ENDM

	.MACRO __GETBRSX
	MOVW R30,R28
	SUBI R30,LOW(-@1)
	SBCI R31,HIGH(-@1)
	LD   R@0,Z
	.ENDM

	.MACRO __GETWRSX
	MOVW R30,R28
	SUBI R30,LOW(-@2)
	SBCI R31,HIGH(-@2)
	LD   R@0,Z+
	LD   R@1,Z
	.ENDM

	.MACRO __GETBRSX2
	MOVW R26,R28
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	LD   R@0,X
	.ENDM

	.MACRO __GETWRSX2
	MOVW R26,R28
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	LD   R@0,X+
	LD   R@1,X
	.ENDM

	.MACRO __LSLW8SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R31,Z
	CLR  R30
	.ENDM

	.MACRO __PUTB1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __CLRW1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X,R30
	.ENDM

	.MACRO __CLRD1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X+,R30
	ST   X+,R30
	ST   X,R30
	.ENDM

	.MACRO __PUTB2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z,R26
	.ENDM

	.MACRO __PUTW2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z+,R26
	ST   Z,R27
	.ENDM

	.MACRO __PUTD2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z+,R26
	ST   Z+,R27
	ST   Z+,R24
	ST   Z,R25
	.ENDM

	.MACRO __PUTBSRX
	MOVW R30,R28
	SUBI R30,LOW(-@1)
	SBCI R31,HIGH(-@1)
	ST   Z,R@0
	.ENDM

	.MACRO __PUTWSRX
	MOVW R30,R28
	SUBI R30,LOW(-@2)
	SBCI R31,HIGH(-@2)
	ST   Z+,R@0
	ST   Z,R@1
	.ENDM

	.MACRO __PUTB1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __MULBRR
	MULS R@0,R@1
	MOVW R30,R0
	.ENDM

	.MACRO __MULBRRU
	MUL  R@0,R@1
	MOVW R30,R0
	.ENDM

	.MACRO __MULBRR0
	MULS R@0,R@1
	.ENDM

	.MACRO __MULBRRU0
	MUL  R@0,R@1
	.ENDM

	.MACRO __MULBNWRU
	LDI  R26,@2
	MUL  R26,R@0
	MOVW R30,R0
	MUL  R26,R@1
	ADD  R31,R0
	.ENDM

;NAME DEFINITIONS FOR GLOBAL VARIABLES ALLOCATED TO REGISTERS
	.DEF _hold1=R5
	.DEF _hold2=R4
	.DEF _max1=R7
	.DEF _max2=R6
	.DEF _count=R8
	.DEF _count_msb=R9
	.DEF _valorADC1=R11
	.DEF _valorADC2=R10

	.CSEG
	.ORG 0x00

;START OF CODE MARKER
__START_OF_CODE:

;INTERRUPT VECTORS
	RJMP __RESET
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00
	RJMP 0x00

;GLOBAL REGISTER VARIABLES INITIALIZATION
__REG_VARS:
	.DB  0x0,0x0,0x0,0x0


__GLOBAL_INI_TBL:
	.DW  0x04
	.DW  0x06
	.DW  __REG_VARS*2

_0xFFFFFFFF:
	.DW  0

#define __GLOBAL_INI_TBL_PRESENT 1

__RESET:
	CLI
	CLR  R30
	OUT  EECR,R30

;INTERRUPT VECTORS ARE PLACED
;AT THE START OF FLASH
	LDI  R31,1
	OUT  GICR,R31
	OUT  GICR,R30
	OUT  MCUCR,R30

;CLEAR R2-R14
	LDI  R24,(14-2)+1
	LDI  R26,2
	CLR  R27
__CLEAR_REG:
	ST   X+,R30
	DEC  R24
	BRNE __CLEAR_REG

;CLEAR SRAM
	LDI  R24,LOW(__CLEAR_SRAM_SIZE)
	LDI  R25,HIGH(__CLEAR_SRAM_SIZE)
	LDI  R26,__SRAM_START
__CLEAR_SRAM:
	ST   X+,R30
	SBIW R24,1
	BRNE __CLEAR_SRAM

;GLOBAL VARIABLES INITIALIZATION
	LDI  R30,LOW(__GLOBAL_INI_TBL*2)
	LDI  R31,HIGH(__GLOBAL_INI_TBL*2)
__GLOBAL_INI_NEXT:
	LPM  R24,Z+
	LPM  R25,Z+
	SBIW R24,0
	BREQ __GLOBAL_INI_END
	LPM  R26,Z+
	LPM  R27,Z+
	LPM  R0,Z+
	LPM  R1,Z+
	MOVW R22,R30
	MOVW R30,R0
__GLOBAL_INI_LOOP:
	LPM  R0,Z+
	ST   X+,R0
	SBIW R24,1
	BRNE __GLOBAL_INI_LOOP
	MOVW R30,R22
	RJMP __GLOBAL_INI_NEXT
__GLOBAL_INI_END:

;HARDWARE STACK POINTER INITIALIZATION
	LDI  R30,LOW(__SRAM_END-__HEAP_SIZE)
	OUT  SPL,R30
	LDI  R30,HIGH(__SRAM_END-__HEAP_SIZE)
	OUT  SPH,R30

;DATA STACK POINTER INITIALIZATION
	LDI  R28,LOW(__SRAM_START+__DSTACK_SIZE)
	LDI  R29,HIGH(__SRAM_START+__DSTACK_SIZE)

	RJMP _main

	.ESEG
	.ORG 0x00

	.DSEG
	.ORG 0xE0

	.CSEG
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x40
	.EQU __sm_mask=0xB0
	.EQU __sm_powerdown=0x20
	.EQU __sm_powersave=0x30
	.EQU __sm_standby=0xA0
	.EQU __sm_ext_standby=0xB0
	.EQU __sm_adc_noise_red=0x10
	.SET power_ctrl_reg=mcucr
	#endif
;unsigned char read_adc(unsigned char adc_input)
; 0000 002C {

	.CSEG
_read_adc:
; .FSTART _read_adc
; 0000 002D ADMUX=adc_input | ADC_VREF_TYPE;
	ST   -Y,R17
	MOV  R17,R26
;	adc_input -> R17
	MOV  R30,R17
	ORI  R30,0x20
	OUT  0x7,R30
; 0000 002E // Delay needed for the stabilization of the ADC input voltage
; 0000 002F delay_us(10);
	__DELAY_USB 3
; 0000 0030 // Start the AD conversion
; 0000 0031 ADCSRA|=(1<<ADSC);
	SBI  0x6,6
; 0000 0032 // Wait for the AD conversion to complete
; 0000 0033 while ((ADCSRA & (1<<ADIF))==0);
_0x3:
	SBIS 0x6,4
	RJMP _0x3
; 0000 0034 ADCSRA|=(1<<ADIF);
	SBI  0x6,4
; 0000 0035 return ADCH;
	IN   R30,0x5
	LD   R17,Y+
	RET
; 0000 0036 }
; .FEND
;void main(void)
; 0000 003B {
_main:
; .FSTART _main
; 0000 003C // Declare your local variables here
; 0000 003D 
; 0000 003E // Input/Output Ports initialization
; 0000 003F // Port A initialization
; 0000 0040 // Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In
; 0000 0041 DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
	LDI  R30,LOW(0)
	OUT  0x1A,R30
; 0000 0042 // State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T
; 0000 0043 PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);
	OUT  0x1B,R30
; 0000 0044 
; 0000 0045 // Port B initialization
; 0000 0046 // Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out
; 0000 0047 DDRB=(1<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0);
	LDI  R30,LOW(255)
	OUT  0x17,R30
; 0000 0048 // State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0
; 0000 0049 PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);
	LDI  R30,LOW(0)
	OUT  0x18,R30
; 0000 004A 
; 0000 004B // Port C initialization
; 0000 004C // Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In
; 0000 004D DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
	OUT  0x14,R30
; 0000 004E // State: Bit7=P Bit6=P Bit5=P Bit4=P Bit3=P Bit2=P Bit1=P Bit0=P
; 0000 004F PORTC=(1<<PORTC7) | (1<<PORTC6) | (1<<PORTC5) | (1<<PORTC4) | (1<<PORTC3) | (1<<PORTC2) | (1<<PORTC1) | (1<<PORTC0);
	LDI  R30,LOW(255)
	OUT  0x15,R30
; 0000 0050 
; 0000 0051 // Port D initialization
; 0000 0052 // Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out
; 0000 0053 DDRD=(1<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);
	OUT  0x11,R30
; 0000 0054 // State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0
; 0000 0055 PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);
	LDI  R30,LOW(0)
	OUT  0x12,R30
; 0000 0056 
; 0000 0057 // Timer/Counter 0 initialization
; 0000 0058 // Clock source: System Clock
; 0000 0059 // Clock value: Timer 0 Stopped
; 0000 005A // Mode: Normal top=0xFF
; 0000 005B // OC0 output: Disconnected
; 0000 005C TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
	OUT  0x33,R30
; 0000 005D TCNT0=0x00;
	OUT  0x32,R30
; 0000 005E OCR0=0x00;
	OUT  0x3C,R30
; 0000 005F 
; 0000 0060 // Timer/Counter 1 initialization
; 0000 0061 // Clock source: System Clock
; 0000 0062 // Clock value: Timer1 Stopped
; 0000 0063 // Mode: Normal top=0xFFFF
; 0000 0064 // OC1A output: Disconnected
; 0000 0065 // OC1B output: Disconnected
; 0000 0066 // Noise Canceler: Off
; 0000 0067 // Input Capture on Falling Edge
; 0000 0068 // Timer1 Overflow Interrupt: Off
; 0000 0069 // Input Capture Interrupt: Off
; 0000 006A // Compare A Match Interrupt: Off
; 0000 006B // Compare B Match Interrupt: Off
; 0000 006C TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
	OUT  0x2F,R30
; 0000 006D TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
	OUT  0x2E,R30
; 0000 006E TCNT1H=0x00;
	OUT  0x2D,R30
; 0000 006F TCNT1L=0x00;
	OUT  0x2C,R30
; 0000 0070 ICR1H=0x00;
	OUT  0x27,R30
; 0000 0071 ICR1L=0x00;
	OUT  0x26,R30
; 0000 0072 OCR1AH=0x00;
	OUT  0x2B,R30
; 0000 0073 OCR1AL=0x00;
	OUT  0x2A,R30
; 0000 0074 OCR1BH=0x00;
	OUT  0x29,R30
; 0000 0075 OCR1BL=0x00;
	OUT  0x28,R30
; 0000 0076 
; 0000 0077 // Timer/Counter 2 initialization
; 0000 0078 // Clock source: System Clock
; 0000 0079 // Clock value: Timer2 Stopped
; 0000 007A // Mode: Normal top=0xFF
; 0000 007B // OC2 output: Disconnected
; 0000 007C ASSR=0<<AS2;
	OUT  0x22,R30
; 0000 007D TCCR2=(0<<WGM20) | (0<<COM21) | (0<<COM20) | (0<<WGM21) | (0<<CS22) | (0<<CS21) | (0<<CS20);
	OUT  0x25,R30
; 0000 007E TCNT2=0x00;
	OUT  0x24,R30
; 0000 007F OCR2=0x00;
	OUT  0x23,R30
; 0000 0080 
; 0000 0081 // Timer(s)/Counter(s) Interrupt(s) initialization
; 0000 0082 TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);
	OUT  0x39,R30
; 0000 0083 
; 0000 0084 // External Interrupt(s) initialization
; 0000 0085 // INT0: Off
; 0000 0086 // INT1: Off
; 0000 0087 // INT2: Off
; 0000 0088 MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
	OUT  0x35,R30
; 0000 0089 MCUCSR=(0<<ISC2);
	OUT  0x34,R30
; 0000 008A 
; 0000 008B // USART initialization
; 0000 008C // USART disabled
; 0000 008D UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
	OUT  0xA,R30
; 0000 008E 
; 0000 008F // Analog Comparator initialization
; 0000 0090 // Analog Comparator: Off
; 0000 0091 // The Analog Comparator's positive input is
; 0000 0092 // connected to the AIN0 pin
; 0000 0093 // The Analog Comparator's negative input is
; 0000 0094 // connected to the AIN1 pin
; 0000 0095 ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
	LDI  R30,LOW(128)
	OUT  0x8,R30
; 0000 0096 
; 0000 0097 // ADC initialization
; 0000 0098 // ADC Clock frequency: 500.000 kHz
; 0000 0099 // ADC Voltage Reference: AREF pin
; 0000 009A // ADC High Speed Mode: Off
; 0000 009B // ADC Auto Trigger Source: ADC Stopped
; 0000 009C // Only the 8 most significant bits of
; 0000 009D // the AD conversion result are used
; 0000 009E ADMUX=ADC_VREF_TYPE;
	LDI  R30,LOW(32)
	OUT  0x7,R30
; 0000 009F ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (1<<ADPS0);
	LDI  R30,LOW(129)
	OUT  0x6,R30
; 0000 00A0 SFIOR=(1<<ADHSM) | (0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);
	LDI  R30,LOW(16)
	OUT  0x30,R30
; 0000 00A1 
; 0000 00A2 // SPI initialization
; 0000 00A3 // SPI disabled
; 0000 00A4 SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
	LDI  R30,LOW(0)
	OUT  0xD,R30
; 0000 00A5 
; 0000 00A6 // TWI initialization
; 0000 00A7 // TWI disabled
; 0000 00A8 TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);
	OUT  0x36,R30
; 0000 00A9 
; 0000 00AA while (1)
_0x6:
; 0000 00AB {
; 0000 00AC valorADC1 = read_adc(0)/32;
	LDI  R26,LOW(0)
	RCALL SUBOPT_0x0
	MOV  R11,R30
; 0000 00AD valorADC2 = read_adc(1)/32;
	LDI  R26,LOW(1)
	RCALL SUBOPT_0x0
	MOV  R10,R30
; 0000 00AE 
; 0000 00AF if(PINC.0 == 0 && PINC.1 == 0){
	SBIC 0x13,0
	RJMP _0xA
	SBIS 0x13,1
	RJMP _0xB
_0xA:
	RJMP _0x9
_0xB:
; 0000 00B0 hold1 = 0;
	CLR  R5
; 0000 00B1 hold2 = 0;
	CLR  R4
; 0000 00B2 switch(valorADC1){
	RCALL SUBOPT_0x1
; 0000 00B3 case 0:     PORTB = 0x00;
	BREQ _0x67
; 0000 00B4 break;
; 0000 00B5 case 1:     PORTB = 0x01;
	RCALL SUBOPT_0x2
	BRNE _0x10
	LDI  R30,LOW(1)
	RJMP _0x68
; 0000 00B6 break;
; 0000 00B7 case 2:     PORTB = 0x03;
_0x10:
	RCALL SUBOPT_0x3
	BRNE _0x11
	LDI  R30,LOW(3)
	RJMP _0x68
; 0000 00B8 break;
; 0000 00B9 case 3:     PORTB = 0x07;
_0x11:
	RCALL SUBOPT_0x4
	BRNE _0x12
	LDI  R30,LOW(7)
	RJMP _0x68
; 0000 00BA break;
; 0000 00BB case 4:     PORTB = 0x0f;
_0x12:
	RCALL SUBOPT_0x5
	BRNE _0x13
	LDI  R30,LOW(15)
	RJMP _0x68
; 0000 00BC break;
; 0000 00BD case 5:     PORTB = 0x1f;
_0x13:
	RCALL SUBOPT_0x6
	BRNE _0x14
	LDI  R30,LOW(31)
	RJMP _0x68
; 0000 00BE break;
; 0000 00BF case 6:     PORTB = 0x3f;
_0x14:
	RCALL SUBOPT_0x7
	BRNE _0x15
	LDI  R30,LOW(63)
	RJMP _0x68
; 0000 00C0 break;
; 0000 00C1 case 7:     PORTB = 0x7f;
_0x15:
	RCALL SUBOPT_0x8
	BRNE _0x16
	LDI  R30,LOW(127)
	RJMP _0x68
; 0000 00C2 break;
; 0000 00C3 case 8:     PORTB = 0xff;
_0x16:
	RCALL SUBOPT_0x9
	BRNE _0x18
	LDI  R30,LOW(255)
	RJMP _0x68
; 0000 00C4 break;
; 0000 00C5 default:    PORTB = 0x00;
_0x18:
_0x67:
	LDI  R30,LOW(0)
_0x68:
	OUT  0x18,R30
; 0000 00C6 break;
; 0000 00C7 }
; 0000 00C8 
; 0000 00C9 switch(valorADC2){
	RCALL SUBOPT_0xA
; 0000 00CA case 0:     PORTD = 0x00;
	BREQ _0x69
; 0000 00CB break;
; 0000 00CC case 1:     PORTD = 0x01;
	RCALL SUBOPT_0x2
	BRNE _0x1D
	LDI  R30,LOW(1)
	RJMP _0x6A
; 0000 00CD break;
; 0000 00CE case 2:     PORTD = 0x03;
_0x1D:
	RCALL SUBOPT_0x3
	BRNE _0x1E
	LDI  R30,LOW(3)
	RJMP _0x6A
; 0000 00CF break;
; 0000 00D0 case 3:     PORTD = 0x07;
_0x1E:
	RCALL SUBOPT_0x4
	BRNE _0x1F
	LDI  R30,LOW(7)
	RJMP _0x6A
; 0000 00D1 break;
; 0000 00D2 case 4:     PORTD = 0x0f;
_0x1F:
	RCALL SUBOPT_0x5
	BRNE _0x20
	LDI  R30,LOW(15)
	RJMP _0x6A
; 0000 00D3 break;
; 0000 00D4 case 5:     PORTD = 0x1f;
_0x20:
	RCALL SUBOPT_0x6
	BRNE _0x21
	LDI  R30,LOW(31)
	RJMP _0x6A
; 0000 00D5 break;
; 0000 00D6 case 6:     PORTD = 0x3f;
_0x21:
	RCALL SUBOPT_0x7
	BRNE _0x22
	LDI  R30,LOW(63)
	RJMP _0x6A
; 0000 00D7 break;
; 0000 00D8 case 7:     PORTD = 0x7f;
_0x22:
	RCALL SUBOPT_0x8
	BRNE _0x23
	LDI  R30,LOW(127)
	RJMP _0x6A
; 0000 00D9 break;
; 0000 00DA case 8:     PORTD = 0xff;
_0x23:
	RCALL SUBOPT_0x9
	BRNE _0x25
	LDI  R30,LOW(255)
	RJMP _0x6A
; 0000 00DB break;
; 0000 00DC default:    PORTD = 0x00;
_0x25:
_0x69:
	LDI  R30,LOW(0)
_0x6A:
	OUT  0x12,R30
; 0000 00DD break;
; 0000 00DE }
; 0000 00DF }
; 0000 00E0 else if(PINC.0 == 1 && PINC.1 == 0){
	RJMP _0x26
_0x9:
	SBIS 0x13,0
	RJMP _0x28
	SBIS 0x13,1
	RJMP _0x29
_0x28:
	RJMP _0x27
_0x29:
; 0000 00E1 switch(valorADC1){
	RCALL SUBOPT_0x1
; 0000 00E2 case 0:     hold1 = 0x00;
	BREQ _0x6B
; 0000 00E3 break;
; 0000 00E4 case 1:     hold1 = 0x01&0b00000001;
	RCALL SUBOPT_0x2
	BRNE _0x2E
	LDI  R30,LOW(1)
	MOV  R5,R30
; 0000 00E5 break;
	RJMP _0x2C
; 0000 00E6 case 2:     hold1 = 0x03&0b00000010;
_0x2E:
	RCALL SUBOPT_0x3
	BRNE _0x2F
	LDI  R30,LOW(2)
	MOV  R5,R30
; 0000 00E7 break;
	RJMP _0x2C
; 0000 00E8 case 3:     hold1 = 0x07&0b00000100;
_0x2F:
	RCALL SUBOPT_0x4
	BRNE _0x30
	LDI  R30,LOW(4)
	MOV  R5,R30
; 0000 00E9 break;
	RJMP _0x2C
; 0000 00EA case 4:     hold1 = 0x0f&0b00001000;
_0x30:
	RCALL SUBOPT_0x5
	BRNE _0x31
	LDI  R30,LOW(8)
	MOV  R5,R30
; 0000 00EB break;
	RJMP _0x2C
; 0000 00EC case 5:     hold1 = 0x1f&0b00010000;
_0x31:
	RCALL SUBOPT_0x6
	BRNE _0x32
	LDI  R30,LOW(16)
	MOV  R5,R30
; 0000 00ED break;
	RJMP _0x2C
; 0000 00EE case 6:     hold1 = 0x3f&0b00100000;
_0x32:
	RCALL SUBOPT_0x7
	BRNE _0x33
	LDI  R30,LOW(32)
	MOV  R5,R30
; 0000 00EF break;
	RJMP _0x2C
; 0000 00F0 case 7:     hold1 = 0x7f&0b01000000;
_0x33:
	RCALL SUBOPT_0x8
	BRNE _0x34
	LDI  R30,LOW(64)
	MOV  R5,R30
; 0000 00F1 break;
	RJMP _0x2C
; 0000 00F2 case 8:     hold1 = 0xff&0b10000000;
_0x34:
	RCALL SUBOPT_0x9
	BRNE _0x36
	LDI  R30,LOW(128)
	MOV  R5,R30
; 0000 00F3 break;
	RJMP _0x2C
; 0000 00F4 default:    hold1 = 0x00;
_0x36:
_0x6B:
	CLR  R5
; 0000 00F5 break;
; 0000 00F6 }
_0x2C:
; 0000 00F7 
; 0000 00F8 switch(valorADC2){
	RCALL SUBOPT_0xA
; 0000 00F9 case 0:     hold2 = 0x00;
	BREQ _0x6C
; 0000 00FA break;
; 0000 00FB case 1:     hold2 = 0x01&0b00000001;
	RCALL SUBOPT_0x2
	BRNE _0x3B
	LDI  R30,LOW(1)
	MOV  R4,R30
; 0000 00FC break;
	RJMP _0x39
; 0000 00FD case 2:     hold2 = 0x03&0b00000010;
_0x3B:
	RCALL SUBOPT_0x3
	BRNE _0x3C
	LDI  R30,LOW(2)
	MOV  R4,R30
; 0000 00FE break;
	RJMP _0x39
; 0000 00FF case 3:     hold2 = 0x07&0b00000100;
_0x3C:
	RCALL SUBOPT_0x4
	BRNE _0x3D
	LDI  R30,LOW(4)
	MOV  R4,R30
; 0000 0100 break;
	RJMP _0x39
; 0000 0101 case 4:     hold2 = 0x0f&0b00001000;
_0x3D:
	RCALL SUBOPT_0x5
	BRNE _0x3E
	LDI  R30,LOW(8)
	MOV  R4,R30
; 0000 0102 break;
	RJMP _0x39
; 0000 0103 case 5:     hold2 = 0x1f&0b00010000;
_0x3E:
	RCALL SUBOPT_0x6
	BRNE _0x3F
	LDI  R30,LOW(16)
	MOV  R4,R30
; 0000 0104 break;
	RJMP _0x39
; 0000 0105 case 6:     hold2 = 0x3f&0b00100000;
_0x3F:
	RCALL SUBOPT_0x7
	BRNE _0x40
	LDI  R30,LOW(32)
	MOV  R4,R30
; 0000 0106 break;
	RJMP _0x39
; 0000 0107 case 7:     hold2 = 0x7f&0b01000000;
_0x40:
	RCALL SUBOPT_0x8
	BRNE _0x41
	LDI  R30,LOW(64)
	MOV  R4,R30
; 0000 0108 break;
	RJMP _0x39
; 0000 0109 case 8:     hold2 = 0xff&0b10000000;
_0x41:
	RCALL SUBOPT_0x9
	BRNE _0x43
	LDI  R30,LOW(128)
	MOV  R4,R30
; 0000 010A break;
	RJMP _0x39
; 0000 010B default:    hold2 = 0x00;
_0x43:
_0x6C:
	CLR  R4
; 0000 010C break;
; 0000 010D }
_0x39:
; 0000 010E PORTB = hold1;
	OUT  0x18,R5
; 0000 010F PORTD = hold2;
	OUT  0x12,R4
; 0000 0110 }
; 0000 0111 
; 0000 0112 else if(PINC.0 == 0 && PINC.1 == 1){
	RJMP _0x44
_0x27:
	SBIC 0x13,0
	RJMP _0x46
	SBIC 0x13,1
	RJMP _0x47
_0x46:
	RJMP _0x45
_0x47:
; 0000 0113 if(count == 10){
	LDI  R30,LOW(10)
	LDI  R31,HIGH(10)
	CP   R30,R8
	CPC  R31,R9
	BRNE _0x48
; 0000 0114 count = 0;
	CLR  R8
	CLR  R9
; 0000 0115 max1 = 0x00;
	CLR  R7
; 0000 0116 max2 = 0x00;
	CLR  R6
; 0000 0117 }else{
	RJMP _0x49
_0x48:
; 0000 0118 if(max1<hold1)
	CP   R7,R5
	BRSH _0x4A
; 0000 0119 max1 = hold1;
	MOV  R7,R5
; 0000 011A if(max2<hold2)
_0x4A:
	CP   R6,R4
	BRSH _0x4B
; 0000 011B max2 = hold2;
	MOV  R6,R4
; 0000 011C count++;
_0x4B:
	MOVW R30,R8
	ADIW R30,1
	MOVW R8,R30
; 0000 011D }
_0x49:
; 0000 011E PORTB = max1;
	OUT  0x18,R7
; 0000 011F PORTD = max2;
	OUT  0x12,R6
; 0000 0120 delay_ms(50);
	LDI  R26,LOW(50)
	LDI  R27,0
	RCALL _delay_ms
; 0000 0121 
; 0000 0122 switch(valorADC1){
	RCALL SUBOPT_0x1
; 0000 0123 case 0:     PORTB = 0x00;     hold1 = 0x00;
	BREQ _0x6D
; 0000 0124 break;
; 0000 0125 case 1:     PORTB = 0x01;     hold1 = 0x01&0b00000001;
	RCALL SUBOPT_0x2
	BRNE _0x50
	LDI  R30,LOW(1)
	OUT  0x18,R30
	MOV  R5,R30
; 0000 0126 break;
	RJMP _0x4E
; 0000 0127 case 2:     PORTB = 0x03;     hold1 = 0x03&0b00000010;
_0x50:
	RCALL SUBOPT_0x3
	BRNE _0x51
	LDI  R30,LOW(3)
	OUT  0x18,R30
	LDI  R30,LOW(2)
	MOV  R5,R30
; 0000 0128 break;
	RJMP _0x4E
; 0000 0129 case 3:     PORTB = 0x07;     hold1 = 0x07&0b00000100;
_0x51:
	RCALL SUBOPT_0x4
	BRNE _0x52
	LDI  R30,LOW(7)
	OUT  0x18,R30
	LDI  R30,LOW(4)
	MOV  R5,R30
; 0000 012A break;
	RJMP _0x4E
; 0000 012B case 4:     PORTB = 0x0f;     hold1 = 0x0f&0b00001000;
_0x52:
	RCALL SUBOPT_0x5
	BRNE _0x53
	LDI  R30,LOW(15)
	OUT  0x18,R30
	LDI  R30,LOW(8)
	MOV  R5,R30
; 0000 012C break;
	RJMP _0x4E
; 0000 012D case 5:     PORTB = 0x1f;     hold1 = 0x1f&0b00010000;
_0x53:
	RCALL SUBOPT_0x6
	BRNE _0x54
	LDI  R30,LOW(31)
	OUT  0x18,R30
	LDI  R30,LOW(16)
	MOV  R5,R30
; 0000 012E break;
	RJMP _0x4E
; 0000 012F case 6:     PORTB = 0x3f;     hold1 = 0x3f&0b00100000;
_0x54:
	RCALL SUBOPT_0x7
	BRNE _0x55
	LDI  R30,LOW(63)
	OUT  0x18,R30
	LDI  R30,LOW(32)
	MOV  R5,R30
; 0000 0130 break;
	RJMP _0x4E
; 0000 0131 case 7:     PORTB = 0x7f;     hold1 = 0x7f&0b01000000;
_0x55:
	RCALL SUBOPT_0x8
	BRNE _0x56
	LDI  R30,LOW(127)
	OUT  0x18,R30
	LDI  R30,LOW(64)
	MOV  R5,R30
; 0000 0132 break;
	RJMP _0x4E
; 0000 0133 case 8:     PORTB = 0xff;     hold1 = 0xff&0b10000000;
_0x56:
	RCALL SUBOPT_0x9
	BRNE _0x58
	LDI  R30,LOW(255)
	OUT  0x18,R30
	LDI  R30,LOW(128)
	MOV  R5,R30
; 0000 0134 break;
	RJMP _0x4E
; 0000 0135 default:    PORTB = 0x00;     hold1 = 0x00;
_0x58:
_0x6D:
	LDI  R30,LOW(0)
	OUT  0x18,R30
	CLR  R5
; 0000 0136 break;
; 0000 0137 }
_0x4E:
; 0000 0138 
; 0000 0139 switch(valorADC2){
	RCALL SUBOPT_0xA
; 0000 013A case 0:     PORTD = 0x00;     hold2 = 0x00;
	BREQ _0x6E
; 0000 013B break;
; 0000 013C case 1:     PORTD = 0x01;     hold2 = 0x01&0b00000001;
	RCALL SUBOPT_0x2
	BRNE _0x5D
	LDI  R30,LOW(1)
	OUT  0x12,R30
	MOV  R4,R30
; 0000 013D break;
	RJMP _0x5B
; 0000 013E case 2:     PORTD = 0x03;     hold2 = 0x03&0b00000010;
_0x5D:
	RCALL SUBOPT_0x3
	BRNE _0x5E
	LDI  R30,LOW(3)
	OUT  0x12,R30
	LDI  R30,LOW(2)
	MOV  R4,R30
; 0000 013F break;
	RJMP _0x5B
; 0000 0140 case 3:     PORTD = 0x07;     hold2 = 0x07&0b00000100;
_0x5E:
	RCALL SUBOPT_0x4
	BRNE _0x5F
	LDI  R30,LOW(7)
	OUT  0x12,R30
	LDI  R30,LOW(4)
	MOV  R4,R30
; 0000 0141 break;
	RJMP _0x5B
; 0000 0142 case 4:     PORTD = 0x0f;     hold2 = 0x0f&0b00001000;
_0x5F:
	RCALL SUBOPT_0x5
	BRNE _0x60
	LDI  R30,LOW(15)
	OUT  0x12,R30
	LDI  R30,LOW(8)
	MOV  R4,R30
; 0000 0143 break;
	RJMP _0x5B
; 0000 0144 case 5:     PORTD = 0x1f;     hold2 = 0x1f&0b00010000;
_0x60:
	RCALL SUBOPT_0x6
	BRNE _0x61
	LDI  R30,LOW(31)
	OUT  0x12,R30
	LDI  R30,LOW(16)
	MOV  R4,R30
; 0000 0145 break;
	RJMP _0x5B
; 0000 0146 case 6:     PORTD = 0x3f;     hold2 = 0x3f&0b00100000;
_0x61:
	RCALL SUBOPT_0x7
	BRNE _0x62
	LDI  R30,LOW(63)
	OUT  0x12,R30
	LDI  R30,LOW(32)
	MOV  R4,R30
; 0000 0147 break;
	RJMP _0x5B
; 0000 0148 case 7:     PORTD = 0x7f;     hold2 = 0x7f&0b01000000;
_0x62:
	RCALL SUBOPT_0x8
	BRNE _0x63
	LDI  R30,LOW(127)
	OUT  0x12,R30
	LDI  R30,LOW(64)
	MOV  R4,R30
; 0000 0149 break;
	RJMP _0x5B
; 0000 014A case 8:     PORTD = 0xff;     hold2 = 0xff&0b10000000;
_0x63:
	RCALL SUBOPT_0x9
	BRNE _0x65
	LDI  R30,LOW(255)
	OUT  0x12,R30
	LDI  R30,LOW(128)
	MOV  R4,R30
; 0000 014B break;
	RJMP _0x5B
; 0000 014C default:    PORTD = 0x00;     hold2 = 0x00;
_0x65:
_0x6E:
	LDI  R30,LOW(0)
	OUT  0x12,R30
	CLR  R4
; 0000 014D break;
; 0000 014E }
_0x5B:
; 0000 014F }
; 0000 0150 
; 0000 0151 //PORTB = valorADC1;
; 0000 0152 //PORTD = valorADC2;
; 0000 0153 delay_ms(50);
_0x45:
_0x44:
_0x26:
	LDI  R26,LOW(50)
	LDI  R27,0
	RCALL _delay_ms
; 0000 0154 // Place your code here
; 0000 0155 
; 0000 0156 }
	RJMP _0x6
; 0000 0157 }
_0x66:
	RJMP _0x66
; .FEND

	.CSEG
;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:3 WORDS
SUBOPT_0x0:
	RCALL _read_adc
	LDI  R31,0
	MOVW R26,R30
	LDI  R30,LOW(32)
	LDI  R31,HIGH(32)
	RCALL __DIVW21
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x1:
	MOV  R30,R11
	LDI  R31,0
	SBIW R30,0
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 6 TIMES, CODE SIZE REDUCTION:8 WORDS
SUBOPT_0x2:
	CPI  R30,LOW(0x1)
	LDI  R26,HIGH(0x1)
	CPC  R31,R26
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 6 TIMES, CODE SIZE REDUCTION:8 WORDS
SUBOPT_0x3:
	CPI  R30,LOW(0x2)
	LDI  R26,HIGH(0x2)
	CPC  R31,R26
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 6 TIMES, CODE SIZE REDUCTION:8 WORDS
SUBOPT_0x4:
	CPI  R30,LOW(0x3)
	LDI  R26,HIGH(0x3)
	CPC  R31,R26
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 6 TIMES, CODE SIZE REDUCTION:8 WORDS
SUBOPT_0x5:
	CPI  R30,LOW(0x4)
	LDI  R26,HIGH(0x4)
	CPC  R31,R26
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 6 TIMES, CODE SIZE REDUCTION:8 WORDS
SUBOPT_0x6:
	CPI  R30,LOW(0x5)
	LDI  R26,HIGH(0x5)
	CPC  R31,R26
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 6 TIMES, CODE SIZE REDUCTION:8 WORDS
SUBOPT_0x7:
	CPI  R30,LOW(0x6)
	LDI  R26,HIGH(0x6)
	CPC  R31,R26
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 6 TIMES, CODE SIZE REDUCTION:8 WORDS
SUBOPT_0x8:
	CPI  R30,LOW(0x7)
	LDI  R26,HIGH(0x7)
	CPC  R31,R26
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 6 TIMES, CODE SIZE REDUCTION:8 WORDS
SUBOPT_0x9:
	CPI  R30,LOW(0x8)
	LDI  R26,HIGH(0x8)
	CPC  R31,R26
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0xA:
	MOV  R30,R10
	LDI  R31,0
	SBIW R30,0
	RET

;RUNTIME LIBRARY

	.CSEG
__ANEGW1:
	NEG  R31
	NEG  R30
	SBCI R31,0
	RET

__DIVW21U:
	CLR  R0
	CLR  R1
	LDI  R25,16
__DIVW21U1:
	LSL  R26
	ROL  R27
	ROL  R0
	ROL  R1
	SUB  R0,R30
	SBC  R1,R31
	BRCC __DIVW21U2
	ADD  R0,R30
	ADC  R1,R31
	RJMP __DIVW21U3
__DIVW21U2:
	SBR  R26,1
__DIVW21U3:
	DEC  R25
	BRNE __DIVW21U1
	MOVW R30,R26
	MOVW R26,R0
	RET

__DIVW21:
	RCALL __CHKSIGNW
	RCALL __DIVW21U
	BRTC __DIVW211
	RCALL __ANEGW1
__DIVW211:
	RET

__CHKSIGNW:
	CLT
	SBRS R31,7
	RJMP __CHKSW1
	RCALL __ANEGW1
	SET
__CHKSW1:
	SBRS R27,7
	RJMP __CHKSW2
	NEG  R27
	NEG  R26
	SBCI R27,0
	BLD  R0,0
	INC  R0
	BST  R0,0
__CHKSW2:
	RET

_delay_ms:
	adiw r26,0
	breq __delay_ms1
__delay_ms0:
	wdr
	__DELAY_USW 0xFA
	sbiw r26,1
	brne __delay_ms0
__delay_ms1:
	ret

;END OF CODE MARKER
__END_OF_CODE:
