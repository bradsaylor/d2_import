
int remove_string(char *str, char *find_string);


int remove_string(char *str, char *find_string)
{
  char *pw = str;
  int match_count;
  int match_flag;

  //printf("\n\ngot here\n\n");

  if(strlen(find_string) > strlen(str)) return 0;

  for(int i = 0; i < (strlen(str) - (strlen(find_string) - 1)); i++)
    {
      match_count = 0;
      match_flag = 0;
      for(int j = 0; j < strlen(find_string); j++)
        {
          if(find_string[j] == str[i + j])
          {
            match_count++;
            if(match_count == strlen(find_string))
              {
                match_flag = 1;
              }
          }
        }
      if(match_flag)
	{

	  i += (strlen(find_string) - 1);
	}
      else
	{
	  *pw = str[i];
	  pw++;
	}
    }
  *pw = '\0';
  return 1;
}

