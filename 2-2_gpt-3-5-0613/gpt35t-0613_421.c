if(strcmp((*pointer).name, (*(pointer + j + 1)).name) > 0)
fgets(book1[i].name, sizeof(book1[i].name), stdin);
// remove the newline character at the end of the input
book1[i].name[strcspn(book1[i].name, "\n")] = '\0';

fgets(book1[i].author, sizeof(book1[i].author), stdin);
// remove the newline character at the end of the input
book1[i].author[strcspn(book1[i].author, "\n")] = '\0';
