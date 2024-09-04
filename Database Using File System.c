#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "students.txt"
#define TEMP_FILENAME "temp.txt"
#define MAX_NAME_LENGTH 100
#define MAX_ADDRESS_LENGTH 200
#define PASSWORD "admin123"

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int roll;
    char address[MAX_ADDRESS_LENGTH];
} Student;

void insertData();
void searchDataByName();
void searchDataByRoll();
void displayData();
void deleteDataByRoll();
void menu();
int verifyPassword();

int main()
{
    int attempts = 3;
    while (attempts > 0)
    {
        if (verifyPassword())
        {
            printf("Access granted.\n");
            menu();
            return 0;
        }
        else
        {
            attempts--;
            printf("Incorrect password. %d attempts remaining.\n", attempts);
        }
    }
    printf("Access denied. Too many failed attempts.\n");
    return 1;
}

int verifyPassword()
{
    char input[20];
    printf("Enter password: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; 

    return strcmp(input, PASSWORD) == 0;
}

void menu()
{
    int choice;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert data to file\n");
        printf("2. Search data by name\n");
        printf("3. Search data by roll number\n");
        printf("4. Display the data\n");
        printf("5. Delete data by roll number\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice)
        {
        case 1:
            insertData();
            break;
        case 2:
            searchDataByName();
            break;
        case 3:
            searchDataByRoll();
            break;
        case 4:
            displayData();
            break;
        case 5:
            deleteDataByRoll();
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void insertData()
{
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    Student student;
    printf("Enter Name: ");
    fgets(student.name, MAX_NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = 0; 

    printf("Enter Roll: ");
    scanf("%d", &student.roll);
    getchar(); 

    printf("Enter Address: ");
    fgets(student.address, MAX_ADDRESS_LENGTH, stdin);
    student.address[strcspn(student.address, "\n")] = 0; 

    fprintf(file, "%s,%d,%s\n", student.name, student.roll, student.address);
    fclose(file);

    printf("Data inserted successfully.\n");
}

void searchDataByName()
{
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter the name to search: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; 

    Student student;
    char line[MAX_NAME_LENGTH + MAX_ADDRESS_LENGTH + 20]; 
    int found = 0;
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%[^,],%d,%[^\n]", student.name, &student.roll, student.address);
        if (strcmp(student.name, searchName) == 0)
        {
            printf("Name: %s\n", student.name);
            printf("Roll: %d\n", student.roll);
            printf("Address: %s\n", student.address);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("No data found for name: %s\n", searchName);
    }

    fclose(file);
}

void searchDataByRoll()
{
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    int searchRoll;
    printf("Enter the roll number to search: ");
    scanf("%d", &searchRoll);
    getchar(); 

    Student student;
    char line[MAX_NAME_LENGTH + MAX_ADDRESS_LENGTH + 20]; 
    int found = 0;
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%[^,],%d,%[^\n]", student.name, &student.roll, student.address);
        if (student.roll == searchRoll)
        {
            printf("Name: %s\n", student.name);
            printf("Roll: %d\n", student.roll);
            printf("Address: %s\n", student.address);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("No data found for roll number: %d\n", searchRoll);
    }

    fclose(file);
}

void displayData()
{
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
      printf("Developer of the program Sankar Das");
    }

    Student student;
    char line[MAX_NAME_LENGTH + MAX_ADDRESS_LENGTH + 20]; 
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%[^,],%d,%[^\n]", student.name, &student.roll, student.address);
        printf("Name: %s\n", student.name);
        printf("Roll: %d\n", student.roll);
        printf("Address: %s\n", student.address);
        printf("---------------------------\n");
    }

    fclose(file);
}

void deleteDataByRoll()
{
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen(TEMP_FILENAME, "w");
    if (file == NULL || tempFile == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    int deleteRoll;
    printf("Enter the roll number to delete: ");
    scanf("%d", &deleteRoll);
    getchar(); 

    Student student;
    char line[MAX_NAME_LENGTH + MAX_ADDRESS_LENGTH + 20]; 
    int found = 0;
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%[^,],%d,%[^\n]", student.name, &student.roll, student.address);
        if (student.roll == deleteRoll)
        {
            found = 1;
            printf("Record with roll number %d deleted.\n", deleteRoll);
        }
        else
        {
            fprintf(tempFile, "%s,%d,%s\n", student.name, student.roll, student.address);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename(TEMP_FILENAME, FILENAME);

    if (!found)
    {
        printf("No data found for roll number: %d\n", deleteRoll);
    }
}
