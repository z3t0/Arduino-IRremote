// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:36:08 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code AdNotam".


#include "IRremote.h"
/*
IRP: 
{35.7k,895,msb}<1,-1|-1,1>(1,-2,1,D:6,F:6,^114m)*[D:0..63,F:0..63]
*/

/*
Protocol documentation:
Very similar to RC5, except AdNotam uses two start bits, and no toggle bit.
*/

#if SEND_ADNOTAM

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
        switch(((unsigned int)data >> (width - i - 1)) & 1) {
        case 0: {
            flash(instance, 895);
            gap(instance, 895);
        }
        break;
        case 1: {
            gap(instance, 895);
            flash(instance, 895);
        }
        break;
        }
    }
}
/**
 * Function for sending one signal from the protcol AdNotam.
 * @param D Protocol parameter in the interval [0 .. 63].
 * @param F Protocol parameter in the interval [0 .. 63].
 */
void IRsend::sendAdNotam(unsigned int D,
        unsigned int F) {
    enableIROut(35700U / 1000U);
    IRsend* instance = this;
    durationCounter = 0UL;
    flash(instance, 895);
    gap(instance, 1790);
    flash(instance, 895);
    bitField(instance, D, 6U);
    bitField(instance, F, 6U);
    extent(instance, 114000UL);
}

#endif // SEND_ADNOTAM 
