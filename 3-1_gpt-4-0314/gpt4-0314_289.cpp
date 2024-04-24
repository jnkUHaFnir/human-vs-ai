vector<char *>::iterator outer_iter, inner_iter;
for (outer_iter = v->begin(); outer_iter != v->end(); ++outer_iter) {
    char *aString = *outer_iter;
    for (inner_iter = outer_iter + 1; inner_iter != v->end();) {
        int comparison = strcmp(aString, *inner_iter);
        if (comparison == 0) {
            inner_iter = v->erase(inner_iter); // Update the iterator to the next valid position
        } else {
            ++inner_iter;
        }
    }
}
