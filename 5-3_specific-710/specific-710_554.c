#include <stdio.h>
#include <string.h>

int main() {
    char sentence[11];
    
    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        sentence[strcspn(sentence, "\n")] = '\0';
    }
    
    printf("Modified sentence: %s\n", sentence);
    
    return 0;
}
