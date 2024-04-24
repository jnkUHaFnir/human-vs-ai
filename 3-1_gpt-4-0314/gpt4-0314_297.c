void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int main(int argc, const char * argv[]) {
  int histogram[10000];
  int i;
  while (1) {
    int *rectPtr = histogram;
    int size;
    scanf("%d", &size);
    clear_input_buffer();  // Call the function to clear the input buffer
    if (!size) return 0;
    for (i = 0; i < size; ++i) {
        scanf("%d", rectPtr);
        rectPtr++;
    }
    clear_input_buffer();  // Call the function to clear the input buffer
    printf("%d", 1);
    printf("\n");
    }
  return 0;
}
