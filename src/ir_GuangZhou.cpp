// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:39:40 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code GuangZhou".


#include "IRremote.h"
/*
IRP: 
{38.0k,182}<3,-3|3,-6>(20,-10,T:2,D:6,F:8,S:8,20,-10,~T:2,D:6,~F:8,3,^108m,(20,-20,3,^108m)*){T=3}[D:0..63,F:0..255,S:0..255]
*/

/*
Protocol documentation:
Forum thread.
*/

#if SEND_GUANGZHOU

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
            flash(instance, 546);
            gap(instance, 546);
        }
        break;
        case 1: {
            flash(instance, 546);
            gap(instance, 1092);
        }
        break;
        }
    }
}
// Local functions; corresponds to Definitions in the IRP.
static inline unsigned int T(unsigned int D,
        unsigned int F,
        unsigned int S) {
    return 3U;
}

/**
 * Function for sending one signal from the protcol GuangZhou.
 * @param D Protocol parameter in the interval [0 .. 63].
 * @param F Protocol parameter in the interval [0 .. 255].
 * @param S Protocol parameter in the interval [0 .. 255].
 */
void IRsend::sendGuangZhou(unsigned int D,
        unsigned int F,
        unsigned int S) {
    enableIROut(38000U / 1000U);
    IRsend* instance = this;
    durationCounter = 0UL;
    flash(instance, 3640);
    gap(instance, 1820);
    bitField(instance, T(D, F, S), 2U);
    bitField(instance, D, 6U);
    bitField(instance, F, 8U);
    bitField(instance, S, 8U);
    flash(instance, 3640);
    gap(instance, 1820);
    bitField(instance, ~T(D, F, S), 2U);
    bitField(instance, D, 6U);
    bitField(instance, ~F, 8U);
    flash(instance, 546);
    extent(instance, 108000UL);
}

#endif // SEND_GUANGZHOU 
