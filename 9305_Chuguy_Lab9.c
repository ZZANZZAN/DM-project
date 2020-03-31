#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*----------------------------------------------------------*/
struct Test{
        char *name;
        char *subject;
        float iq;
        float averenge;
        int age;
        int min;
        int mark[3];
};
typedef struct Test test;

/* ------- Function prototypes ------------------------- */

/* function to clear array of string */
void ClearStringArray(char **str, int n);

/* function to split string to array by separator */
char **simple_split(char *str, int length, char sep);

/* function to print header string without data */
void print_header();

/* function to create structure by array of strings*/
test *struct_fill(char **str);

/* function to output structure fields on console */
void struct_out(test *str0);

/* function to search struct */
test *ssearch(test *str0, int option1,int option2);

void sort_min(test **str0, int n);
/*----------------------------------------------------------*/

int main()
{
    enum {maxlen=128};
    test **test0=NULL;
    test *f=NULL;
    int slen,i,n,count,option1,option2,g=0;
    char **s2=NULL;
    char s1[maxlen];
    char sep;
    FILE *df;
/*----------------------------------------------------------*/
    df=fopen("struct-data.txt","r");
    if(df!=NULL)
    {
/*----------------------------------------------------------*/
        sep=';';
        n=0;
        while((fgets(s1,maxlen,df))!=NULL) n++;
        rewind(df);
        test0=(test**)malloc(n*sizeof(test*));
        if(test0!=NULL)
        {
            for(i=0,count=0;i<n;i++,count++)
            {
                fgets(s1,maxlen,df);
                slen=strlen(s1);
                s1[slen-1]='\0';
                slen=strlen(s1);

                s2=simple_split(s1,slen,sep);
                if(s2!=NULL)
                {
                    test0[i]=struct_fill(s2);
                    if(test0[i]==NULL)
                    {
                        puts("Structure not allocated!");
                        i=n;
                    }
                }
                else puts("Error at data reading!");
            }
/*----------------------------------------------------------*/
            option1=1;
            option2=100;
/*----------------------------------------------------------*/
            sort_min(test0,count);
            for(i=0;i<count;i++)
            {
                if((f=ssearch(test0[i],option1,option2))!=NULL)
                {
                    g++;
                    if(g==1)
                    {
                        print_header();
                    }
                    struct_out(test0[i]);
                }
            }
            if(g==0)
            {
                puts("There aren't students with this mark.");
            }
/*----------------------------------------------------------*/
            free(test0);
            test0=NULL;
        }
        else puts("No memory allocation!");
/*----------------------------------------------------------*/
        if(fclose(df)==EOF)
        {
            puts("Error closing!");
        }
        else
        {
            puts("Closing ok.");
        }
    }
    else puts("File not found!");
    getchar();
    return 0;
}

/*----------------------------------------------------------*/

void ClearStringArray(char **str, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        free(str[i]);
        str[i]=NULL;
    }
    free(str);
    str=NULL;

}

char** simple_split(char *str, int length, char sep)
{
    char **str_array=NULL;
    int i,j,k,m;
    int key,count;
    for(j=0,m=0;j<length;j++)
    {
        if(str[j]==sep) m++;
    }

    key=0;
    str_array=(char**)malloc((m+1)*sizeof(char*));
    if(str_array!=NULL)
    {
        for(i=0,count=0;i<=m;i++,count++)
        {
            str_array[i]=(char*)malloc(length*sizeof(char));
            if(str_array[i]!=NULL) key=1;
            else
            {
                key=0;
                i=m;
            }
        }
        if(key)
        {
            k=0;
            m=0;
            for(j=0;j<length;j++)
            {
                if(str[j]!=sep) str_array[m][j-k]=str[j];
                else
                {
                    str_array[m][j-k]='\0';
                    k=j+1;
                    m++;
                }
            }
        }
        else
        {
            ClearStringArray(str_array,count);
        }
     }
     return str_array;
}

void print_header()
{
    printf("|%15s |%8s |%5s |%5s |%3s |%4s |%4s|%4s|%4s|\n","fullname","subject","iq","averenge","age","min","ball 1","ball 2","ball 3");
    printf("+----------------+---------+------+---------+----+-----+------+------+------+\n");
}

test *struct_fill(char **str)
{
    test *str0=NULL;

    str0=(test*)malloc(sizeof(test));
    if(str0!=NULL)
    {
        str0->name=str[0];
        str0->subject=str[1];
        str0->iq=atoi(str[2]);
        str0->averenge=atoi(str[3]);
        str0->age=atoi(str[4]);
        str0->min=atoi(str[5]);
        str0->mark[0]=atoi(str[6]);
        str0->mark[1]=atoi(str[7]);
        str0->mark[2]=atoi(str[8]);
    }
    return str0;
}

void struct_out(test *str0)
{
    printf("|%15s |%8s |%3.2f |%3.2f    |%3d |%4d |%5d |%5d |%5d |\n",
        str0->name,str0->subject,str0->iq,str0->averenge,str0->age,str0->min,str0->mark[0],str0->mark[1],str0->mark[2]);
}

test *ssearch(test *str0, int option1,int option2)
{
    test *found;
    int i,count=0;

    found=(test*)malloc(sizeof(test));
    if(found!=NULL)
    {
        for(i=0;i<3;i++)
        {
            if(((str0->mark[i])>=option1)&&((str0->mark[i])<=option2)) count++;
        }
        if(count==3)
            found=str0;
        else found=NULL;
    }
    return found;
}

void sort_min(test **str0, int n)
{
    test *tmp_struct;
    int i,j;

    for(i=0;i<n;i=i+1)
    {
        tmp_struct=str0[i];
        for(j=i-1;(j>=0)&&((str0[j]->min)<(tmp_struct->min));j--)
            str0[j+1]=str0[j];
        str0[j+1]=tmp_struct;
     }
}
