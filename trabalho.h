#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node_disciplina{
    char *nome,*mencao;
    struct node_disciplina *next;
}Node_disciplina;

typedef struct list_disciplina{
    int size;
    Node_disciplina *head;
}List_disciplina;

typedef struct node_aluno{
    char *nome,*email,*matricula;
    List_disciplina *head;
    struct node_aluno *next;
}Node_aluno;

typedef struct list_aluno{
    int size;
    Node_aluno *head;
}List_aluno;

//Cria estruturas
List_disciplina * create_list_disciplina(){
    List_disciplina *list=(List_disciplina*)malloc(sizeof(List_disciplina));
    list->head=NULL;
    list->size=0;
    return list;
}

Node_disciplina * create_node_disciplica(){
    Node_disciplina *node=(Node_disciplina*)malloc(sizeof(Node_disciplina));
    node->mencao=(char*)malloc(sizeof(char)*2);
    node->nome=(char*)malloc(sizeof(char)*40);
    printf("Digite o nome da disciplina: ");
    scanf("%[^\n]",node->nome);
    printf("Digite a menção: ");
    scanf("%s",node->mencao);
    node->next=NULL;
    return node;
}

List_aluno * create_list_aluno(){
    List_aluno *list=(List_aluno*)malloc(sizeof(List_aluno));
    list->head=NULL;
    list->size=0;
    return list;
}

Node_aluno * create_node_aluno(){
    Node_aluno *node=(Node_aluno*)malloc(sizeof(Node_aluno));
    node->email=(char*)malloc(sizeof(char)*40);
    node->matricula=(char*)malloc(sizeof(char)*40);
    node->nome=(char*)malloc(sizeof(char)*40);
    printf("Digite o nome do aluno: ");
    scanf("%[^\n]",node->nome);
    printf("Digite a matrícula do aluno: ");
    scanf("%s",node->matricula);
    printf("Digite o email do aluno: ");
    scanf("%s",node->email);
    node->next=NULL;
    node->head=NULL;
    return node;
}

bool is_empty(List_disciplina *list){
    return list->size==0;
}
bool is_empty(List_aluno *list){
    return list->size==0;
}

void push_aluno(List_aluno *list,Node_aluno *node){
    if(node){
        node->next=list->head;
        list->head=node;
        list->size++;
        return;
    }
}

void print_alunos(List_aluno *list){
    if(is_empty(list)){
        printf("Lista vazia!\n");
        return;
    }
    Node_aluno *node=list->head;
    while(node){
        printf("Nome: %s.\nEmail: %s.\nMatrícula: %s.\n",node->nome,node->email,node->matricula);
        printf("\n-------------------------------------------------------------------------------\n\n");
        node=node->next;
    }
}

void print_disciplinas(List_disciplina *list){
    if(is_empty(list)){
        printf("Lista vazia!\n");
        return;
    }
    Node_disciplina *node=list->head;
    while(node){
        printf("Nome: %s.\nMenção: %s.\n",node->nome,node->mencao);
        printf("\n-------------------------------------------------------------------------------\n\n");
        node=node->next;
    }
}

void pop_aluno(List_aluno *list){
    if(is_empty(list)){
        return;
    }
    Node_aluno *node=list->head;
    list->head=node->next;
    free(node);
    list->size--;
}

void pop_disciplina(List_disciplina *list){
    if(is_empty(list)){
        return;
    }
    Node_disciplina *node=list->head;
    list->head=node->next;
    free(node);
    list->size--;
}