#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NO_ARGS 1
#define EMPTY_FILE 2
#define ERROR_FILE 3

typedef struct class
{
    char name[200];
    float avrg_mark;
}stud;

//calculate average mark
float rating(float sum, float count)
{
    if(count<3)
    {
        sum+= 2*(3-count);
        count=3;
    }
    return(sum/count);
}

//calculate the best mark among students
int best_stud(int number, stud* s)
{
    float max = 0;

    int number_of_stud=0;

    for(int i =0; i<number; i++)
    {
        if(s[i].avrg_mark>max)
        {
            max=s[i].avrg_mark;
            number_of_stud=i;
        }
    }

    return number_of_stud;
}
 
 
int main(int argc, char* argv[])
{
    if(argc<2)
    {
        printf("Please, enter the path to the file before starting the program");
        return NO_ARGS;
    }

    FILE *f =fopen(argv[1] , "r");

    if(f==NULL)
    {
        perror("fopen() failed");
    }
   

    char* str= (char*)calloc(1000, sizeof(char));
    stud arr[30];
   
    int num_str =0;

    while(feof(f)==0)
    {
        fgets(str,999,f);
     
        int len_str = strlen(str);

        float sum_mark =0;
        float count_mark = 0;

        //-'\0' - '\n'
        len_str-=2;

        while(isdigit(str[len_str]) || str[len_str] == ',')
        //for(;len_str>0;len_str--)
        {
            
            if(isdigit(str[len_str]))
            {
                sum_mark += (str[len_str]-'0');
                count_mark++;
                
            }
            len_str--;
        }

        
       
        for(int i= 0; i<len_str; i++)
            {
                arr[num_str].name[i]=str[i];
            }

        arr[num_str].avrg_mark =rating(sum_mark,count_mark);

        num_str++;

    }

    if(ferror(f))
        {
            perror("Incorrect work of file" );
            return ERROR_FILE;
        }
    fclose(f);

    int best = best_stud(num_str,arr);
 
    printf("Ученик с самым высоким средним баллом:  %f \n%s",  arr[best].avrg_mark,
    arr[best].name);
}
