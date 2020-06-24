// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:39:54 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code Humax%204Phase".


#include "IRremote.h"
/*
IRP: 
{56k,105,msb}<-2,2|-3,1|1,-3|2,-2>(T=0,(2,-2,D:6,S:6,T:2,F:7,~F:1,^95m,T=1)+)[D:0..63,S:0..63,F:0..127]
*/

/*
Protocol documentation:
See this.
*/

#if SEND_HUMAX4PHASE

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
    static unsigned int pendingBits = 0U;
    static unsigned int pendingData = 0U;
    if (pendingBits > 0U) {
        // This code is valid for msb-first only
        data &= (1U << width) - 1U;
        data |= pendingData << width;
        width += pendingBits;
        pendingBits = 0U;
    }
    if (width % 2U != 0U) {
        pendingData = data;
        pendingBits = width;
        width = 0U;
    }
    for (unsigned int i = 0; i < width; i += 2) {
        switch(((unsigned int)data >> (width - i - 2)) & 3) {
        case 0: {
            gap(instance, 210);
            flash(instance, 210);
        }
        break;
        case 1: {
            gap(instance, 315);
            flash(instance, 105);
        }
        break;
        case 2: {
            flash(instance, 105);
            gap(instance, 315);
        }
        break;
        case 3: {
            flash(instance, 210);
            gap(instance, 210);
        }
        break;
        }
    }
}
/**
 * Function for sending one signal from the protcol Humax4Phase.
 * @param D Protocol parameter in the interval [0 .. 63].
 * @param S Protocol parameter in the interval [0 .. 63].
 * @param F Protocol parameter in the interval [0 .. 127].
 */
void IRsend::sendHumax4Phase(unsigned int D,
        unsigned int S,
        unsigned int F) {
    enableIROut(56000U / 1000U);
    IRsend* instance = this;
    unsigned int T;
    durationCounter = 0UL;
    T = 0U;
    flash(instance, 210);
    gap(instance, 210);
    bitField(instance, D, 6U);
    bitField(instance, S, 6U);
    bitField(instance, T, 2U);
    bitField(instance, F, 7U);
    bitField(instance, ~F, 1U);
    extent(instance, 95000UL);
    T = 1U;
}

#endif // SEND_HUMAX4PHASE 
