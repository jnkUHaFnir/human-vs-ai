#include <stdio.h>

int main(){
    int N,i;
    printf("Get the num : ");
    scanf("%d",&N);
    // Consume the newline character left after scanf
    getchar();

    char color[N][20]; // Note: This is a VLA (variable-length array), supported in C99 but may not be supported in C90 or by all compilers.

    printf("Enter the message\n");
    for(i=0;i<N;i++){
        fgets(color[i],20,stdin);
        // Remove the newline character at the end of each input string if necessary:
        color[i][strcspn(color[i], "\n")] = 0;
    }
    for(i=0;i<N;i++){
        printf("%s\n",color[i]);
    }
    return 0;
}
