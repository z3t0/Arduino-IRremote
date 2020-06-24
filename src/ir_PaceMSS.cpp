// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:42:39 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code PaceMSS".


#include "IRremote.h"
/*
IRP: 
{38k,630,msb}<1,-7|1,-11>(1,-5,1,-5,T:1,D:1,F:8,1,^120m)*[D:0..1,F:0..255,T:0..1]
*/

/*
Protocol documentation:
This is a moderately robust protocol, but spurious decodes are still possible.
*/

#if SEND_PACEMSS

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
            flash(instance, 630);
            gap(instance, 4410);
        }
        break;
        case 1: {
            flash(instance, 630);
            gap(instance, 6930);
        }
        break;
        }
    }
}
/**
 * Function for sending one signal from the protcol PaceMSS.
 * @param D Protocol parameter in the interval [0 .. 1].
 * @param F Protocol parameter in the interval [0 .. 255].
 * @param T Protocol parameter in the interval [0 .. 1].
 */
void IRsend::sendPaceMSS(unsigned int D,
        unsigned int F,
        unsigned int T) {
    enableIROut(38000U / 1000U);
    IRsend* instance = this;
    durationCounter = 0UL;
    flash(instance, 630);
    gap(instance, 3150);
    flash(instance, 630);
    gap(instance, 3150);
    bitField(instance, T, 1U);
    bitField(instance, D, 1U);
    bitField(instance, F, 8U);
    flash(instance, 630);
    extent(instance, 120000UL);
}

#endif // SEND_PACEMSS 
