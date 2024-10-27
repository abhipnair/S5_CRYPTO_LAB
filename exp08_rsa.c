# include <stdio.h>

int gcd_eucli(int r1, int r2){

    int r;
    while (r2 != 0){
        r = r1 % r2;
        r1 = r2, r2 = r;
    }

    return r1;


}

int find_e(int phi_n){

    for (int e = 2; e < phi_n; e++){
        if(gcd_eucli(e, phi_n) == 1){
            return e;
        }
    }

    return 1;


}

int find_d(int e, int phi_n){

    int d = 0;
    while(((e * d) % phi_n) != 1){
        d++;
    }
    return d;
}

int power_mod(int base, int expo, int mod){

    int pow_mod = 1;
    for (int i = 0; i < expo; i++){
        pow_mod = (pow_mod * base) % mod;
    }
    return pow_mod;

}



int main(){

    int p, q, message;
    printf("Enter the primes p and q: ");
    scanf("%d %d", &p, &q);
    int n = p*q, phi_n = (p - 1) * (q - 1);

    int encryption_key = find_e(phi_n);
    int decryption_key = find_d(encryption_key, phi_n);

    printf("E: %d\n", encryption_key);
    printf("D: %d\n", decryption_key);

    printf("Enter the message: ");
    scanf("%d", &message);

    printf("Ciphertext is: %d\n", power_mod(message, encryption_key, n));
    printf("Plaintext is: %d\n", power_mod(power_mod(message, encryption_key, n), decryption_key, n));



    return 0;
}