/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F25K22
        Driver Version    :  2.00
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

#include <stdint.h>
#include "mcc_generated_files/mcc.h"
#include "main.h"

uint16_t adValueLux = 0;          // 照度のAD値
uint16_t adValueLightPower = 0;   // LEDの明るさ
uint16_t adValueLightOnTimer = 0; // 点灯時間

/**
 * @name インターバルタイマー
 */
/*@{*/
uint16_t intervaltimer_10msec = 0;
uint16_t intervaltimer_50msec = 0;
uint16_t intervaltimer_100msec = 0;
uint16_t intervaltimer_500msec = 0;
uint16_t intervaltimer_1sec = 0;
uint16_t intervaltimer_1min = 0;
/*@}*/

stIntervalTimerFlag itFlag;
stModeFlag modeFlag;

/**
 * @name 人感センサー
 */
/*@{*/
uint8_t delayCounterIR1 = 0;
uint8_t delayCounterIR2 = 0;
/*@}*/

/**
 * @name AD
 */
/*@{*/
uint16_t adLux = 0;              //!< 照度センサー
uint16_t adLuxVolume = 0;        //!< 点灯するLux
uint16_t adLightingTime = 0;     //!< 点灯時間
uint16_t adLightingPower = 0;    //!< 点灯明るさ
uint16_t adLuxSum = 0;           //!< 照度の平均値計算用
uint16_t adLuxVolumeSum = 0;     //!< Lux設定の平均値計算用
uint16_t adLightingTimeSum = 0;  //!< 点灯時間設定の平均値計算用
uint16_t adLightingPowerSum = 0; //!< 明るさの平均値計算用
uint8_t adCount = 0;             //!< 平均値合計回数のカウンタ
uint8_t adCountMax = 0;          //!< 平均値計算カウンタの最大値
/*@}*/

/**
 * @name PWM
 */
/*@{*/
uint16_t PWMDutyPrev = 0;   //!< 前回のPWM設定値
uint16_t PWMDuty = 0;       //!< WM設定値
uint16_t PWMDutyTarget = 0; //!< PWM設定の目標値
/*@}*/

/**
 * @name LED
 */
