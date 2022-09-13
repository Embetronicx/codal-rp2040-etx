#ifndef CODAL_RP2040_ETX_LEDMATRIX_H
#define CODAL_RP2040_ETX_LEDMATRIX_H

#include "RP2040Pin.h"

namespace codal
{
    class ETX_LedMatrix : CodalComponent
    {
        //bool enabled = false;
    public:
        ETX_LedMatrix(  RP2040Pin &r0,
                        RP2040Pin &r1,
                        RP2040Pin &r2,
                        RP2040Pin &r3,
                        RP2040Pin &r4,
                        RP2040Pin &c0,
                        RP2040Pin &c1,
                        RP2040Pin &c2,
                        RP2040Pin &c3,
                        RP2040Pin &c4 );
        virtual int etx_plot(int x, int y);
        virtual int etx_unplot(int x, int y);
    };
} // namespace codal

#endif