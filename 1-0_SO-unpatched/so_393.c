    if (value == 1) {
        int price = 0, price_final;
        printf ("INSERT A PRICE >> ");
        if (scanf ("%d", &price) == 0) {
            fprintf(stderr, "Invalid price");
            exit(EXIT_FAILURE);
        }
        price_final = price - (price - 0.01);
        printf ("Final value %d\n", price_final);
    }