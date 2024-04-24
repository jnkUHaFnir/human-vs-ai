#include <openssl/dsa.h>
#include <openssl/engine.h>
#include <stdio.h>
#include <string.h>

#define N 3000

int main()
{
    DSA *dsa = DSA_new();
    
    // Generate DSA parameters and key pair
    DSA_generate_parameters_ex(dsa, 1024, NULL, 0, NULL, NULL, NULL);
    DSA_generate_key(dsa);

    unsigned char msg[] = "I am watching you! I am watching you!";
    unsigned char sign[256];
    unsigned int siglen;

    // Setup DSA signature context once
    DSA_SIG *sig = DSA_do_sign(msg, strlen((const char *)msg), dsa);

    // Sign multiple messages efficiently
    for (int i = 0; i < N; i++) {
        if (!DSA_do_verify(msg, strlen((const char *)msg), sig, dsa)) {
            printf("Signature verification failed\n");
        }
    }

    DSA_SIG_free(sig);
    DSA_free(dsa);

    return 0;
}
