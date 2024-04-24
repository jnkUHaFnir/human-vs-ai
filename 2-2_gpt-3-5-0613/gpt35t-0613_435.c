#include <openssl/dsa.h>
#include <stdio.h>
#include <openssl/evp.h>

int N=3000;

int main()
{
    // Initialize DSA parameters and generate key pair
    DSA *set=DSA_new();
    int a;
    a=DSA_generate_parameters_ex(set, 1024, NULL, 1, NULL, NULL, NULL);
    printf("%d\n",a);
    a=DSA_generate_key(set);
    printf("%d\n",a);

    unsigned char msg[]="I am watching you!I am watching you!";
    unsigned char sign[256];
    unsigned int size;

    // Pre-compute the DSA sign setup
    DSA_SIG *sign_setup = DSA_do_sign_setup(msg, sizeof(msg), set);

    // Sign multiple messages
    for(int i=0;i<N;i++)
        a = DSA_do_sign_ex(msg, sizeof(msg), sign, &size, sign_setup);

    printf("%d %d\n",a,size);

    // Free allocated resources
    DSA_free(set);
    DSA_SIG_free(sign_setup);

    return 0;
}
