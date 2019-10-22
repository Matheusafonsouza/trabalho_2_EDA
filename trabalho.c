#include "trabalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void menu_aluno(Node_aluno *node_aluno){
    int opcao;
    char continuar;
    Node_disciplina *node_disciplina;
    List_disciplina *list_disciplina;
    if(node_aluno->head==NULL){
        list_disciplina=create_list_disciplina();
    }else{
        list_disciplina=node_aluno->head;
    }
    do{
        system("clear");
        printf("1. Cadastrar disciplina.\n");
        printf("2. Listar disciplinas do aluno.\n");
        printf("3. Editar disciplina do aluno.\n");
        printf("4. Excluir disciplina do aluno.\n");
        printf("5. Filtrar disciplinas por menção.\n");
        printf("6. Apresentar relatório geral do aluno.\n");
        printf("7. Voltar ao menu principal.\n");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                node_disciplina=create_node_disciplica();
                printf("Disciplina adicionada!\n");
                push_disciplina(list_disciplina,node_disciplina);
                getchar();
                printf("Aperte enter para continuar.");
                scanf("%c",&continuar);
                break;
            case 2:
                print_disciplinas(list_disciplina);
                getchar();
                printf("Aperte enter para continuar.");
                scanf("%c",&continuar);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                filtrar_disciplinas(list_disciplina);
                getchar();
                printf("Aperte enter para continuar.");
                scanf("%c",&continuar);
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                printf("Opção inválida! Digite novamente.");
                break;
        }
    }while(opcao!=7);
}

void menu(List_aluno *list_aluno,Node_aluno *node_aluno){
    int opcao,indice;
    char continuar;
    char *procura=(char*)malloc(sizeof(char)*40);
    

    system("clear");
    printf("1. Cadastrar aluno.\n");
    printf("2. Listar alunos.\n");
    printf("3. Visualizar aluno.\n");
    printf("4. Editar aluno.\n");
    printf("5. Excluir aluno.\n");
    printf("6. Fechar programa.\n");
    scanf("%d",&opcao);

    system("clear");
    switch(opcao){
    case 1:
        node_aluno=create_node_aluno();
        push_aluno(list_aluno,node_aluno);
        printf("Aluno adicionado!\n");
        getchar();
        printf("Aperte enter para continuar.");
        scanf("%c",&continuar);
        menu(list_aluno,node_aluno);
        break;
    case 2:
        print_alunos(list_aluno);
        getchar();
        printf("Aperte enter para continuar.");
        scanf("%c",&continuar);
        menu(list_aluno,node_aluno);
        break;
    case 3:

        
        do{
            system("clear");
            printf("Você vai buscar o aluno por:\n");
            printf("1. Nome.\n");
            printf("2. Email.\n");
            printf("3. Índice.\n");
            scanf("%d",&opcao);

            if(opcao!=1&&opcao!=2&&opcao!=3){
                printf("Opção inválida! Aperte enter para voltar ao menu de escolha.\n");
                getchar();
                scanf("%c",&continuar);
            }else{
                break;
            }
        }while(opcao!=1||opcao!=2||opcao!=3);

        switch(opcao){
            case 1:
                break;
            case 2:
                break;
            case 3:
                printf("Digite o índice: ");
                scanf("%d",&indice);
                node_aluno=at_pos(list_aluno,indice);
                if(node_aluno==NULL){
                }else{
                    menu_aluno(node_aluno);
                }
                break;
        }

        getchar();
        printf("Aperte enter para continuar.");
        scanf("%c",&continuar);
        menu(list_aluno,node_aluno);
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