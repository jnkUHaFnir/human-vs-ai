#include <openssl/dsa.h>
#include <openssl/err.h>

#define NUM_MSG 3000

int main() {
    DSA *dsa = DSA_generate_parameters(1024, NULL, 0, NULL, NULL, NULL, NULL);
    DSA_generate_key(dsa);

    DSA_SIG **sigs = calloc(NUM_MSG, sizeof(DSA_SIG *));
    unsigned char *msgs[NUM_MSG];
    unsigned int msg_lens[NUM_MSG];
    int i;
    for (i = 0; i < NUM_MSG; i++) {
        msgs[i] = (unsigned char *) "I am watching you!I am watching you!";
        msg_lens[i] = strlen((char *) msgs[i]);
    }

    DSA_sign_setup(dsa, NULL, NULL);
    for (i = 0; i < NUM_MSG; i++) {
        sigs[i] = DSA_do_sign_ex(msgs[i], msg_lens[i], dsa);
    }

    int verify_result;
    for (i = 0; i < NUM_MSG; i++) {
        verify_result = DSA_do_verify(msgs[i], msg_lens[i], sigs[i], dsa);
        if (verify_result != 1) {
            printf("Verification failed for message %d\n", i);
        }
    }

    for (i = 0; i < NUM_MSG; i++) {
        DSA_SIG_free(sigs[i]);
    }
    free(sigs);
    DSA_free(dsa);

    return 0;
}