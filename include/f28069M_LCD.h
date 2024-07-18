/*
 * main.h
 *
 *  Created on: Jun 26, 2024
 *      Author: Ethan
 */

#ifndef LCD_H_
#define LCD_H_

#define RS_PIN    54
#define E_PIN     23
#define DATA_PINS {21, 14, 20, 32, 33, 22, 18, 12}

//Driver functions
void Initialize(void);                                      // Initialize LCD
void SendByte(unsigned char Value);                       //Turns on/off registers based on input
void Display_LCD(unsigned char LineNumber, char *String);   // Display the given message
void WriteCommand(unsigned char CommandByte);               // Write the given command
void WriteData(unsigned char DataByte);                     // Write the given data

//Utility functions
void clear_display(void);                                   // Clears display
void cursor_on(void);


void LCDDelay1600(void);                                    //1600 us delay
void LCDDelay(void);                                        //200 us delay

#endif
