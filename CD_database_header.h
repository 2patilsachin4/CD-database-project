/*
    This file contains all the library includes
    ,structure definitions and function prototype definitions
*/

//All preprocessor directives
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Constant definitions
#define MAX_BUFFER 200

//Structure and typedef definitions
struct CD_type{
    char title[MAX_BUFFER];
    char artist[MAX_BUFFER];
    int  num_of_tracks;
    int  album;
    float price;
};

typedef struct CD_type cd_t;


//Global Variables
int number_of_entries;
int List_initialized;
char *current_file_name;
int file_initialized;
cd_t *List;

//Function Prototypes
//Display prototype
void Welcome();
void Menu_display();
void Display_specific_record(cd_t *CD, int CD_no);
void Display_all_records(cd_t List[]);

//Input prototypes
void Create_CD(cd_t *CD);
void enter(char string[]);
int yesno(char string[]);
int read_int(char string[]);
float read_float(char string[]);
void read_string(char string[], char answer[], int MAX);
char *read_file_name();

//File handler prototypes
cd_t *New_list();
cd_t *Open_list();
void Save_list(cd_t List[], char filename[]);
void Save_list_new_name(cd_t List[], char filename[]);
void List_appender(cd_t Append_entry[]);

//Utilities prototypes
void trim_newline(char string[]);
int binary_file_size(char filename[]);
int warning();
int file_exist(char filename[]);
void if_file_initialized(int *file_ini_flag);
int goodbye(cd_t List[],char current_file_name[]);
void reset_everything();
