int numStrsInList(const char* strList) {
    int count = 0;
    int flag = 0;
    if(!(*strList))
        return 0;

    while (flag != 2) {
        if (*strList == '\0') {
            count++;
            flag++;
        }
        else
            flag = 0;
        strList++;
    }
    return count;
}
