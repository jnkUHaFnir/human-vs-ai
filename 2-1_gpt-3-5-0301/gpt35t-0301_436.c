#include <openssl/dsa.h>
#include <stdio.h>
#include <string.h>

#define N 3000

int main()
{
    DSA *key = DSA_new();
    DSA_generate_parameters_ex(key, 1024, NULL, 0, NULL, NULL, NULL);
    DSA_generate_key(key);

    unsigned char msg[N][32];
    DSA_SIG *sigs[N];
    for (int i = 0; i < N; i++) {
        sprintf((char *)msg[i], "Message %d", i);
        sigs[i] = DSA_SIG_new();
    }

    int num_msgs = N;
    unsigned char *md_array[N];
    for (int i = 0; i < N; i++) {
        md_array[i] = msg[i];
    }

    int r = DSA_do_sign_ex(md_array, N, key, sigs);
    if (r != 1) {
        printf("Error signing\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        unsigned char buf[256];
        int len = i2d_DSA_SIG(sigs[i], &buf);
        // Verify signature
        r = DSA_do_verify(md_array[i], 32, sigs[i], key);
        if (r != 1) {
            printf("Signature verification failed for message %d\n", i);
        }
    }

    DSA_free(key);
    for (int i = 0; i < N; i++) {
        DSA_SIG_free(sigs[i]);
    }

    return 0;
}
