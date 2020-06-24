// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:36:30 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code Amino-56".


#include "IRremote.h"
/*
IRP: 
{56.0k,268,msb}<-1,1|1,-1>(T=1,(7,-6,3,D:4,1:1,T:1,1:2,0:8,F:8,15:4,C:4,-79m,T=0)+){C=(D:4+4*T+9+F:4+F:4:4+15)&15}[D:0..15,F:0..255]
*/

/*
Protocol documentation:

*/

#if SEND_AMINO56

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
            gap(instance, 268);
            flash(instance, 268);
        }
        break;
        case 1: {
            flash(instance, 268);
            gap(instance, 268);
        }
        break;
        }
    }
}
// Local functions; corresponds to Definitions in the IRP.
static inline unsigned int C(unsigned int D,
        unsigned int F,
        unsigned int T) {
    return ((((((finiteBitField(D, 4U, 0, false, false)) + ((4U) * (T))) + (9U)) + (finiteBitField(F, 4U, 0, false, false))) + (finiteBitField(F, 4U, 4U, false, false))) + (15U))&(15U);
}

/**
 * Function for sending one signal from the protcol Amino56.
 * @param D Protocol parameter in the interval [0 .. 15].
 * @param F Protocol parameter in the interval [0 .. 255].
 */
void IRsend::sendAmino56(unsigned int D,
        unsigned int F) {
    enableIROut(56000U / 1000U);
    IRsend* instance = this;
    unsigned int T;
    T = 1U;
    flash(instance, 1876);
    gap(instance, 1608);
    flash(instance, 804);
    bitField(instance, D, 4U);
    bitField(instance, 1U, 1U);
    bitField(instance, T, 1U);
    bitField(instance, 1U, 2U);
    bitField(instance, 0U, 8U);
    bitField(instance, F, 8U);
    bitField(instance, 15U, 4U);
    bitField(instance, C(D, F, T), 4U);
    gap(instance, 79000);
    T = 0U;
}

#endif // SEND_AMINO56 
