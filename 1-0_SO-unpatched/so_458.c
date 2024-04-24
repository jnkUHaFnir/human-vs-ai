    #include <stdio.h>
    #include <string.h>
     char* replaceindex(char *s, char *replace, unsigned int start, unsigned int end)
     {
      
       char *rep= (char*)malloc(strlen(s)+1);
       memset(rep,0,strlen(s)+1);
       if(strlen(replace)<=(end-start))
         { memcpy(rep,s,start);
          memcpy(rep+start,replace,strlen(replace));
          memcpy(rep+start+strlen(replace),s+end,strlen(s+end));
          return rep;
        }
        else{free(rep);}
        return s;
     
     }
     
           
    int main() {
    char* z="This answer is crazy";
    printf("%s",replaceindex(z,"Code",5,11));
    
    return 0;
    } 