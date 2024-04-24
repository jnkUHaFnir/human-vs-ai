    #include <cctype>
    
    for (size_t i = 0; i < str.length(); ++i)
        if (!isalnum(str[i]) || str[i] != ' ')
            str.erase(i, 1);