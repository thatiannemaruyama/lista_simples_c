#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario{
    char nome[50];
    int idade;
    char funcao[30];
    struct funcionario *prox;
}Funcionario;

Funcionario* criar_funcionario(){
    Funcionario *novo = (Funcionario*)malloc(sizeof(Funcionario));
    return novo;
}
//Estrutura Nó que aponta para os dados do funcionário

Funcionario* inserir(Funcionario* Lista){
    Funcionario *novo = criar_funcionario();
    fflush(stdin);
    printf("\nDigite o nome do funcionário: ");
    gets(novo->nome);
    printf("\nInsira a idade do funcionario: ");
    scanf("%i", &novo->idade);
    fflush(stdin);
    printf("\nDigite a funcao do funcionario: ");
    gets(novo->funcao);

    if (Lista  == NULL){
        novo->prox = NULL;
        Lista = novo;
    }
    else{
        Funcionario* aux = Lista;
        while(aux->prox != NULL){
            aux=aux->prox;
        }
        novo->prox = NULL;
        aux->prox=novo;
    }
    return Lista;
}

void imprimir_lista(Funcionario* Lista){
    Funcionario *aux=Lista;

    while(aux != NULL){
        printf("\n%s - %i - %s", aux->nome, aux->idade, aux->funcao);
        aux=aux->prox;
    }
}
int main(int argc, const char * argv[]){
    int aux1, aux2;
    Funcionario *Lista = NULL;
    printf("Bem-vindo ao programa. Insira uma opcao:\n\n1 - Iniciar opcoes\n0 - Sair\n");
    scanf("%i", &aux1);
    while(aux1!=0){
        printf("\nInsira a opcao desejada\n\n1 - Inserir funcionario\n2 - Imprimir lista\n");
        scanf("%i", &aux2);
        if (aux2 == 1){
            Lista=inserir(Lista);
        }
        else if (aux2 == 2){
            imprimir_lista(Lista);
        }
        else{
            printf("\nOpção inválida, insira novamente.");
        }
        printf("\nOperacao concluída. Insira o proximo passo\n\n1 - Continuar no programa\n0 - Sair\n");
        scanf("%i", &aux1);
    }
    printf("\nPrograma Finalizado.");
    return 0;
}
