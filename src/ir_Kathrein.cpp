// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:40:36 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code Kathrein".


#include "IRremote.h"
/*
IRP: 
{38k,540}<1,-1|1,-3>(16,-8,D:4,~D:4,F:8,~F:8,1,^105m,(16,-8,F:8,1,^105m)+)[D:0..15,F:0..255]
*/

/*
Protocol documentation:
This protocol signals repeats by the use of dittos. It is unusual in that the ditto frame carries part of the signal data, specifically the function code (OBC) but not the device code. Similar to Logitech, but both decodes give the same device number and OBC.
*/

#if SEND_KATHREIN

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
            flash(instance, 540);
            gap(instance, 540);
        }
        break;
        case 1: {
            flash(instance, 540);
            gap(instance, 1620);
        }
        break;
        }
    }
}
/**
 * Function for sending one signal from the protcol Kathrein.
 * @param D Protocol parameter in the interval [0 .. 15].
 * @param F Protocol parameter in the interval [0 .. 255].
 */
void IRsend::sendKathrein(unsigned int D,
        unsigned int F) {
    enableIROut(38000U / 1000U);
    IRsend* instance = this;
    durationCounter = 0UL;
    flash(instance, 8640);
    gap(instance, 4320);
    bitField(instance, D, 4U);
    bitField(instance, ~D, 4U);
    bitField(instance, F, 8U);
    bitField(instance, ~F, 8U);
    flash(instance, 540);
    extent(instance, 105000UL);
    flash(instance, 8640);
    gap(instance, 4320);
    bitField(instance, F, 8U);
    flash(instance, 540);
    extent(instance, 105000UL);
}

#endif // SEND_KATHREIN 
