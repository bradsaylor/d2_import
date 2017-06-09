
int search_string(char *str, char *find_string);


int search_string(char *str, char *find_string)
{

  int match_count;

  if(strlen(find_string) > strlen(str)) return 0;

  for(int i = 0; i < (strlen(str) - (strlen(find_string) - 1)); i++)
    {
      match_count = 0;
      for(int j = 0; j < strlen(find_string); j++)
        {
          if(find_string[j] == str[i + j])
          {
            match_count++;
            if(match_count == strlen(find_string))
              {
                return 1;
              }
          }
        }
    }
  return 0;
}

