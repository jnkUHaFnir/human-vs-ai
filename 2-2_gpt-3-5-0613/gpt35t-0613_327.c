while ((scanf("%d", &numOfDef) != 1) || (numOfDef <= 0))
{
  printf("Not a positive number. Try again: ");
  while (getchar() != '\n');  // Clear input buffer
}
