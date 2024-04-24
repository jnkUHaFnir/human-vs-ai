#include <ctype.h>

/* ... */

fgets(input1, 254, title);
fgets(input2, 254, author);
input1[strcspn(input1, "\n")] = '\0';
input2[strcspn(input2, "\n")] = '\0';

/* Convert input1 to uppercase */
for (int i = 0; input1[i]; i++) {
    input1[i] = toupper(input1[i]);
}

/* Convert input2 to uppercase */
for (int i = 0; input2[i]; i++) {
    input2[i] = toupper(input2[i]);
}

printf("<%s> <%s>\n", input1, input2);
