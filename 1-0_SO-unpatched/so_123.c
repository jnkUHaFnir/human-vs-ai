    int saveWiz(struct Wizard * wiz)  //assuming you return 1 for success 0 for failure
    {
      File * fp = fopen("champion.txt","w");
      if(!fp) {
        //file opening failed
       return 0;
    }
      char * buff = malloc(100);
      if(buff) {
      sprintf(buff,"%s",wiz->name);
      sprintf(buff,"%d %d %d %d %d" , wiz->maxHealth,  wiz->attackMin,    wiz->attackRange, wiz->curHealth, wiz->winCount);
      fputs(buff,fp);
      fclose(fp);
      free(buff);
      return 1;
      }
    else {
       //memory allocation failed
    return 0;
    }
    }