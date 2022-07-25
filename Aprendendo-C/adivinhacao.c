#include <stdio.h>

int main()
{
    printf("************************************\n");
    printf("* Bem-vindo ao Jogo de Adivinhacao *\n");
    printf("************************************\n");

    int numerosecreto;
    numerosecreto = 26;
    // %d substitui um inteiro

    int chute;
    
    for (int i = 1; i <= 3; i++)
    {
    
        printf("\nInsira seu chute: ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        int acertou = chute == numerosecreto;

        if (acertou)
        {
            printf("Parabens! Voce acertou");
        } else {

            int maior = chute > numerosecreto;

            if (maior)
            {
                printf("Seu chute foi maior do que o numero secreto.\n");
            }

            int menor = chute < numerosecreto;

            if (menor)
            {
                printf("Seu chute foi menor do que o numero secreto\m");
            }
        
    }
    }
}
