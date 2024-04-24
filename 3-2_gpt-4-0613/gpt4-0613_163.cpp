std::pair<std::shared_ptr<int>, std::size_t> foo() {
    std::shared_ptr<std::vector<int>> ptr = std::make_shared<std::vector<int>>(/* fill data here */);
    return std::make_pair(ptr, ptr->size());
}
std::pair<int*, std::size_t> foo() {
    std::vector<int> vec = /* fill data here */;
    int* raw_ptr = new int[vec.size()];
    std::copy(vec.begin(), vec.end(), raw_ptr);
    return std::make_pair(raw_ptr, vec.size());
}
class MyClass {
    std::vector<int> vec = /* fill data here */;
    public:
    std::pair<int*, std::size_t> getRawData() {
        return std::make_pair(vec.data(), vec.size());
    }
};
