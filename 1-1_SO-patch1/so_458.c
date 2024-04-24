     void replaceindex(char *s, char *replace, unsigned int start, unsigned int end)
        {
         
          char *rep= (char*)malloc(strlen(s)+1);
          memset(rep,0,strlen(s)+1);
          if(slrlen(replace)<=(end-start))
            { memcpy(rep,s,start-1);
             memcpy(rep+start,replace,strlen(replace));
             memcpy(rep+end,s+end,strlen(s+end));
             s=rep;
           }
           else{free(rep);}
           
        
        }