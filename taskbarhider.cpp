#include <windows.h>

int main() {
    HWND hwnd = FindWindow("Shell_traywnd", "");
    if (IsWindowVisible(hwnd))
        SetWindowPos(hwnd,0,0,0,0,0,SWP_HIDEWINDOW);
    else
        SetWindowPos(hwnd,0,0,0,0,0,SWP_SHOWWINDOW);
    return 0;
}
