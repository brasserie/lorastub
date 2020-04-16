#ifndef BOARD_H
#define BOARD_H


#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "mbedtls/aes.h"
#include "mbedtls/cmac.h"
#include "mbedtls/cipher.h"

#include "radio.h"

#define USE_BAND_868

#define MAX(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define MIN(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })


int32_t randr(int32_t min, int32_t max);

typedef uint64_t TimerTime_t;

TimerTime_t TimerGetCurrentTime();
TimerTime_t TimerGetElapsedTime(TimerTime_t t);

typedef struct {
    uint32_t period;
    uint64_t timestamp;
} TimerEvent_t;

void TimerInit(TimerEvent_t *ev, void ( *cb )( void ) );
void TimerSetValue(TimerEvent_t *ev, uint32_t delay);
void TimerStart(TimerEvent_t *ev);
void TimerStop(TimerEvent_t *ev);


// ===============================================  LORA FAKE LAYER  ===============================================

#define REG_LR_SYNCWORD                             0x39

/*!
 * Radio wakeup time from SLEEP mode
 */
#define RADIO_OSC_STARTUP                           1 // [ms]

/*!
 * Radio PLL lock and Mode Ready delay which can vary with the temperature
 */
#define RADIO_SLEEP_TO_RX                           2 // [ms]

/*!
 * Radio complete Wake-up Time with margin for temperature compensation
 */
#define RADIO_WAKEUP_TIME                           ( RADIO_OSC_STARTUP + RADIO_SLEEP_TO_RX )


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // BOARD_H
