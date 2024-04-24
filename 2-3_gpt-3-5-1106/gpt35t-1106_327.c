char input[100];
int numOfDef;

while(1) {
  printf("Enter a positive number: ");
  fgets(input, sizeof(input), stdin);
  if (sscanf(input, "%d", &numOfDef) == 1 && numOfDef > 0) {
    break;
  } else {
    printf("Invalid input, please try again\n");
  }
}
