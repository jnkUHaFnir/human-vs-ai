    __m128i shuffleTable[65536];
    UINT32 MyGetIP(const char *str) {
    	__m128i input = _mm_lddqu_si128((const __m128i*)str);	//"192.167.1.3"
    	input = _mm_sub_epi8(input, _mm_set1_epi8('0'));		//1 9 2 254 1 6 7 254 1 254 3 208 245 0 8 40 
    	__m128i cmp = input;									//...X...X.X.XX...  (signs)
    	int mask = _mm_movemask_epi8(cmp);						//6792 - magic index
    	__m128i shuf = shuffleTable[mask];						//10 -1 -1 -1 8 -1 -1 -1 6 5 4 -1 2 1 0 -1 
    	__m128i arr = _mm_shuffle_epi8(input, shuf);			//3 0 0 0 | 1 0 0 0 | 7 6 1 0 | 2 9 1 0 
    	__m128i coeffs = _mm_set_epi8(0, 100, 10, 1, 0, 100, 10, 1, 0, 100, 10, 1, 0, 100, 10, 1);
    	__m128i prod = _mm_maddubs_epi16(coeffs, arr);			//3 0 | 1 0 | 67 100 | 92 100 
    	prod = _mm_hadd_epi16(prod, prod);						//3 | 1 | 167 | 192 | ? | ? | ? | ?
    	__m128i imm = _mm_set_epi8(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6, 4, 2, 0);
    	prod = _mm_shuffle_epi8(prod, imm);						//3 1 167 192 0 0 0 0 0 0 0 0 0 0 0 0
    	return _mm_extract_epi32(prod, 0);
    //	return (UINT32(_mm_extract_epi16(prod, 1)) << 16) + UINT32(_mm_extract_epi16(prod, 0));	//no SSE 4.1
    }