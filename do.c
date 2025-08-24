#include <stdio.h>
#include <windows.h>

void enableUTF8() {
    // Set Windows console to UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

int main() {
    enableUTF8();

    printf("╔═══════════════════════╗\n");
    printf("║   HOSPITAL SYSTEM    ║\n");
    printf("╚═══════════════════════╝\n");

    printf("\nWelcome to the system!\n");
    return 0;
}

