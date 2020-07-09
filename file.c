#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NO_ARGS 1
#define EMPTY_FILE 2
#define ERROR_FILE 3

//calculate average mark
float rating(float s, float c)
{
    if(c<3)
    {
        s+= 2*(3-c);
        c=3;
    }
    return(s/c);
}

//calculate the best mark among students
int best_stud(int number, stud* r)
{
    float max = 0;

    int number_of_stud;

    for(int i =0; i<number; i++)
    {
        if(r[i].avrg_mark>max)
        {
            max=r[i].avrg_mark;
            number_of_stud=i;
        }
    }

    return number_of_stud;
}
 
typedef struct class
{
    char name[200];
    float avrg_mark;
}stud;
 
int main(int argc, char* argv[])
{
    if(argc<1)
    {
        printf("Please, enter the path to the file before starting the program");
        return NO_ARGS;
    }

    char name_f[argc];

    for(int i=0; i<argc; i++)
    {
        name_f[i] = argv[i];
    }

    FILE *f =fopen(name_f , "r");

    if(f==NULL)
    {
        return EMPTY_FILE;
    }

    char str= calloc(100, sizeof(char));
    stud arr[30];
   
    char name_s[200];
    int num_str =0;

    while(feof(f)==0)
    {
        fgets(str,999,f);
     
        int len_str = strlen(str);
        float sum_mark =0;
        float count_mark = 0;
 
        while(isdigit(str[len_str] || str[len_str] == ','))
        {
            if(isdigit(str[i]))
            {
                sum_mark += (str[i]-'0');
                count_mark++;
            }
            len_str--;
        }

        int end_name = len_str-1;

        arr[num_str].avrg_mark =rating(sum_mark,count_mark);
       
        for(int i= 0; i<end_name; i++)
            {
                arr[num_str].name[i]=str[i];
            }

        num_str++;

    }

    if(ferror(f))
        {
            perror("AAAAAA:" );
            return ERROR_FILE;
        }
    fclose(f);

    int number_of_stud = best_stud(num_str,arr);
 
    printf("Ученик с самым высоким средним баллом:  %f \n%s",  arr[number_of_stud].avrg_mark,
    arr[number_of_stud].name);
}
