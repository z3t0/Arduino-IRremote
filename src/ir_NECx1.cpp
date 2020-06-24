// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:41:53 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code NECx1".


#include "IRremote.h"
/*
IRP: 
{38.4k,564}<1,-1|1,-3>(8,-8,D:8,S:8,F:8,~F:8,1,^108m,(8,-8,D:1,1,^108m)*)[D:0..255,S:0..255=255-D,F:0..255]
*/

/*
Protocol documentation:

*/

#if SEND_NECX1

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
            flash(instance, 564);
            gap(instance, 564);
        }
        break;
        case 1: {
            flash(instance, 564);
            gap(instance, 1692);
        }
        break;
        }
    }
}
/**
 * Function for sending one signal from the protcol NECx1.
 * @param D Protocol parameter in the interval [0 .. 255].
 * @param S Protocol parameter in the interval [0 .. 255].
 * @param F Protocol parameter in the interval [0 .. 255].
 */
void IRsend::sendNECx1(unsigned int D,
        unsigned int S,
        unsigned int F) {
    enableIROut(38400U / 1000U);
    IRsend* instance = this;
    durationCounter = 0UL;
    flash(instance, 4512);
    gap(instance, 4512);
    bitField(instance, D, 8U);
    bitField(instance, S, 8U);
    bitField(instance, F, 8U);
    bitField(instance, ~F, 8U);
    flash(instance, 564);
    extent(instance, 108000UL);
}

#endif // SEND_NECX1 
