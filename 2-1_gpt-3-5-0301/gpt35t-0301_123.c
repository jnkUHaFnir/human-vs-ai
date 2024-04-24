int saveWiz(struct Wizard * wiz)
{
  FILE * fp = fopen("champion.txt","w");
  if (!fp) {
    perror("Error opening file");
    return 1;
  }

  fprintf(fp, "Name: %s\n", wiz->name);
  fprintf(fp, "Max health: %d\n", wiz->maxHealth);
  fprintf(fp, "Attack min: %d\n", wiz->attackMin);
  fprintf(fp, "Attack range: %d\n", wiz->attackRange);
  fprintf(fp, "Current health: %d\n", wiz->curHealth);
  fprintf(fp, "Win count: %d\n", wiz->winCount);

  fclose(fp);
  return 0;
}
