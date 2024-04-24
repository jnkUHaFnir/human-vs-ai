#include <openssl/dsa.h>
#include <stdlib.h>
#include <stdio.h>

int N = 3000;

int main()
{
    DSA *set = DSA_new();
    DSA_generate_parameters_ex(set, 1024, NULL, 0, NULL, NULL, NULL);
    DSA_generate_key(set);

    unsigned char msg[] = "I am watching you! I am watching you!";
    unsigned char sign[256];
    unsigned int size;
    
    DSA_SIG *sig;
    
    DSA_sign_setup(set, NULL, NULL);
    
    for(int i = 0; i < N; i++) {
        DSA_sign(0, msg, sizeof(msg), sign, &size, set);
    }

    DSA_free(set);

    return 0;
}
