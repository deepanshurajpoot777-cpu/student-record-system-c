#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    int stdclass;
    char name[20];
    char mother[20];
    char father[20];
    float marks;
    char address[100];
};

int main() {
    struct Student s;
    int choice;

    FILE *fp;

    while(1) {
        printf("\n===== Student Record System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 0) break;

        switch(choice) {

        case 1:
            fp = fopen("students.dat", "ab"); // append binary

            printf("Enter Roll: ");
            scanf("%d", &s.roll);

            printf("Enter Class: ");
            scanf("%d", &s.stdclass);

            getchar(); // buffer clear

            printf("Enter Name: ");
            fgets(s.name, sizeof(s.name), stdin);

            printf("Enter Mother Name: ");
            fgets(s.mother, sizeof(s.mother), stdin);

            printf("Enter Father Name: ");
            fgets(s.father, sizeof(s.father), stdin);

            printf("Enter Marks: ");
            scanf("%f", &s.marks);
            getchar();

            printf("Enter Address: ");
            fgets(s.address, sizeof(s.address), stdin);

            fwrite(&s, sizeof(s), 1, fp);
            fclose(fp);

            printf("Student Saved Successfully!\n");
            break;

        case 2:
            fp = fopen("students.dat", "rb");

            if(fp == NULL) {
                printf("No records found!\n");
                break;
            }

            printf("\n===== Student List =====\n");

            while(fread(&s, sizeof(s), 1, fp)) {
                printf("\nRoll: %d", s.roll);
                printf("\nClass: %d", s.stdclass);
                printf("\nName: %s", s.name);
                printf("Mother: %s", s.mother);
                printf("Father: %s", s.father);
                printf("Marks: %.2f", s.marks);
                printf("\nAddress: %s", s.address);
                printf("\n----------------------\n");
            }

            fclose(fp);
            break;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}