# include <stdio.h>

int power_mod(int base, int expo, int mod_value){
    int value = 1;

    for (int i = 0; i < expo; i++){
        value = (value * base) % mod_value;
    }

    return value;
}

int main(){

    int P = 11, G = 2, pvt_key_bob, pvt_key_alice;

    printf("Public number of alice and bob are P = %d and G = %d\n", P, G);

    printf("Enter the private key of bob: ");
    scanf("%d", &pvt_key_bob);

    printf("Enter the private key of alice: ");
    scanf("%d", &pvt_key_alice);

    int pub_key_bob = power_mod(G, pvt_key_bob, P);
    int pub_key_alice = power_mod(G, pvt_key_alice, P);

    printf("Public key of alice  = %d and bob = %d\n", pub_key_alice, pub_key_bob);

    int scrt_key_bob = power_mod(pub_key_alice, pvt_key_bob, P);
    int scrt_key_alice = power_mod(pub_key_bob, pvt_key_alice, P);

    printf("Shared Sceret key of alice  = %d and bob = %d\n", scrt_key_alice, scrt_key_bob);


    return 0;
}