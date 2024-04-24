#include <openssl/dsa.h>
#include <openssl/evp.h>
#include <stdio.h>

#define N 3000

int main()
{
    DSA *dsa = DSA_new();
    DSA_generate_parameters_ex(dsa, 2048, NULL, 0, NULL, NULL, NULL);
    DSA_generate_key(dsa);

    unsigned char msg[] = "I am watching you!I am watching you!";
    unsigned char sign[256];
    unsigned int size;

    // Precompute part of the signing process
    DSA_SIG *sig = DSA_do_sign_setup(dsa, NULL, NULL);
    if (!sig) {
        fprintf(stderr, "Error in DSA_do_sign_setup\n");
        return 1;
    }

    // Sign multiple messages using the precomputed values
    for (int i = 0; i < N; i++) {
        if (!DSA_do_sign(msg, sizeof(msg)-1, sig, dsa)) {
            fprintf(stderr, "Error in DSA_do_sign\n");
            return 1;
        }
    }

    // Clean up
    DSA_SIG_free(sig);
    DSA_free(dsa);

    printf("Messages signed successfully.\n");

    return 0;
}
