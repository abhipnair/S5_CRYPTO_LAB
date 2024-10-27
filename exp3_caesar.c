# include <stdio.h>
# include <string.h>
# define BUFF 100

int main(){

    char message[BUFF], plaintext[BUFF], ciphertext[BUFF];
    int key, i;
    
    printf("Enter the message: ");
    scanf("%s", message);

    printf("Enter the key: ");
    scanf("%d", &key);

    for (i = 0; i < strlen(message); i++){

        ciphertext[i] = (((message[i] - 'A') + key) % 26) + 'A';

    }
    ciphertext[i] = '\0';
    for (i = 0; i < strlen(message); i++){

        plaintext[i] = ((ciphertext[i] - 'A') - key) + 'A';

    }
    plaintext[i] = '\0';

    printf("Ciphertext is: %s\n", ciphertext);
    printf("Plaintext is: %s\n", plaintext);



    return 0;
}