    #include <iostream>
    
    class print_this_later {
        std::string value;
    public:
        print_this_later(std::string const& value): value(value) {}
        char* str() const { return strcpy(new char[value.size() + 1], value.c_str()); }
        static int index() { static int rc = std::ios_base::xalloc(); return rc; }
    };
    std::ostream& operator<< (std::ostream& out, print_this_later const& value) {
        out.pword(value.index()) = value.str();
        return out;
    }
    
    std::ostream& print_now(std::ostream& out) {
        return out << static_cast<char*>(out.pword(print_this_later::index()));
    }
    
    int main()
    {
        std::cout << print_this_later("world") << "hello" << ", " << print_now << '\n';
    }