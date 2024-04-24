#include <openssl/ecdsa.h>
#include <openssl/ec.h>
#include <openssl/bn.h>
#include <openssl/sha.h>
#include <stdio.h>

int N = 3000;

void digest_message(const unsigned char *message, size_t message_len, unsigned char *digest)
{
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, message, message_len);
    SHA256_Final(digest, &ctx);
}

int main()
{
    EC_KEY *eckey = NULL;
    ECDSA_SIG *sig = NULL;
    BN_CTX *bnctx = NULL;
    int ret;

    // Create EC key and generate key pair
    eckey = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);
    ret = EC_KEY_generate_key(eckey);
    printf("EC key: %d\n", ret);

    // Create a BN_CTX for temporary bignums during signing
    bnctx = BN_CTX_new();

    // Create a buffer to hold the message hash
    unsigned char hash[SHA256_DIGEST_LENGTH];

    for (int i = 0; i < N; i++)
    {
        // Compute a hash of the message
        unsigned char msg[] = "I am watching you!I am watching you!";
        digest_message(msg, sizeof(msg) - 1, hash);

        // Sign the hash
        sig = ECDSA_do_sign_ex(hash, sizeof(hash), NULL, NULL, eckey);
        if (!sig)
            printf("Error signing\n");

        ECDSA_SIG_free(sig);
    }

    // Free resources
    BN_CTX_free(bnctx);
    EC_KEY_free(eckey);

    return 0;
}
