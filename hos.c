#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Enable UTF-8 for Windows console
void enableUTF8() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

// Color printing (Windows ANSI escape sequences)
void setColor(int color) {
    // 0 = reset, 31-37 = text colors, 40-47 = bg colors
    printf("\033[%dm", color);
}

typedef struct {
    char name[50];
    int age;
    char gender[10];
    char disease[50];
} Patient;

void addPatient();
void viewPatients();

int main() {
    enableUTF8();

    int choice;
    while (1) {
        system("cls");
        setColor(36); // Cyan
        printf("╔════════════════════════════════╗\n");
        printf("║    HOSPITAL MANAGEMENT SYSTEM  ║\n");
        printf("╚════════════════════════════════╝\n");
        setColor(33); // Yellow
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Exit\n");
        setColor(37); // White
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewPatients();
                break;
            case 3:
                setColor(32); // Green
                printf("Exiting...\n");
                setColor(0);
                exit(0);
            default:
                setColor(31); // Red
                printf("Invalid choice!\n");
                setColor(0);
                system("pause");
        }
    }
}

void addPatient() {
    FILE *fp = fopen("patients.txt", "a");
    if (!fp) {
        setColor(31);
        printf("Error opening file!\n");
        setColor(0);
        return;
    }
    Patient p;
    setColor(37);
    printf("Enter name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;

    printf("Enter age: ");
    scanf("%d", &p.age);
    getchar();

    printf("Enter gender: ");
    fgets(p.gender, sizeof(p.gender), stdin);
    p.gender[strcspn(p.gender, "\n")] = 0;

    printf("Enter disease: ");
    fgets(p.disease, sizeof(p.disease), stdin);
    p.disease[strcspn(p.disease, "\n")] = 0;

    fprintf(fp, "%s,%d,%s,%s\n", p.name, p.age, p.gender, p.disease);
    fclose(fp);
    setColor(32);
    printf("Patient added successfully!\n");
    setColor(0);
    system("pause");
}

void viewPatients() {
    FILE *fp = fopen("patients.txt", "r");
    if (!fp) {
        setColor(31);
        printf("No patients found!\n");
        setColor(0);
        system("pause");
        return;
    }
    Patient p;
    char line[200];
    setColor(36);
    printf("╔════════════════════════════════════════════════════════════════╗\n");
    printf("║ Name                     │ Age │ Gender     │ Disease         ║\n");
    printf("╠════════════════════════════════════════════════════════════════╣\n");
    setColor(37);
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%49[^,],%d,%9[^,],%49[^\n]", p.name, &p.age, p.gender, p.disease);
        printf("║ %-24s │ %-3d │ %-9s │ %-14s ║\n", p.name, p.age, p.gender, p.disease);
    }
    setColor(36);
    printf("╚════════════════════════════════════════════════════════════════╝\n");
    setColor(0);
    fclose(fp);
    system("pause");
}
