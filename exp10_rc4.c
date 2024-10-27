# include <stdio.h>
# include <string.h>

# define BUFF 100

void swap(unsigned char *si, unsigned char *sj){

    unsigned char temp = *si;
    *si = *sj;
    *sj = temp;

}

void key_sceduling(unsigned char *S, unsigned char *key){

    for (int i = 0; i < 256; i++){
        S[i] = i;
    }
    int j = 0, length = strlen(key);
    for (int i = 0; i < 256; i++){
        j = (j + S[i] + key[i % length]) % 256;
        swap(&S[i], &S[j]);
    }

}

void stream_key_gen(unsigned char *S, unsigned char *input, unsigned char *output){

    int i = 0, j = 0, k;
    unsigned char key;
    for (k = 0; k < strlen(input); k++){

        i = (i + 1) % 256;
        j = (j + S[i]) % 256;

        swap(&S[i], &S[j]);

        key = S[(S[i] + S[j]) % 256];

        output[k] = input[k] ^ key;

    }
    output[k] = '\0';

}



int main(){

    char message[BUFF], key[BUFF], plaintext[BUFF];
    unsigned char S[256], ciphertext[BUFF];

    printf("Enter the message: ");
    fgets(message, BUFF, stdin);
    message[strlen(message)] = '\0';

    printf("Enter the key: ");
    fgets(key, BUFF, stdin);
    message[strlen(key)] = '\0';

    //encpt
    key_sceduling(S, key);
    stream_key_gen(S, message, ciphertext);
    printf("Ciphertext is: ");
    for (int i = 0; i < strlen(ciphertext); i++){
        printf("%02X", ciphertext[i]);
    }
    printf("\n");

    //decrp
    key_sceduling(S, key);
    stream_key_gen(S, ciphertext, plaintext);
    printf("Plaintext is: %s\n" ,plaintext);

    return 0;
}