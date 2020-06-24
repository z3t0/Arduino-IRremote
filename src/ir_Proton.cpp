// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:43:27 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code Proton".


#include "IRremote.h"
/*
IRP: 
{38.5k,500}<1,-1|1,-3>(16,-8,D:8,1,-8,F:8,1,^63m)*[D:0..255,F:0..255]
*/

/*
Protocol documentation:
This is not a robust protocol, so spurious decodes are likely.
*/

#if SEND_PROTON

extern unsigned int finiteBitField(unsigned int data,
        unsigned int width,
        unsigned int chop,
        bool complement,
        bool reverse);
extern unsigned int bitCount(unsigned int data);
extern unsigned int bitReverse(unsigned int data, unsigned int width);

static unsigned long durationCounter = 0UL;

static inline void flash(IRsend* instance, unsigned int d) {
    instance->mark(d);
    durationCounter += (unsigned long) d;
}

static inline void gap(IRsend* instance, unsigned int d) {
    instance->space(d);
    durationCounter += (unsigned long) d;
}

static inline void extent(IRsend* instance, unsigned long d) {
    instance->space((unsigned int)(d - durationCounter));
    durationCounter = 0UL;
}

static void bitField(IRsend* instance, unsigned int data, unsigned int width) {
    for (unsigned int i = 0; i < width; i++) {
        switch(((unsigned int)data >> i) & 1) {
        case 0: {
            flash(instance, 500);
            gap(instance, 500);
        }
        break;
        case 1: {
            flash(instance, 500);
            gap(instance, 1500);
        }
        break;
        }
    }
}
/**
 * Function for sending one signal from the protcol Proton.
 * @param D Protocol parameter in the interval [0 .. 255].
 * @param F Protocol parameter in the interval [0 .. 255].
 */
void IRsend::sendProton(unsigned int D,
        unsigned int F) {
    enableIROut(38500U / 1000U);
    IRsend* instance = this;
    durationCounter = 0UL;
    flash(instance, 8000);
    gap(instance, 4000);
    bitField(instance, D, 8U);
    flash(instance, 500);
    gap(instance, 4000);
    bitField(instance, F, 8U);
    flash(instance, 500);
    extent(instance, 63000UL);
}

#endif // SEND_PROTON 
