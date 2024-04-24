int remainingLength = snprintf(buf2, sizeof buf2, "%s", "456 dolor sit");
if (remainingLength < 0) {
    // handle error
} else if (remainingLength >= sizeof buf2) {
    // handle buffer overflow
} else {
    int offset = sizeof buf2 - remainingLength;
    snprintf(buf2 + offset, remainingLength, "456 dolor sit");
}
