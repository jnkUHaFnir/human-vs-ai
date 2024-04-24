    int validate(int low, int high) {
    int s=0;
        do{
            if (scanf("%d", &s)!=1 || (s<low || s>high))
                printf("innvalid Input, try again:");
        } while (s<low || s>high);
        return s;
    }