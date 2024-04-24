int numStrsInList(const char* strList) {
    int count = 0;
    int flag = 0;
    if(!(*strList))
        return -1;

    while (*strList != '\0' || (*(strList + 1) != '\0')) {
        if (*strList == '\0' && *(strList + 1) == '\0') {
            count++;
            strList++;
        }
        strList++;
    }
    return count;
}
