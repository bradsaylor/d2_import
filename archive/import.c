#include <stdio.h>
#include <string.h>


/*
DECLARE EXTERNAL VARIABLES
*/

char * format(char *string);
char tmp_string[100];


int main(){

  
  /*DECLARE INTERNAL VARIABLES*/

  FILE *fp1;
  FILE *fp2;
  const int BUFFER = 100;
  const int DATA_SIZE = 5;
  char input[BUFFER];
  char *temp[7];
  char temp1[DATA_SIZE];
  char temp2[DATA_SIZE];
  char temp3[DATA_SIZE];
  char temp4[DATA_SIZE];
  char temp5[DATA_SIZE];
  char temp6[DATA_SIZE];
  char temp7[DATA_SIZE];
  char address[BUFFER];
  char value[BUFFER];
  int test;

  
  /*OPEN INPUT AND OUTPUT FILES*/

  fp1 = fopen("mag2cfg.h", "r");
  fp2 = fopen("output.txt", "w");

  
  /*READ AND WRITE LOOP*/
  
  while(fgets(input, BUFFER, fp1) != NULL){

    
    strcpy(address,"");    //CLEAR HOLDER STRINGS
    strcpy(value,"");
    strcpy(temp1,"");
    strcpy(temp2,"");
    strcpy(temp3,"");
    strcpy(temp4,"");
    strcpy(temp5,"");
    strcpy(temp6,"");
    strcpy(temp7,"");
    
    /*PARSE FILE LINE TO STRINGS WITH APPROPRIATE FORMATTING*/
    test=sscanf(input,"%s %s %s %s %s %s %s",temp1, temp2, temp3, temp4, temp5, temp6, temp7);
    
    if((!strcmp(temp1,"0x00,"))&&test){    //SKIP HEADER BEGIN ON DATA LINE '0X00'
     
      strcat(temp2,temp3);    //COMBINE STRINGS 2-4 AND 5-7
      strcat(temp2,temp4);
      strcat(temp5, temp6);
      strcat(temp5, temp7);
      
      strcpy(address,format(temp2));    //SEND CAT'D STRINGS FOR FORMATTING AND ASSIGN
      strcpy(value,format(temp5));
      
      fprintf(fp2,"0x%s,0x%s\n",address, value);    //OUTPUT TO FILE
    }
    
  }

  
  fclose(fp1);    //CLOSE FILES
  fclose(fp2);

  
  return 0;  
}




char * format(char string[]){

  
  int count = 0;        //COUNTERS TO TRACK STRING POSITIONS
  int tmp_count = 0;

  
  while(string[count]){

    
    if((string[count]!=' ')&&(string[count]!='x')&&(string[count]!=',')){    //SKIP SELECTED CHARACTERS
      tmp_string[tmp_count]=string[count];   //ASSIGN TO NEW STRING 
      tmp_count++;
    }

    
    else if(string[count]=='x'){    //DECREMENT NEW STRING COUNTER TO ACCOUNT FOR '0' OF '0x'
      tmp_count--;
    }
    
    
    count++;
  }


  
  return tmp_string;
}
