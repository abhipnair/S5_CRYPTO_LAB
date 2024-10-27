# include <stdio.h>
# include <string.h>


int main(){

    char string[]  = "Hello World", xor[100], and[100];

    for(int i = 0; i < strlen(string); i++){
        xor[i] = string[i] ^ 127;
        and[i] = string[i] & 127;
    }
    xor[strlen(string)] = '\0';
    and[strlen(string)] = '\0';

    printf("\nXOR result: %s", xor);
    printf("\nAND result: %s\n", and);


    return 0;
}