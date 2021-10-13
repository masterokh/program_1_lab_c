#include<locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define _crt_secure_no_warnings

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
    if (argc == 3)
    {

        FILE* file;
        char ch;
        char prevch = '\0';

        int lines = 1;
        int words = 0;
        int characters = 0;
        int file_size = 0;
        char* filename = argv[1];

         file = fopen(/*filename*//*"info.txt"*/filename, "r");
        if (file == NULL)
        {
            fprintf(stderr, "Cannot open file %s \n" /*,filename*/);
             file_size = -1;
             exit(-1);
        }
        

            while ((ch = fgetc(file)) != EOF)
           {
              if (isspace(ch))
              {
                  if (ch == '\n')
                       lines++;
              }
             else 
             {
                 if (prevch == '\0' || isspace(prevch))
                        words++;
             }
                file_size++;
                // characters++;
                prevch = ch;
            }
         fclose(file);

        //printf("Number of characters: %d\n", characters);
        //printf("Number of words: %d\n", words);
        //printf("Number of lines: %d\n", lines);
        //printf("File size:%d\n",file_size);
        char strl[] = "-l";
        char strll[] = "--lines";
        char strm[] = "-w";
        char strmm[] = "--words";
        char strs[] = "-c";
        char strss[] = "--bytes";
        if ((strcmp (strl, argv[argc - 1]) == 0) || (strcmp (strll, argv[argc - 1]) == 0))
        {
            printf("Number of lines: %d\n", lines);
        }
        else if ((strcmp (strm, argv[argc - 1]) == 0) || (strcmp (strmm, argv[argc - 1]) == 0))
        {
            printf("Number of words: %d\n", words);
        }
        else if ((strcmp (strs, argv[argc - 1]) == 0) || (strcmp (strss, argv[argc - 1]) == 0))
        {
            printf("Size of file:%d\n",file_size);
        }
    } 
    else printf("\nНе верный ввод");
    return 0;
}