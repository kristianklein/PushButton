#include <PushButton.h> // Include the PushButton library
#define BUTTON_PIN 2 // Define which pin your button is connected to
#define LED_PIN 13 // Use onboard LED

PushButton myButton(BUTTON_PIN); // Create a button object giving the digital pin as the only input parameter

void setup() {
  pinMode(BUTTON_PIN, INPUT); // Set button as input
  pinMode(LED_PIN, OUTPUT); // Set onboard LED as output
}

void loop() {
  myButton.update(); // Update the button state. This should ALWAYS be done as the first thing in your main loop!

  // Check for a specific button event, eg. isClicked(), isReleased(), isDoubleClicked(), isHeld() or isActive()
  if (myButton.isClicked())
  {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN)); // Toggle the LED everytime the button is clicked
  }
}
