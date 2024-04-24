    int saveWiz(struct Wizard * wiz)
    {
      File * fp = fopen("champion.txt","w");
      char * buff = malloc(100);
      sprintf(buff,"%s",wiz->name);
      sprintf(buff,"%d %d %d %d %d" , wiz->maxHealth,  wiz->attackMin,    wiz->attackRange, wiz->curHealth, wiz->winCount);
      fputs(buff,fp);
      fclose(fp);
    }