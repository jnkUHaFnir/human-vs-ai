    size_t size = sizeof(stringcard) / sizeof(stringcard[0]);
    size_t size2 = sizeof(reds) / sizeof(reds[0]);
    int allmatch = 0;
    if (size == size2) {
        allmatch = 1;
        for (int i = 0; i < size; ++i) {
            int curmatch = 0;
            for (int j = 0; j < size; ++j) {
                if (strcmp(stringcard[i], reds[j]) == 0) {
                    curmatch = 1;
                    break;
                }
            }
            if (! curmatch) {
                allmatch = 0;
                break;
            }
        }
    }