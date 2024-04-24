#include <openssl/dsa.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSG_LEN 32
#define N 3000

int main() {
    DSA *set = DSA_new();
    int a;
    
    a = DSA_generate_parameters_ex(set, 1024, NULL, 0, NULL, NULL, NULL);
    if (a != 1) {
        fprintf(stderr, "Failed to generate DSA parameters\n");
        return 1;
    }

    a = DSA_generate_key(set);
    if (a != 1) {
        fprintf(stderr, "Failed to generate DSA key\n");
        return 1;
    }

    unsigned char msg[MSG_LEN] = "I am watching you! I am watching you!";
    unsigned char *signatures[N];
    unsigned int sizes[N];

    DSA_SIG *signature;

    for (int i = 0; i < N; i++) {
        // Signing
        signature = DSA_do_sign(msg, MSG_LEN, set);
        if (signature == NULL) {
            fprintf(stderr, "DSA signing failed\n");
            return 1;
        }

        // Verify if needed
        if (DSA_do_verify(msg, MSG_LEN, signature, set) != 1) {
            fprintf(stderr, "DSA verification failed\n");
            return 1;
        }

        // Store the signature and size
        signatures[i] = (unsigned char *)signature;
        sizes[i] = sizeof(*signature);
    }

    // Free memory
    for (int i = 0; i < N; i++) {
        free(signatures[i]);
    }

    // Free DSA structure
    DSA_free(set);

    return 0;
}
