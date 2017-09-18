struct word_freq    //structure to store word and word corresponding frequency
{
    char word[20];
    int freq;
};

struct files_plagiarism     //structure to store each file words list,euclidean norm,plagiarism value,words frequency,no of words
{
   char fwords_array[100][100];
   float e_norm;
   float plagiarism;
   struct word_freq str_freq[100];
   int noofwords;
}str_var[100];


char words_array[100][100]={'\0'}; //to store words in each file
int j,l,sum,mul;
int row,col;    //variables to print matrix form
int directory(char dir_path[100],char file_names[100][100])     //to read text files from directory
{
	int count = 0;
	DIR *p;
	struct dirent *pp;
	chdir(dir_path);
	p = opendir (dir_path); //to open directory
	if (p != NULL)
	{
		while ((pp = readdir (p))!=NULL)
		{
			int length = strlen(pp->d_name);
			if (strncmp(pp->d_name + length - 4, ".txt", 4) == 0)   //taking txt files
			{
				strcpy(file_names[count],pp->d_name);
				count++;
            }
        }

	(void) closedir (p);
	}
    return count;
}
void Find_words(char a[])   //finding words in file
{
    char c[100]={'\0'};
    j=0;
    FILE *ptr;
    ptr=fopen(a,"r");
    int k=0,i;
    int p1=fscanf(ptr,"%[^\n]\n",c);    //reading single line in file
    while(p1 != -1)
    {
        strlwr(c);
        for(i=0;c[i]!='\0';i++)
        {
            if((c[i]>96 && c[i]<123) || (c[i]>47 && c[i]<58) || c[i]=='_')
            {
                words_array[j][k]=c[i];
                k++;
            }
            else if(c[i]==' ')
            {
                j++;
                k=0;
            }
        }
        j++;
        k=0;
        p1=fscanf(ptr,"%[^\n]\n",c);    //reading single line in file
    }
    //printf("%d",j);
    /*for(i=0;words_array[i][0]!='\0';i++){
        printf("%s\n",words_array[i]);
    }*/
}
void Find_frequency()   //finding words frequency
{
    int i,c,k,m,l=0;
    //printf("%d",j);
    for(i=0;i<j;i++)
    {
        c=1;
        if(words_array[i][0]!='\0')
        {
          for(k=i+1;k<j;k++)
          {
            if(strcmp(words_array[i],words_array[k])!=0){}
            else
            {
                c++;
                words_array[k][0]='\0';
            }
          }
          for(m=0;m<strlen(words_array[i]);m++)
          {
            str_var[col].str_freq[l].word[m]=words_array[i][m];
          }
          str_var[col].str_freq[l].freq=c;
          l++;
        }
    }
    str_var[col].noofwords=l;
    /*for(i=0;i<l;i++){
        printf("%s\t\t%d\n",str_var[index].str_freq[i].word,str_var[index].str_freq[i].freq);
    }*/
    sum=0;
    for(i=0;i<l;i++)
    {
        sum+=((str_var[col].str_freq[i].freq)*(str_var[col].str_freq[i].freq));
    }
}
void dot_product()      //finding dot product of 2 files
{
    mul=0;
     int i,j;
     int k;
    //printf("%d,%d\n",str_var[index-1].noofwords,str_var[index].noofwords);
    for(i=0;i<str_var[row].noofwords;i++)
    {
        for(j=0;j<str_var[col].noofwords;j++)
        {
            if(strcmp(str_var[row].str_freq[i].word,str_var[col].str_freq[j].word)==0)
            {
                mul+=((str_var[row].str_freq[i].freq)*(str_var[col].str_freq[j].freq));     //dot product of two files
                //k=mul;
            }
        }
    }

}
