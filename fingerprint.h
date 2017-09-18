int hash_table1[100]={0};
int hash_table2[100]={0};
char f1[100][100]={'\0'};
char f2[100][100]={'\0'};
int len1,len2;
char rd[100][100]={'\0'};

int read_data(char fn[50],char f[100][100]);
int directory(char direction[100],char file_names[100][100]);
int space_remove(char f[100][100],int len,int hash[100]);
float common(int hash_table1[100], int len1, int hash_table2[100], int len2);

int read_data(char fn[50], char f[100][100])    //to read data from each file
{
	FILE *fp;
	fp=fopen(fn,"r");       //opening file to read
	char c;
	int i=0,j=0;
	while(1)
	{
		c=fgetc(fp);
		int ascii=(int)(c);
		if(c==EOF)
        {
           break;
        }
		else if(c==' '|| c=='\n')
		{
			f[i][j]='\0';
			i++;
			j=0;
		}
		if((ascii>=65 && ascii <=90) || (ascii>=97 && ascii<=122))
		{
		f[i][j]=tolower(c); //converting data to lowercase
		j++;
		}

	}
	int len=i+1;
	fclose(fp);     //closing file
	return len;
}
int space_remove(char f[100][100],int len,int hash[100])
{
	char a[500]={'\0'};
	int i=0,j,p=0,q,r,x,y;
	char rd[100][100]={'\0'};
 	int arraylen=0;
	while(i<len)
	{
		j=0;
		while(f[i][j]!='\0')
		{
			a[p]=f[i][j];   //copying file data
			p++;
			j++;
		}
		i++;
	}
	int k=5;
	for(i=0;i<strlen(a)-9;i++)
	{
		p=0;
		y=i;
		while(p<k){
			rd[i][p]=a[y];
			p++;
			y++;
		}
	}
	long long s;
	int g=0;
	for(q=0;q<i;q++)
    {
		s=0;
		g=0;
		for(r=0;r<strlen(rd[q]);r++)
		{
			s+=(rd[q][r]*pow(k,k-(r+1)));
            g=s%10007;
            hash[q]=g;  //storing each word hashing value
        }
	}
	arraylen=q;
	return arraylen;
}
int directory(char direction[100],char file_names[100][100])
{

	int count = 0;
	DIR *p;
	struct dirent *pp;
	chdir(direction);
	p = opendir (direction);
	if (p != NULL)
	{
		while ((pp = readdir (p))!=NULL)
		{
			int length = strlen(pp->d_name);
			if (strncmp(pp->d_name + length - 4, ".txt", 4) == 0)           //gathering only txt files
			{

				strcpy(file_names[count],pp->d_name);
				count++;
	      		}
	    	}

	(void) closedir (p);
	}
	return count;
}
float common(int hash_table1[100], int len1, int hash_table2[100], int len2)         //common values from hash tables
{
	int i,j,e=0;
	float percent=0;
	for(i=0;i<len1;i++)
	{
		for(j=0;j<len2;j++)
		{
			if(hash_table1[i]==hash_table2[j])
			{
				e=e+1;
			}
		}
	}

	percent=(float)(2*e)/(len1+len2);
	return percent;
}
