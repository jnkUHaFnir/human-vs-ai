    int validate(int low, int high) {
    int s=0;
    char buf[128];
        do {
			if (gets(buf)==0 || sscanf(buf, "%d", &s)!=1 || (s<low || s>high))
                printf("invalid Input, try again:");
            else
				return s;
        } while (1);
    }