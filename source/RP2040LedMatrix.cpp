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
    /**
     * Constructor.
     */
    ETX_LedMatrix::ETX_LedMatrix()
    {
        
    }

    REAL_TIME_FUNC
    int ETX_LedMatrix::etx_plot( RP2040Pin &x, RP2040Pin &y )
    {
        x.setDigitalValue(1);
        y.setDigitalValue(0);
        
        //test.slr();
        return 0;
    }

    REAL_TIME_FUNC
    int ETX_LedMatrix::etx_unplot( RP2040Pin &x, RP2040Pin &y )
    {
        x.setDigitalValue(0);
        y.setDigitalValue(1);
        return 0;
    }

} // namespace codal