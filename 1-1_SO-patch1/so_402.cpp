std::string str0;
const std::string str1 = "abc";
// assign str1 to str0
str0 = str1;
cout << str0 << endl;  // output: abc
If you insist on using C:
char* str0;
const char* str1 = "abc";
str0 = malloc(strlen(str1) + 1);
// if you use a c++ compiler you need instead:
// str0 = (char*) malloc(strlen(str1) + 1);
strcpy(str0, str1);
// and free after use
// if you use C++ this will not help much
// as pretty much any exception above will cause your code to get out of `free`,
// causing a memory leak
free(str0);