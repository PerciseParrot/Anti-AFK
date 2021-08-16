#include <iostream>
#include <windows.h>

#define PRESS_TIME	50		//time in ms
#define DELAY		1000

INPUT ip;

int key_press(char key)
{
	ip.ki.wVk = key;
	ip.ki.dwFlags = 0;

	SendInput(1, &ip, sizeof(INPUT));

	Sleep(PRESS_TIME);

	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));

	return 0;
}

int main()
{
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	while (true)
	{
		key_press('W');
		Sleep(DELAY);
		key_press('A');
		Sleep(DELAY);
		key_press('S');
		Sleep(DELAY);
		key_press('D');
		Sleep(DELAY);
	}
	return 0;
}