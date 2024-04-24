vector<char *>::iterator iter;
// sort the vector using a custom comparison function for c-string
std::sort(v->begin(), v->end(), 
    [](const char* a, const char* b) { return strcmp(a, b) < 0; });

// use std::unique to move duplicate elements to the end of the vector
iter = std::unique(v->begin(), v->end(), 
    [](const char* a, const char* b) { return strcmp(a, b) == 0; });

// delete all elements from the new end of the vector to the actual end
v->erase(iter, v->end());
