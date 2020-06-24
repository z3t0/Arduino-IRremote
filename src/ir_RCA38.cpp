// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:44:04 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code RCA-38".


#include "IRremote.h"
/*
IRP: 
{38.7k,460,msb}<1,-2|1,-4>(8,-8,D:4,F:8,~D:4,~F:8,1,-16)*[D:0..15,F:0..255]
*/

/*
Protocol documentation:
These are recently discovered variants of the RCA protocol. They differ from RCA and RCA(Old) only in the frequency, which is 38.7kHz instead of the standard 58kHz. Note (BM): One entry split into two.
*/

#if SEND_RCA38

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
    for (unsigned int i = 0; i < width; i++) {
        switch(((unsigned int)data >> (width - i - 1)) & 1) {
        case 0: {
            flash(instance, 460);
            gap(instance, 920);
        }
        break;
        case 1: {
            flash(instance, 460);
            gap(instance, 1840);
        }
        break;
        }
    }
}
/**
 * Function for sending one signal from the protcol RCA38.
 * @param D Protocol parameter in the interval [0 .. 15].
 * @param F Protocol parameter in the interval [0 .. 255].
 */
void IRsend::sendRCA38(unsigned int D,
        unsigned int F) {
    enableIROut(38700U / 1000U);
    IRsend* instance = this;
    flash(instance, 3680);
    gap(instance, 3680);
    bitField(instance, D, 4U);
    bitField(instance, F, 8U);
    bitField(instance, ~D, 4U);
    bitField(instance, ~F, 8U);
    flash(instance, 460);
    gap(instance, 7360);
}

#endif // SEND_RCA38 
