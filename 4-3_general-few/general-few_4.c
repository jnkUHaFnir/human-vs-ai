int numStrsInList(const char* strList) {
    int count = 0;
    int flag = 0;

    while (*strList || flag != 1) {
        if (!*strList) {
            count++;
            flag++;
        } else {
            flag = 0;
        }
        strList++;
    }

    return count;
}
