#include <stdio.h>

#define MAX_POINTS 5

struct Point {
    int x;
    int y;
};

int main() {
    char input[] = "((1828,299),(2729,2553),(2797,2929),(2200,1383),(2894,876))";
    struct Point arr[MAX_POINTS];
    char *token = strtok(input, "("); // Skip the first parenthesis

    for (int i = 0; i < MAX_POINTS; i++) {
        token = strtok(NULL, ",");
        if (token == NULL) {
            break;
        }
        sscanf(token, "%d %*c %d", &arr[i].x, &arr[i].y);
    }

    // Print the points
    for (int i = 0; i < MAX_POINTS; i++) {
        printf("Point %d: (%d, %d)\n", i+1, arr[i].x, arr[i].y);
    }

    return 0;
}
