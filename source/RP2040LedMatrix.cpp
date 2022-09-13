#include "RP2040Pin.h"
#include "RP2040LedMatrix.h"
#include "Button.h"
#include "Timer.h"
#include "codal_target_hal.h"
#include "codal-core/inc/types/Event.h"
#include "CodalDmesg.h"

#include "hardware/gpio.h"
#include "hardware/structs/iobank0.h"
#include "hardware/irq.h"

namespace codal
{
    RP2040Pin *row[5];
    RP2040Pin *col[5];

    /**
     * Constructor.
     */
    ETX_LedMatrix::ETX_LedMatrix( RP2040Pin &r0,
                                  RP2040Pin &r1,
                                  RP2040Pin &r2,
                                  RP2040Pin &r3,
                                  RP2040Pin &r4,
                                  RP2040Pin &c0,
                                  RP2040Pin &c1,
                                  RP2040Pin &c2,
                                  RP2040Pin &c3,
                                  RP2040Pin &c4 )
    {
        row[0] = &r0;
        row[1] = &r1;
        row[2] = &r2;
        row[3] = &r3;
        row[4] = &r4;
        col[0] = &c0;
        col[1] = &c1;
        col[2] = &c2;
        col[3] = &c3;
        col[4] = &c4;
    }

    REAL_TIME_FUNC
    int ETX_LedMatrix::etx_plot( int x, int y )
    {
        row[x]->setDigitalValue(1);
        col[y]->setDigitalValue(0);
        return 0;
    }

    REAL_TIME_FUNC
    int ETX_LedMatrix::etx_unplot( int x, int y )
    {
        row[x]->setDigitalValue(0);
        col[y]->setDigitalValue(1);
        return 0;
    }

} // namespace codal