# include <stdio.h>

int main()
{
    float coordX, coordY;
    printf("Insira a coordenada X: ");
    scanf("%f", &coordX);
    printf("Insira a coordenada Y: ");
    scanf("%f", &coordY);

    int xPositivo = coordX > 0;
    int xNegativo = coordX < 0;
    int xZero = coordX == 0;

    int yPositivo = coordY > 0;
    int yNegativo = coordY < 0;
    int yZero = coordY == 0;

    if (xPositivo && yPositivo)
    {
        printf("O ponto esta no PRIMEIRO quadrante");
        
    } else if (xNegativo && yPositivo)
    {
        printf("O ponto esta no SEGUNDO quadrante");

    } else if (xNegativo && yNegativo)
    {
        printf("O ponto esta no TERCEIRO quadrante");

    } else if (xPositivo && yNegativo)
    {
        printf("O ponto esta no QUARTO quadrante");
        
    } else if (!xZero && yZero)
    {
        printf("O ponto esta no EIXO DAS ABSCISSAS");
    } else if (xZero && !yZero)
    {
        printf("O ponto esta no EIXO DAS ORDENADAS");
    } else printf("O ponto esta no PONTO DE ORIGEM");
    
    return 0;
}
