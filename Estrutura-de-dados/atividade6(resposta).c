#include <stdio.h>
#include <stdlib.h> //usado system
#include <ctype.h>  //usado toupper
#include <string.h> //usado strcmp

typedef char Str20[20];

typedef struct Reg{
    Str20 Taxista; //nome
    void *Prox;
}TpReg;

Str20 T;

TpReg *Inicio, *Fim = NULL;
TpReg *Aux;

//Estrutura para lista de espera
typedef struct Clientes{
    Str20 Nome; //nome
    void *Prox;
}Cliente;

Cliente *Ini, *Final = NULL;
Cliente *Auxi;

Str20 N;

int Opcao;

void EmFila(Str20 S){
    Aux = (TpReg *)malloc(sizeof(TpReg));
    strcpy(Aux->Taxista, S);
    Aux->Prox = NULL;
    if ((Inicio == NULL) && (Fim == NULL)){
        Inicio = Aux;
        Fim = Aux;
    }
    else{
        Fim->Prox = Aux;
        Fim = Aux;
    }
}

//Para incluir taxista.
void Incluir(){
    char R;
    if ((Ini != NULL)){
        system("cls");
        printf("*** Chegada de Taxista ***\n\n");
        printf("Taxista: ");
        scanf("%[^\n]s", T);
        fflush(stdin);
        
        EmFila(T);
        Remover(T);
        RemoveCliente(Ini->Nome);
    }
    else{
        do{
            system("cls");
            printf("*** Chegada de Taxista ***\n\n");
            printf("Taxista: ");
            scanf("%[^\n]s", T);
            fflush(stdin);
            //inclusao da taxista na fila
            EmFila(T);

            printf("\nOutro taxista? S/N ");
            scanf("%c", &R);
            fflush(stdin);
            R = toupper(R);      
        }while(R != 'N');
    }
    return;
}

//Lista de espera dos clientes
void ListaEspera(Str20 S){
    Auxi = (Cliente *)malloc(sizeof(Cliente));
    strcpy(Auxi->Nome, S);
    Auxi->Prox = NULL;
    if ((Ini == NULL) && (Final == NULL)){
        Ini = Auxi;
        Final = Auxi;
    }
    else{
        Final->Prox = Auxi;
        Final = Auxi;
    }
}

//Inclui cliente na lista de espera
void IncluiCliente(){
    system("cls");
    printf("*** Cliente em Espera ***\n\n");
    printf("Cliente: ");
    scanf("%[^\n]s", N);
    fflush(stdin);

    //inclusao de cliente na lista de espera
    ListaEspera(N);
    return;
}

//Para atender chamada
void Remover(Str20 Titulo){
    char R;
    if ((Inicio == NULL) && (Fim == NULL)){
            printf("Lista de Taxistas Vazia\n\n");
            IncluiCliente();                      
            system("pause");
            R = 'N';
    }
    else{
        do{
            system("cls");
            printf("Taxista: ");
            printf("%s \n\n", Inicio->Taxista);
            Aux = Inicio;
            Inicio = Inicio->Prox;
            free(Aux);
            if (Inicio == NULL)
                Fim = NULL;

            printf("Efetuar novo atendimento? S/N ");
            scanf("%c", &R);
            fflush(stdin);
            R = toupper(R);
        }while (R != 'N');
    }
    return;
}

void RemoveCliente(Str20 N){
    char R;
    system("cls");
    Auxi = Ini;
    Ini = Ini->Prox;
    free(Auxi);
    if (Ini == NULL)
        Final = NULL;
    return;
}

void LTodos(){
    system("cls");
    printf("***Fila de Taxistas***\n\n ");
    if (Inicio != NULL){
        Aux = Inicio;
        do{
            printf("%s\n", Aux->Taxista);
            Aux = Aux->Prox;
        } while (Aux != NULL);
    }
    else
        printf("\nLista de taxistas vazia. Pressione <ENTER>\n");
    system("pause");
    return;
}

int main(){
    do{
        system("cls");
        printf("\n\n> > > Charme Taxis < < < \n\n");
        printf("Taxistas disponiveis: ");
        if (Inicio != NULL){
            Aux = Inicio;
            do{
                printf("%s ", Aux->Taxista);
                Aux = Aux->Prox;
            } while (Aux != NULL);
        }
        printf("\nClientes em espera: ");
        if (Ini != NULL){
            Auxi = Ini;
            do{
                printf("%s ", Auxi->Nome);
                Auxi = Auxi->Prox;
            } while (Auxi != NULL);
        }
        printf("\n\nQue deseja fazer? \n\n");
        printf("1 - Chegada de Taxista \n");
        printf("2 - Chamada de Cliente \n"); //taxista é removido da fila
        printf("3 - Listar Todos \n");
        printf("4 - Sair \n\n");
        printf("Opcao: ");
        scanf("%d", &Opcao);
        fflush(stdin);
        switch (Opcao){
        case 1:
            Incluir();
            break;
        case 2:
            Remover("*** Atender Chamada ***");
            break;
        case 3:
            LTodos();
            break;
        }
    } while (Opcao != 4);
    return 0;
}