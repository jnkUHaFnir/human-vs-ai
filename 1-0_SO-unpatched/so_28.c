    int main() {
        str1 s1; allocate(&s1, "Damn");
        puts(s1.array);
        deallocate(&s1);
        return 0;
    }