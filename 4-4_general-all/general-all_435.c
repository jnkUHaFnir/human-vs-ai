#include <openssl/dsa.h>
#include <stdio.h>

int N = 3000;

int main()
{
    DSA *set = DSA_new();
    int a;
    a = DSA_generate_parameters_ex(set, 1024, NULL, 1, NULL, NULL, NULL);
    printf("%d\n", a);
    a = DSA_generate_key(set);
    printf("%d\n", a);

    // Precompute DSA signing parameters
    DSA_SIG *sig;
    DSA_sign_setup(set, NULL, NULL, &sig);

    unsigned char msg[] = "I am watching you! I am watching you!";
    unsigned char sign[256];
    unsigned int size;

    for (int i = 0; i < N; i++) {
        a = DSA_sign(0, msg, sizeof(msg) - 1, sign, &size, set);
    }

    printf("%d %d\n", a, size);

    DSA_SIG_free(sig); // Free the precomputed signature after use
    DSA_free(set); // Free the DSA key

    return 0;
}
