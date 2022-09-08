#ifndef CODAL_RP2040_ETX_LEDMATRIX_H
#define CODAL_RP2040_ETX_LEDMATRIX_H

#include "RP2040Pin.h"

namespace codal
{
    class ETX_LedMatrix : CodalComponent
    {
        //bool enabled = false;
    public:
        ETX_LedMatrix();
        virtual int etx_plot(RP2040Pin &x, RP2040Pin &y);
        virtual int etx_unplot(RP2040Pin &x, RP2040Pin &y);
    };
} // namespace codal

#endif