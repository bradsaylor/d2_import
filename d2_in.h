#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "search_string.h"


void format(char *file_line);
void combine(char *str, char *address, char *value);
void file_out(char *out_filename);

FILE *in_file;
FILE *out_file;
char file_line[100];
char *address;
char *value;
char *out_filename = "d2_import.txt";
char *in_filename = "d2.h";

void format(char *file_line)
{

  char c = ',';
  char *pr = file_line, *pw = file_line;
  while(*pr)
    {
      *pw = *pr++;
      pw += (*pw != c);
    }
  *pw = '\0';
}


void combine(char *file_line, char *address, char *value)
{

}


void file_out(char *out_filename)
{

}
