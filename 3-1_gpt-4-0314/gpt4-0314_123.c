int saveWiz(struct Wizard * wiz)
{
  FILE * fp = fopen("champion.txt","w");
  if (!fp) return -1; // File opening failed

  char * buff = malloc(100);
  sprintf(buff, "Name: %s\n", wiz->name);
  fputs(buff, fp);

  sprintf(buff, "Max Health: %d\n", wiz->maxHealth);
  fputs(buff, fp);

  sprintf(buff, "Attack Min: %d\n", wiz->attackMin);
  fputs(buff, fp);

  sprintf(buff, "Attack Range: %d\n", wiz->attackRange);
  fputs(buff, fp);

  sprintf(buff, "Current Health: %d\n", wiz->curHealth);
  fputs(buff, fp);

  sprintf(buff, "Win Count: %d\n", wiz->winCount);
  fputs(buff, fp);

  fclose(fp);
  free(buff);
  return 0; // Success
}
