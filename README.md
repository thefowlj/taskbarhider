# taskbarhider

An example of a small C++ program to hide/show the Windows Taskbar using the Windows API. By default it will toggle between showing and hiding the taskbar on monitors each time it is executed

To force it to try and show or hide the taskbar, execute with the `-show` or `-hide` flags.

This is likely not the best method to accomplish the task of hiding the taskbar UI elements in most production cases, but it is a simple example of how it can still be forced through the old 32-bit Windows APIs. Previously this was tested with 1-2 monitors on Windows 7 and 10. A workaround was added (March 2024) for Windows 11 as well.