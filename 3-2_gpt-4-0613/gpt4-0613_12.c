int count=1 ; 
char c;
for (c = getc(in); c != EOF; c = getc(in)) {
    if (c == '\n') // Increment count if this character is newline
        count = count + 1;
}

rewind(in); // here

char* lines[count];
