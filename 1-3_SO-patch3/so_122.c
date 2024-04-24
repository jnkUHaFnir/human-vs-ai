        int main(int argc, char *argv[]) {
            Tree *myTree = NULL;
            char buffer[256] = { 0 };
            int temp;
            int i = 0;
            FILE *fp = fopen(argv[1], "r");
            if (fp)  {
                while ((temp = getc(fp)) != EOF) {
                    temp = toupper(temp);
                    if (temp >= 'A' && temp <= 'Z') {
                        buffer[i] = temp;
                        i++;
                    } else {
                        buffer[i] = '\0';
                        if (i > 0) {
                            puts(buffer);
                            myTree = insert(myTree, buffer);
                            memset(buffer, 0, sizeof(buffer));
                            i = 0;
                        }
                    }
                }
                fclose(fp);
                show(myTree);
            }
            return 0;
        }