#include <PushButton.h> // Include the PushButton library
#define BUTTON_PIN 2 // Define which pin your button is connected to
#define LED_PIN 13 // Use onboard LED

PushButton myButton(BUTTON_PIN); // Create a button object giving the digital pin as the only input parameter

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Set button as input with the internal pullup resistor enabled
  pinMode(LED_PIN, OUTPUT); // Set onboard LED as output
  myButton.setActiveLogic(LOW); // Set the button logic as active low (the voltage at the input pin is LOW when the button is pressed)
}

void loop() {
  myButton.update(); // Update the button state. This should ALWAYS be done as the first thing in your main loop!

  // Check for a specific button event, eg. isClicked(), isReleased(), isDoubleClicked(), isHeld() or isActive()
  if (myButton.isClicked())
  {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN)); // Toggle the LED everytime the button is clicked
  }
}
