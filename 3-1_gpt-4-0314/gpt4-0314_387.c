#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *tmp1;
    char *artist = NULL;
    size_t len = 0;
    ssize_t read;

    tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");

    if (tmp1 == NULL) {
        perror("popen");
        exit(EXIT_FAILURE);
    }

    read = getline(&artist, &len, tmp1);

    if (read == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }

    printf("Artist: %s", artist);

    pclose(tmp1);
    free(artist);

    return 0;
}
