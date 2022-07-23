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

    int acertou = chute == numerosecreto;
    if (acertou)
    {
        printf("Parabens! Voce acertou");
    } else {

        int maior = chute > numerosecreto;
        if (maior)
        {
            printf("Seu chute foi maior do que o numero secreto.");
        }

        int menor = chute < numerosecreto;
        if (menor)
        {
            printf("Seu chute foi menor do que o numero secreto");
        }
        
    }
    
}
