val = new char[1];
val[0] = '\0';
if (val) {
    delete[] val;
    val = NULL;
}
val = new char[strlen(clone.val) + 1];
strcpy(val, clone.val);
