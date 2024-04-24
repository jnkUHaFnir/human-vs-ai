#include <openssl/evp.h>
#include <openssl/dsa.h>

int N = 3000;

int main() {
    EVP_PKEY* pkey = EVP_PKEY_new();
    EVP_PKEY_assign_DSA(pkey, DSA_new());

    DSA* dsa = EVP_PKEY_get1_DSA(pkey);
    DSA_generate_parameters_ex(dsa, 1024, NULL, 0, NULL, NULL, NULL);
    DSA_generate_key(dsa);

    const unsigned char* msg = (const unsigned char*)"I am watching you! I am watching you!";
    unsigned char* sig = NULL;
    size_t siglen = 0;

    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    EVP_SignInit(ctx, EVP_dss1());
    
    for (int i = 0; i < N; i++) {
        EVP_SignUpdate(ctx, msg, strlen((const char*)msg));
        EVP_SignFinal(ctx, sig, &siglen, pkey);
    }

    EVP_PKEY_free(pkey);
    EVP_MD_CTX_free(ctx);
    
    return 0;
}
