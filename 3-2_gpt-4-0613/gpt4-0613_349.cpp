#include <iostream>
#include <climits>
#include <cerrno>

int main(){
    char *end;
    char *str = "123";
    errno = 0;
    long res = std::strtol(str, &end, 10);

    // check if conversion was successful
    if (errno == ERANGE){
        std::cout << "Conversion out of range, got cut off." << std::endl;
    }else if (errno != 0){
        std::cout << "Conversion failure, non-convertible part: " << end << std::endl;
    }else if (*end != '\0'){
        std::cout << "Partial conversion, non-convertible part: " << end << std::endl;
    }else{
        std::cout << "Conversion Successful: " << res << std::endl;
    }
    return 0;
}
