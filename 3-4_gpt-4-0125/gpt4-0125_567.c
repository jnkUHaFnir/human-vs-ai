temp->word = (char*)malloc(sizeof(char));
strcpy(temp->word, word);
temp->word = (char*)malloc(strlen(word) + 1); // +1 for the '\0'
strcpy(temp->word, word);
while (temp != EOF)
int c; // Use int to correctly handle EOF
while ((c = getc(fp)) != EOF) {
    temp = toupper(c);

    /* your code */
}
if (fp)  {
    // Your file reading code.

    fclose(fp); // Close the file here.
}
