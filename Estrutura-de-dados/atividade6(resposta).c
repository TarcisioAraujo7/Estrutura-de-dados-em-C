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

typedef struct RegCliente{
    Str20 Nome; 
    void *Prox;
}Cliente;

Cliente *InicioCliente, *FimCliente = NULL;
Cliente *AuxCliente;

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


void Incluir(){
    char R;
    if ((InicioCliente != NULL)){
        system("cls");
        printf("*** Chegada de Taxista ***\n\n");
        printf("Taxista: ");
        scanf("%[^\n]s", T);
        fflush(stdin);
        
        EmFila(T);
        Remover(T);
        RemoverCliente(InicioCliente->Nome);
    }
    else{
        do{
            system("cls");
            printf("*** Chegada de Taxista ***\n\n");
            printf("Taxista: ");
            scanf("%[^\n]s", T);
            fflush(stdin);
            EmFila(T);

            printf("\nOutro taxista? S/N ");
            scanf("%c", &R);
            fflush(stdin);
            R = toupper(R);      
        }while(R != 'N');
    }
    return;
}


// LISTA DOS CLIENTES
void ListaEspera(Str20 S){
    AuxCliente = (Cliente *)malloc(sizeof(Cliente));
    strcpy(AuxCliente->Nome, S);
    AuxCliente->Prox = NULL;
    if ((InicioCliente == NULL) && (FimCliente == NULL)){
        InicioCliente = AuxCliente;
        FimCliente = AuxCliente;
    }
    else{
        FimCliente->Prox = AuxCliente;
        FimCliente = AuxCliente;
    }
}

// FUNÇÃO PARA INCLUIR CLIENTES
void IncluiCliente(){
    system("cls");
    printf("*** Chegada de cliente ***\n\n");
    printf("Cliente: ");
    scanf("%[^\n]s", N);
    fflush(stdin);

    ListaEspera(N);
    return;
}


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

// FUNÇÃO PARA REMOVER CLIENTES
void RemoverCliente(Str20 N){
    char R;
    system("cls");
    AuxCliente = InicioCliente;
    InicioCliente = InicioCliente->Prox;
    free(AuxCliente);
    if (InicioCliente == NULL)
        FimCliente = NULL;
    return;
}

// FUNÇÃO MODIFICADA PARA EXIBIR TAMBEM O TOTAL DOS CLIENTES EM ESPERA
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
        printf("\nLista de taxistas vazia.\n");

    printf("\n***Clientes em espera***\n\n");

    if (InicioCliente != NULL){
        AuxCliente = InicioCliente;
        do{
            printf("%s\n", AuxCliente->Nome);
            AuxCliente = AuxCliente->Prox;
        } while (AuxCliente != NULL);
    }
    else
        printf("\nLista de clientes vazia. Pressione ENTER.\n");

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
        if (InicioCliente != NULL){
            AuxCliente = InicioCliente;
            do{
                printf("%s ", AuxCliente->Nome);
                AuxCliente = AuxCliente->Prox;
            } while (AuxCliente != NULL);
        }
        printf("\n\nQue deseja fazer? \n\n");
        printf("1 - Chegada de Taxista \n");
        printf("2 - Chegada de Cliente \n"); //taxista é removido da fila
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