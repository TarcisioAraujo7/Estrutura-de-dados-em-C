#include <stdio.h>
#include <stdlib.h>  
#include <ctype.h>   
#include <string.h>

struct TpPedido{
    char cliente[20];     // Nome do cliente
    char produto[20];
    int quantidade;
    int entregue;         // Entregue ou não
    float valor_original; // Valor de compra do fornecedor
    float valor_revenda;  // Valor da revenda
    char codigo[20];      // Codigo do pedido
  };

typedef struct TpPedido TpPEDIDO;

TpPEDIDO RgPedido;

FILE *ArqPedidos;

long int Tamanho = sizeof(RgPedido);

long int TArquivo(){
	fseek(ArqPedidos,0,2);
	long int R=ftell(ArqPedidos)/Tamanho;
	return R;}

void adicionar(){
    char resposta;
    do
    {
        system("cls");
        printf("------INCLUIR PEDIDO------\n\n");
        printf("NOME DO CLIENTE: ");
        scanf("%s",RgPedido.cliente);

        printf("PRODUTO: ");
        scanf("%s",RgPedido.produto);

        printf("QUANTIDADE: ");
        scanf("%d",&RgPedido.quantidade);

        printf("VALOR COMPRA: ");
        scanf("%f",&RgPedido.valor_original);

        printf("VALOR REVENDA: ");
        scanf("%f",&RgPedido.valor_revenda);

        printf("CODIGO DO PEDIDO: ");
        scanf("%s",RgPedido.codigo);

        RgPedido.entregue = 0;

        fseek(ArqPedidos,0,2);
        fwrite(&RgPedido,Tamanho,1,ArqPedidos);
        
        printf("\nDESEJA ADICIONAR OUTRO? S/N\n ");
        scanf(" %c",&resposta);
        resposta = toupper(resposta);
        
    } while (resposta != "N");
    
}

void entregarPedido(){
    char cod_entregue[20];
    printf("------ENTREGA DE PEDIDO------\n\n");
    printf("CODIGO DO PEDIDO A SER ENTREGUE: ");
    scanf("%s", cod_entregue);

    if (TArquivo() != 0)
    {
      fclose(ArqPedidos);
      ArqPedidos=fopen("Pedidos.dat","r+b");
      fseek(ArqPedidos,0,0);
      int Existe = 0;
      do {
      fread(&RgPedido,Tamanho,1,ArqPedidos);
      if (strcmp(RgPedido.codigo,cod_entregue) == 0 && RgPedido.entregue == 0){
        printf("PEDIDO ENTREGUE. ");
        RgPedido.entregue = 1;
        Existe = 1;
        }
        }
        while (!feof(ArqPedidos)&&(Existe==0));
      if (Existe == 0 )
      {
        printf("O PEDIDO NÃO EXISTE, CONFIRA NOVAMENTE O CODIGO.");
      }
      

    } else
    {
      printf("O arquivo está vazio.");
    }

}

int main(){
    entregarPedido();
    return 0;
}