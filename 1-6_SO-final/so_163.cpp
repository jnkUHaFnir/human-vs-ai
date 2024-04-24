    int* retResut = reinterpret_cast<int*>(std::malloc(v.size() * sizeof(int)));
    std::memcopy(retResut,v.data(),v.size());
    return retResut 