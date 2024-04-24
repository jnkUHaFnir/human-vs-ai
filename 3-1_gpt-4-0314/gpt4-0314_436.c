#include <openssl/dsa.h>
#include <openssl/engine.h>
#include <stdio.h>
#include <openssl/evp.h>

int N=3000;

int main()
{
    DSA *set=DSA_new();
    int a;
    a=DSA_generate_parameters_ex(set,1024,NULL,0,NULL,NULL,NULL);
    printf("%d\n",a);
    a=DSA_generate_key(set);
    printf("%d\n",a);
    unsigned char msg[]="I am watching you!I am watching you!";
    unsigned char sign[256];
    unsigned int size;

    // Precompute k and r values
    DSA_SIG *sig = NULL;
    BIGNUM *kinv = NULL, *rp = NULL;
    for (int i = 0; i < N; i++) {
        DSA_sign_setup(set, NULL, &kinv, &rp);
        if (!DSA_sign(0, msg, 32, sign, &size, set)) {
            printf("DSA_sign failed\n");
            return 1;
        }
        printf("Signature size: %d\n", size);

        // Verify the signature
        sig = DSA_SIG_new();
        DSA_SIG_set0(sig, rp, kinv);
        if (DSA_do_verify(msg, 32, sig, set) != 1) {
            printf("DSA_verify failed\n");
            DSA_SIG_free(sig);
            return 1;
        } else {
            printf("Signature verified\n");
        }

        DSA_SIG_free(sig);
    }

    printf("%d %d\n",a,size);
    DSA_free(set);
    return 0;
}
