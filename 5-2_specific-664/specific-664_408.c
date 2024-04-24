#include <stdio.h>
#include <wchar.h>

wchar_t* sanitizeString(wchar_t *pCharArg1)
{
    wchar_t *pCharWorker = pCharArg1;

    /* The look-up map
     */
    wchar_t* charLookup[] = { L"ab", L"àa", L"ss", L"åa", L"ÅA", L"ÿy", L"XX", L"" };

    /* For every character in the input string we're going to verify
     * if the character needs to be replaced with one from the look-up
     * map.
     */
    while (*pCharWorker != '\0')
    {
        int finishedFlag = 0;
        int j = 0;
     
        /*
         * Loop the look-up map
         */
        while (*(charLookup[j]) != L'\0' && finishedFlag == 0)
        {
            if (*pCharWorker == *(charLookup[j]))
            {
                *pCharWorker = *(charLookup[j] + 1);
                finishedFlag = 1;
            }
            j++;
        }
        pCharWorker++;
    }
    return pCharArg1;
}

int main(int argc, char* argv[])
{
    wchar_t* z = argv[1];
    wprintf(L"PRINT : %ls \n", z);
    wchar_t* p2 = sanitizeString(z);
    wprintf(L"Sanitized string: %ls \n", p2);
    return 0;
}
