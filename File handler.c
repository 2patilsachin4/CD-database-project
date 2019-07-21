/*
    This file contains all the functions which handle functionality
    of file options like in notepad
*/

#include <stdio.h>
#include "CD_database_header.h"


//Creates a new list to add CD entries
cd_t *New_list()
{
    int cd_count;
    cd_t *CD_array;
    cd_count = read_int("How many CD's you would like in this list.?: ");
    CD_array = malloc(cd_count*sizeof(cd_t));
    for(int i = 0; i < cd_count; i++)
    {
        //For neat output
        printf("\n");
        //Take CD details for input
        printf("Enter the details of CD %d : \n", i + 1);
        Create_CD(&CD_array[i]);
        number_of_entries += 1;
    }
    return CD_array;
}


//Opens an existing list by reading it from a file
cd_t *Open_list()
{
    number_of_entries = 0;
    cd_t *CD_array;
    int file_size;
    int Number_of_cds;
    char filename[MAX_BUFFER];
    read_string("Enter the name of file with path(include \\)", filename, 200);
    current_file_name = strdup(filename);   //appoint the global variable to the opening file name;
    file_initialized = 1;                   //Flag variable to show file has been opened
    file_size = binary_file_size(filename);  //Finding the file size in bytes
    Number_of_cds = file_size/sizeof(cd_t);  //Dividing file size by size of a Cd structure to read number of CDs present

    CD_array = malloc(Number_of_cds*sizeof(cd_t));
    FILE *Optr = fopen(filename,"rb");
    if(Optr == NULL)
    {
        fprintf(stderr,"Could not open %s - %s\n",filename,sys_errlist[errno]);
        exit(1);
    }

    for(int i = 0; i < Number_of_cds; i++)
    {
        fread(&CD_array[i],sizeof(cd_t),1,Optr);
        number_of_entries += 1;
    }
    return CD_array;
}

//Saves a newly created list
void Save_list(cd_t List[], char filename[])
{
    int entries = number_of_entries;
    FILE *Sptr;
    Sptr = fopen(filename,"wb");
    for(int i = 0; i < entries; i++)
    {
        fwrite(&List[i],sizeof(cd_t),1,Sptr);
        number_of_entries -= 1;
    }
    fclose(Sptr);
}


//Saves a list with new name
void Save_list_new_name(cd_t List[],char filename[])
{
    int entries = number_of_entries;
    FILE *Sptr;
    Sptr = fopen(filename,"wb");
    for(int i = 0; i < entries; i++)
    {
        fwrite(&List[i],sizeof(cd_t),1,Sptr);
        number_of_entries -= 1;
    }
    fclose(Sptr);
}


//Appends current list to another file
void List_appender(cd_t Append_entry[])
{
    char filename[MAX_BUFFER];
    FILE *Aptr;
    int entries = number_of_entries;
    int file_does_exist;
    read_string("Enter the name of file with path(include \\)", filename, 200);
    file_does_exist = file_exist(filename);
    if(file_does_exist)
    {
        Aptr = fopen(filename,"ab");
    }
    else
    {
        Aptr = fopen(filename,"wb");
    }

    if(Aptr == NULL)
    {
        fprintf(stderr,"Could not open %s - %s\n",filename,sys_errlist[errno]);
        exit(1);
    }
    for(int i = 0; i < entries; i++)
    {
        fwrite(&Append_entry[i], sizeof(cd_t), 1, Aptr);
        number_of_entries -= 1;
    }
    fclose(Aptr);
}
