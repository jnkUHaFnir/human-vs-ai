#include <openssl/evp.h>
#include <stdio.h>
#include <string.h>
#include <omp.h>

#define N 3000

void handleErrors(void)
{
    ERR_print_errors_fp(stderr);
    abort();
}

int main()
{
    EVP_PKEY* pkey = NULL;
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    const EVP_MD* md = EVP_sha256();
    unsigned char msg[] = "I am watching you! I am watching you!";
    unsigned char* sign = NULL;
    size_t siglen;
    int i, ret;

    // Generate EC key pair
    EVP_PKEY_CTX* pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_EC, NULL);
    EVP_PKEY_keygen_init(pctx);
    EVP_PKEY_CTX_set_ec_paramgen_curve_nid(pctx, NID_secp256k1);
    EVP_PKEY_keygen(pctx, &pkey);
    EVP_PKEY_CTX_free(pctx);

    // Sign messages in parallel
    #pragma omp parallel for private(i, sign, siglen) shared(ret)
    for (i = 0; i < N; i++) {
        sign = (unsigned char*)OPENSSL_malloc(EVP_PKEY_size(pkey));
        if (!sign) {
            handleErrors();
        }

        // Sign the message
        if (!EVP_DigestSignInit(ctx, NULL, md, NULL, pkey) ||
            !EVP_DigestSign(ctx, NULL, &siglen, msg, strlen((char*)msg)) ||
            !EVP_DigestSign(ctx, sign, &siglen, msg, strlen((char*)msg))) {
            handleErrors();
        }

        OPENSSL_free(sign);
    }

    EVP_MD_CTX_free(ctx);
    EVP_PKEY_free(pkey);

    return 0;
}
