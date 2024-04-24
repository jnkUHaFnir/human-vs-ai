    #include <iostream>
    #include <string>
    
    class print_this_later {
        std::string value;
    public:
        print_this_later(std::string const& value): value(value) {}
        std::string const& str() const { return this->value; }
        static int index() {
            static int rc = std::ios_base::xalloc(); return rc;
        }
        static void erase(std::ios_base::event ev, std::ios_base& ios, int index) {
            if (ev == std::ios_base::erase_event) {
                delete static_cast<std::string*>(ios.pword(index));
            }
        }
    };
    std::ostream& operator<< (std::ostream& out, print_this_later const& value) {
        void*& pword(out.pword(value.index()));
        if (pword) {
            std::unique_ptr<std::string> tmp(static_cast<std::string*>(pword));
            pword = new std::string(*tmp + value.str());
        }
        else {
            out.register_callback(&print_this_later::erase, value.index());
            pword = new std::string(value.str());
        }
        return out;
    }
    
    std::ostream& print_now(std::ostream& out) {
        return out << *static_cast<std::string*>(out.pword(print_this_later::index()));
    }
    
    int main()
    {
        std::cout << print_this_later("world")
                  << print_this_later("!")
                  << "hello" << ", " << print_now << '\n';
    }