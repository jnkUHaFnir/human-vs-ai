#include <openssl/dsa.h>
#include <openssl/engine.h>
#include <stdio.h>
#include <openssl/evp.h>

int N=3000;

int main()
{
    DSA *set=DSA_new();
    int a;
    a=DSA_generate_parameters_ex(set,1024,NULL,1,NULL,NULL,NULL);
    printf("%d\n",a);
    a=DSA_generate_key(set);
    printf("%d\n",a);
    unsigned char msg[]="I am watching you!I am watching you!";
    unsigned char sign[256];
    unsigned int size;
    
    // Precomputation
    DSA_SIG *sig = DSA_do_sign(msg, sizeof(msg), set);
    
    for(int i=0;i<N;i++)
        a = DSA_do_verify(msg, sizeof(msg), sig, set);
    
    printf("%d\n",a);
    
    DSA_SIG_free(sig); // Free the DSA_SIG structure
    
    // Free the DSA key
    DSA_free(set);
    
    return 0;
}
