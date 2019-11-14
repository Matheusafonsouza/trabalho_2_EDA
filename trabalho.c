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

//menu principal
void menu(List_aluno *list_aluno,Node_aluno *node_aluno){
    int indice,opcao;
    char continuar;
    char *procura=(char*)malloc(sizeof(char)*40);
    

    //printar menu e seleção de opção
    system("clear");
    printf("1. Cadastrar aluno.\n");
    printf("2. Listar alunos.\n");
    printf("3. Visualizar aluno.\n");
    printf("4. Editar aluno.\n");
    printf("5. Excluir aluno.\n");
    printf("6. Fechar programa.\n");
    scanf("%d",&opcao);

    //switch para opções
    system("clear");
    switch(opcao){
        //Cadastro aluno  
        case 1:
            //cria node aluno e insere informações
            node_aluno=create_node_aluno(); 
            //insere node aluno criado na lista de alunos
            push_aluno(list_aluno,node_aluno);
            printf("Aluno adicionado!\n");
            getchar();
            printf("Aperte enter para continuar.");
            scanf("%c",&continuar);
            //retorna ao menu
            menu(list_aluno,node_aluno);
            break;
        //printar lista de alunos
        case 2:
            //printa lista de alunos
            print_alunos(list_aluno);
            getchar();
            printf("Aperte enter para continuar.");
            scanf("%c",&continuar);
            //retorna ao menu
            menu(list_aluno,node_aluno);
            break;
        //visualizar menu de disciplinas de determinado aluno
        case 3:
            //do while para verificação de entrada
            do{
                //printa entradas
                system("clear");
                printf("Você vai buscar o aluno por:\n");
                printf("1. Nome.\n");
                printf("2. Email.\n");
                printf("3. Índice.\n");

                //seleciona entrada
                scanf("%d",&opcao);

                //verifica se a entrada é correta
                if(opcao!=1&&opcao!=2&&opcao!=3){
                    printf("Opção inválida! Aperte enter para voltar ao menu de escolha.\n");
                    getchar();
                    scanf("%c",&continuar);
                }else{
                    break;
                }
            }while(opcao!=1&&opcao!=2&opcao!=3);
           
            //switch para entradas
            switch(opcao){
                //busca por nome
                case 1:
                    //recebe nome 
                    printf("Digite o nome do aluno: ");
                    getchar();
                    scanf("%[^\n]",procura);
                    //procura alunos que tenham o nome dado como parte do nome
                    node_aluno=search_by_name(list_aluno,procura);
                    //caso não tenha, retorna null. Caso tenha, é aberto o menu de disciplinas.
                    if(node_aluno==NULL){
                    }else{
                        //entrada no menu de disciplinas do aluno.
                        menu_aluno(node_aluno);
                    }
                    break;
                //busca por email
                case 2:
                    //recebe email
                    printf("Digite o email do aluno: ");
                    getchar();
                    scanf("%[^\n]",procura);
                    //procura alunos que tenham o email dado
                    node_aluno=search_by_email(list_aluno,procura);
                    //caso não tenha, retorna null. Caso tenha, é aberto o menu de disciplinas.
                    if(node_aluno==NULL){
                    }else{
                        //entrada no menu de disciplinas do aluno.
                        menu_aluno(node_aluno);
                    }
                    break;
                //busca por índice
                case 3:
                    //recebe indice
                    printf("Digite o índice: ");
                    scanf("%d",&indice);
                    //busca aluno paseado no indice
                    node_aluno=at_pos(list_aluno,indice);
                    //caso não tenha, retorna null. Caso tenha, é aberto o menu de disciplinas.
                    if(node_aluno==NULL){
                    }else{
                        //entrada no menu de disciplinas do aluno.
                        menu_aluno(node_aluno);
                    }
                    break;
            }

            getchar();
            //retorna ao menu
            menu(list_aluno,node_aluno);
            break;
        //editar aluno
        case 4:
            //do while para verificação de entrada
            do{
                //printa entradas
                system("clear");
                printf("Você vai buscar o aluno por:\n");
                printf("1. Nome.\n");
                printf("2. Email.\n");
                printf("3. Índice.\n");
                
                //seleciona entrada
                scanf("%d",&opcao);

                //verifica se a entrada é correta
                if(opcao!=1&&opcao!=2&&opcao!=3){
                    printf("Opção inválida! Aperte enter para escolher novamente.\n");
                    getchar();
                    scanf("%c",&continuar);
                }else{
                    break;
                }
            }while(opcao!=1&&opcao!=2&&opcao!=3);

            //switch para entradas
            switch(opcao){
                //busca por nome
                case 1:
                    //recebe nome
                    printf("Digite o nome do aluno: ");
                    getchar();
                    scanf("%[^\n]",procura);
                    //procura alunos que tenham o nome dado como parte do nome
                    node_aluno=search_by_name(list_aluno,procura);
                    //caso não tenha, retorna null. Caso tenha, é redirecionado para edição de aluno.
                    if(node_aluno==NULL){
                    }else{
                        //entrada para editar aluno.
                        edit_aluno(node_aluno);
                    }
                    break;
                //busca por email
                case 2:
                    //recebe email
                    printf("Digite o email do aluno: ");
                    getchar();
                    scanf("%[^\n]",procura);
                    //procura alunos que tenham o email.
                    node_aluno=search_by_email(list_aluno,procura);
                    //caso não tenha, retorna null. Caso tenha, é redirecionado para edição de aluno.
                    if(node_aluno==NULL){
                    }else{
                        //entrada para editar aluno.
                        edit_aluno(node_aluno);
                    }
                    break;
                //busca por indice
                case 3:
                    //recebe indice
                    printf("Digite o índice: ");
                    scanf("%d",&indice);
                    //procura aluno do indice indicado.
                    node_aluno=at_pos(list_aluno,indice);
                    //caso não tenha, retorna null. Caso tenha, é redirecionado para edição de aluno.
                    if(node_aluno==NULL){
                    }else{
                        //entrada para editar aluno.
                        edit_aluno(node_aluno);
                    }
                    break;
            }
            getchar();
            printf("Aperte enter para continuar.");
            scanf("%c",&continuar);
            //retorna ao menu principal.
            menu(list_aluno,node_aluno);
            break;
        //excluir aluno
        case 5:
            //do while para verificação de entrada
            do{
                //printa entradas
                system("clear");
                printf("Você vai buscar o aluno por:\n");
                printf("1. Nome.\n");
                printf("2. Email.\n");
                printf("3. Índice.\n");

                //seleciona entrada
                scanf("%d",&opcao);
                
                //verifica se a entrada é correta
                if(opcao!=1&&opcao!=2&&opcao!=3){
                    printf("Opção inválida! Aperte enter para voltar ao menu de escolha.\n");
                    getchar();
                    scanf("%c",&continuar);
                }else{
                    break;
                }
            }while(opcao!=1&&opcao!=2&&opcao!=3);

            //switch para entradas
            switch(opcao){
                //busca por nome
                case 1:
                    //recebe nome
                    printf("Digite o nome do aluno: ");
                    getchar();
                    scanf("%[^\n]",procura);
                    //procura alunos que tenham o nome dado como parte do nome
                    node_aluno=search_by_name(list_aluno,procura);
                    //caso não tenha, retorna null. Caso tenha, é redirecionado para excluir o aluno.
                    if(node_aluno==NULL){
                    }else{
                        //exclui aluno
                        erase_aluno(list_aluno,node_aluno);
                    }
                    break;
                //busca por email
                case 2:
                    //recebe email
                    printf("Digite o email do aluno: ");
                    getchar();
                    scanf("%[^\n]",procura);
                    //procura alunos que tenham o email.
                    node_aluno=search_by_email(list_aluno,procura);
                    //caso não tenha, retorna null. Caso tenha, é redirecionado para excluir o aluno.
                    if(node_aluno==NULL){
                    }else{
                        //exclui aluno
                        erase_aluno(list_aluno,node_aluno);
                    }
                    break;
                //busca por indice
                case 3:
                    //recebe email
                    printf("Digite o índice: ");
                    scanf("%d",&indice);
                    //procura aluno do indice indicado.
                    node_aluno=at_pos(list_aluno,indice);
                    //caso não tenha, retorna null. Caso tenha, é redirecionado para excluir o aluno.
                    if(node_aluno==NULL){
                    }else{
                        //exclui aluno.
                        erase_aluno(list_aluno,node_aluno);
                    }
                    break;
            }
            getchar();
            printf("Aperte enter para continuar.");
            scanf("%c",&continuar);
            //retorna ao menu principal.
            menu(list_aluno,node_aluno);
            break;
        
        //finaliza programa.
        case 6:
            break;
        //caso a entrada sejá uma opção inválida.
        default:
            printf("Opção inválida! Aperte enter para voltar ao menu.\n");
            getchar();
            scanf("%c",&continuar);
            menu(list_aluno,node_aluno);
            break;
    }

}


int main(){
    //cria estrutura para node e lista de aluno
    List_aluno *list_aluno=create_list_aluno();
    Node_aluno *node_aluno;
    
    //inicia menu
    menu(list_aluno,node_aluno);

    //dar free em todas as listas e nodes
    fechar_programa(list_aluno);
    free(node_aluno);
    return 0;
}
