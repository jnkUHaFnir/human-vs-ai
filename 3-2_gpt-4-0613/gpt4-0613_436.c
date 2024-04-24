#include <openssl/dsa.h>
#include <openssl/engine.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <openssl/evp.h>

#define N 3000

int main()
{
    DSA *dsa = DSA_new();
    BN_GENCB *cb = BN_GENCB_new();

    int a;
    a = DSA_generate_parameters_ex(dsa, 1024, NULL, 0, NULL, NULL, cb);
    printf("%d\n", a);
    a = DSA_generate_key(dsa);
    printf("%d\n", a);

    // setup: speed up signing by precomputing part of the sighash
    DSA_SIG *sig = NULL;
    BN_CTX *ctx = NULL;
    BIGNUM *kinv = NULL;
    BIGNUM *rp = NULL;
    DSA_sign_setup(dsa, ctx, &kinv, &rp);

    unsigned char msg[]="I am watching you!I am watching you!";
    unsigned char sign[DSA_size(dsa)];
    clock_t start_t, end_t;
    start_t = clock();

    for(int i=0;i<N;i++)
        a = DSA_do_sign_ex(msg, sizeof(msg) - 1, kinv, rp, dsa);

    end_t = clock();
    printf("time: %f\n", ((double) (end_t - start_t)) / CLOCKS_PER_SEC);

    DSA_SIG_free(sig);
    BN_free(kinv);
    BN_free(rp);
    BN_CTX_free(ctx);
    DSA_free(dsa);
}
#include <openssl/ecdsa.h>
#include <openssl/obj_mac.h>
#include <openssl/rand.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define N 3000

int main()
{
    EC_KEY *eckey = EC_KEY_new_by_curve_name(NID_secp224r1);
    EC_KEY_generate_key(eckey);
    ECDSA_SIG *sig = NULL;
    ECDSA_SIG *sigs[N];
    BIGNUM *kinv = NULL;
    BIGNUM *rp = NULL;
    unsigned char buf[32];

    RAND_bytes(buf, 32);  // msg to sign
    unsigned char sign[1024];
    unsigned int size;
    clock_t start_t, end_t;

    // generate N signatures
    for (int i = 0; i < N; i++)
    {
        ECDSA_sign_setup(eckey, NULL, &kinv, &rp);
        sigs[i] = ECDSA_do_sign_ex(buf, 32, kinv, rp, eckey);
    }

    // start time
    start_t = clock();

    for (int i = 0; i < N; i++)
    {
        ECDSA_do_verify(buf, 32, sigs[i], eckey);
    }

    end_t = clock();
    printf("time: %f\n", ((double) (end_t - start_t)) / CLOCKS_PER_SEC);

    EC_KEY_free(eckey);
    for (int i = 0; i < N; i++)
        ECDSA_SIG_free(sigs[i]);
    BN_free(kinv);
    BN_free(rp);
}
