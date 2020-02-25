/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC18F25K22
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set ONTIME_VOLUME aliases
#define ONTIME_VOLUME_TRIS                 TRISAbits.TRISA0
#define ONTIME_VOLUME_LAT                  LATAbits.LATA0
#define ONTIME_VOLUME_PORT                 PORTAbits.RA0
#define ONTIME_VOLUME_ANS                  ANSELAbits.ANSA0
#define ONTIME_VOLUME_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define ONTIME_VOLUME_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define ONTIME_VOLUME_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define ONTIME_VOLUME_GetValue()           PORTAbits.RA0
#define ONTIME_VOLUME_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define ONTIME_VOLUME_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define ONTIME_VOLUME_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define ONTIME_VOLUME_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set POWER_VOLUME aliases
#define POWER_VOLUME_TRIS                 TRISAbits.TRISA1
#define POWER_VOLUME_LAT                  LATAbits.LATA1
#define POWER_VOLUME_PORT                 PORTAbits.RA1
#define POWER_VOLUME_ANS                  ANSELAbits.ANSA1
#define POWER_VOLUME_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define POWER_VOLUME_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define POWER_VOLUME_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define POWER_VOLUME_GetValue()           PORTAbits.RA1
#define POWER_VOLUME_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define POWER_VOLUME_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define POWER_VOLUME_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define POWER_VOLUME_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set LUX_VOLUME aliases
#define LUX_VOLUME_TRIS                 TRISAbits.TRISA2
#define LUX_VOLUME_LAT                  LATAbits.LATA2
#define LUX_VOLUME_PORT                 PORTAbits.RA2
#define LUX_VOLUME_ANS                  ANSELAbits.ANSA2
#define LUX_VOLUME_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LUX_VOLUME_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LUX_VOLUME_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LUX_VOLUME_GetValue()           PORTAbits.RA2
#define LUX_VOLUME_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LUX_VOLUME_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LUX_VOLUME_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LUX_VOLUME_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set LUX_SENSOR aliases
#define LUX_SENSOR_TRIS                 TRISAbits.TRISA3
#define LUX_SENSOR_LAT                  LATAbits.LATA3
#define LUX_SENSOR_PORT                 PORTAbits.RA3
#define LUX_SENSOR_ANS                  ANSELAbits.ANSA3
#define LUX_SENSOR_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LUX_SENSOR_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LUX_SENSOR_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LUX_SENSOR_GetValue()           PORTAbits.RA3
#define LUX_SENSOR_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LUX_SENSOR_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LUX_SENSOR_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define LUX_SENSOR_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSB2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/