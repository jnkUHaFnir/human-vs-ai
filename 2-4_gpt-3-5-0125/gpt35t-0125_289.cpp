vector<char *> uniqueStrings;
for (auto iter = v->begin(); iter != v->end(); iter++){
    char *aString = *iter;
    bool isDuplicate = false;
    
    for (const char *uniqueString : uniqueStrings){
        if (strcmp(aString, uniqueString) == 0){
            isDuplicate = true;
            break;
        }
    }
    
    if (!isDuplicate){
        uniqueStrings.push_back(aString);
    }
}

// Reassign the unique elements back to the original vector
*v = uniqueStrings;
