static string printInt(Object self) {
  string str;
  char* tmp;
  asprintf(&tmp, "%lu", getValueInt(self));
  str = GC_realloc(tmp, strlen(tmp) + 1);
  return str;
}
static string printInt(Object self) {
  string str = GC_MALLOC(sizeof(char) * 20); // assuming the maximum length of the integer string
  snprintf(str, 20, "%lu", getValueInt(self));
  return str;
}
