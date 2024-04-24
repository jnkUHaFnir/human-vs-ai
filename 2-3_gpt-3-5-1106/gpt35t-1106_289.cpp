vector<char *>::iterator iter;
for (iter = v->begin(); iter != v->end(); ++iter) {
    char *aString = *iter;
    vector<char *>::iterator nextIter = iter + 1;
    while (nextIter != v->end()) {
        if (strcmp(aString, *nextIter) == 0) {
            nextIter = v->erase(nextIter);
        } else {
            ++nextIter;
        }
    }
}
