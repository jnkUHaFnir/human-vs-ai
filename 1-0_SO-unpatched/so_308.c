    char * extract_sub_string(char *in, const char *key);
    int main(void)
    {
        char buf[100] = {0};    
        
        sprintf(buf, "Found sub_string: %s\n", extract_sub_string(line, fetch));
      return 0;
    }
    char * extract_sub_string(char *in, const char *key)
    {
        char *tok;
        tok = strtok(in, " ");
        while(tok)
        {
            if(strcmp(tok, key) == 0)
            {
                in = tok;//re-assign ptr to found string
                break;
            }
            tok = strtok(NULL, " ");
        }
        return in;
    }