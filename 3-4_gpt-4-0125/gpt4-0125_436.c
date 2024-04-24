#include <openssl/ec.h>
#include <openssl/ecdsa.h>
#include <openssl/objects.h>
#include <openssl/err.h>
#include <stdio.h>
#include <string.h>

int main() {
    int N = 3000;
    unsigned int sig_len, i;
    unsigned char* signature;
    unsigned char msg[] = "I am watching you! I am watching you!";
    size_t msg_len = strlen((char*)msg);

    // 1. Create a new EC key
    EC_KEY* eckey = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1); // Example curve
    if (eckey == NULL) exit(-1);

    // 2. Generate key pair
    if (!EC_KEY_generate_key(eckey)) exit(-2);

    // 3. Sign message(s)
    for (i = 0; i < N; i++) {
        sig_len = ECDSA_size(eckey);
        signature = OPENSSL_malloc(sig_len);

        if (!ECDSA_sign(0, msg, msg_len, signature, &sig_len, eckey)) {
            ERR_print_errors_fp(stderr);
            exit(-3);
        }
        
        // For demonstration purposes, one would usually verify and or use the signature here

        OPENSSL_free(signature);
    }

    // Cleanup
    EC_KEY_free(eckey);

    printf("Signing completed.\n");
    return 0;
}
