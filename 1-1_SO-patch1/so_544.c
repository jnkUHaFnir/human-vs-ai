    void bar(const char *fileName, int *pX) {
        FILE *fp = fopen(fileName, "r");
        char buffer[15];
        if (fp != NULL) {
            fgets(buffer, sizeof buffer, fp);
            sscanf(buffer, "%d", &pX);
            fclose(fp);
        }
    }
    void foo(void) {
        int x = 1;
        bar("test.txt", &x);
        /* do something with x */
    }