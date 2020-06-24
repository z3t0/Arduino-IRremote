// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:36:48 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code Archer".


#include "IRremote.h"
/*
IRP: 
{0k,12}<1,-3.3m|1,-4.7m>(F:5,1,-9.7m)*[F:0..31]
*/

/*
Protocol documentation:
This is not a robust protocol, so spurious decodes are likely.
*/

#if SEND_ARCHER

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
            flash(instance, 12);
            gap(instance, 3300);
        }
        break;
        case 1: {
            flash(instance, 12);
            gap(instance, 4700);
        }
        break;
        }
    }
}
/**
 * Function for sending one signal from the protcol Archer.
 * @param F Protocol parameter in the interval [0 .. 31].
 */
void IRsend::sendArcher(unsigned int F) {
    enableIROut(0U / 1000U);
    IRsend* instance = this;
    bitField(instance, F, 5U);
    flash(instance, 12);
    gap(instance, 9700);
}

#endif // SEND_ARCHER 
