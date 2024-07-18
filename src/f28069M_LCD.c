// LCD Interface - 8 bit mode

// LCD Connections

// D0 -> GPIO21
// D1 -> GPIO14
// D2 -> GPIO20
// D3 -> GPIO32
// D4 -> GPIO33
// D5 -> GPIO22
// D6 -> GPIO18
// D7 -> GPIO12

// RS -> GPIO32 changed to GPIO54
// RW -> GND
// E  -> GPIO33 changed to GPIO23

#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
#include "f28069M_LCD.h"


// Initialize LCD to whatever you want to based on the data sheet, what's written is my personal setup
void Initialize(void)
{
    DELAY_US(15000); //delay 15ms

    //Set Enable pin High
    GpioDataRegs.GPASET.bit.GPIO23 = 1;

    WriteCommand(0x30);         //8 bit interface
    DELAY_US(4300);             //delay 4.3 ms

    WriteCommand(0x30);         //8 bit interface
    DELAY_US(200);                  //delay 200us

    WriteCommand(0x30);         //8 bit interface
    LCDDelay1600();

    WriteCommand(0x38);         //FUNCTION SET: 8 bit interface, 2 lines, 5x8 font
    //WriteCommand(0x3C);         //FUNCTION SET: 8 bit interface, 2 lines, 5x11 font


    WriteCommand(0x08);         //Display off, cursor off, blink off
    WriteCommand(0x01);         //Display clear
    LCDDelay1600();             // delay for clearing display

    WriteCommand(0x06);         // Entry mode set: increment cursor, no shift

    WriteCommand(0x0C);         // Display on, cursor off, blink off

}

// Function to write a command to the LCD
void WriteCommand(unsigned char CommandByte)
{
    //Clear RS pin to write command
    GpioDataRegs.GPBCLEAR.bit.GPIO54 = 1;
    SendByte(CommandByte);
}

// Send Databyte to the LCD
void SendByte(unsigned char Value)
{

    if ((Value & 0x01) == 0x01)
        GpioDataRegs.GPASET.bit.GPIO21 = 1;  // Set D0 High
    else
        GpioDataRegs.GPACLEAR.bit.GPIO21 = 1; // Set D0 Low

    if ((Value & 0x02) == 0x02)
        GpioDataRegs.GPASET.bit.GPIO14 = 1;  // Set D1 High
    else
        GpioDataRegs.GPACLEAR.bit.GPIO14 = 1; // Set D1 Low

    if ((Value & 0x04) == 0x04)
        GpioDataRegs.GPASET.bit.GPIO20 = 1;  // Set D2 High
    else
        GpioDataRegs.GPACLEAR.bit.GPIO20 = 1; // Set D2 Low

    if ((Value & 0x08) == 0x08)
        GpioDataRegs.GPBSET.bit.GPIO32 = 1;  // Set D3 High
    else
        GpioDataRegs.GPBCLEAR.bit.GPIO32 = 1; // Set D3 Low

    if ((Value & 0x10) == 0x10)
        GpioDataRegs.GPBSET.bit.GPIO33 = 1;  // Set D4 High
    else
        GpioDataRegs.GPBCLEAR.bit.GPIO33 = 1; // Set D4 Low

    if ((Value & 0x20) == 0x20)
        GpioDataRegs.GPASET.bit.GPIO22 = 1;  // Set D5 High
    else
        GpioDataRegs.GPACLEAR.bit.GPIO22 = 1; // Set D5 Low

    if ((Value & 0x40) == 0x40)
        GpioDataRegs.GPASET.bit.GPIO18 = 1;  // Set D6 High
    else
        GpioDataRegs.GPACLEAR.bit.GPIO18 = 1; // Set D6 Low

    if ((Value & 0x80) == 0x80)
        GpioDataRegs.GPASET.bit.GPIO12 = 1;  // Set D7 High
    else
        GpioDataRegs.GPACLEAR.bit.GPIO12 = 1; // Set D7 Low

//Set E pin to select LCD
    GpioDataRegs.GPASET.bit.GPIO23 = 1;

    DELAY_US(60);  //enable pulse width time to read

//Clear E pin to deselect LCD
    GpioDataRegs.GPACLEAR.bit.GPIO23 = 1;
}

//Write a data byte to LCD
void WriteData(unsigned char DataByte)
{
//Set RS pin to write data
    GpioDataRegs.GPBSET.bit.GPIO54 = 1;
    SendByte(DataByte);
    LCDDelay();                         //Small delay
}

// Displays data
void Display_LCD(unsigned char LineNumber, char *String)
{
    unsigned char Address;

    // Choose the starting address based on the line number
    if (LineNumber == 1)
        Address = 0x00; // 1st line address
    else
        Address = 0xC0; // 2nd line address

    // Write the starting address to the LCD
    WriteCommand(Address);  //MAYBEEEEE

    //Displays character to display
    while (*String)
    {
        WriteData(*String++);
    }

}

void clear_display()
{
    GpioDataRegs.GPBCLEAR.bit.GPIO54 = 1;
    SendByte(0x01);
    GpioDataRegs.GPBSET.bit.GPIO54 = 1;
}

// Small delay
void LCDDelay(void)
{
    DELAY_US(200);
}

// Big delay
void LCDDelay1600(void)
{
    DELAY_US(1600);
}

void cursor_on(void)
{
    GpioDataRegs.GPBCLEAR.bit.GPIO54 = 1;
    SendByte(0x0f);
    GpioDataRegs.GPBSET.bit.GPIO54 = 1;

}
