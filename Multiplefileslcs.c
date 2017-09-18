#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include "lcs.h"

int directory(char dir_path[100], char file_names[100][100]);

int main()
{
    char dir_path[100]; //array to store directory path
	printf("enter the files location");
	fflush(stdin);
	scanf("%[^\n]",dir_path);       //reading directory path from console
	char file_names[100][100]={'\0'};

	int nofiles= directory(dir_path,file_names);    //returns no of text files in directory
	printf("--files--");
	int i;
	for(i=0;i<nofiles;i++)
	{
		printf(" %11.8s",file_names[i] );           //printing file names in a row
	}
	memset(char_list,'\0',sizeof(char_list));       //empty the character list
    character_list(file_names[0]);
    strcpy(str_var[0].fchar_list,char_list);
    //printf("%s\n",str_var[0].fchar_list);
    for(row=0;row<nofiles;row++)
	{
		printf("\n");
		printf("%8s",file_names[row]);          //printing file names in a column
        for(col=0;col<nofiles;col++)
        {
            if((strcmp(file_names[row],file_names[col]))==0)
            {
                printf("%12s","100");
            }
            else
            {
                memset(char_list,'\0',sizeof(char_list));       //empty the character list
                character_list(file_names[col]);
               //printf("%s",str_var[row].fchar_list);
                strcpy(str_var[col].fchar_list,char_list);
                //printf("%s\n",str_var[col].fchar_list);
                substring();                                    //finding longest substring
                //printf("%d%s",str_var[col].plagiarism,"%");
                 //printf(" %11.2f",str_var[col].plagiarism);
            }
        }
	}
    return 0;

}

