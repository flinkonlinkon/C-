#include <windows.h>

int main() {
    char title[50];
    char message[100];

    for (int i = 1; i <= 100; i++) {
        // Create dynamic title and message
        sprintf(title, "😈 ALERT #%d", i);
        sprintf(message, "This is your %dth alert!\nPrepare yourself! 🚨", i);

        // Show the message box
        MessageBox(NULL, message, title, MB_OK | MB_ICONWARNING);
    }

    return 0;
}

