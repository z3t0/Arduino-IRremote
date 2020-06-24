// This file was generated by IrpTransmogrifier version 0.2.1dev by bengt
// on Mon Oct 23 11:36:40 CEST 2017
// using command line arguments:
// "-c /home/bengt/harctoolbox/IrpTransmogrifier/tools/../src/main/resources/IrpProtocols.xml --url --loglevel info --logformat %5$s%n code -s src/main/st --dir ../Arduino-IRremote-bm/src -t irremote-renderer-cppsymbols -t irremote-renderer-declarations -t irremote-renderer-code Anthem_relaxed".


#include "IRremote.h"
/*
IRP: 
{38.0k,605}<1,-1|1,-3>(8000u,-4000u,D:8,S:8,F:8,C:8,1,-25m)*{C=~(D+S+F+255):8}[D:0..255,S:0..255,F:0..255]
*/

/*
Protocol documentation:
Relaxed version of the Anthem protocol.
*/

#if SEND_ANTHEM_RELAXED

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
            flash(instance, 605);
            gap(instance, 605);
        }
        break;
        case 1: {
            flash(instance, 605);
            gap(instance, 1815);
        }
        break;
        }
    }
}
// Local functions; corresponds to Definitions in the IRP.
static inline unsigned int C(unsigned int D,
        unsigned int S,
        unsigned int F) {
    return finiteBitField((((D) + (S)) + (F)) + (255U), 8U, 0, true, false);
}

/**
 * Function for sending one signal from the protcol Anthem_relaxed.
 * @param D Protocol parameter in the interval [0 .. 255].
 * @param S Protocol parameter in the interval [0 .. 255].
 * @param F Protocol parameter in the interval [0 .. 255].
 */
void IRsend::sendAnthem_relaxed(unsigned int D,
        unsigned int S,
        unsigned int F) {
    enableIROut(38000U / 1000U);
    IRsend* instance = this;
    flash(instance, 8000);
    gap(instance, 4000);
    bitField(instance, D, 8U);
    bitField(instance, S, 8U);
    bitField(instance, F, 8U);
    bitField(instance, C(D, S, F), 8U);
    flash(instance, 605);
    gap(instance, 25000);
}

#endif // SEND_ANTHEM_RELAXED 
