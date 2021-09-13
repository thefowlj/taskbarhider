#include <windows.h>

using namespace std;

int main() {
    HWND hwnd = FindWindow(TEXT("Shell_traywnd"), NULL);
    HWND hwnd2 = FindWindow(TEXT("Shell_SecondaryTrayWnd"), NULL);
    if (IsWindowVisible(hwnd)) {
        ShowWindow(hwnd, 0);
        ShowWindow(hwnd2, 0);
        //SetWindowPos(hwnd,0,0,0,0,0,SWP_HIDEWINDOW);
    }
    else {
        ShowWindow(hwnd, 1);
        ShowWindow(hwnd2, 1);
        //SetWindowPos(hwnd,0,0,0,0,0,SWP_SHOWWINDOW);
    }
    return 0;
}
