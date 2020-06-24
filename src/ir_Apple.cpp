// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:36:44 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code Apple".


#include "IRremote.h"
/*
IRP: 
{38.4k,564}<1,-1|1,-3>(16,-8,D:8,S:8,C:1,F:7,PairID:8,1,^108m,(16,-4,1,^108m)*){C=1-(#F+#PairID)%2,S=135}[D:0..255=238,F:0..127,PairID:0..255]
*/

/*
Protocol documentation:
C=1 if the number of 1 bits in the fields F and I is even. I is the remote ID. Apple uses the same framing as NEC1, with D=238 in normal use, 224 while pairing. S=135
*/

#if SEND_APPLE

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
// Local functions; corresponds to Definitions in the IRP.
static inline unsigned int C(unsigned int D,
        unsigned int F,
        unsigned int PairID) {
    return (1U) - (((bitCount(F)) + (bitCount(PairID)))%(2U));
}

static inline unsigned int S(unsigned int D,
        unsigned int F,
        unsigned int PairID) {
    return 135U;
}

/**
 * Function for sending one signal from the protcol Apple.
 * @param D Protocol parameter in the interval [0 .. 255].
 * @param F Protocol parameter in the interval [0 .. 127].
 * @param PairID Protocol parameter in the interval [0 .. 255].
 */
void IRsend::sendApple(unsigned int D,
        unsigned int F,
        unsigned int PairID) {
    enableIROut(38400U / 1000U);
    IRsend* instance = this;
    durationCounter = 0UL;
    flash(instance, 9024);
    gap(instance, 4512);
    bitField(instance, D, 8U);
    bitField(instance, S(D, F, PairID), 8U);
    bitField(instance, C(D, F, PairID), 1U);
    bitField(instance, F, 7U);
    bitField(instance, PairID, 8U);
    flash(instance, 564);
    extent(instance, 108000UL);
}

#endif // SEND_APPLE 
