#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// You should use wchar_t for wide characters.
wchar_t* sanitizeString(wchar_t *pCharArg1) {
    // The rest of the logic needs to be adapted for wchar_t
    // ...
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, ""); // Set locale to allow for wide character output

    if(argc < 2) {
        wprintf(L"No input string provided.\n");
        return 1;
    }

    char* z = argv[1];
    wchar_t wz[1024] = {0};
    // Convert z to a wide character string before processing
    // This is naive and only works if the input is actually ASCII
    mbstowcs(wz, z, 1024);

    wprintf(L"PRINT: %ls \n", wz);
    wchar_t* p2 = sanitizeString(wz);
    wprintf(L"Sanitized string: %ls \n", p2);

    return 0;
}
