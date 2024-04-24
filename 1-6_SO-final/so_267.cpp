    #include <memory>
    #include <iostream>
    #include <string>
    #include <cstdio>
    using namespace std; //don't if you're in a Header-file
    template<typename ... Args>
    string string_format(const string& format, Args ... args){
    	size_t size = snprintf(nullptr, 0, format.c_str(), args ...);
    	unique_ptr<char[]> buf(new char[size]);
    	snprintf(buf.get(), size, format.c_str(), args ...);
    	return string(buf.get(), buf.get() + size);
    }