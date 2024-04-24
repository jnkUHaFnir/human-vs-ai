int testRemoveMeio(){

  int result, i;
  struct list_t *list = list_create();

  // Change the "tdata" array to hold mutable char arrays
  char tdata[3][32] = {{"   "}, {"2014"}, {"Fixe!"}};
  struct tuple_t *t = tuple_create2(3, tdata);
  struct tuple_t *tdups[4];

  struct entry_t *entries[4];

  // Use strcpy instead of sprintf to copy the string
  strcpy(t->tuple[0], "abc");
  tdups[0] = tuple_dup(t);
  entries[0] = entry_create(tdups[0]);
  list_add(list, entries[0]);

  //extra code similar to above
  return 0;
}
struct tuple_t *tuple_create2(int tuple_dim, char tdata[][32]){

    struct tuple_t *t = (struct tuple_t *) malloc(sizeof(struct tuple_t));

    if(t == NULL)
        return NULL;

    t->tuple_dimension = tuple_dim;

    // Allocate memory for the tuple
    t->tuple = (char **) malloc(tuple_dim * sizeof(char *));
    for (int i = 0; i < tuple_dim; i++) {
        t->tuple[i] = (char *) malloc(32 * sizeof(char));
        strcpy(t->tuple[i], tdata[i]); // Copy the strings from tdata[][] to the tuple
    }
    
    return t;
}
#include <stdio.h>
#include <string.h>
int main(void)
{
  char * s = "ABC";
  printf("%s\n",s);
  sprintf(s,"DEF");
  printf("%s\n",s); 
  return 0;
}
#include <stdio.h>
#include <string.h>
int main(void)
{
  char s[10] = "ABC";
  printf("%s\n",s);
  strcpy(s, "DEF");
  printf("%s\n",s); 
  return 0;
}
