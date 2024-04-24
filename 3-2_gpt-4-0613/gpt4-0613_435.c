#include <stdio.h>
#include <openssl/ec.h>
#include <openssl/ecdsa.h>
#include <openssl/objects.h>
#include <openssl/err.h>

int main() {
    EC_KEY* eckey = EC_KEY_new_by_curve_name(NID_secp256k1);
    if (!eckey) {
        fprintf(stderr, "Failed to create new EC Key\n");
        ERR_print_errors_fp(stderr);
        return -1;
    }

    if (!EC_KEY_generate_key(eckey)) {
        fprintf(stderr, "Failed to generate EC Key\n");
        ERR_print_errors_fp(stderr);
        EC_KEY_free(eckey);
        return -1;
    }

    unsigned char digest[32];
    unsigned int sig_len;
    unsigned char* signature = ECDSA_do_sign(digest, sizeof(digest), eckey);
    if (signature == NULL) {
        fprintf(stderr, "Failed to generate ECDSA Signature\n");
        ERR_print_errors_fp(stderr);
        EC_KEY_free(eckey);
        return -1;
    }

    // your signature is now in 'signature', and its length in 'sig_len'
    // do not forget to free your signature when you're done with it:
    ECDSA_SIG_free(signature);
    EC_KEY_free(eckey);

    return 0;
}