int main(void) {
  str1 s1;
  s1.array = (char *)malloc(10 * sizeof(char)); // allocate memory for the array
  strcpy(s1.array, "Damn"); // copy the string "Damn" into the array
  display(&s1); // call the display function and pass the address of s1
  free(s1.array); // free the allocated memory
  return 0;
}
void display(str1 *p1) {
  printf("%s", p1->array);
}
