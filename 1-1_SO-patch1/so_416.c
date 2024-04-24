    FILE *hypo_table[4][4],*fp=NULL;
    char buf[10];
    
        for(i = 0; i < 4; i++) {
            for(j = 0; j < 4; j++) {
                   sprintf(buf,"%d%d.txt",i,j);    
                   fp = fopen(buf, "w");
                   if(fp!=NULL)
                      {
                      hypo_table[i][j] =fp;
                      fp=NULL;  
                      }    
                   else
                      {
                      perror("ERROR");
                      //Handle As you want or simply exit. 
                      } 
                   }
              }