vector<char *>::iterator iter;
for (iter = v->begin(); iter != v->end()-1; iter++ ){
    char *aString = *iter;
    int n = 1;
    while(iter+n != v->end()){ // Problematic because v->end() can change after erase
        int comparison = strcmp(aString, *(iter+n));
        if(comparison == 0){
            v->erase(iter + n); // Invalidates iterators at and past the erased element
            
            // No increment of 'n' here, you need to remain at the same relative position.
        } else {
            // Only increment 'n' if an element wasn't erased
            n++;
        }
    }
}
vector<char *>::iterator iter;
for (iter = v->begin(); iter != v->end(); /* no increment here */) {
    char *aString = *iter;
    vector<char *>::iterator it_to_compare = iter + 1; // Start comparing with the next element
    while(it_to_compare != v->end()) {
        if(strcmp(aString, *it_to_compare) == 0) {
            // Erasing from the vector invalidates it_to_compare, but returns a valid iterator to the next element
            it_to_compare = v->erase(it_to_compare);
        } else {
            ++it_to_compare;
        }
    }
    ++iter; // Increment the outer iterator only after internal iteration is complete
}
std::unordered_set<std::string> seen;
v->erase(std::remove_if(v->begin(), v->end(), 
    [&seen](const char* str) {
        if(seen.find(str) != seen.end())
            return true;
        seen.insert(str);
        return false;
    }), 
    v->end());
