#include <pcre.h>
const char* pattern = "[^\\w\\s]+";
pcre* regex = pcre_compile(pattern, 0, &error, &error_offset, NULL);
// Assuming the retrieved data is stored in a variable called 'data'
char* cleaned_data = pcre_replace(regex, NULL, data, strlen(data), 0, NULL);
free(cleaned_data);
