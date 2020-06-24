// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:44:18 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code RECS80-0045".


#include "IRremote.h"
/*
IRP: 
{38k,158,msb}<1,-31|1,-47>(1:1,T:1,D:3,F:6,1,-45m)*[D:0..7,F:0..63,T@:0..1=0]
*/

/*
Protocol documentation:

*/

#if SEND_RECS800045

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
            flash(instance, 158);
            gap(instance, 4898);
        }
        break;
        case 1: {
            flash(instance, 158);
            gap(instance, 7426);
        }
        break;
        }
    }
}
/**
 * Function for sending one signal from the protcol RECS800045.
 * @param D Protocol parameter in the interval [0 .. 7].
 * @param F Protocol parameter in the interval [0 .. 63].
 * @param T Protocol parameter in the interval [0 .. 1].
 */
void IRsend::sendRECS800045(unsigned int D,
        unsigned int F,
        unsigned int T) {
    enableIROut(38000U / 1000U);
    IRsend* instance = this;
    bitField(instance, 1U, 1U);
    bitField(instance, T, 1U);
    bitField(instance, D, 3U);
    bitField(instance, F, 6U);
    flash(instance, 158);
    gap(instance, 45000);
}

#endif // SEND_RECS800045 
