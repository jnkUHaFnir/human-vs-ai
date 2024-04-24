#include <fast_float/fast_float.h>

std::string input = "123.45 678.90 101.112";
std::vector<float> numbers;
float x{0};

auto begin = input.data();
auto end = input.data() + input.size();
while (begin != end) { 
    auto [ptr, err] = fast_float::from_chars(begin, end, x);
    if (err != fast_float::error_code::success) {
        break;
    }

    numbers.push_back(x);
    begin = ptr;
}
```    

2. Boost Spirit: Boost Spirit is strongly recommended for parsing tasks. It might seem a bit complicated at the first sight, but it's exceptionally powerful and flexible.

```cpp
std::string input = "123.45 678.90 101.112";
std::vector<float> numbers;
boost::spirit::qi::phrase_parse(input.begin(), input.end(), 
                                boost::spirit::qi::float_ % ' ', 
                                boost::spirit::ascii::space, numbers);
std::vector<float> parse(const std::string &line) {
    std::istringstream is(line);
    std::vector<float> result;
    std::string token;
    while(std::getline(is, token, ' ')) {
        result.push_back(std::stof(token));
    }
    return result;
}
