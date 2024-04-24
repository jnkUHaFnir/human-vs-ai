void recursive_call(int n, void (*func)()) {
  if (n > 0) {
    (*func)(); // Call the function pointed to by func
    recursive_call(n-1, func); // Recursive call with n-1
  }
}

void my_function1() {
  printf("Hello from function 1\n");
}

void my_function2() {
  printf("Hello from function 2\n");
}

int main() {
  void (*function_pointers[2])() = {my_function1, my_function2};

  // Call each function twice
  recursive_call(2, function_pointers[0]);
  recursive_call(2, function_pointers[1]);

  return 0;
}
