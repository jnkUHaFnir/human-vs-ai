int numStrsInList(const char* strList) {
    int count = 0;
    while (1) {
        if (!strList[0]) {
            if (!strList[1]) return count; // end of the list
            count++; // end of a string, increment count
            strList++; // skip the next null char
        }
        strList++;
    }
}
