    int bar(const char *fileName, int *pX) {
        char buffer[15];
        FILE *fp = fopen(fileName, "r");
        int success = 0;
        if (fp != NULL) {
            fgets(buffer, sizeof buffer, fp);
            if (sscanf(buffer, "%d", pX) == 1)
                success = 1;
            fclose(fp);
        }
        return success;
    }
    void foo(void) {
        int x = 1;
        bar("test.txt", &x);
        /* do something with x */
    }