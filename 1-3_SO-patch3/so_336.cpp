    void MyInit() {
    	int parts[16][16];
    	int lens[16] = {0};
    	for (int i = 0; i < 65536; i++) {
    	    int s = 0, t = 0;
    	    for (int j = 0; j < 16; j++) {
    	    	bool comma = (i >> j) & 1;
    		    if (comma) {
    		    	lens[s++] = t;
    		    	t = 0;
    		    }
    		    else
    	    		parts[s][t++] = j;
    	    }
    	    lens[s++] = t;
    		if (s <= 4)
    			continue;
    		char mask[128];
    		memset(mask, -1, sizeof(mask));
    		for (int j = 3; j>=0; j--) {
    			for (int w = lens[j]-1; w>=0; w--) {
    				int pos = 4 * (3-j) + (lens[j]-1-w);
    				mask[pos] = parts[j][w];
    			}
    		}
    		_mm_store_si128(&shuffleTable[i], _mm_loadu_si128((__m128i*)mask));
    	}
    }