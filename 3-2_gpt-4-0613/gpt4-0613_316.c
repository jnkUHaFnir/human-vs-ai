#include <stdio.h>

#define MAX_DIGITS 241
#define N_BYTES 3

void print_decimal(unsigned char* n, int size) {
  int digits[MAX_DIGITS] = {0};
  
  for (int i = size - 1; i >= 0; --i) {
    int carry = n[i];
    for (int j = 0; j < MAX_DIGITS; ++j) {
      int val = digits[j] * 256 + carry;
      digits[j] = val % 10;
      carry = val / 10;
    }
  }
  
  int not_zero_found = 0;
  for (int i = MAX_DIGITS - 1; i >= 0; --i) {
    if (!not_zero_found && digits[i] == 0) continue;
    not_zero_found = 1;
    printf("%d", digits[i]);
  }
  
  if (!not_zero_found) printf("0");
  printf("\n");
}

int main() {
  unsigned char n[N_BYTES] = {1, 2, 3};
  print_decimal(n, N_BYTES);
  return 0;
}
