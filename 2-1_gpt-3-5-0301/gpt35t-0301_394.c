int main() {
  size_t buffer_size = 1024; /* starting size for buffer */
  char *buffer = malloc(buffer_size);
  if (buffer == NULL) {
    /* handle error */
    return -1;
  }
  
  size_t message_len = 0;
  for (int i = 0; i < 200000; i++) {
    int size = snprintf(NULL, 0, "%d \n", i);
    char *a = malloc(size + 1);
    sprintf(a, "%d \n", i);

    message_len += 1 + strlen(a); /* 1 + for separator ';' */
    if (message_len > buffer_size) {
      buffer_size += message_len; /* increase buffer size */
      buffer = realloc(buffer, buffer_size);
      if (buffer == NULL) {
        /* handle error */
        return -1;
      }
    }
    strncat(buffer, a, message_len);
  }
  
  char substr[56];
  memcpy(substr, buffer, 56);
  printf("%s", substr);

  free(buffer);
  return 1;
}
typedef struct string_node {
  char *string;
  struct string_node *next;
} string_node_t;

int main() {
  string_node_t *head = NULL;
  string_node_t *tail = NULL;
  
  for (int i = 0; i < 200000; i++) {
    int size = snprintf(NULL, 0, "%d \n", i);
    char *a = malloc(size + 1);
    sprintf(a, "%d \n", i);

    string_node_t *node = malloc(sizeof(string_node_t));
    node->string = a;
    node->next = NULL;
    
    if (head == NULL) {
      head = node;
    } else {
      tail->next = node;
    }
    tail = node;
  }

  /* concatenate strings */
  size_t message_len = 0;
  for (string_node_t *node = head; node != NULL; node = node->next) {
    message_len += strlen(node->string);
  }
  char *buffer = malloc(message_len + 1);
  char *ptr = buffer;
  for (string_node_t *node = head; node != NULL; node = node->next) {
    size_t len = strlen(node->string);
    memcpy(ptr, node->string, len);
    ptr += len;
  }
  *ptr = '\0';
  
  char substr[56];
  memcpy(substr, buffer, 56);
  printf("%s", substr);

  /* free memory */
  for (string_node_t *node = head; node != NULL; ) {
    string_node_t *next = node->next;
    free(node->string);
    free(node);
    node = next;
  }
  free(buffer);
  
  return 1;
}
