#include <openssl/dsa.h>
#include <openssl/engine.h>
#include <stdio.h>
#include <openssl/evp.h>

int N=3000;

int main()
{
    DSA *dsa=DSA_new();
    if (DSA_generate_parameters_ex(dsa,1024,NULL,0,NULL,NULL,NULL) != 1 ||
        DSA_generate_key(dsa) != 1) {
        printf("DSA key generation failed.\n");
        DSA_free(dsa);
        return -1;
    }

    unsigned char msg[] = "I am watching you!I am watching you!";
    unsigned char sign[DSA_size(dsa)];
    unsigned int size;
    int a, i;

    // Precompute parts of the signature.
    DSA_SIG *sig = DSA_SIG_new();
    BIGNUM *kinv = NULL, *r = NULL;
    a = DSA_sign_setup(dsa, NULL, &kinv, &r);
    if (a != 1) {
        printf("DSA_sign_setup failed.\n");
        DSA_free(dsa);
        DSA_SIG_free(sig);
        return -1;
    }

    for(i=0; i<N; i++) {
        a = DSA_sign(0, msg, sizeof(msg)-1, sign, &size, dsa);
        if (a != 1) {
            printf("DSA_sign failed on iteration %d.\n", i);
            break;
        }
    }

    printf("%d %d\n", a, size);

    DSA_free(dsa);
    DSA_SIG_free(sig);
    BN_clear_free(kinv);
    BN_clear_free(r);

    return 0;
}
#include <openssl/ec.h>
#include <openssl/ecdsa.h>

// Code for setting up your EC_KEY, selecting the curve, etc.

for(i=0; i<N; i++) {
    a = ECDSA_sign(0, msg, sizeof(msg)-1, sign, &size, ec_key);
    if (a != 1) {
        printf("ECDSA_sign failed on iteration %d.\n", i);
        break;
    }
}

// Clean-up code for your EC_KEY and other data structures.
