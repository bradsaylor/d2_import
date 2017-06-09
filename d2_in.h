#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "search_string.h"
#include "remove_string.h"

void format(char *file_line);
void split(char *str, char *address, char *value);
void file_out(char *out_filename);

FILE *in_file;
FILE *out_file;
char file_line[100];
char address[9];
char value[9];
char *out_filename = "d2_import.txt";
char *in_filename = "d2.h";

void split(char *file_line, char *address, char *value)
{
  int i;
  address[0] = value[0] = '0';
  address[1] = value[1] = 'x';
  address[9] = value[9] = '\0';
    
  for(i = 2; i < 8; i ++)
    {
      *(address + i) = file_line[i];
    }

  for(i = 8; i < 14; i++)
    {
      *(value + i - 6) = file_line[i];
    }
}

