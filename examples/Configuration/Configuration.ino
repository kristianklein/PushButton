#include <PushButton.h> // Include the PushButton library
#define BUTTON_PIN 2 // Define which pin your button is connected to
#define LED_PIN 13 // Use on-board LED

PushButton myButton(BUTTON_PIN); // Create a button object giving the digital pin number as the only input parameter

void setup() {
  // Configure button as needed
  myButton.disableDoubleClick(); // Disables double-click functionality
  myButton.enableDoubleClick(); // Enables double-click functionality [default: Enabled]
  myButton.setDebounceTime(20); // Set debounce time (ms) [default: 10]
  myButton.setHoldTime(1000); // Set time (ms) for a hold-event to trigger [default: 2000]
  myButton.setDoubleClickTime(500); // Set maximum time (ms) between two click events to trigger a double-click event [default: 300]
  myButton.setActiveLogic(LOW); // Set the logic as active LOW, i.e. digital pin is LOW when button is pressed [default: HIGH]
  
  pinMode(BUTTON_PIN, INPUT); // Set button as input
  pinMode(LED_PIN, OUTPUT); // Set onboard LED as output
}

void loop() {
  myButton.update(); // Update the button state. This should ALWAYS be done as the first thing in your main loop!

  // Check for a specific button event, eg. isClicked(), isReleased(), isDoubleClicked(), isHeld() or isActive()
  if (myButton.isHeld())
  {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN)); // Toggle the LED everytime the button is clicked
  }
}
