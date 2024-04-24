    k = 0x FF FF;
    C = 0x 3B 9A C9 FF;    // 999999999
    n = k*C = 0x 3B 9A | 8E 64 36 01;
    n % 1000000000 = 0x 3B 99 CA 01;
    n / 1000000000 = 0x FF FE;