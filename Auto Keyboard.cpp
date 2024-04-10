#include <iostream>
#include <windows.h>
#include <WinUser.h>
#include <conio.h>

using namespace std;

void pressKeyboard(HWND handler, WPARAM key) {
	Sleep(10);
	SendMessage(handler, WM_KEYDOWN, key, 0);
	Sleep(1000);
	SendMessage(handler, WM_KEYUP, key, 0);
	Sleep(10);
}

int main(void) {
	while (1) {
		if (GetKeyState(VK_SPACE) < 0) {
			while (1) {
				HWND hwnd = FindWindow(L"SDL_app", NULL);
				pressKeyboard(hwnd, VK_LEFT);
				pressKeyboard(hwnd, VK_RIGHT);
			}
		}
	}
}

