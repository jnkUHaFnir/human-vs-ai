#define LENGTH 45
#define HASH_SIZE 65536

typedef struct node {
  char word[LENGTH + 1];
  struct node* next;
} node;

node* global_hash[HASH_SIZE] = {NULL};

unsigned int hash_func(char* hash_val) {
  unsigned int h = 0;
  for (int i = 0, j = strlen(hash_val); i < j; i++) {
    h = (h << 2) ^ hash_val[i];
  }
  return h % HASH_SIZE;
}

bool load(const char *dictionary) {
  node* new_node;
  char word[LENGTH + 1];

  FILE* dic = fopen(dictionary, "r");
  if(dic == NULL) {
    fprintf(stdout, "Error: File is NULL.");
    return false;
  }

  while(fscanf(dic, "%s", word) != EOF) {
    new_node = malloc(sizeof(node));
    if(new_node == NULL) {
      return false;
    }
    strcpy(new_node->word, word);
    unsigned int hash_indx = hash_func(new_node->word);
    new_node->next = global_hash[hash_indx];
    global_hash[hash_indx] = new_node;
  }

  fclose(dic);
  return true;
}
