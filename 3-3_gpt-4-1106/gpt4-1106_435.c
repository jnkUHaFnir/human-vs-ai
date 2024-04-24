#include <openssl/dsa.h>
#include <openssl/engine.h>
#include <stdio.h>
#include <openssl/evp.h>

int N=3000;

int main() {
    DSA *dsa = DSA_new();
    if (!dsa) {
        fprintf(stderr, "DSA_new failed.\n");
        return 1;
    }

    int a = DSA_generate_parameters_ex(dsa, 2048, NULL, 0, NULL, NULL, NULL);
    if (a != 1) {
        fprintf(stderr, "DSA_generate_parameters_ex failed.\n");
        return 1;
    }

    a = DSA_generate_key(dsa);
    if (a != 1) {
        fprintf(stderr, "DSA_generate_key failed.\n");
        return 1;
    }

    unsigned char msg[] = "I am watching you! I am watching you!";
    unsigned char sign[DSA_size(dsa)];
    unsigned int size;

    DSA_SIG *sig;
    BIGNUM *kinv = NULL;
    BIGNUM *rp = NULL;

    // Precompute kinv and rp which are used in the signing
    a = DSA_sign_setup(dsa, NULL, &kinv, &rp);
    if (a != 1) {
        fprintf(stderr, "DSA_sign_setup failed.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        // Use the precomputed kinv and rp for each signing
        sig = DSA_do_sign(msg, sizeof(msg) - 1, dsa);
        if (sig == NULL) {
            fprintf(stderr, "DSA_do_sign failed.\n");
            return 1;
        }

        // After getting the DSA_SIG object, you need to convert it to the DER encoded format
        // This is the format that is usually expected for signatures
        size = i2d_DSA_SIG(sig, &sign);

        if (size == 0) {
            fprintf(stderr, "Signature encoding failed.\n");
        }

        // Free the DSA_SIG object after use
        DSA_SIG_free(sig);
    }

    printf("Last signature size: %d\n", size);

    // Clean up the precomputed values and the DSA object
    BN_clear_free(kinv);
    BN_clear_free(rp);
    DSA_free(dsa);

    return 0;
}
