#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <dirent.h>
#include <ctype.h>
#include "fingerprint.h"

int main()
{
	char direction[100];        //array to store directory path
	printf("enter the files location");
	fflush(stdin);
	scanf("%[^\n]",direction);      //reading directory path
	char file_names[100][100]={'\0'};       //array to store all file names
	int nofiles= directory(direction,file_names);   //calculating no of files in directory
	printf("%d",nofiles);
	printf(": check : ");
	int i;
	for(i=0;i<nofiles;i++)              //printing file names in a row
	{
		printf("%11.8s ",file_names[i] );
	}
	int row,col;
	for(row=0;row<nofiles;row++)
	{
		printf("\n");
		printf("%8s",file_names[row]);  //printing file name in a column
		for(col=0;col<nofiles;col++)
		{
			char fn1[50];
			char fn2[50];
			int l1,l2;
			int b,p;
			float plagiarism;
			memset(f1,'\0',sizeof(f1));
			memset(f2,'\0',sizeof(f2));

			for(b=0;b<strlen(file_names[row]);b++)
            {
                fn1[b] = file_names[row][b];    //copying first file name
            }
			fn1[b] = '\0';
			for(b=0;b<strlen(file_names[row]);b++)
            {
                fn2[b] = file_names[col][b];        //copying second file name
            }
			fn2[b] = '\0';
			if((strcmp(file_names[row],file_names[col]))==0)
			{
				printf("%12s","100");
			}
			else
			{
                l1=read_data(fn1,f1);   //reading data from first file
                l2=read_data(fn2,f2);      //reading data from second file
                len1=space_remove(f1,l1,hash_table1);
                len2=space_remove(f2,l2,hash_table2);
                plagiarism=common(hash_table1,len1,hash_table2,len2);
                printf(" %11.2f",plagiarism*100);
			}
		}
	}
}





