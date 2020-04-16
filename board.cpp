
#include "board.h"


void    RadioImplInit ( RadioEvents_t *events )
{
    (void) events;
}

RadioState_t RadioImplGetStatus ( void )
{
    return RF_IDLE;
}

void    RadioImplSetModem( RadioModems_t modem )
{
    (void) modem;
}

void    RadioImplSetChannel( uint32_t freq )
{
    (void) freq;
}

bool   RadioImplIsChannelFree ( RadioModems_t modem, uint32_t freq, int16_t rssiThresh )
{
    (void) modem;
    (void) freq;
    (void) rssiThresh;
    return true;
}

uint32_t RadioImplRandom ( void )
{
    static uint32_t rnd = 123456;
    return rnd++;
}

void    RadioImplSetRxConfig ( RadioModems_t modem, uint32_t bandwidth,
                          uint32_t datarate, uint8_t coderate,
                          uint32_t bandwidthAfc, uint16_t preambleLen,
                          uint16_t symbTimeout, bool fixLen,
                          uint8_t payloadLen,
                          bool crcOn, bool FreqHopOn, uint8_t HopPeriod,
                          bool iqInverted, bool rxContinuous )
{
    (void) modem;
    (void) bandwidth;
    (void) datarate;
    (void) coderate;
    (void) bandwidthAfc;
    (void) preambleLen;
    (void) symbTimeout;
    (void) fixLen;
    (void) payloadLen;
    (void) crcOn;
    (void) FreqHopOn;
    (void) HopPeriod;
    (void) iqInverted;
    (void) rxContinuous;
}

void    RadioImplSetTxConfig ( RadioModems_t modem, int8_t power, uint32_t fdev,
                          uint32_t bandwidth, uint32_t datarate,
                          uint8_t coderate, uint16_t preambleLen,
                          bool fixLen, bool crcOn, bool FreqHopOn,
                          uint8_t HopPeriod, bool iqInverted, uint32_t timeout )
{
    (void) modem;
    (void) bandwidth;
    (void) datarate;
    (void) coderate;
    (void) power;
    (void) preambleLen;
    (void) fdev;
    (void) fixLen;
    (void) timeout;
    (void) crcOn;
    (void) FreqHopOn;
    (void) HopPeriod;
    (void) iqInverted;
}

bool RadioImplCheckRfFrequency( uint32_t frequency )
{
    (void) frequency;
    return true;
}

uint32_t  RadioImplTimeOnAir( RadioModems_t modem, uint8_t pktLen )
{
    (void) modem;
    (void) pktLen;
    return 0;
}

extern void LoraSendPacket ( uint8_t *buffer, uint8_t size );

void RadioImplSend ( uint8_t *buffer, uint8_t size )
{
    LoraSendPacket(buffer, size);
}


void RadioImplSleep ( void )
{

}

void    RadioImplStandby( void )
{

}

void    RadioImplRx ( uint32_t timeout )
{
    (void) timeout;
}

void    RadioImplStartCad ( void )
{

}

void    RadioImplSetTxContinuousWave ( uint32_t freq, int8_t power, uint16_t time )
{

}

int16_t RadioImplRssi ( RadioModems_t modem )
{

}

void    RadioImplWrite ( uint8_t addr, uint8_t data )
{

}

uint8_t RadioImplRead ( uint8_t addr )
{

}

void    RadioImplWriteBuffer ( uint8_t addr, uint8_t *buffer, uint8_t size )
{

}

void    RadioImplReadBuffer ( uint8_t addr, uint8_t *buffer, uint8_t size )
{

}

void    RadioImplSetMaxPayloadLength ( RadioModems_t modem, uint8_t max )
{

}

void    RadioImplSetPublicNetwork ( bool enable )
{

}



const struct Radio_s Radio = {
    RadioImplInit,
    RadioImplGetStatus,
    RadioImplSetModem,
    RadioImplSetChannel,
    RadioImplIsChannelFree,
    RadioImplRandom,
    RadioImplSetRxConfig,
    RadioImplSetTxConfig,
    RadioImplCheckRfFrequency,
    RadioImplTimeOnAir,
    RadioImplSend,
    RadioImplSleep,
    RadioImplStandby,
    RadioImplRx,
    RadioImplStartCad,
    RadioImplSetTxContinuousWave,
    RadioImplRssi,
    RadioImplWrite,
    RadioImplRead,
    RadioImplWriteBuffer,
    RadioImplReadBuffer,
    RadioImplSetMaxPayloadLength,
    RadioImplSetPublicNetwork
};

int32_t randr(int32_t min, int32_t max)
{
    return rand() % (max - min + 1) + min;
}

double ceil(double d)
{
    int64_t i;

    i = d;
    if (d == i) {
        return i;
    }
    return i + 1;
}

double floor(double d)
{
    return (int64_t)d;
}

double round(double d)
{
    return (int64_t)(d + 0.5);
}

uint32_t os_cputime_get32() {
    return 0; // FIXME
}

uint32_t TimerGetElapsedTime(uint32_t savedTime)
{
    return os_cputime_get32() - savedTime;
}

uint32_t TimerGetFutureTime(uint32_t eventInFuture)
{
    return os_cputime_get32() + eventInFuture;
}


TimerTime_t TimerGetCurrentTime()
{
    return 0; // FIXME
}

TimerTime_t TimerGetElapsedTime(TimerTime_t t)
{
    return 0; // FIXME
}

void TimerInit(TimerEvent_t *ev, void ( *cb )( void ) )
{

}

void TimerSetValue(TimerEvent_t *ev, uint32_t delay)
{

}

void TimerStart(TimerEvent_t *ev)
{

}

void TimerStop(TimerEvent_t *ev)
{

}
