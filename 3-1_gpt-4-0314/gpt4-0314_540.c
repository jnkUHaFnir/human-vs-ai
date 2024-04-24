#include <stdio.h>

#define REPEAT_HYPHEN(num) REPEAT_HYPHEN_HELPER(num)
#define REPEAT_HYPHEN_HELPER(num) REPEAT_HYPHEN_##num()
#define REPEAT_HYPHEN_3() "---"
#define REPEAT_HYPHEN_4() "----"
#define REPEAT_HYPHEN_5() "-----"
// Add more cases as needed

int main() {
  printf("%s\n", REPEAT_HYPHEN(3)); // Output: ---
  printf("%s\n", REPEAT_HYPHEN(4)); // Output: ----
  printf("%s\n", REPEAT_HYPHEN(5)); // Output: -----
  // Call with other numbers as needed
  return 0;
}
