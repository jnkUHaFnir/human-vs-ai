#include <openssl/dsa.h>
#include <openssl/engine.h>
#include <stdio.h>
#include <openssl/evp.h>

int N=3000;

int main() {
    DSA *dsa = DSA_new();
    int result;
    result = DSA_generate_parameters_ex(dsa, 2048, NULL, 0, NULL, NULL, NULL); // Updated to 2048-bits for stronger security
    printf("Parameters generated: %d\n", result);
    result = DSA_generate_key(dsa);
    printf("Key generated: %d\n", result);
    
    unsigned char msg[] = "I am watching you! I am watching you!";
    unsigned char sign[DSA_size(dsa)];
    unsigned int size;

    // Variables for DSA_sign_setup
    DSA_SIG *sig;
    BIGNUM *kinv = NULL, *rp = NULL;
    
    for (int i = 0; i < N; i++) {
        // Call DSA_sign_setup before each DSA_sign call to precompute values (or optionally call it once outside for slight performance gain with reduced security)
        result = DSA_sign_setup(dsa, NULL, &kinv, &rp);
        if(!result) {
            printf("DSA_sign_setup failed\n");
            exit(1);
        }
        
        // Use precomputed kinv and rp in DSA_sign
        result = DSA_sign(0, msg, sizeof(msg) - 1, sign, &size, dsa);
        if (!result) {
            printf("Signing failed\n");
            exit(1);
        }
        // Note: kinv and rp are not explicitly passed to DSA_sign in the OpenSSL API; they would internally be part of the DSA structure if used differently
        
        // Free kinv and rp if they were used multiple times
        BN_clear_free(kinv);
        BN_clear_free(rp);
        kinv = rp = NULL;
    }

    printf("Last sign result: %d, size: %d\n", result, size);
    
    DSA_free(dsa);
    return 0;
}
