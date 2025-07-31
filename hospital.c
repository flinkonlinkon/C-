#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[100];
    char admitDate[15];
};

struct Doctor {
    int id;
    char name[50];
    char specialization[50];
    char availability[20];
};

struct Appointment {
    int patientId;
    int doctorId;
    char date[15];
};

void addPatient(), viewPatients(), searchPatient(), deletePatient();
void addDoctor(), viewDoctors();
void scheduleAppointment(), login();

int main() {
    login();

    int choice;
    while (1) {
        printf("\n Hospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Search Patient by ID\n");
        printf("4. Delete Patient\n");
        printf("5. Add Doctor\n");
        printf("6. View Doctors\n");
        printf("7. Schedule Appointment\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchPatient(); break;
            case 4: deletePatient(); break;
            case 5: addDoctor(); break;
            case 6: viewDoctors(); break;
            case 7: scheduleAppointment(); break;
            case 8: exit(0);
            default: printf(" Invalid choice\n");
        }
    }
    return 0;
}

// ------------------ Login ------------------
void login() {
    char user[20], pass[20];
    printf(" Admin Login\n");
    printf("Username: ");
    fgets(user, 20, stdin);
    strtok(user, "\n");

    printf("Password: ");
    fgets(pass, 20, stdin);
    strtok(pass, "\n");

    if (strcmp(user, "admin") != 0 || strcmp(pass, "1234") != 0) {
        printf(" Access Denied\n");
        exit(1);
    }
    printf(" Login Successful!\n");
}

// ------------------ Patients ------------------
void addPatient() {
    FILE *fp = fopen("patients.dat", "ab");
    struct Patient p;

    printf("\nEnter Patient ID: ");
    scanf("%d", &p.id);
    getchar();
    printf("Enter Name: ");
    fgets(p.name, 50, stdin); strtok(p.name, "\n");
    printf("Enter Age: ");
    scanf("%d", &p.age); getchar();
    printf("Enter Gender: ");
    fgets(p.gender, 10, stdin); strtok(p.gender, "\n");
    printf("Enter Disease: ");
    fgets(p.disease, 100, stdin); strtok(p.disease, "\n");
    printf("Enter Admit Date (DD/MM/YYYY): ");
    fgets(p.admitDate, 15, stdin); strtok(p.admitDate, "\n");

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);

    printf(" Patient added successfully!\n");
}

void viewPatients() {
    FILE *fp = fopen("patients.dat", "rb");
    struct Patient p;
    if (!fp) { printf(" No records found.\n"); return; }

    printf("\n-- Patient List --\n");
    while (fread(&p, sizeof(p), 1, fp)) {
        printf("\nID: %d | Name: %s | Age: %d | Gender: %s\nDisease: %s | Admit Date: %s\n",
            p.id, p.name, p.age, p.gender, p.disease, p.admitDate);
    }
    fclose(fp);
}

void searchPatient() {
    FILE *fp = fopen("patients.dat", "rb");
    struct Patient p;
    int id, found = 0;
    printf("Enter Patient ID to search: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            found = 1;
            printf("\n Patient Found!\n");
            printf("ID: %d\nName: %s\nAge: %d\nGender: %s\nDisease: %s\nAdmit Date: %s\n",
                   p.id, p.name, p.age, p.gender, p.disease, p.admitDate);
            break;
        }
    }
    if (!found) printf(" Patient not found.\n");
    fclose(fp);
}

void deletePatient() {
    FILE *fp = fopen("patients.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Patient p;
    int id, found = 0;

    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id != id)
            fwrite(&p, sizeof(p), 1, temp);
        else
            found = 1;
    }
    fclose(fp); fclose(temp);
    remove("patients.dat");
    rename("temp.dat", "patients.dat");

    if (found) printf(" Patient deleted.\n");
    else printf(" Patient not found.\n");
}

// ------------------ Doctors ------------------
void addDoctor() {
    FILE *fp = fopen("doctors.dat", "ab");
    struct Doctor d;

    printf("\nEnter Doctor ID: ");
    scanf("%d", &d.id); getchar();
    printf("Enter Name: ");
    fgets(d.name, 50, stdin); strtok(d.name, "\n");
    printf("Enter Specialization: ");
    fgets(d.specialization, 50, stdin); strtok(d.specialization, "\n");
    printf("Enter Availability: ");
    fgets(d.availability, 20, stdin); strtok(d.availability, "\n");

    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);
    printf(" Doctor added successfully!\n");
}

void viewDoctors() {
    FILE *fp = fopen("doctors.dat", "rb");
    struct Doctor d;
    if (!fp) { printf(" No doctor records.\n"); return; }

    printf("\n-- Doctor List --\n");
    while (fread(&d, sizeof(d), 1, fp)) {
        printf("\nID: %d | Name: %s | Specialization: %s | Available: %s\n",
               d.id, d.name, d.specialization, d.availability);
    }
    fclose(fp);
}

// ------------------ Appointments ------------------
void scheduleAppointment() {
    FILE *fp = fopen("appointments.dat", "ab");
    struct Appointment a;

    printf("\nEnter Patient ID: ");
    scanf("%d", &a.patientId);
    printf("Enter Doctor ID: ");
    scanf("%d", &a.doctorId);
    getchar();
    printf("Enter Appointment Date (DD/MM/YYYY): ");
    fgets(a.date, 15, stdin); strtok(a.date, "\n");

    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);
    printf(" Appointment scheduled!\n");
}
