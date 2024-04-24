#include <stdint.h>

uint32_t GetIP(const char *p_str) {
    uint32_t result = 0;
    
    for (uint32_t part = 0;; ++p_str) {
        if ((*p_str == '.') || (*p_str == '\0')) {
            result = (result << 8) + part;
            part = 0;
            if (*p_str == '\0') 
                break;
        } 
        else 
            part = part * 10 + (*p_str - '0');
    }
    
    return result;
}
