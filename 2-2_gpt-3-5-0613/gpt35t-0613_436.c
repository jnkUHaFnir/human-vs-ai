#include <openssl/ec.h>
#include <openssl/evp.h>
#include <stdio.h>

#define N 3000

int main()
{
    EC_KEY *ec_key = EC_KEY_new_by_curve_name(NID_secp256k1);
    
    int a = EC_KEY_generate_key(ec_key);
    if (a != 1) {
        fprintf(stderr, "Error generating ECDSA key\n");
        return -1;
    }
    
    unsigned char msg[] = "I am watching you!I am watching you!";
    unsigned char sign[256];
    unsigned int size;
    
    for (int i = 0; i < N; i++)
        a = ECDSA_sign(0, msg, sizeof(msg) - 1, sign, &size, ec_key);
    
    printf("%d %d\n", a, size);
    
    EC_KEY_free(ec_key);
    return 0;
}
