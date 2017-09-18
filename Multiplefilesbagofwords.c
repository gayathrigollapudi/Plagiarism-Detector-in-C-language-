#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <dirent.h>
#include <ctype.h>
#include "bagofwords.h"

/*void Find_frequency();
void Find_words(char a[]);
void dot_product();*/
int directory(char dir_path[100], char file_names[100][100]);



int main(){
    char dir_path[100];         //to store directory path
	printf("enter the files location");
	fflush(stdin);
	scanf("%[^\n]",dir_path);   //reading directory path
	char file_names[100][100]={'\0'};   //to store file names

	int nofiles= directory(dir_path,file_names);    //returns no of text files in directory
	printf("--files--");
	int i;
	for(i=0;i<nofiles;i++)          //print file names in a row
	{
		printf(" %11.8s",file_names[i] );
	}
    memset(words_array,'\0',sizeof(words_array));       //empty words_array
    Find_words(file_names[0]);                          //finding words list
    int k;
    for(k=0;k<j;k++)
    {
        strcpy(str_var[0].fwords_array[k],words_array[k]);  //copying word list
    }
    Find_frequency();                   //finding frequency of words
    str_var[0].e_norm=sqrt(sum);        //finding euclidean norm
    //printf("%d",str_var[0].e_norm);
    for(row=0;row<nofiles;row++)
	{
		printf("\n");
		printf("%8s",file_names[row]);      //printing files in column
        for(col=0;col<nofiles;col++)
        {
           // words_array[100][100]={'\0'};
           if((strcmp(file_names[row],file_names[col]))==0)
            {
                printf("%12s","100");
            }
            else
            {
                memset(words_array,'\0',sizeof(words_array));        //empty words_array
                Find_words(file_names[col]);                        //finding words list
                int k;
                for(k=0;k<j;k++)
                {
                    strcpy(str_var[col].fwords_array[k],words_array[k]);    //copying word list
                }
                int i;
                /*for(i=0;str_var[index].fwords_array[i][0]!='\0';i++){
                printf("%s\n",str_var[index].fwords_array[i]);
                }*/
                Find_frequency();               //finding frequency of words
                str_var[col].e_norm=sqrt(sum);     //finding euclidean norm
                dot_product();
                str_var[col].plagiarism=(mul/(str_var[row].e_norm * str_var[col].e_norm));  //finding plagiarism for both files
                printf(" %11.2f",str_var[col].plagiarism*100);          //printing plagiarism percentage
            }
        }
	}
    return 0;
}




