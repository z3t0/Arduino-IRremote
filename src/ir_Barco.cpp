// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:36:57 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code Barco".


#include "IRremote.h"
/*
IRP: 
{0k,10}<1,-5|1,-15>(1,-25,D:5,F:6,1,-25,1,-120m)*[D:0..31,F:0..63]
*/

/*
Protocol documentation:
This protocol uses no modulation of the signal. This is a moderately robust protocol, but spurious decodes are still possible.
*/

#if SEND_BARCO

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
            flash(instance, 10);
            gap(instance, 50);
        }
        break;
        case 1: {
            flash(instance, 10);
            gap(instance, 150);
        }
        break;
        }
    }
}
/**
 * Function for sending one signal from the protcol Barco.
 * @param D Protocol parameter in the interval [0 .. 31].
 * @param F Protocol parameter in the interval [0 .. 63].
 */
void IRsend::sendBarco(unsigned int D,
        unsigned int F) {
    enableIROut(0U / 1000U);
    IRsend* instance = this;
    flash(instance, 10);
    gap(instance, 250);
    bitField(instance, D, 5U);
    bitField(instance, F, 6U);
    flash(instance, 10);
    gap(instance, 250);
    flash(instance, 10);
    gap(instance, 120000);
}

#endif // SEND_BARCO 
