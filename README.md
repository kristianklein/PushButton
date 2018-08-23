# PushButton library for Arduino
An Arduino library that makes it easy to check for push button events (click, double-click, hold) without blocking your application with a delay.

# Installation
1. Download the zip-file from https://github.com/kristianklein/PushButton
2. Open Arduino IDE
3. Go to *Sketch* -> *Include Library* -> *Add .ZIP Library...*
4. Browse to the downloaded zip-file and press *Open* 
5. Read the usage instructions below or open up one of the example sketches in *File* -> *Examples* -> *PushButton*

# Simple usage instructions
First include the library either by browsing to *Sketch* -> *Include Library* -> *PushButton* or
by typing the include-directive at the beginning of your sketch:

``` cpp
#include <PushButton.h>
```

Now create a PushButton-object. I'll call mine *myButton*, but you can call yours whatever you like - and create more than just one!
The class constructors takes just one input parameter: the pin that your push button is connected to. I have connected mine
to digital pin 2.

``` cpp
PushButton myButton(2)
```

In your setup() function, you may want to set the given pin as an input, but it is not strictly necessary as all
digital pins are inputs by default.

``` cpp
void setup() {
	pinMode(2, INPUT);
}
```

In your loop() function, it is **very important** that you run the update() function for each of your buttons before
checking for events. The update() function reads the digital pin and determines whether the pin is active or inactive,
and if it has been clicked, double-clicked or held down for a specified amount of time. After running the update
function, let's check if the button has been clicked.

``` cpp
void loop() {
	myButton.update();
	
	if (myButton.isClicked())
	{
		// ... your code goes here ...
	}
}
```

All there's left to do now is to write your application! To learn how to check for other button events or to configure the button
exactly to your need, keep reading the sections below.

# Check for button events
You can use the following member functions to check for button events.

`myButton.isActive()` returns true if the button is currently being pressed down. You can change the logic from active high to active low if necessary (see *Advanced configuration*).

`myButton.isClicked()` returns true if the button has just been clicked. It is automatically debounced without using the delay-function, so it doesn't block the rest of your application.

`myButton.isReleased()` returns true if the button has just been released. This is also automatically debounced.

`myButton.isDoubleClicked()` returns true if the button has been clicked twice within a short period of time.

`myButton.isHeld()` returns true if the button is being held down for a specified amount of time, i.e. a long push.

# Advanced configuration
You can configure the push button to suit your needs by using the followin member functions.

`myButton.setActiveLogic(HIGH_or_LOW)` is used to specify whether the digital logic is active high or active low [default: HIGH].

`myButton.setDebounceTime(milliseconds)` sets the debounce time (in milliseconds) [default: 10].

`myButton.setDoubleClickTime(milliseconds)` sets the maximum amount of time (in milliseconds) between two clicks for a double-click event to be triggered [default: 300].

`myButton.setHoldTime(milliseconds)` sets the amount time (in milliseconds) a button must be held down to trigger a hold event [default: 2000].

`myButton.disableDoubleClick()` disables the double-click feature. Consecutive button clicks will only trigger a regular click event.

`myButton.enableDoubleClick()` enables the double-click feature [default: enabled].