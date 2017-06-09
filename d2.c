#include "d2_in.h"

/*
* Purpose
** take d2.cfg file and reformat register value writes
*** format:  0x[address], 0x[value]
* Method
** read in .cfg file line by line
** skip lines that do not begin with "0x"
** remove all ,'s and 0x's
** ignore first chunk of data
** combine next six numbers as address
** combine next six numbers as value
** append 0x's in front
** output in .txt file in two columns
*/


int main()
{

  in_file = fopen(in_filename, "r");
  while(fgets(file_line, 100, in_file) != NULL)
    {
  
      if(search_string(file_line, "0x"))
	{
          format(file_line);
	  printf("%s", file_line);
	}
    }

  fclose(in_file);

}
//read in .cfg file line by line
//skip lines that do not begin with "0x"
//remove all ,'s and 0x's
//ignore first chunk of data
//combine next six numbers as address
//combine next six numbers as value
//append 0x's in front
//output in .txt file in two columnsuu
