/*
The MIT License (MIT)

Copyright (c) 2017 Lancaster University.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

/**
  * Class definition for LEDMatrix.
  *
  * A LEDMatrix represents the LED matrix array on the micro:bit.
  */
#include "RP2040LedMatrix.h"
#include "RP2040Pin.h"
#include "CodalDmesg.h"
#include "ErrorNo.h"
#include "hardware/gpio.h"

using namespace codal;

static RP2040LEDMatrix *instance = NULL;

static void display_irq(uint16_t mask)
{
    if (instance)
        instance->render();
}

/**
 * Constructor.
 *
 * Create a software representation an LED matrix.
 * The display is initially blank.
 *
 * @param displayTimer The RP2040 timer to use to driver the LEDMatrix display.
 * @param map The mapping information that relates pin inputs/outputs to physical screen coordinates.
 * @param id The id the display should use when sending events on the MessageBus. Defaults to DEVICE_ID_DISPLAY.
 * @param mode The DisplayMode to use. Default: DISPLAY_MODE_BLACK_AND_WHITE.
 */
RP2040LEDMatrix::RP2040LEDMatrix(RP2040LowLevelTimer &displayTimer, const MatrixMap &map, uint16_t id, DisplayMode mode) : Display(map.width, map.height, id), matrixMap(map), timer(displayTimer)
{

}

/**
 * Configures the mode of the display.
 *
 * @param mode The mode to swap the display into. One of: DISPLAY_MODE_GREYSCALE,
 *             DISPLAY_MODE_BLACK_AND_WHITE, DISPLAY_MODE_BLACK_AND_WHITE_LIGHT_SENSE
 *
 * @code
 * display.setDisplayMode(DISPLAY_MODE_GREYSCALE); //per pixel brightness
 * @endcode
 */
void RP2040LEDMatrix::setDisplayMode(DisplayMode mode)
{

}

/**
 * Retrieves the mode of the display.
 *
 * @return the current mode of the display
 */
DisplayMode RP2040LEDMatrix::getDisplayMode()
{
    return this->mode;
}

/**
 * Enables the display, should only be called if the display is disabled.
 *
 * @code
 * display.enable(); //Enables the display 
 * @endcode
 *
 * @note Only enables the display if the display is currently disabled.
 */
void RP2040LEDMatrix::enable()
{

}

/**
 * Disables the display, which releases control of the GPIO pins used by the display,
 * which are exposed on the edge connector.
 *
 * @code
 * display.disable(); //disables the display
 * @endcode
 *
 */
void RP2040LEDMatrix::disable()
{

}

/**
 * Configure the next frame to be drawn.
 */
void RP2040LEDMatrix::render()
{
    //gpio_init(25);
    // gpio_set_dir(25, GPIO_IN);
    // return gpio_get(25);

    //gpio_set_dir(25, GPIO_OUT);
    gpio_put(25, 1);
 //sio_hw->gpio_set = 1<<25;
}

/**
  * Clears the display of any remaining pixels.
  *
  * `display.image.clear()` can also be used!
  *
  * @code
  * display.clear(); //clears the display
  * @endcode
  */
void RP2040LEDMatrix::clear()
{
    image.clear();
}

/**
 * Configures the brightness of the display.
 *
 * @param b The brightness to set the brightness to, in the range 0 - 255.
 *
 * @return DEVICE_OK, or DEVICE_INVALID_PARAMETER
 */
int RP2040LEDMatrix::setBrightness(int b)
{
    return DEVICE_OK;
}

/**
 * Determines the last ambient light level sensed.
 *
 * @return The light level sensed, as an unsigned 8-bit value in the range 0..255
 */
int RP2040LEDMatrix::readLightLevel()
{
    return 1;
}

/**
 * Puts the component in (or out of) sleep (low power) mode.
 */
int RP2040LEDMatrix::setSleep(bool doSleep)
{
    static bool wasEnabled;

    if (doSleep)
    {
        wasEnabled = enabled;
        disable();
    }

    if (!doSleep && wasEnabled)
    {
        enable();
    }
   
    return DEVICE_OK;
}

/**
  * Destructor for LEDMatrix, where we deregister this instance from the array of system components.
  */
RP2040LEDMatrix::~RP2040LEDMatrix()
{
    this->status &= ~DEVICE_COMPONENT_STATUS_SYSTEM_TICK;
}
