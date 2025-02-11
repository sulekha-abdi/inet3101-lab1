char databaseName[150];//name of database stored here
int recordchange = 0;//the amount of modifications made so far


//Function deleteRecord 
void DeleteRecord() {
    printf("You have entered the delete last record function %s\n", databaseName);
    recordchange++;
}