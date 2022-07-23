#include <stdio.h>

int main()
{
    printf("************************************\n");
    printf("* Bem-vindo ao Jogo de Adivinhacao *\n");
    printf("************************************\n");

    int numerosecreto;
    numerosecreto = 26;
    printf("O numero %d e secreto!", numerosecreto);
    // %d substitui um inteiro

    int chute;
    printf("\nInsira seu chute: ");
    scanf("%d", &chute);
    printf("Seu chute foi %d", chute);
}
