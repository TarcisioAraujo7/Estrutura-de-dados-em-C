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
        if (chute < 0)
        {
            printf("Numeros negativos não são aceitos\n")
            i--;
            continue;
        }
        
        printf("Seu %do chute foi %d\n", i, chute);
        
        int acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;
        int menor = chute < numerosecreto;

        if (acertou) {
            printf("Parabens! Voce acertou");
            break;

        } else if (maior){
                printf("Seu chute foi maior do que o numero secreto.\n");
            } else{
                printf("Seu chute foi menor do que o numero secreto\n");
            }
        
    }
}

