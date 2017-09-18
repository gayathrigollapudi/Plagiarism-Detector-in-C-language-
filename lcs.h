void character_list();  //to find character list for each file
void substring();       //to find longest substring in two files
char char_list[100]={'\0'};     //array to store characters
int row,col,j,lcs;

struct string_compare       //to store each file character list
{
  char fchar_list[100];

}str_var[10];

int directory(char dir_path[100],char file_names[100][100]) //to read all text files from directory
{
	int count = 0;
	DIR *p;
	struct dirent *pp;
	chdir(dir_path);
	p = opendir (dir_path);
	if (p != NULL)
	{
		while ((pp = readdir (p))!=NULL)
		{
			int length = strlen(pp->d_name);
			if (strncmp(pp->d_name + length - 4, ".txt", 4) == 0)   //taking only txt files
			{
				strcpy(file_names[count],pp->d_name);
				count++;
            }
        }

	(void) closedir (p);
	}
    return count;
}
void character_list(char a[])       //to find character list
{
    char c[100]={'\0'};
    j=0;
    FILE *ptr;
    ptr=fopen(a,"r");
    int i;
    int p1=fscanf(ptr,"%[^\n]\n",c);    //reading single line from file
    while(p1 != -1)
    {
        strlwr(c);
        for(i=0;c[i]!='\0';i++)
        {
            if((c[i]>96 && c[i]<123) || (c[i]>47 && c[i]<58) || c[i]=='_' ||c[i]==' ')      //removing special characters
            {
                char_list[j]=c[i];
                j++;
            }
        }
        p1=fscanf(ptr,"%[^\n]\n",c);     //reading single line from file
    }
    //printf("%s\n",char_list);

}
void substring()        //finding longest substring in two files
{

    int le,le1,len;
    float plagiarism=0;
    le=strlen(str_var[row].fchar_list);
    le1=strlen(str_var[col].fchar_list);
    //printf("%d,%d",le,le1);
    lcs=0;
    int i,j,t,a[20],k;
    for(i=0;i<le;i++)
    {
        for(j=0;j<le1;j++)

        {
            memset(a,'\0',sizeof(a));
            k=0;
            t=i;
            while(i<le && j<le1 && str_var[row].fchar_list[i]==str_var[col].fchar_list[j])
            {
              a[k]= str_var[row].fchar_list[i] ;
                i++;
                j++;
                k++;
            }
            len=k;
            if(len != 0)
            {
                if(a[0]==' ' && a[k-1]==' ')
                {
                    len=len-2;
                }
                else if(a[0]==' ' || a[k-1]==' ')
                {
                    len--;
                }
                if(lcs<len)
                {
                    lcs=len;
                }
            }
            i=t;
        }
    }
   //printf("%d",lcs);
    plagiarism=(int)(((float)(lcs*2)/(le+le1))*100);        //finding lcs
    //plagiarism=lcs*2;
    printf(" %11.2f",plagiarism);                   //printing lcs of two files

}

