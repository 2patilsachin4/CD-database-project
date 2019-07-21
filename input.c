/*
    This file contains all the input functions used to Create new records.
*/

#include <stdio.h>
#include "CD_database_header.h"

//A function to display a string which waits for user to press enter
void enter(char string[])
{
    printf("%s",string);
    fflush(stdin);
    getchar();
}

//A function to read a string. The string is dynamically allocated, hence should be freed in the end.
char *read_file_name()
{
    char buffer[MAX_BUFFER];
    printf("Enter the name of the file: \n");
    fflush(stdin);
    fgets(buffer,MAX_BUFFER,stdin);
    trim_newline(buffer);
    return strdup(buffer);
}


//A function to read an integer value
int read_int(char string[])
{
    int ret_value = 0;
    printf("%s",string);
    fflush(stdin);
    scanf("%d",&ret_value);
    return ret_value;
}

//A function to read an float value
float read_float(char string[])
{
    float ret_value = 0;
    printf("%s",string);
    fflush(stdin);
    scanf("%f",&ret_value);
    return (ret_value);
}

//A function to display a string and wait for user input and read it
int yesno(char string[])
{
    char type;
    int  true_false;
    for( ; ; )
    {
        printf("%s\n",string);
        fflush(stdin);
        scanf("%c",&type);
        type = toupper(type);
        if(type == 'Y' || type == 'N')
            break;
        enter("Error- Only 'y' or 'n' are allowed.\n");
    }
    true_false = type == 'Y';
    return true_false;
}


//A function to read a string
void read_string(char string[], char answer[], int MAX)
{
    printf("%s",string);
    fflush(stdin);
    fgets(answer,MAX,stdin);
    trim_newline(answer);
}


//Function to Create a new record
void Create_CD(cd_t *CD)
{
    int type;

    //Read in the details about the title,artist and number of tracks in CD
    read_string("Enter the title of the CD: \n", CD->title, MAX_BUFFER);
    printf("\n");
    read_string("Enter the name of the Artist: \n",CD->artist,MAX_BUFFER);
    printf("\n");
    CD->num_of_tracks = read_int("Enter the number of tracks: \n");
    printf("\n");

    //Check whether the CD is an album or single
    type = yesno("Is this CD an album?: Enter y for yes and n for no ");
    printf("\n");
    CD->album = type;               //album_or_single = 1 for album and 0 for single

    //Read in the price of the CD
    CD->price = read_float("Enter the price of the CD: \n");
    printf("\n");
}



