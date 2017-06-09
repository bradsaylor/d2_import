





#include <stdio.h>
#include <string.h>


int main()
{
  void read_file(FILE *fp, char *data);  
  FILE *fp;
  fp = fopen("d2.h", "r");
  char *data;
  
  for(int i = 0; i<20; i++)
    {
      read_file(fp, data);
      //printf("%s\n", data);
    }

  
  fclose(fp);
}


void read_file(FILE *fp, char *data)
{

    char line[100];
    fgets(line, 100, fp);
        printf("%s\n", line);
    strcpy(data, line);
}
