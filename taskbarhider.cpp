#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

/**
 * @brief Checks if the taskbar is visible.
 * 
 * @return true if the taskbar is visible, false otherwise.
 */
boolean isTaskbarVisible() {
    // Get a handle to the taskbar and secondary taskbar windows
    HWND hwnd = FindWindow(TEXT("Shell_traywnd"), NULL);
    HWND hwnd2 = FindWindow(TEXT("Shell_SecondaryTrayWnd"), NULL);

    // Return true if the taskbar is visible; otherwise, return false
    return IsWindowVisible(hwnd) || IsWindowVisible(hwnd2);
}

/**
 * Hides or shows the taskbar.
 *
 * @param hide - A boolean value indicating whether to hide or show the taskbar.
 */
void hideTaskbar(boolean hide) {
    // Get a handle to the taskbar and secondary taskbar windows
    HWND hwnd = FindWindow(TEXT("Shell_traywnd"), NULL);
    HWND hwnd2 = FindWindow(TEXT("Shell_SecondaryTrayWnd"), NULL);

    // In Windows 11 the taskbar ShowWindow function does not always work on the first try
    // The loop trying twice is a workaround to make sure the taskbar is hidden  
    for (int i = 0; i < 2; i++) {
        // Hide/show the taskbar
        ShowWindow(hwnd, hide ? 0 : 1);
        ShowWindow(hwnd2, hide ? 0 : 1);

        // Wait for a moment 
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}


int main() {
    // Get a handle to the taskbar and secondary taskbar windows
    HWND hwnd = FindWindow(TEXT("Shell_traywnd"), NULL);
    HWND hwnd2 = FindWindow(TEXT("Shell_SecondaryTrayWnd"), NULL);

    // If the taskbar is visible, hide it; otherwise, show it
    if (isTaskbarVisible()) {
        hideTaskbar(true);
    }
    else {
        hideTaskbar(false);
    }

    return 0;
}