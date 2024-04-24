int numStrsInList(const char* strList) {
    int count = 0;

    if (!(*strList) && *(strList + 1) == '\0')
        return 0;

    while (*strList || *(strList + 1)) { // Check the current and next character.
        if (*strList == '\0') {
            count++;
        }
        strList++;
    }
    return count;
}
const char* empty = "\0";
const char* one = "Hell0 \t\n\v\f\rw0r1d\0";
const char* two = "Hello\0 \t\0";
const char* simple = "Hello\0world\0!\0";

numStrsInList(empty); // Should return 0
numStrsInList(one);   // Should return 1
numStrsInList(two);   // Should return 2
numStrsInList(simple); // Should return 3
