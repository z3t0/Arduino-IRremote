// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:42:20 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code NRC16".


#include "IRremote.h"
/*
IRP: 
{38k,500}<-1,1|1,-1>(1,-5,1:1,254:8,127:7,-15m,(1,-5,1:1,F:8,D:7,-110m)+,1,-5,1:1,254:8,127:7,-15m)[D:0..127,F:0..255]
*/

/*
Protocol documentation:

*/

#if SEND_NRC16

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
            gap(instance, 500);
            flash(instance, 500);
        }
        break;
        case 1: {
            flash(instance, 500);
            gap(instance, 500);
        }
        break;
        }
    }
}
/**
 * Function for sending one signal from the protcol NRC16.
 * @param D Protocol parameter in the interval [0 .. 127].
 * @param F Protocol parameter in the interval [0 .. 255].
 */
void IRsend::sendNRC16(unsigned int D,
        unsigned int F) {
    enableIROut(38000U / 1000U);
    IRsend* instance = this;
    flash(instance, 500);
    gap(instance, 2500);
    bitField(instance, 1U, 1U);
    bitField(instance, 254U, 8U);
    bitField(instance, 127U, 7U);
    gap(instance, 15000);
    flash(instance, 500);
    gap(instance, 2500);
    bitField(instance, 1U, 1U);
    bitField(instance, F, 8U);
    bitField(instance, D, 7U);
    gap(instance, 110000);
}

#endif // SEND_NRC16 
