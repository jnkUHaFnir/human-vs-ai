#include <openssl/dsa.h>
#include <openssl/engine.h>
#include <stdio.h>
#include <openssl/evp.h>

int N = 3000;

int main()
{
    DSA *set = DSA_new();
    int a;
    a = DSA_generate_parameters_ex(set, 1024, NULL, 0, NULL, NULL, NULL);
    printf("%d\n", a);
    a = DSA_generate_key(set);
    printf("%d\n", a);
  
    unsigned char msg[] = "I am watching you!I am watching you!";
    unsigned char sign[256];
    unsigned int size;
  
    // Setup the DSA signature, precomputes parts for faster signing
    a = DSA_sign_setup(set, NULL, 0, NULL, 0, NULL);
    if (a != 1) {
        fprintf(stderr, "DSA_sign_setup failed\n");
        return -1;
    }
  
    // Sign messages multiple times efficiently
    for (int i = 0; i < N; i++) {
        a = DSA_sign(0, msg, sizeof(msg) - 1, sign, &size, set);
        if (a != 1) {
            fprintf(stderr, "DSA_sign failed\n");
            return -1;
        }
    }
    printf("%d %d\n", a, size);

    DSA_free(set);

    return 0;
}
