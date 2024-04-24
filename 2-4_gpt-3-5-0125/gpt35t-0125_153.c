#include <stdio.h>
#include <string.h>

int minute, hour;

void parseString(char *str) {
    char *token;
    token = strtok(str, "&"); // tokenize the string using "&" as delimiter
    token = strtok(NULL, "&"); // get the hour value
    hour = atoi(token); // convert the hour value to integer
    
    token = strtok(NULL, "&"); // get the minute value
    minute = atoi(token); // convert the minute value to integer
}

int main() {
    char str[] = "?cmd=ASET&08&30";
    
    if (strncmp(str, "?cmd=ASET", 9) == 0) { // check if the string starts with "?cmd=ASET"
        parseString(str);
        printf("Hour: %d, Minute: %d\n", hour, minute);
    } else {
        printf("String does not start with '?cmd=ASET'\n");
    }
    
    return 0;
}
