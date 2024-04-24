    bool memcheck(char* p, char chr, size_t size) {
        int near_half, far_half;
        while (size > 1) {
            near_half = size/2;
            far_half = size-near_half;
            if(!memcmp(p, p+far_half, near_half))
                return false;
            size = far_half;
        }
        return *p == chr;
    }