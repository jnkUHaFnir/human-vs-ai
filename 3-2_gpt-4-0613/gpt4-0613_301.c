char *result;
int length = 0; 
int bufsize = 50;

result = malloc(bufsize); // Initialize with some reasonable size

if (!result) {
    // Handle error
}

for (int i = 0; i < someCondition; i++) {
    char *objectString = objectToString(object[i]); // Get string from object
    int objectStringLength = strlen(objectString);

    if(length + objectStringLength >= bufsize) {
        bufsize *= 2; // We double the buffer size as needed
        result = realloc(result, bufsize); 
        
        if (!result) {
            // Handle error
        }
    }

    sprintf(result + length, "%s", objectString);
    length += objectStringLength;
}

if (freezeCount < 0)
    sprintf(result + length, "%s", "]");
else
    sprintf(result + length, "%s", ")");
// When you're done with the buffer, don't forget to release it
free(result);
