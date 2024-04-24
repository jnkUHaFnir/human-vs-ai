#include <openssl/dsa.h>
#include <openssl/engine.h>
#include <stdio.h>
#include <openssl/evp.h>

#define N 3000

int main()
{
    DSA *set = DSA_new();
    int a;
    a = DSA_generate_parameters_ex(set, 1024, NULL, 0, NULL, NULL, NULL);
    printf("%d\n", a);
    a = DSA_generate_key(set);
    printf("%d\n", a);

    // Perform DSA sign setup for efficient signing
    DSA_SIG *signature;
    a = DSA_sign_setup(set, NULL, NULL);
    if (a != 1) {
        printf("DSA sign setup failed\n");
        return -1;
    }

    // Setup message once for multiple signings
    const unsigned char msg[] = "I am watching you! I am watching you!";

    // Perform multiple signings efficiently
    unsigned char *signatures[N];
    unsigned int sizes[N];
    for (int i = 0; i < N; i++) {
        signature = DSA_do_sign(msg, strlen((const char*)msg), set);
        if (signature == NULL) {
            printf("DSA signing failed\n");
            return -1;
        }

        // Extract signature components r and s
        memcpy(signatures[i], BN_bn2hex(signature->r), BN_num_bytes(signature->r));
        memcpy(signatures[i] + BN_num_bytes(signature->r), BN_bn2hex(signature->s), BN_num_bytes(signature->s));
        sizes[i] = BN_num_bytes(signature->r) + BN_num_bytes(signature->s);

        // Cleanup signature
        DSA_SIG_free(signature);
    }

    // Print the first signature as an example
    for (int i = 0; i < sizes[0]; i++) {
        printf("%02X", signatures[0][i]);
    }
    printf("\n");

    return 0;
}
