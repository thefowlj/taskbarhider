/**
 * @file taskbarhider.cpp
 * @brief A program to hide or show the Windows taskbar.
 */

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
bool isTaskbarVisible() {
    // Get a handle to the taskbar and secondary taskbar windows
    HWND hwnd = FindWindow(TEXT("Shell_traywnd"), NULL);
    HWND hwnd2 = FindWindow(TEXT("Shell_SecondaryTrayWnd"), NULL);

    // Return true if the taskbar is visible; otherwise, return false
    return IsWindowVisible(hwnd) || IsWindowVisible(hwnd2);
}

/**
 * @brief Hides or shows the taskbar.
 *
 * @param hide - A boolean value indicating whether to hide or show the taskbar.
 */
void hideTaskbar(bool hide) {
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

/**
 * @brief The main function of the program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments. argv[0] is the program name, argv[1] is the first argument, and so on.
 *             The following command-line arguments are supported:
 *             - "-hide": Hides the taskbar.
 *             - "-show": Shows the taskbar.
 * @return The exit status of the program.
 */
int main(int argc, char* argv[]) {
    bool hide = false;
    bool force = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-hide") == 0) {
            force = true;
            hide = true;
        } else if (strcmp(argv[i], "-show") == 0) {
            force = true;
            hide = false;
        } 
    }

    // Get a handle to the taskbar and secondary taskbar windows
    HWND hwnd = FindWindow(TEXT("Shell_traywnd"), NULL);
    HWND hwnd2 = FindWindow(TEXT("Shell_SecondaryTrayWnd"), NULL);

    if (force) {
        hideTaskbar(hide);
        return 0;
    }
    
    // If the taskbar is visible, hide it; otherwise, show it
    if (isTaskbarVisible()) {
        hideTaskbar(true);
    }
    else {
        hideTaskbar(false);
    }

    return 0;
}