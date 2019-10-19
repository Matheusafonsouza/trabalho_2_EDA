#include "trabalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void menu(List_aluno *list_aluno,Node_aluno *node_aluno){
    int opcao;
    

    system("clear");
    printf("1. Cadastrar aluno.\n");
    printf("2. Listar alunos.\n");
    printf("3. Visualizar aluno.\n");
    printf("4. Editar aluno.\n");
    printf("5. Excluir aluno.\n");
    printf("6. Fechar programa.\n");
    scanf("%d",&opcao);

    switch(opcao){
    case 1:
        node_aluno=create_node_aluno();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    default:
        printf("Opção inválida! Digite novamente.");
        menu(list_aluno,node_aluno);
        break;
    }

}

int main(){
    List_aluno *list_aluno=create_list_aluno();
    Node_aluno *node_aluno;
    
    menu(list_aluno,node_aluno);
    return 0;
}