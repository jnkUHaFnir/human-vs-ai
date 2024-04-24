float fib(float x) {
  if (x <= 0)
    return 0;
  
  float a = 0, b = 1, tmp;
  for(int i = 2; i <= x; i++) {
    tmp = a + b;
    a = b;
    b = tmp;
  }
  
  return b;
}
