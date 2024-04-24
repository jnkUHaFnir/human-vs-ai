vector<char *>::iterator iter1, iter2;
for (iter1 = v->begin(); iter1 != v->end(); iter1++){
    iter2 = find(iter1 + 1, v->end(), *iter1); // search for duplicates
    while (iter2 != v->end()){
        delete [] *iter2;  // delete the duplicate element
        iter2 = v->erase(iter2); // remove duplicate from vector
        iter2 = find(iter2, v->end(), *iter1); // search for next duplicate
    }
}