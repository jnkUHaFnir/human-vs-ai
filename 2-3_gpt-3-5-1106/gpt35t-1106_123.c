int saveWiz(struct Wizard * wiz)
{
  FILE * fp = fopen("champion.txt","w");
  char * buff = malloc(100);
  
  sprintf(buff, "Name: %s\nMax Health: %d\nAttack Range: %d - %d\nCurrent Health: %d\nWin Count: %d\n", wiz->name, wiz->maxHealth, wiz->attackMin, wiz->attackRange, wiz->curHealth, wiz->winCount);
  
  fputs(buff,fp);
  fclose(fp);
  free(buff);
  return 0;
}
