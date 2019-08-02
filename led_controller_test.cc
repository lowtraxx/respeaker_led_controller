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
#include <unistd.h>
#include <cstdlib>
#include <new>
#include <signal.h>

#define NUMBER_OF_LEDS 12
#define MAX_BRIGHTNESS 31

// Interruption Signal Handler, so we clean up after Ctrl+C
void IntSignalHandler(int sig) {
  LedController *led_controller = &LedController::GetInstance();
  led_controller->PowerDown();
  exit(0);
}

int main() {
  // Install the signal handler
  signal(SIGINT, IntSignalHandler);

  // Initialize the Controller
  LedController *led_controller = &LedController::GetInstance();
  led_controller->PowerUp(NUMBER_OF_LEDS);

  // Rotating the LEDs one time
  for(int i = 0; i <= NUMBER_OF_LEDS; i++)
  {
    // Clear the LEDs
    led_controller->Clear();

    // Set a few pixel to test
    // Red
    led_controller->SetPixelColor(i % NUMBER_OF_LEDS, 24, 0, 0, MAX_BRIGHTNESS);

    // Green
    led_controller->SetPixelColor((i + 3) % NUMBER_OF_LEDS, 0, 24, 0, MAX_BRIGHTNESS);

    // Blue
    led_controller->SetPixelColor((i + 6) % NUMBER_OF_LEDS, 0, 0, 24, MAX_BRIGHTNESS);

    // White
    led_controller->SetPixelColor((i + 9) % NUMBER_OF_LEDS, 12, 12, 12, MAX_BRIGHTNESS);

    // Show the pixels
    led_controller->Show();

    // Sleep for a few seconds and the clean up
    sleep(1);
  }

  // Shutdown
  led_controller->PowerDown();

  return 0;
}
