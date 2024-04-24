#include <openssl/dsa.h>
#include <openssl/engine.h>
#include <stdio.h>
#include <openssl/evp.h>

int N = 3000;

int main()
{
    DSA *set = DSA_new();
    int a;
    
    // Generate DSA parameters
    a = DSA_generate_parameters_ex(set, 2048, NULL, 0, NULL, NULL, NULL);
    printf("%d\n", a);
    
    // Generate DSA keys
    a = DSA_generate_key(set);
    printf("%d\n", a);
    
    // Initialize the DSA signature context
    DSA_SIG *sig;
    DSA_sign_setup(set, NULL, NULL, &sig);
    
    unsigned char msg[] = "I am watching you! I am watching you!";
    unsigned char sign[256];
    unsigned int size;
    
    // Sign multiple messages efficiently
    for (int i = 0; i < N; i++) {
        a = DSA_sign(0, msg, sizeof(msg)-1, sign, &size, set);
    }
    printf("%d %d\n", a, size);
    
    // Free memory occupied by the DSA structure and signature context
    DSA_free(set);
    DSA_SIG_free(sig);
    
    return 0;
}
