/*
    This is a CD DATABASE program
*/
#include <stdio.h>
#include <stdlib.h>
#include "CD_database_header.h"

//Local Variables

int main(/*int argc, char *argv[]*/)
{
    //int current_CDs = 0;  //A variable to keep track of number of CD's in the database
    int choice;
    int decision;
    int file_exists;
                 //Creating a pointer of type cd_t to track a list of CD's

    //Print out a good welcome message which is well formatted
    Welcome();

    //Free the memory and end the program with a goodbye message at the exit of program
    //atexit(goodbye(List,current_file_name));

    //Start the forever loop for the database functioning
    for( ; ; )
    {
        //Display the whole menu with current number of entries in the system and currently opened file.
        Menu_display();
        printf("The number of CD_records currently stored in memory are: %d\n",number_of_entries);
        printf("Name of file opened currently: %s\n",current_file_name);

        choice = read_int("What would you like to do? (Enter a number(1-9)) \n");
        switch(choice)
        {
            //done
            case 1: if(List_initialized)          //Check for unsaved entries in the system
                    {
                        decision = warning();     //Warn the user over losing unsaved data
                        if(decision)
                        {
                            free(List);
                            number_of_entries = 0;    //Free up the memory for new list
                            List_initialized = 0;
                            if_file_initialized(&file_initialized);  //If any file was open previously. Close iy
                        }
                        else
                            break;
                    }
                    List = New_list();               //Initialize the new list
                    List_initialized = 1;
                    break;


            case 2: if(List_initialized)
                    {
                        decision = warning();
                        if(decision)
                        {
                            free(List);
                            number_of_entries = 0;
                            List_initialized = 0;
                        }
                        else
                            break;
                    }
                    List = Open_list();
                    List_initialized = 1;
                    break;


            case 3: if(!List_initialized)
                    {
                        printf("No entries to save.\n");
                        break;
                    }
                    current_file_name = read_file_name();
                    file_initialized = 1;
                    file_exists = file_exist(current_file_name);
                    if(file_exists)
                    {
                        decision = yesno("A file with the same name already exists.Do you want to overwrite (y for yes, n for no)\n");
                        if(!decision)
                            break;
                    }
                    Save_list(List,current_file_name);
                    List_initialized = 0;
                    free(List);
                    if_file_initialized(&file_initialized);
                    break;


            case 4: if(!List_initialized)
                    {
                        printf("No entries to save.\n");
                        break;
                    }
                    current_file_name = read_file_name();
                    file_initialized = 1;
                    file_exists = file_exist(current_file_name);
                    if(file_exists)
                    {
                        decision = yesno("A file with the same name already exists.Do you want to overwrite (y for yes, n for no)\n");
                        if(!decision)
                            break;
                    }
                    Save_list_new_name(List,current_file_name);
                    List_initialized = 0;
                    free(List);
                    if_file_initialized(&file_initialized);
                    break;


            case 5: if(!List_initialized)
                    {
                        printf("No entries to append.\n");
                        break;
                    }
                    List_appender(List);
                    List_initialized = 0;
                    free(List);
                    if_file_initialized(&file_initialized);
                    break;

            case 6:
                {
                    if(List_initialized)
                    {
                        decision = warning();
                        if(decision)
                        {
                            free(List);
                        }
                        else
                            break;
                    }
                    number_of_entries = 0;
                    List = malloc(sizeof(cd_t));
                    Create_CD(List);
                    List_initialized = 1;
                    number_of_entries += 1;
                    if_file_initialized(&file_initialized);
                    break;
                }

            case 7: if(!List_initialized)
                    {
                        printf("No entries to display.\n");
                        break;
                    }
                    int entry_no;
                    printf("Enter the number of CD record which you would like to see: (1:%d)?",number_of_entries);
                    fflush(stdin);
                    scanf("%d",&entry_no);
                    Display_specific_record(&List[entry_no],entry_no);
                    break;


            case 8: if(!List_initialized)
                    {
                        printf("No entries to display.\n");
                        break;
                    }
                    Display_all_records(List);
                    break;

            case 9: if(List_initialized)
                    {
                        decision = warning();
                        if(decision)
                        {
                            free(List);
                        }
                        else
                            break;
                    }
                    exit(1);
                    break;

            default: printf("Not a valid input\n");
                    break;
        }
    }
    free(List);  //At the end of the program free up any memory being used up by List pointer
    free(current_file_name);
    return 0;
}

