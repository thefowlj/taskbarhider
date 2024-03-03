#include <windows.h>

using namespace std;

int main() {
    // Get a handle to the taskbar and secondary taskbar windows
    HWND hwnd = FindWindow(TEXT("Shell_traywnd"), NULL);
    HWND hwnd2 = FindWindow(TEXT("Shell_SecondaryTrayWnd"), NULL);

    // If the taskbar is visible, hide it; otherwise, show it
    if (IsWindowVisible(hwnd)) {
        ShowWindow(hwnd, 0);
        ShowWindow(hwnd2, 0);
    }
    else {
        ShowWindow(hwnd, 1);
        ShowWindow(hwnd2, 1);
    }

    return 0;
}