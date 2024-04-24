#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ConvertToDynamicString(const char* prefix, int number, const char* suffix)
{
    char numberString[4];
    snprintf(numberString, 4, "%03d", number);

    size_t prefixLen = strlen(prefix);
    size_t suffixLen = strlen(suffix);
    size_t numberLen = strlen(numberString);

    char* result = (char*)malloc(prefixLen + numberLen + suffixLen + 1);
    if (!result) {
        // Handle memory allocation failure
        return NULL;
    }

    strcpy(result, prefix);
    strcat(result, numberString);
    strcat(result, suffix);

    return result;
}

int main()
{
    int frontValue = GetWord("@FrontVIB@", 0);
    int rearValue = GetWord("@RearVIB@", 0);

    char* string1 = ConvertToDynamicString("*FV", frontValue, "#");
    char* string2 = ConvertToDynamicString("*RV", rearValue, "#");

    if (string1 && string2) {
        printf("%s\n", string1); // Output *FV200#
        printf("%s\n", string2); // Output *RV200#

        free(string1); // Free dynamically allocated memory
        free(string2);
    }

    return 0;
}
