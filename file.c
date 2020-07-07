#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

 
float rating(float s, float c)
{
    if(c<3)
    {
        s+= 2*(3-c);
        c=3;
    }
    return(s/c);
}
 
typedef struct class
{
    char name[200];
    float med_mark;
}stud;
 
int main()
{
    char name_f[] = "/home/ekaterina/rs/documents/file";
    FILE *f =fopen(name_f , "r");

    if(f==NULL)
    {
        printf("Файл пуст");
        return NULL;
    }

    char str[1000];
    stud arr[30];
   
    float sum_mark;
    float count_mark;
    char name_s[200];
    int end_name;
    int num_str =0;

    while(feof(f)==0)
    {
        fgets(str,999,f);
     
        int len_str = strlen(str);
        end_name = len_str;
        sum_mark =0;
        count_mark = 0;
 
   
        for(int i=len_str; i>0;i--)
        {
            if(isdigit(str[i]))
            {
                sum_mark += (str[i]&0x0F);
                count_mark++;
                end_name = i-1;
            }
        }

    arr[b].med_mark =rating(sum_mark,count_mark);
   
    memset (name_s, 0, sizeof(name_s));
   
    for(int i= 0; i<end_name; i++)
        {
            name_s[i]=str[i];
        }

    strcpy(arr[num_str].name, name_s);

    num_str++;

    }

    if(ferror(f))
        {
            perror("AAAAAA:" );
        }
    fclose(f);
    

    double max = 0;

    int number_of_stud;

    for(int i =0; i<b; i++)
    {
        if(arr[i].med_mark>max)
        {
            max=arr[i].med_mark;
            number_of_stud=i;
        }
    } 
printf("Ученик с самым высоким средним баллом:  %f \n%s",  arr[number_of_stud].med_mark,
 arr[number_of_stud].name);
}
