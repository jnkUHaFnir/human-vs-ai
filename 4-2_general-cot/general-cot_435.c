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

    unsigned char msg[] = "I am watching you! I am watching you!";
    unsigned char sign[256];
    unsigned int size;

    // Setup the DSA signing context
    DSA_SIG *sig;
    DSA_sign_setup(set, NULL, NULL);

    // Sign N messages efficiently
    for (int i = 0; i < N; i++) {
        // Sign the message
        sig = DSA_do_sign(msg, strlen((char *)msg), set);
        if (sig != NULL) {
            // Extract the signature values from the DSA_SIG structure
            // and store them in 'sign'
            size = BN_num_bytes(sig->r);
            BN_bn2bin(sig->r, &sign[0]);
            size += BN_num_bytes(sig->s);
            BN_bn2bin(sig->s, &sign[BN_num_bytes(sig->r)]);

            // Verify the signature (optional)
            // int verify = DSA_do_verify(msg, strlen((char *)msg), sig, set);

            // Free the DSA_SIG structure after each signature
            DSA_SIG_free(sig);
        } else {
            fprintf(stderr, "Error signing the message %d\n", i);
            break;
        }
    }

    printf("%d %d\n", a, size);
    DSA_free(set);

    return 0;
}
