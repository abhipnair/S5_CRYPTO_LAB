# include <stdio.h>

int main(){

    char message[3][3], key[4], ciphertext[4];

    printf("Enter the message: ");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            scanf("%c", &message[i][j]);
        }
    }

    printf("Enter the key: ");
    scanf("%s", key);

    int added_result;
    for (int i = 0; i < 3; i++){

        added_result = 0;
        for (int j = 0; j < 3; j++){
            added_result += ((message[i][j] - 'A') * (key[j] - 'A'));
        }
        ciphertext[i] = (added_result % 26) + 'A';

    }
    ciphertext[4] = '\0';
    printf("Ciphertext is: %s\n", ciphertext);

    return 0;
}