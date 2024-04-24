long long myLongLongValue = 0;
*(long long *)myMemoryChunk = myLongLongValue;
int myIntValue = 0;
*(int *)myMemoryChunk = myIntValue;
*((int *)myMemoryChunk + 1) = myIntValue;
int myIntValue = 0;
for (size_t i = 0; i < size_of_chunk / sizeof(int); i++) {
    ((int *)myMemoryChunk)[i] = myIntValue;
}
char myCharValue = 0;
for (size_t i = 0; i < size_of_chunk; i++) {
    ((char *)myMemoryChunk)[i] = myCharValue;
}
