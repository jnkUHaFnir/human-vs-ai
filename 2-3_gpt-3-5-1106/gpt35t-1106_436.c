#include <openssl/dsa.h>
#include <stdio.h>

int N = 3000;

int main() {
    DSA *set = DSA_new();
    int a;
    a = DSA_generate_parameters_ex(set, 1024, NULL, 0, NULL, NULL, NULL);
    printf("%d\n", a);
    a = DSA_generate_key(set);
    printf("%d\n", a);

    unsigned char msg[] = "I am watching you! I am watching you!";
    unsigned char sign[256];
    unsigned int size;

    DSA_SIG *sig;
    sig = DSA_do_sign_setup(set, 0, 0, NULL);
  
    for (int i = 0; i < N; i++) {
        a = DSA_do_sign(msg, 32, sig, set);
    }
    printf("%d %d\n", a, size);
}
