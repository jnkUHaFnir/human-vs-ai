    int validate(int low, int high) {
    int s;
        do{
        scanf("%d", s);
        if (s<low || s>high)
            printf("innvalid Input, try again:");
        } while (s<low || s>high);
        return s;
    }