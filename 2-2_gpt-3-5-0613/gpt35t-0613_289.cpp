#include <algorithm>

vector<char*>::iterator iter;
for (iter = v->begin(); iter != v->end(); iter++){
    char *aString = *iter;
    vector<char*>::iterator next = iter + 1;
    while(next != v->end()){
        if(strcmp(aString, *next) == 0){
            next = v->erase(next);
        } else {
            ++next;
        }
    }
}

v->erase(unique(v->begin(), v->end()), v->end());
