#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// variable to keep track of number of students
int i = 0;
// structure to store the student
struct sinfo
{
    char fname[50];
    char lname[50];
    int roll;
    float cgpa;
    int cid[10];
} st[55];

// function to add the student
void add_student()
{
    if (i >= 50) {
        printf("\nMaximum number of students reached!\n");
        return;
    }
    printf("\nAdd the student's details");
    printf("\n_________________________\n");
    printf("\nEnter the first name of student: ");
    scanf("%s", st[i].fname);
    printf("Enter the last name of student: ");
    scanf("%s", st[i].lname);
    printf("Enter the roll number of student: ");
    scanf("%d", &st[i].roll);
    printf("Enter the CGPA: ");
    scanf("%f", &st[i].cgpa);
    printf("Enter the course IDs (5 courses): ");
    for (int j = 0; j < 5; j++)
    {
        scanf("%d", &st[i].cid[j]);
    }
    i++;
    printf("Student added successfully!\n");
}

// function to find the student by the roll number
void find_rl()
{
    int x, found = 0;
    printf("\nEnter the roll number of the student: ");
    scanf("%d", &x);
    for (int j = 0; j < i; j++)
    {
        if (x == st[j].roll)
        {
            printf("\nStudent details:");
            printf("\nFirst name: %s", st[j].fname);
            printf("\nLast name: %s", st[j].lname);
            printf("\nCGPA: %.2f", st[j].cgpa);
            printf("\nCourse IDs: ");
            for (int k = 0; k < 5; k++)
            {
                printf("%d ", st[j].cid[k]);
            }
            printf("\n");
            found = 1;
            break;
        }
    }
    if (!found)
        printf("\nStudent not found.\n");
}

// function to find the student by the first name
void find_fn()
{
    char a[50];
    int found = 0;
    printf("\nEnter the first name of the student: ");
    scanf("%s", a);
    for (int j = 0; j < i; j++)
    {
        if (strcmp(st[j].fname, a) == 0)
        {
            printf("\nStudent details:");
            printf("\nFirst name: %s", st[j].fname);
            printf("\nLast name: %s", st[j].lname);
            printf("\nRoll number: %d", st[j].roll);
            printf("\nCGPA: %.2f", st[j].cgpa);
            printf("\nCourse IDs: ");
            for (int k = 0; k < 5; k++)
            {
                printf("%d ", st[j].cid[k]);
            }
            printf("\n");
            found = 1;
        }
    }
    if (!found)
        printf("\nNo student found with the given first name.\n");
}

// function to find students enrolled in a particular course
void find_c()
{
    int id, found = 0;
    printf("\nEnter the course ID: ");
    scanf("%d", &id);
    for (int j = 0; j < i; j++)
    {
        for (int d = 0; d < 5; d++)
        {
            if (id == st[j].cid[d])
            {
                printf("\nStudent details:");
                printf("\nFirst name: %s", st[j].fname);
                printf("\nLast name: %s", st[j].lname);
                printf("\nRoll number: %d", st[j].roll);
                printf("\nCGPA: %.2f", st[j].cgpa);
                printf("\n");
                found = 1;
                break;
            }
        }
    }
    if (!found)
        printf("\nNo student found enrolled in this course.\n");
}

// function to print the total number of students
void tot_s()
{
    printf("\nTotal number of students: %d", i);
    printf("\nYou can have a max of 50 students.");
    printf("\nYou can add %d more students.\n", 50 - i);
}

// function to delete a student by roll number
void del_s()
{
    int a, found = 0;
    printf("\nEnter the roll number to delete: ");
    scanf("%d", &a);
    for (int j = 0; j < i; j++)
    {
        if (a == st[j].roll)
        {
            for (int k = j; k < i - 1; k++)
            {
                st[k] = st[k + 1];
            }
            i--;
            found = 1;
            printf("\nStudent record deleted successfully.\n");
            break;
        }
    }
    if (!found)
        printf("\nStudent with this roll number not found.\n");
}

// function to update student details
void up_s()
{
    int x, found = 0;
    printf("\nEnter the roll number to update: ");
    scanf("%d", &x);
    for (int j = 0; j < i; j++)
    {
        if (st[j].roll == x)
        {
            printf("\nWhat do you want to update?");
            printf("\n1. First name\n2. Last name\n3. Roll number\n4. CGPA\n5. Course IDs\n");
            int z;
            scanf("%d", &z);

            switch (z)
            {
            case 1:
                printf("Enter the new first name: ");
                scanf("%s", st[j].fname);
                break;
            case 2:
                printf("Enter the new last name: ");
                scanf("%s", st[j].lname);
                break;
            case 3:
                printf("Enter the new roll number: ");
                scanf("%d", &st[j].roll);
                break;
            case 4:
                printf("Enter the new CGPA: ");
                scanf("%f", &st[j].cgpa);
                break;
            case 5:
                printf("Enter the new course IDs (5 courses): ");
                for (int k = 0; k < 5; k++)
                    scanf("%d", &st[j].cid[k]);
                break;
            default:
                printf("Invalid option.\n");
            }
            printf("UPDATED SUCCESSFULLY.\n");
            found = 1;
            break;
        }
    }
    if (!found)
        printf("\nStudent with this roll number not found.\n");
}

// drive code
int main()
{
    int choice;
    while (1)
    {
        printf("\n\nChoose the task you want to perform:\n");
        printf("1. Add student details\n");
        printf("2. Find student by roll number\n");
        printf("3. Find student by first name\n");
        printf("4. Find students by course ID\n");
        printf("5. Show total number of students\n");
        printf("6. Delete student details\n");
        printf("7. Update student details\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            find_rl();
            break;
        case 3:
            find_fn();
            break;
        case 4:
            find_c();
            break;
        case 5:
            tot_s();
            break;
        case 6:
            del_s();
            break;
        case 7:
            up_s();
            break;
        case 8:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}