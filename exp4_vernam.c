# include <stdio.h>
# include <string.h>

# define BUFF 100

int main() {

    char message[BUFF], cipher_text[BUFF], key[BUFF];

    printf("Enter the message: ");
    scanf("%s", message);

    printf("Enter the key: ");
    scanf("%s", key);

    for (int i = 0; i < strlen(message); i++){
        cipher_text[i] = (((message[i] - 'A') ^ (key[i] - 'A')) % 26) + 'A';
    }
    cipher_text[strlen(message)] = '\0';

    printf("Ciphertext is: %s\n", cipher_text);

    return 0;
}