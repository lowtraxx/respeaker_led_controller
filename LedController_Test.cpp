/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose. You are free to modify it and use it in any way you want,
** but you have to leave this header intact.
**               
**
** LedController_Test.cpp
** A simple test app, that lights 4 LEDs of the ReSpeaker 4mic_hat using the
** LedController class
**
** Author: Oliver Pahl
** -------------------------------------------------------------------------*/
#include "LedController.h"
#include <new>
#include <unistd.h>
#include <cstdlib>

int main()
{
	// Initialize the Controller
	// with 12 LEDs
	LedController *led_controller = &LedController::GetInstance();
	led_controller->PowerUp(12);
	
	// Clear the LEDs
	led_controller->Clear();
	
	// Set a few pixel to test
	// Red
	led_controller->SetPixelColor(0, 24, 0, 0, 31);
	
	// Green
	led_controller->SetPixelColor(3, 0, 24, 0, 31);
	
	// Blue
	led_controller->SetPixelColor(6, 0, 0, 24, 31);
	
	// White
	led_controller->SetPixelColor(9, 12, 12, 12, 31);
	
	// Show the pixels
	led_controller->Show();
	
	// Sleep for a few seconds and the clean up
	sleep(3);
	led_controller->Clear();
	
	return 0;	
}
