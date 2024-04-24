int testRemoveMeio(){

  struct list_t *list = list_create();

  // Use malloc to ensure the strings are in writable memory
  char *tdata[3];
  tdata[0] = malloc(4 * sizeof(char)); // Allocate space for "abc\0"
  strcpy(tdata[0], "   ");
  tdata[1] = strdup("2014");
  tdata[2] = strdup("Fixe!");

  struct tuple_t *t = tuple_create2(3, tdata);

  sprintf(t->tuple[0], "abc"); // Now this is safe, as t->tuple[0] points to writable memory

  // Follow with your original logic, making sure to free duplicated/copied strings when done
  return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  char *s = malloc(4 * sizeof(char)); // Ensure space for "DEF\0"
  strcpy(s, "ABC");
  printf("%s\n",s);
  sprintf(s,"DEF");
  printf("%s\n",s);
  free(s);
  return 0;
}
