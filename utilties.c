
/*This file contains all the utility functions */


#include "CD_database_header.h"

//This function will trim a newline character from the string
void trim_newline(char string[])
{
    if(string[strlen(string)-1] == '\n')
        string[strlen(string)-1] = '\0';
}

//This function is used to get the size of any file.
int binary_file_size(char filename[])
{
    int file_size;
    FILE *fptr = fopen(filename,"rb");
    if(fptr == NULL)
    {
        fprintf(stderr,"Could not open %s - %s\n",filename,sys_errlist[errno]);
        exit(1);
    }

    //Move the file pointer to the end
    fseek(fptr,0,SEEK_END);
    file_size = ftell(fptr);
    fclose(fptr);
    return file_size;
}

//This function will be called whenever user forgets to save any unsaved CD entries present in the system.
int warning()
{
   int decision;
   decision = yesno("There are unsaved entries present in the system. Do you want to continue?(y for yes,n for no)");
   return decision;
}

//Checks if a file already exists. If yes returns 1 otherwise 0
int file_exist(char filename[])
{
    FILE *file;
    if((file = fopen(filename,"rb")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}


//Checks if currently a file is open. If yes, then points the file to null and initializes file_flag to 0 again.
void if_file_initialized(int *file_ini_flag)
{
    if(*file_ini_flag)
    {
        current_file_name = NULL;
        *file_ini_flag = 0;
    }
}


//What to do at program exit
int goodbye(cd_t List[],char current_file_name[])
{
    free(List);
    free(current_file_name);
    printf("\n\n The Database is shutting down now.....\n");
    exit(1);
}


void reset_everything()
{
    free(List);
    number_of_entries = 0;    //Free up the memory for new list
    List_initialized = 0;
    if_file_initialized(&file_initialized);  //If any file was open previously. Close iy
}
