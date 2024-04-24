        if (scanf("%d", &i) == 1) {
            printf("\n\n%d %d\n\n", i, j);
        } else {
            fgets(buf, sizeof(buf), stdin);
            printf("error in line %d: got %s", j, buf);
            return 0;
        }