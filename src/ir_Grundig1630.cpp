// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:39:35 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code Grundig16-30".


#include "IRremote.h"
/*
IRP: 
{30.3k,578,msb}<-4,2|-3,1,-1,1|-2,1,-2,1|-1,1,-3,1>(806u,-2960u,1346u,T:1,F:8,D:7,-100)*[D:0..127,F:0..255,T:0..1]
*/

/*
Protocol documentation:
These are two variants of the same protocol, differing only in frequency. The IRP notation is corrected from previous versions of this document, to bring it into line with what DecodeIR actually does. Note (BM): These two entries was one in the original document; I split it into two separate.
*/

#if SEND_GRUNDIG1630

extern unsigned int finiteBitField(unsigned int data,
        unsigned int width,
        unsigned int chop,
        bool complement,
        bool reverse);
extern unsigned int bitCount(unsigned int data);
extern unsigned int bitReverse(unsigned int data, unsigned int width);


static inline void flash(IRsend* instance, unsigned int d) {
    instance->mark(d);
}

static inline void gap(IRsend* instance, unsigned int d) {
    instance->space(d);
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
            gap(instance, 2312);
            flash(instance, 1156);
        }
        break;
        case 1: {
            gap(instance, 1734);
            flash(instance, 578);
            gap(instance, 578);
            flash(instance, 578);
        }
        break;
        case 2: {
            gap(instance, 1156);
            flash(instance, 578);
            gap(instance, 1156);
            flash(instance, 578);
        }
        break;
        case 3: {
            gap(instance, 578);
            flash(instance, 578);
            gap(instance, 1734);
            flash(instance, 578);
        }
        break;
        }
    }
}
/**
 * Function for sending one signal from the protcol Grundig1630.
 * @param D Protocol parameter in the interval [0 .. 127].
 * @param F Protocol parameter in the interval [0 .. 255].
 * @param T Protocol parameter in the interval [0 .. 1].
 */
void IRsend::sendGrundig1630(unsigned int D,
        unsigned int F,
        unsigned int T) {
    enableIROut(30300U / 1000U);
    IRsend* instance = this;
    flash(instance, 806);
    gap(instance, 2960);
    flash(instance, 1346);
    bitField(instance, T, 1U);
    bitField(instance, F, 8U);
    bitField(instance, D, 7U);
    gap(instance, 57800);
}

#endif // SEND_GRUNDIG1630 
