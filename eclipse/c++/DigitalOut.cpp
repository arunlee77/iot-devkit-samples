/*
 * Author: Ivan De Cesaris <ivan.de.cesaris@intel.com>
 * Copyright (c) 2015 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * @file
 * @ingroup grove 
 * @brief Digital Output
 * 
 * Write a digital value to an output pin using the IO mraa library.
 *
 * @date 29/09/2015
 */

#include "mraa.hpp"

#include <iostream>
#include <unistd.h>

/*
 * Digital output example
 *
 * Demonstrate how to write a digital value to an output pin using the MRAA
 * library.
 * A suitable part to use this example with in the Grove Starter Kit is the LED.
 *
 * - digital out: output connected to digital pin 8 (Grove Base Shield Port D8)
 *
 * Additional linker flags: none
 */

int main()
{
	// check that we are running on Galileo or Edison
	mraa::Platform platform = mraa::getPlatformType();
	if((platform != mraa::INTEL_GALILEO_GEN1) &&
			(platform != mraa::INTEL_GALILEO_GEN2) &&
			(platform != mraa::INTEL_EDISON_FAB_C)) {
		std::cerr << "Unsupported platform, exiting" << std::endl;
		return mraa::ERROR_INVALID_PLATFORM;
	}

	// create a gpio object from MRAA using pin 8
	mraa::Gpio* d_pin = new mraa::Gpio(8);
	if(d_pin == NULL) {
		std::cerr << "Can't create mraa::Gpio object, exiting" << std::endl;
		return mraa::ERROR_UNSPECIFIED;
	}

	// set the pin as output
	if (d_pin->dir(mraa::DIR_IN) != mraa::SUCCESS) {
		std::cerr << "Can't set digital pin as output, exiting" << std::endl;
		return mraa::ERROR_UNSPECIFIED;
	}

	// loop forever toggling the digital output every second
	for(;;) {
		d_pin->write(0);
		sleep(1);
		d_pin->write(1);
		sleep(1);
	}

	return mraa::SUCCESS;
}
