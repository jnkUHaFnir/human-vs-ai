#include <openssl/dsa.h>
#include <openssl/evp.h>
#include <string.h>
#include <stdio.h>

#define N 3000

int main() {
    DSA *dsa = DSA_new();
    DSA_generate_parameters_ex(dsa, 1024, NULL, 0, NULL, NULL, NULL);
    DSA_generate_key(dsa);

    unsigned char msg[] = "I am watching you!";

    DSA_SIG *sig;
    DSA_CTX *ctx = DSA_CTX_new();
    int status = DSA_sign_setup(dsa, ctx, NULL, 0);
    if (status != 1) {
        fprintf(stderr, "Error in sign setup\n");
        return 1;
    }

    unsigned char sign[256];
    unsigned int size;

    for (int i = 0; i < N; i++) {
        status = DSA_sign(0, msg, strlen(msg), sign, &size, dsa);
        if (status != 1) {
            fprintf(stderr, "Error in sign\n");
            return 1;
        }
    }

    printf("Signing %d messages with DSA key successful.\n", N);

    DSA_CTX_free(ctx);
    DSA_free(dsa);

    return 0;
}
