#include "trabalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Função para printar menu de disciplinas do aluno
void menu_aluno(Node_aluno *node_aluno){
    char continuar, *procura;
    int opcao;
    Node_disciplina *node_disciplina;
    List_disciplina *list_disciplina;

    //Caso haja uma lista de disciplinas, ela será carregada. Caso não haja ela será criada.
    if(node_aluno->head==NULL){
        list_disciplina=create_list_disciplina();
    }else{
        list_disciplina=node_aluno->head;
    }

    //printa menu
    do{
        system("clear");
        printf("1. Cadastrar disciplina.\n");
        printf("2. Listar disciplinas do aluno.\n");
        printf("3. Editar disciplina do aluno.\n");
        printf("4. Excluir disciplina do aluno.\n");
        printf("5. Filtrar disciplinas por menção.\n");
        printf("6. Apresentar relatório geral do aluno.\n");
        printf("7. Voltar ao menu principal.\n");

        //Faz seleção do menu
        scanf("%d",&opcao);

        //Switch para opções  
        system("clear");
        switch(opcao){
            //Cadastra disciplina
            case 1:
                //Cria node disciplina e insere dados
                node_disciplina=create_node_disciplica();
                printf("Disciplina adicionada!\n");
                //Insere o node na lista de disciplinas
                push_disciplina(list_disciplina,node_disciplina);
                getchar();
                printf("Aperte enter para continuar.");
                scanf("%c",&continuar);
                break;
            //printa lista de disciplinas
            case 2:
                //printa lista de disciplinas
                print_disciplinas(list_disciplina);
                getchar();
                printf("Aperte enter para continuar.");
                scanf("%c",&continuar);
                break;
            //edita disciplina da lista de disciplinas
            case 3:
                printf("Digite o nome da disciplina: ");
                getchar();
                //leitura do nome da disciplina
                scanf("%[^\n]",procura);
                //retorna node baseado no nome da disciplina
                node_disciplina=search_disciplina(list_disciplina,procura);
                //caso seja null a disciplina não existe
                if(node_disciplina==NULL){
                }else{
                    //caso exista, os dados dela serão reinseridos
                    edit_disciplina(node_disciplina);
                }
                getchar();
                printf("Aperte enter para continuar.\n");
                scanf("%c",&continuar);
                break;
            //exclui disciplina da lista 
            case 4:
                printf("Digite o nome da disciplina: ");
                getchar();
                //leitura do nome da disciplina
                scanf("%[^\n]",procura);
                //retorna node baseado no nome da disciplina
                node_disciplina=search_disciplina(list_disciplina,procura);
                //caso seja null a disciplina não existe
                if(node_disciplina==NULL){
                }else{
                    //caso exista, a disciplina será excluida
                    erase_disciplina(list_disciplina,node_disciplina);
                }
                getchar();
                printf("Aperte enter para continuar.\n");
                scanf("%c",&continuar);
                break;
            //filtra disciplinas pela menção
            case 5:
                //filtar disciplinas pela menção
                filtrar_disciplinas(list_disciplina);
                getchar();
                printf("Aperte enter para continuar.");
                scanf("%c",&continuar);
                break;
            //printa relatorio geral do aluno 
            case 6:
                //printa relatorio geral do aluno
                relatorio_geral(list_disciplina);
                getchar();
                printf("Aperte enter para continuar.\n");
                scanf("%c",&continuar);   
                break;
            //retorna para o menu inicial e salva lista de disciplinas
            case 7:
                node_aluno->head=list_disciplina;
                break;
            //opções inválidas
            default:
                printf("Opção inválida! Aperte enter para voltar ao menu do aluno.\n");
                getchar();
                scanf("%c",&continuar);
                break;
        }
    }while(opcao!=7);
}

void menu(List_aluno *list_aluno,Node_aluno *node_aluno){
    int indice,opcao;
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
            }while(opcao!=1&&opcao!=2&opcao!=3);

            switch(opcao){
                case 1:
                    printf("Digite o nome do aluno: ");
                    getchar();
                    scanf("%[^\n]",procura);
                    node_aluno=search_by_name(list_aluno,procura);
                    if(node_aluno==NULL){
                    }else{
                        menu_aluno(node_aluno);
                    }
                    break;
                case 2:
                    printf("Digite o email do aluno: ");
                    getchar();
                    scanf("%[^\n]",procura);
                    node_aluno=search_by_email(list_aluno,procura);
                    if(node_aluno==NULL){
                    }else{
                        menu_aluno(node_aluno);
                    }
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
            menu(list_aluno,node_aluno);
            break;
        case 4:
            do{
                system("clear");
                printf("Você vai buscar o aluno por:\n");
                printf("1. Nome.\n");
                printf("2. Email.\n");
                printf("3. Índice.\n");
                
                scanf("%d",&opcao);

                if(opcao!=1&&opcao!=2&&opcao!=3){
                    printf("Opção inválida! Aperte enter para escolher novamente.\n");
                    getchar();
                    scanf("%c",&continuar);
                }else{
                    break;
                }
            }while(opcao!=1&&opcao!=2&&opcao!=3);

            switch(opcao){
                case 1:
                    printf("Digite o nome do aluno: ");
                    getchar();
                    scanf("%[^\n]",procura);
                    node_aluno=search_by_name(list_aluno,procura);
                    if(node_aluno==NULL){
                    }else{
                        edit_aluno(node_aluno);
                    }
                    break;
                case 2:
                    printf("Digite o email do aluno: ");
                    getchar();
                    scanf("%[^\n]",procura);
                    node_aluno=search_by_email(list_aluno,procura);
                    if(node_aluno==NULL){
                    }else{
                        edit_aluno(node_aluno);
                    }
                    break;
                case 3:
                    printf("Digite o índice: ");
                    scanf("%d",&indice);
                    node_aluno=at_pos(list_aluno,indice);
                    if(node_aluno==NULL){
                    }else{
                        edit_aluno(node_aluno);
                    }
                    break;
            }
            getchar();
            printf("Aperte enter para continuar.");
            scanf("%c",&continuar);
            menu(list_aluno,node_aluno);
            break;
        case 5:
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
            }while(opcao!=1&&opcao!=2&&opcao!=3);

            switch(opcao){
                case 1:
                    printf("Digite o nome do aluno: ");
                    getchar();
                    scanf("%[^\n]",procura);
                    node_aluno=search_by_name(list_aluno,procura);
                    if(node_aluno==NULL){
                    }else{
                        erase_aluno(list_aluno,node_aluno);
                    }
                    break;
                case 2:
                    printf("Digite o email do aluno: ");
                    getchar();
                    scanf("%[^\n]",procura);
                    node_aluno=search_by_email(list_aluno,procura);
                    if(node_aluno==NULL){
                    }else{
                        erase_aluno(list_aluno,node_aluno);
                    }
                    break;
                case 3:
                    printf("Digite o índice: ");
                    scanf("%d",&indice);
                    node_aluno=at_pos(list_aluno,indice);
                    if(node_aluno==NULL){
                    }else{
                        erase_aluno(list_aluno,node_aluno);
                    }
                    break;
            }
            getchar();
            printf("Aperte enter para continuar.");
            scanf("%c",&continuar);
            menu(list_aluno,node_aluno);
            break;
        case 6:
            break;
        default:
            printf("Opção inválida! Aperte enter para voltar ao menu.\n");
            getchar();
            scanf("%c",&continuar);
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