/*@{*/
uint16_t ledCounter = 0;       //!< LEDの点灯時間カウンタ
uint16_t LedCounterTarget = 0; //!< LEDの点灯時間ターゲット
enLEDStatus ledStatus = OFF;   //!< LED点灯制御
/*@}*/

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    itFlag.Flag1msec = 0;
    itFlag.Flag10msec = 0;
    itFlag.Flag50msec = 0;
    itFlag.Flag100msec = 0;
    itFlag.Flag500msec = 0;
    itFlag.Flag1sec = 0;
    itFlag.Flag1min = 0;

    modeFlag.FlagIR1Sensor = 0;
    modeFlag.FlagIR2Sensor = 0;

    adCountMax = 1 << AD_AVERAGE_COUNT; // AD平均値計算の合計回数

    while (1)
    {
        // Add your application code
        if (itFlag.Flag1msec)
        {
            itFlag.Flag1msec = 0;

            if (ledStatus == FADE_IN)
            {
                // PWMのデューティを上げる
                if (PWMDuty < PWMDutyTarget)
                {
                    PWMDuty += LED_FADE_VALUE;
                    PWM4_LoadDutyValue(PWMDuty);
                }
                else if (PWMDuty >= PWMDutyTarget)
                {
                    ledStatus = ON;
                    PWM4_LoadDutyValue(PWMDuty);
                }
            }
            else if (ledStatus == FADE_OUT)
            {
                // PWMのデューティを下げる
                if (PWMDuty > 0)
                {
                    PWMDuty -= LED_FADE_VALUE;
                    PWM4_LoadDutyValue(PWMDuty);
                }
                else if (PWMDuty == 0)
                {
                    ledStatus = OFF;
                    PWM4_LoadDutyValue(PWMDuty);
                }
            }
        }

        if (itFlag.Flag10msec)
        {
            itFlag.Flag10msec = 0;

            // LuxのAD値取得
            adLuxVolumeSum += ADC_GetConversion(LUX_SENSOR);

            // 点灯時間のAD値取得
            adLightingTimeSum += ADC_GetConversion(ONTIME_VOLUME);

            // 点灯明るさのAD値取得
            adLightingPowerSum += ADC_GetConversion(POWER_VOLUME);

            // 照度センサーのしきい値
            adLuxSum += ADC_GetConversion(LUX_VOLUME);

            if (++adCount == adCountMax)
            {
                // 平均値計算
                adLux = adLuxSum >> AD_AVERAGE_COUNT;
                adLightingPower = adLightingPowerSum >> AD_AVERAGE_COUNT;
                adLightingTime = adLightingTimeSum >> AD_AVERAGE_COUNT;
                adLuxVolume = adLuxVolumeSum >> AD_AVERAGE_COUNT;

                adCount = 0;
                adLuxSum = 0;
                adLightingPowerSum = 0;
                adLightingTimeSum = 0;
                adLuxVolumeSum = 0;

                /* 
                 * LED明るさ
                 * ADC 12bit, PWM 10bitなので2bit右シフトして1/4にする
                 */
                PWMDutyTarget = adLightingPower >> 2;

                // 点灯時間設定
                LedCounterTarget = (uint16_t)((double)1800 * (double)(adLightingPower / 4096)) + 30;

                // 照度による点灯可能判定
                if (modeFlag.FlagLuxEnable)
                {
                    // ヒス以上の変化があれば点灯不可にする
                    if (adLux > (adLuxVolume + AD_LUX_SENSOR_HIS))
                    {
                        modeFlag.FlagLuxEnable = 0;
                        ledStatus = FADE_OUT;
                    }
                }
                else if (~modeFlag.FlagLuxEnable)
                {
                    // ヒス以上の変化があれば点灯可能にする
                    if ((adLux + AD_LUX_SENSOR_HIS) < adLuxVolume)
                    {
                        modeFlag.FlagLuxEnable = 1;
                    }
                }

                /*
                if (PWMDuty != PWMDutyPrev)
                {
                    PWM4_LoadDutyValue(PWMDuty);
                    PWMDutyPrev = PWMDuty;
                }
                */
            }
        }

        if (itFlag.Flag50msec)
        {
            itFlag.Flag50msec = 0;
        }

        if (itFlag.Flag100msec)
        {
            itFlag.Flag100msec = 0;

            // 消灯中なら点灯､点灯中なら消灯までの時間を延長する
            if (ledStatus == ON)
            {
                ledCounter = LedCounterTarget;
            }
            else if (ledStatus == OFF)
            {
                // 照度値が設定以下でIRセンサーの入力があればLED点灯
                if (modeFlag.FlagLuxEnable && (modeFlag.FlagIR1Sensor || modeFlag.FlagIR2Sensor))
                {
                    ledCounter = LedCounterTarget;
                    ledStatus = FADE_IN;
                }
            }
            else if (ledStatus == FADE_OUT)
            {
                ledStatus = FADE_IN;
            }
        }

        if (itFlag.Flag500msec)
        {
            itFlag.Flag500msec = 0;
        }

        if (itFlag.Flag1sec)
        {
            itFlag.Flag1sec = 0;

            /*
             * LED点灯カウンタのデクリメント
             * 設定可能な点灯時間は30secから30min (1800sec)まで?
             */
            if (ledStatus == ON)
            {
                if (--ledCounter == 0)
                {
                    ledStatus = FADE_OUT;
                }
            }
        }

        if (itFlag.Flag1min)
        {
            itFlag.Flag1min = 0;
        }
    }
}

void CalIntervalTimer()
{
    itFlag.Flag1msec = 1;

    if (++intervaltimer_10msec == INTERVAL_COUNT_10MSEC)
    {
        intervaltimer_10msec = 0;
        itFlag.Flag10msec = 1;
    }

    if (++intervaltimer_50msec == INTERVAL_COUNT_50MSEC)
    {
        intervaltimer_50msec = 0;
        itFlag.Flag50msec = 1;
    }

    if (++intervaltimer_100msec == INTERVAL_COUNT_100MSEC)
    {
        intervaltimer_100msec = 0;
        itFlag.Flag100msec = 1;
    }

    if (++intervaltimer_500msec == INTERVAL_COUNT_500MSEC)
    {
        intervaltimer_500msec = 0;
        itFlag.Flag500msec = 1;
    }

    if (++intervaltimer_1sec == INTERVAL_COUNT_1SEC)
    {
        intervaltimer_1sec = 0;
        itFlag.Flag1sec = 1;
    }

    if (++intervaltimer_1min == INTERVAL_COUNT_1MIN)
    {
        intervaltimer_1sec = 0;
        itFlag.Flag1sec = 1;
    }
}

/**
 End of File
*/
