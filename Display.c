/*
   This file contains all the function which handle the
   functionality for displaying information about the Database.
*/

#include <stdio.h>
#include "CD_database_header.h"

//A function that prints a well formatted welcome message for the program.
void Welcome()
{
    printf("Welcome to the CD DATABASE.\n\n");
}


void Menu_display()
{
    printf("\n1. File: Create a New List\n");
    printf("2.       Open an existing file\n");
    printf("3.       Save the list\n");
    printf("4.       Save the list with New name\n");
    printf("5.       Append list to another file\n");
    printf("6. Edit: Create a New record\n");
    printf("7. View: Display a specific record\n");
    printf("8.       Display all the records\n");
    printf("9. Exit\n\n");
}

//Function to display a specific record in currently open file
void Display_specific_record(cd_t *CD, int CD_no)
{
    printf("The details of CD %d are....\n", CD_no + 1);
    printf("The Title of the CD is %s\n",CD->title);
    printf("The Name of the artist is %s\n",CD->artist);
    printf("The number of tracks are %d\n",CD->num_of_tracks);
    if(CD->album)
    {
        printf("album\n");
    }
    else
    {
        printf("single\n");
    }
    printf("The price of the CD is %.2f\n",CD->price);
    printf("\n");
}


//Function to display all records of current file
void Display_all_records(cd_t List[])
{
    for(int i = 0; i < number_of_entries; i++)
    {
        Display_specific_record(&List[i],i);
    }
}
