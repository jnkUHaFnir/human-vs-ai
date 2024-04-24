for (size_t i = 0; i < strlen(cAFirst); i++) {
  k = (int)cAFirst[i];
  if ((k <= 90) && (k >= 65)) {
    uc++;
  }
  if ((k >= 97) && (k <= 122)) {
    lc++;
  }
}
size_t len = strlen(cAFirst);
for (size_t i = 0; i < len; i++) {
  k = (int)cAFirst[i];
  if ((k <= 90) && (k >= 65)) {
    uc++;
  }
  if ((k >= 97) && (k <= 122)) {
    lc++;
  }
}
if(cAFirst[strlen(cAFirst) - 1] == '\n') {
   cAFirst[strlen(cAFirst) - 1] = '\0';
}
