/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.
#ifndef XC_HEADER_TEMPLATE_H
#define XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded. "
#include <stdint.h>

/**
 * @name インターバルタイマ 設定
 */
/*@{*/
#define INTERVAL_COUNT_10MSEC 10   //!< インターバルタイマ 10msec, 1msec * 10
#define INTERVAL_COUNT_50MSEC 50   //!< インターバルタイマ 50msec
#define INTERVAL_COUNT_100MSEC 100 //!< インターバルタイマ 100msec
#define INTERVAL_COUNT_500MSEC 500 //!< インターバルタイマ 500msec
#define INTERVAL_COUNT_1SEC 1000   //!< インターバルタイマ 1sec
#define INTERVAL_COUNT_1MIN 60000  //!< インターバルタイマ 1min
/*@}*/

/**
 * @name AD平均値計算
 */
/*@{*/
#define AD_AVERAGE_COUNT 2 //!< 2^n回の平均
/*@}*/

/**
 * @name センサー 動作設定
 */
/*@{*/
#define AD_LUX_SENSOR_HIS 40 //!< 照度センサーでON, OFFするAD値ヒステリシス
/*@}*/

/**
 * @name LED
 */
/*@{*/
#define LED_FADE_VALUE 2 //!< PWM ON, OFFのフェード効果
/*@{*/

/**
 * @struct stIntervalTimerFlag
 * @breif インターバルタイマ フラグ
 */
/*@{*/
typedef struct
{
    uint8_t Flag1msec : 1;   //!< 1msec経過
    uint8_t Flag10msec : 1;  //!< 10msec経過
    uint8_t Flag50msec : 1;  //!< 50msec経過
    uint8_t Flag100msec : 1; //!< 100msec経過
    uint8_t Flag500msec : 1; //!< 500msec経過
    uint8_t Flag1sec : 1;    //!< 1sec経過
    uint8_t Flag1min : 1;    //!< 1min経過
} stIntervalTimerFlag;
/*@}*/

/**
 * @struct stModeFlag
 * @breif 内部制御 フラグ
 */
/*@{*/
typedef struct
{
    uint8_t FlagLuxEnable : 1; //!< LED点灯可能な照度 0:NG, 1:OK
    uint8_t FlagIR1Sensor : 1; //!< 人感センサー1  0:OFF, 1:ON
    uint8_t FlagIR2Sensor : 1; //!< 人感センサー2  0:OFF, 1:ON
} stModeFlag;
/*@}*/

/**
 * @enum enLEDStatus
 */
/*@{*/
typedef enum
{
    OFF,
    FADE_IN,
    ON,
    FADE_OUT
} enLEDStatus;
/*@]*/

extern stModeFlag modeFlag;

void CalIntervalTimer(void);

#endif /* XC_HEADER_TEMPLATE_H */
