/*
MIT License

Copyright (c) 2018 Kristian Klein Jacobsen

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "PushButton.h"
#include <Arduino.h>

#define IDLE 0
#define ACTIVE 1
#define CLICKED 2
#define DOUBLE_CLICKED 3
#define RELEASED 4
#define FIRST_HELD 5
#define HELD 6

PushButton::PushButton(int pin)
{
	pin_ = pin;
	state_ = IDLE;
	debounced_ = true;
	doubleClickable_ = true;
	activeLogic_ = true;
	debounceTime_ = 10;
	holdTime_ = 2000;
	doubleClickTime_ = 300;
	lastClickTime_ = 0;
	lastReleaseTime_ = 0;
}

void PushButton::update()
{
	switch (state_)
	{
		case IDLE:
			if (debounced_)
			{
				if (isActive()) // Button clicked
				{	
					if (doubleClickable_ && millis() - lastClickTime_ < doubleClickTime_)
					{
						state_ = DOUBLE_CLICKED;
					}
					else
					{
						state_ = CLICKED;
					}
					
					debounced_ = false;
					lastClickTime_ = millis();
				}
			}
			else if (millis() - lastReleaseTime_ > debounceTime_)
			{
				debounced_ = true;
			}
			break;
			
		case ACTIVE:
			if (debounced_) // Only check button again when it has been debounced
			{
				if (!isActive()) // Button not active, hence released
				{
					state_ = RELEASED;
				}
				else if (millis() - lastClickTime_ > holdTime_) // Button held
				{
					state_ = FIRST_HELD;
				}
			}
			else if (millis() - lastClickTime_ > debounceTime_) // Check if debounce time has passed
			{
				debounced_ = true;
			}
			break;
			
		case CLICKED:
		case DOUBLE_CLICKED:
			state_ = ACTIVE;
			break;
			
		case RELEASED:
			state_ = IDLE;
			debounced_ = false;
			lastReleaseTime_ = millis();
			break;
			
		case FIRST_HELD:
			state_ = HELD;
			break;
		
		case HELD:
			if (!isActive())
			{
				state_ = RELEASED;
			}
			break;
			
		default: // This should never execute
			state_ = IDLE;
			break;
	}
}

bool PushButton::isActive()
{
	return (digitalRead(pin_) == activeLogic_);
}

bool PushButton::isClicked()
{
	return (state_ == CLICKED);
}

bool PushButton::isDoubleClicked()
{
	if (doubleClickable_)
	{
		return (state_ == DOUBLE_CLICKED);
	}
	else
	{
		return false;
	}
}

bool PushButton::isHeld()
{
	return (state_ == FIRST_HELD);
}

bool PushButton::isReleased()
{
	return (state_ == RELEASED);
}

void PushButton::disableDoubleClick()
{
	doubleClickable_ = false;
}

void PushButton::enableDoubleClick()
{
	doubleClickable_ = true;
}

void PushButton::setDebounceTime(int ms)
{
	debounceTime_ = ms;
}

void PushButton::setHoldTime(int ms)
{
	holdTime_ = ms;
}

void PushButton::setDoubleClickTime(int ms)
{
	doubleClickTime_ = ms;
}

void PushButton::setActiveLogic(int high_or_low)
{
	activeLogic_ = high_or_low;
}