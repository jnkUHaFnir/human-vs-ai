    #include <iostream>
    #include <cstdarg>
    #include <cstdio>
    std::string format(const char *fmt, ...)
    {
        std::string result;
        va_list ap;
        va_start(ap, fmt);
        char *tmp = 0;
        vasprintf(&tmp, fmt, ap);
        result = tmp;
        free(tmp);
        return result;
    }
    int main(int argc, char *argv[]) {
        std::string username = "you";
        std::cout << format("Hello %s! %d", username.c_str(), 123) << std::endl;
        return 0;
    }