// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:47:02 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code X10_18".


#include "IRremote.h"
/*
IRP: 
{40.8k,565}<2,-12|7,-7>(7,-7,F:9,~F:9,21,-7)*[F:0..511]
*/

/*
Protocol documentation:

*/

#if SEND_X10_18

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
        switch(((unsigned int)data >> i) & 1) {
        case 0: {
            flash(instance, 1130);
            gap(instance, 6780);
        }
        break;
        case 1: {
            flash(instance, 3955);
            gap(instance, 3955);
        }
        break;
        }
    }
}
/**
 * Function for sending one signal from the protcol X10_18.
 * @param F Protocol parameter in the interval [0 .. 511].
 */
void IRsend::sendX10_18(unsigned int F) {
    enableIROut(40800U / 1000U);
    IRsend* instance = this;
    flash(instance, 3955);
    gap(instance, 3955);
    bitField(instance, F, 9U);
    bitField(instance, ~F, 9U);
    flash(instance, 11865);
    gap(instance, 3955);
}

#endif // SEND_X10_18 
