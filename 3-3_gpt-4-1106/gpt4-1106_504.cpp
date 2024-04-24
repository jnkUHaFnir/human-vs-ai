std::vector<int> vec;
vec.reserve(1); // Start with some initial capacity
for (int i = 0; ... ) {
    if (vec.size() == vec.capacity()) {
        vec.reserve(vec.capacity() * growth_factor); // Grow by a certain factor
    }
    vec.push_back(value);
}
