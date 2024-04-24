#include <openssl/ec.h>
#include <openssl/obj_mac.h>
#include <openssl/ecdsa.h>
#include <stdio.h>
#include <string.h>

int N = 3000;

int main()
{
    // Create an EC_KEY object for ECDSA
    EC_KEY *ec_key = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);

    // Generate an ECDSA key pair
    if (!EC_KEY_generate_key(ec_key)) {
        fprintf(stderr, "Error generating EC key pair\n");
        return 1;
    }

    unsigned char msg[] = "I am watching you!";  // Message to sign
    unsigned char digest[SHA256_DIGEST_LENGTH];

    // Calculate message digest
    SHA256(msg, strlen((char*)msg), digest);

    unsigned char *signature;
    size_t siglen;

    // Sign N messages
    for (int i = 0; i < N; i++) {
        // Sign the message digest
        signature = NULL;  // Ensure signature is initialized
        siglen = 0;        // Ensure signature length is initialized
        if (!ECDSA_sign(0, digest, SHA256_DIGEST_LENGTH, signature, &siglen, ec_key)) {
            fprintf(stderr, "Error signing message\n");
            return 1;
        }

        // Allocate memory for the signature
        signature = OPENSSL_malloc(siglen);
        if (!signature) {
            fprintf(stderr, "Error allocating memory for signature\n");
            return 1;
        }

        // Actually sign the message digest
        if (!ECDSA_sign(0, digest, SHA256_DIGEST_LENGTH, signature, &siglen, ec_key)) {
            fprintf(stderr, "Error signing message\n");
            OPENSSL_free(signature);
            return 1; 
        }

        // Verify the signature (optional, but recommended for security)
        if (!ECDSA_verify(0, digest, SHA256_DIGEST_LENGTH, signature, siglen, ec_key)) {
            fprintf(stderr, "Error verifying signature\n");
            OPENSSL_free(signature);
            return 1;
        }

        OPENSSL_free(signature);  // Free memory used for the signature
    }

    EC_KEY_free(ec_key);  // Free the EC_KEY object

    return 0;
}
