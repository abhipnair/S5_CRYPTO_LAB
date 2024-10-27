# include <stdio.h>
# include <string.h>

int main(){

    char string[] = "Hello World", output[100];

    for (int i = 0; i < strlen(string); i++){
        printf("%c", string[i] ^ 0);
    }
    printf("\n");


    return 0;
}