while(scanf("%49[^:]\n", x)==1){
  getchar();// this function gets the next character, which is ':'
  strncat(x, ":", 1);// this adds ':' at the end of the string
}
