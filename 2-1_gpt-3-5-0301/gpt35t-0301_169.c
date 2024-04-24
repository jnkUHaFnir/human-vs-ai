#define MAX_LINE_LENGTH 100 // maximum length of a line in the file

char line1[MAX_LINE_LENGTH];
char line2[MAX_LINE_LENGTH];

int i = 0, j = 0; // counters for the characters in each line
int line_num = 1; // variable to track which line we're on

while (1) {
    char c = fgetc(f); // read a character from the file

    if (c == EOF) { // end of file
        break;
    }

    if (c == '\n') { // end of a line
        if (line_num == 1) { // if it's the first line
            line1[i] = '\0'; // add null terminator at the end
            i = 0; // reset the character counter for the next line
            line_num++; // move to the next line
        } else { // if it's the second line
            line2[j] = '\0'; // add null terminator at the end
            j = 0; // reset the character counter for the next line
            break; // we're done reading the file
        }
    } else { // not end of line
        if (line_num == 1) { // if it's the first line
            line1[i++] = c; // add the character to the line1 array
        } else { // if it's the second line
            line2[j++] = c; // add the character to the line2 array
        }
    }
}

printf("1st line: %s\n", line1);
printf("2nd line: %s\n", line2);
