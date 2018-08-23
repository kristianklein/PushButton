#include <PushButton.h> // Include the PushButton library
#define BUTTON_PIN 2 // Define which pin your button is connected to
#define LED_PIN 13 // Use onboard LED

PushButton myButton(BUTTON_PIN); // Create a button object giving the digital pin number as the only input parameter

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT); // Set button as input
  pinMode(LED_PIN, OUTPUT); // Set onboard LED as output
}

void loop() {
  myButton.update(); // Update the button state. This should ALWAYS be done as the first thing in your main loop!

  // Check for button events and print them to the serial monitor
  if (myButton.isClicked()) // Click event
  {
    Serial.println("Button clicked!");
  }

  if (myButton.isReleased()) // Release event
  {
    Serial.println("Button released!");
  }

  if (myButton.isDoubleClicked()) // Double-click event
  {
    Serial.println("Button double-clicked!");
  }

  if (myButton.isHeld()) // Hold/long push event
  {
    Serial.println("Button held down!");
  }

  // Activate the onboard LED whenever the button is active
  if (myButton.isActive())
  {
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }
}
