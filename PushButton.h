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

#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

class PushButton
{
	public:
		PushButton(int pin);
		void update();
		bool isActive();
		bool isClicked();
		bool isDoubleClicked();
		bool isHeld();
		bool isReleased();
		void disableDoubleClick();
		void enableDoubleClick();
		void setDebounceTime(int ms);
		void setHoldTime(int ms);
		void setDoubleClickTime(int ms);
		void setActiveLogic(int high_or_low);
	private:
		int state_;
		long lastClickTime_;
		long lastReleaseTime_;
		int pin_;
		bool doubleClickable_;
		bool activeLogic_;
		bool debounced_;
		int debounceTime_;
		int holdTime_;
		int doubleClickTime_;
};

#endif