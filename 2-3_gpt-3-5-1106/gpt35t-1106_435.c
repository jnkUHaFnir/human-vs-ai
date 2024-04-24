DSA *set = DSA_new();
... // Generate DSA parameters and keys

unsigned char msg[] = "I am watching you! I am watching you!";
unsigned char sign[256];
unsigned int size;

DSA_sign_setup(set, NULL, 0, NULL, NULL);

for (int i = 0; i < N; i++) {
    a = DSA_sign(0, msg, sizeof(msg) - 1, sign, &size, set);
}

DSA_free(set);
EC_KEY *ec_key = EC_KEY_new_by_curve_name(NID_secp256k1);
EC_KEY_generate_key(ec_key);

unsigned char msg[] = "I am watching you! I am watching you!";
unsigned char sign[256];
unsigned int size;

for (int i = 0; i < N; i++) {
    a = ECDSA_sign(0, msg, sizeof(msg) - 1, sign, &size, ec_key);
}

EC_KEY_free(ec_key);
