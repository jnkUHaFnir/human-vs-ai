int main()
{
    FILE *fp;
    fp = fopen("c1.txt", "r+"); // Change mode from "w+" to "r+"
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    start(fp);

    return 0;
}
