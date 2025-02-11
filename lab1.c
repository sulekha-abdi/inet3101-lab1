#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//functions
void PrintAllRecords();
void AddRecord();
void DeleteRecord();
void PrintNumRecords();
void PrintDatabaseSize();
void PrintNumChanges (bool print);

//variables
char databaseName[50];//name of database stored here
int recordchange = 0;//the amount of modifications made so far

int main(int argc, char *argv[]) {
    int ans; //variable that stores the menu options

    
    if (argc < 2) { //this is for command line argumnt
        printf("Error: Database name needed to go on.\n"); //if the database name isn't written error is displayed
        return 1; 
    }

    // The data here is stored 
    snprintf (databaseName, sizeof(databaseName), "%s", argv[1]);


    // User can choose from Menu 
    while (1) {
        printf("\nDatabase: %s\n", databaseName);
        printf("1) Print all records\n");
        printf("2) Add record\n");
        printf("3) Delete last record\n");
        printf("4) Print number of records\n");
        printf("5) Print database size\n");
        printf("6) Print number of changes\n");
        printf("7) Exit\n");
        printf("Please enter your selection >");

        // Read user info
        if (scanf("%d", &ans) != 1) {
            printf("Invalid. Enter a number.\n");
            while (getchar() != '\n'); // clear invalid input
            continue;
        }

        // Case/Switch Statements
        switch (ans) {
            case 1:
                PrintAllRecords();
                break;
            case 2:
                AddRecord();
                break;
            case 3:
                DeleteRecord();
                break;
            case 4:
                PrintNumRecords();
                break;
            case 5:
                PrintDatabaseSize();
                break;
            case 6:
                PrintNumChanges(true);
                break;
            case 7:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid please try again\n");
        }
    }
    return 0;
}

void PrintAllRecords() {
    printf("You have entered the Print all records function %s\n", databaseName);
}

//This function allows for the data to be added 
void AddRecord() {
    int partNum;
    char partName[50];
    float size;
    char partSizeMetric[10];
    float cost;

    printf("Enter part number: ");
    scanf("%d", &partNum);
    printf("Enter part name: ");
    scanf(" %[^\n]", partName);
    printf("Enter part size: ");
    scanf("%f", &size);
    printf("Enter part size metric: "); 
    scanf("%s", partSizeMetric);
    printf("Enter part cost: ");
    scanf("%f", &cost);


//shows the output
    printf("You entered\n");
    printf("Part Number: %d\n", partNum);
    printf("Part Name: %s\n", partName);
    printf("Size: %.2f %s\n", size, partSizeMetric);
    printf("Cost: $%.2f\n", cost);
    PrintNumChanges(false);
}

//Function deleteRecord 
void DeleteRecord() {
    printf("You have entered the delete last record function %s\n", databaseName);
    recordchange++;
}

//Function print number of records 
void PrintNumRecords() {
    printf("You have entered the Print number of records function %s\n", databaseName);
}

//Function printDatabaseSize 
void PrintDatabaseSize() {
    printf("You have entered the Print database size function %s\n", databaseName);
}

void PrintNumChanges(bool print) { // This function allows for updates on whats been changed so far
    if (print) { //if this statement is true displays whats been altered so far
        printf("Database has been changed %d times\n", recordchange);
    } else {
        recordchange++;//the number of changes increment by 1
        printf("%d changes made\n", recordchange);
    }
}