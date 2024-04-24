#include <algorithm>

// Assuming v is a vector<char*>*

std::sort(v->begin(), v->end()); // Sort the vector

v->erase(std::unique(v->begin(), v->end()), v->end()); // Erase duplicates
