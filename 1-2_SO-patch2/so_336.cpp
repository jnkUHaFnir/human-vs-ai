    void MyInit() {
        memset(shuffleTable, -1, sizeof(shuffleTable));
        int len[4];
        for (len[0] = 1; len[0] <= 3; len[0]++)
            for (len[1] = 1; len[1] <= 3; len[1]++)
                for (len[2] = 1; len[2] <= 3; len[2]++)
                    for (len[3] = 1; len[3] <= 3; len[3]++) {
                        int slen = len[0] + len[1] + len[2] + len[3] + 4;
                        int rem = 16 - slen;
                        for (int rmask = 0; rmask < 1<<rem; rmask++) {
    //                    { int rmask = (1<<rem)-1;    //note: only maximal rmask is possible if strings are zero-padded
                            int mask = 0;
                            char shuf[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
                            int pos = 0;
                            for (int i = 0; i < 4; i++) {
                                for (int j = 0; j < len[i]; j++) {
                                    shuf[(3-i) * 4 + (len[i]-1-j)] = pos;
                                    pos++;
                                }
                                mask ^= (1<<pos);
                                pos++;
                            }
                            mask ^= (rmask<<slen);
                            _mm_store_si128(&shuffleTable[mask], _mm_loadu_si128((__m128i*)shuf));
                        }
                    }
    }