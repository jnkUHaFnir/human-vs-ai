#include <openssl/dsa.h>
#include <openssl/engine.h>
#include <stdio.h>
#include <openssl/evp.h>
#include <string.h>

int N=3000;

int main()
{
    DSA *set = DSA_new();
    int ret;
    ret = DSA_generate_parameters_ex(set, 2048, NULL, 0, NULL, NULL, NULL); // Use a larger key size
    printf("Generate parameters: %d\n", ret);
    ret = DSA_generate_key(set);
    printf("Generate key: %d\n", ret);

    unsigned char msg[] = "I am watching you! I am watching you!";
    unsigned char sign[256];
    unsigned int size;

    DSA_set_method(set, DSA_OpenSSL());
    DSA_sign_setup(set, NULL, NULL);

    // Signing multiple messages efficiently
    for(int i = 0; i < N; i++) {
        ret = DSA_sign(0, msg, strlen((char *)msg), sign, &size, set);
        if(ret != 1) {
            printf("Error signing message %d\n", i);
            break;
        }
    }

    DSA_free(set);

    printf("Finished signing %d messages\n", N);

    return 0;
}
