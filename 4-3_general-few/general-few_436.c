#include <openssl/dsa.h>
#include <openssl/err.h>
#include <openssl/engine.h>
#include <stdio.h>
#include <openssl/evp.h>

#define N 3000

int main()
{
    DSA *dsa = DSA_new();
    int ret;

    ret = DSA_generate_parameters_ex(dsa, 1024, NULL, 0, NULL, NULL, NULL);
    if (ret != 1) {
        fprintf(stderr, "Failed to generate DSA parameters\n");
        return 1;
    }

    ret = DSA_generate_key(dsa);
    if (ret != 1) {
        fprintf(stderr, "Failed to generate DSA key\n");
        DSA_free(dsa);
        return 1;
    }

    unsigned char msg[] = "I am watching you! I am watching you!";
    unsigned char sign[256]; // DSA signature is 256 bytes
    unsigned int size;

    DSA_SIG *signature;

    EVP_MD_CTX *md_ctx = EVP_MD_CTX_new();
    if (!md_ctx) {
        fprintf(stderr, "Failed to create EVP MD context\n");
        DSA_free(dsa);
        return 1;
    }

    for (int i = 0; i < N; i++) {
        // Setup the DSA signature once
        DSA_sign_setup(dsa, md_ctx, NULL, 0);

        // Sign the message
        ret = DSA_sign(0, msg, sizeof(msg)-1, sign, &size, dsa);
        if (ret != 1) {
            fprintf(stderr, "Failed to sign message\n");
            ERR_print_errors_fp(stderr);
            EVP_MD_CTX_free(md_ctx);
            DSA_free(dsa);
            return 1;
        }
    }

    EVP_MD_CTX_free(md_ctx);
    DSA_free(dsa);

    return 0;
}
