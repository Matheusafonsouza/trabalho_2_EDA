#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//Struct node para disciplina.
typedef struct node_disciplina{
    char *nome,*mencao;
    struct node_disciplina *next;
}Node_disciplina;

//Struct lista para disciplina.
typedef struct list_disciplina{
    int size;
    Node_disciplina *head;
}List_disciplina;

//Struct node para aluno.
typedef struct node_aluno{
    char *nome,*email,*matricula;
    List_disciplina *head;
    struct node_aluno *next;
}Node_aluno;

//Struct lista para aluno.
typedef struct list_aluno{
    int size;
    Node_aluno *head;
}List_aluno;

//Cria Lista de disciplinas vazia.
List_disciplina * create_list_disciplina(){
    List_disciplina *list=(List_disciplina*)malloc(sizeof(List_disciplina));
    list->head=NULL;
    list->size=0;
    return list;
}

//Cria node disciplina, registra nome e menção.
Node_disciplina * create_node_disciplica(){
    char continuar;
    Node_disciplina *node=(Node_disciplina*)malloc(sizeof(Node_disciplina));
    node->mencao=(char*)malloc(sizeof(char)*2);
    node->nome=(char*)malloc(sizeof(char)*40);
    getchar();
    printf("Digite o nome da disciplina: ");
    scanf("%[^\n]",node->nome);
    
    do{
        printf("Digite a menção: ");
        scanf("%s",node->mencao);

        if(strcmp(node->mencao,"TR")!=0&&strcmp(node->mencao,"II")!=0&&strcmp(node->mencao,"MI")!=0&&strcmp(node->mencao,"MM")!=0&&strcmp(node->mencao,"MS")!=0&&strcmp(node->mencao,"SS")!=0){
            printf("Menção inválida! Aperte entender para digitar novamente.\n");
            getchar();
            scanf("%c",&continuar);
        }
        else{
            break;
        }

    }while(strcmp(node->mencao,"TR")!=0&&strcmp(node->mencao,"II")!=0&&strcmp(node->mencao,"MI")!=0&&strcmp(node->mencao,"MM")!=0&&strcmp(node->mencao,"MS")!=0&&strcmp(node->mencao,"SS")!=0);
    node->next=NULL;
    return node;
}

//Cria lista de alunos vazia.
List_aluno * create_list_aluno(){
    List_aluno *list=(List_aluno*)malloc(sizeof(List_aluno));
    list->head=NULL;
    list->size=0;
    return list;
}

//Cria node aluno, registra email, nome e matricula.
Node_aluno * create_node_aluno(){
    Node_aluno *node=(Node_aluno*)malloc(sizeof(Node_aluno));
    node->email=(char*)malloc(sizeof(char)*40);
    node->matricula=(char*)malloc(sizeof(char)*40);
    node->nome=(char*)malloc(sizeof(char)*40);
    getchar();
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

//Insere novos nome, matricula e email para um node aluno.
void edit_aluno(Node_aluno *node){
    if(node){
        getchar();
        printf("Digite o novo nome do aluno: ");
        scanf("%[^\n]",node->nome);
        printf("Digite a nova matrícula do aluno: ");
        scanf("%s",node->matricula);
        printf("Digite o novo email do aluno: ");
        scanf("%s",node->email);
    }
}
//Insere novos nome e menção para um node disciplina.
void edit_disciplina(Node_disciplina *node){
    if(node){
        getchar();
        printf("Digite o nome da disciplina: ");
        scanf("%[^\n]",node->nome);
        printf("Digite a menção: ");
        scanf("%s",node->mencao);
    }
}

//Verifica se a lista de disciplinas está vazia.
bool is_empty_disciplina(List_disciplina *list){
    return list->size==0;
}
//Verifica se a lista de alunos está vazia.
bool is_empty_aluno(List_aluno *list){
    return list->size==0;
}

//Insere aluno na primeira posição da lista.
void push_aluno(List_aluno *list,Node_aluno *node){
    if(node){
        node->next=list->head;
        list->head=node;
        list->size++;
        return;
    }
}

//Insere disciplina na primeira posição da lista.
void push_disciplina(List_disciplina *list,Node_disciplina *node){
    if(node){
        node->next=list->head;
        list->head=node;
        list->size++;
        return;
    }
}


//Printa lista de alunos.
void print_alunos(List_aluno *list){
    if(is_empty_aluno(list)){
        printf("Lista vazia!\n");
        return;
    }
    Node_aluno *node=list->head;
    while(node){
        printf("Nome: %s.\nEmail: %s.\nMatrícula: %s.\n",node->nome,node->email,node->matricula);
        if(node->head==NULL||node->head->size==0){
            printf("Aluno sem disciplina.\n");
        }else{
            printf("Histórico: %d disciplinas.",node->head->size);
        }
        printf("\n-------------------------------------------------------------------------------\n\n");
        node=node->next;
    }
}

//Printa lista de disciplinas.
void print_disciplinas(List_disciplina *list){
    if(is_empty_disciplina(list)){
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

//Exclui primeira posição da lista de alunos.
void pop_aluno(List_aluno *list){
    if(is_empty_aluno(list)){
        printf("Lista vazia!\n");
        return;
    }
    Node_aluno *node=list->head;
    list->head=node->next;
    free(node);
    list->size--;
}

//Exclui primeira posição da lista de disciplinas.
void pop_disciplina(List_disciplina *list){
    if(is_empty_disciplina(list)){
        printf("Lista vazia!\n");
        return;
    }
    Node_disciplina *node=list->head;
    list->head=node->next;
    free(node);
    list->size--;
}

//Retorna nodeda lista de alunos baseado em seu índice.
Node_aluno * at_pos(List_aluno *list, int index){
    if(is_empty_aluno(list)){
        printf("Lista Vazia!\n");
        return NULL;
    }
    if(index>list->size||index<=0){
        printf("Índice inválido.\n");
        return NULL;
    }
    Node_aluno *aux=list->head;
    do{
        if(index==1){
            return aux;
        }
        aux=aux->next;
        index--;
    }while(index!=1);
}

//Filtra disciplinas por menção
void filtrar_disciplinas(List_disciplina *list){
    if(is_empty_disciplina(list)){
        printf("Lista vazia!\n");
        return;
    }
    Node_disciplina *aux=list->head;
    printf("TR:\n");
    while(aux){
        if(strcmp(aux->mencao,"TR")==0){
            printf("%s\n",aux->nome);
        }else{

        }
        aux=aux->next;
    }
    printf("\n");
    aux=list->head;
    printf("II:\n");
    while(aux){
        if(strcmp(aux->mencao,"II")==0){
            printf("%s\n",aux->nome);
        }else{

        }
        aux=aux->next;
    }
    printf("\n");
    aux=list->head;
    printf("MI:\n");
    while(aux){
        if(strcmp(aux->mencao,"MI")==0){
            printf("%s\n",aux->nome);
        }else{

        }
        aux=aux->next;
    }
    printf("\n");
    aux=list->head;
    printf("MM:\n");
    while(aux){
        if(strcmp(aux->mencao,"MM")==0){
            printf("%s\n",aux->nome);
        }else{

        }
        aux=aux->next;
    }
    printf("\n");
    aux=list->head;
    printf("MS:\n");
    while(aux){
        if(strcmp(aux->mencao,"MS")==0){
            printf("%s\n",aux->nome);
        }else{

        }
        aux=aux->next;
    }
    printf("\n");
    aux=list->head;
    printf("SS:\n");
    while(aux){
        if(strcmp(aux->mencao,"SS")==0){
            printf("%s\n",aux->nome);
        }else{

        }
        aux=aux->next;
    }
    printf("\n");
}

//Procura aluno baseado em seu nome.
Node_aluno * search_by_name(List_aluno *list,char *procura){
    if(is_empty_aluno(list)){
        printf("Lista vazia!\n");
        return NULL;
    }
    Node_aluno *aux=list->head;
    char *search;
    int contador=0,i=0,op;
    while(aux){
        search=strstr(aux->nome,procura);
        if(search==NULL){
        }else{
            contador++;
        }
        aux=aux->next;
    }
    Node_aluno **list_nomes=(Node_aluno**)malloc(sizeof(Node_aluno*)*contador);
    aux=list->head;
    while(aux){
        search=strstr(aux->nome,procura);
        if(search==NULL){
        }else{
            list_nomes[i]=aux;
            i++;
        }
        aux=aux->next;
    }
    if(contador==0){
        printf("Não existe esse aluno!\n");
        return NULL;
    }
    else{
        printf("Alunos encontrados:\n");
        for(i=0;i<contador;i++){
            printf("%d. %s.\n",i+1,list_nomes[i]->nome);
        }
        printf("Escolha o número do aluno: ");
        scanf("%d",&op);
        return list_nomes[op-1];
    }
}

//O=Procura aluno baseado em seu nome.
Node_aluno * search_by_email(List_aluno *list,char *procura){
    if(is_empty_aluno(list)){
        printf("Lista vazia!\n");
        return NULL;
    }
    Node_aluno *aux=list->head;
    char *search;
    int contador=0,i=0,op;
    while(aux){
        search=strstr(aux->email,procura);
        if(search==NULL){
        }else{
            contador++;
        }
        aux=aux->next;
    }
    Node_aluno **list_emails=(Node_aluno**)malloc(sizeof(Node_aluno*)*contador);
    aux=list->head;
    while(aux){
        search=strstr(aux->email,procura);
        if(search==NULL){
        }else{
            list_emails[i]=aux;
            i++;
        }
        aux=aux->next;
    }
    if(contador==0){
        printf("Não existe esse aluno!\n");
        return NULL;
    }
    else{
        printf("Alunos encontrados:\n");
        for(i=0;i<contador;i++){
            printf("%d. %s.\n",i+1,list_emails[i]->nome);
        }
        printf("Escolha o número do aluno: ");
        scanf("%d",&op);
        return list_emails[op-1];
    }
}

//Deleta aluno.
void erase_aluno(List_aluno *list,Node_aluno *node){
    if(is_empty_aluno(list)){
        printf("Lista vazia!\n");
        return;
    }
    if(node){
        if(list->size==1){
            pop_aluno(list);
            return;
        }
        if(list->head->matricula==node->matricula){
            pop_aluno(list);
            return;
        }
        Node_aluno *aux=list->head,*aux2;
        while(aux){
            if(aux->next->matricula==node->matricula){
                aux2=aux;
                aux=aux->next;
                aux2->next=aux->next;
                list->size--;
                break;
            }
            aux=aux->next;
        }
        
        free(aux);
    }
}

//Deleta disciplina.
void erase_disciplina(List_disciplina *list,Node_disciplina *node){
    if(is_empty_disciplina(list)){
        printf("Lista vazia!\n");
        return;
    }
    if(node){
        if(list->size==1){
            pop_disciplina(list);
            return;
        }
        if(list->head->nome==node->nome){
            pop_disciplina(list);
            return;
        }
        Node_disciplina *aux=list->head,*aux2;
        while(aux){
            if(aux->next->nome==node->nome){
                aux2=aux;
                aux=aux->next;
                aux2->next=aux->next;
                list->size--;
                break;
            }
            aux=aux->next;
        }
        
        free(aux);
    }
}

//Procura disciplina baseado em seu nome.
Node_disciplina * search_disciplina(List_disciplina *list,char *procura){
    if(is_empty_disciplina(list)){
        printf("Lista vazia!\n");
        return NULL;
    }
    Node_disciplina *aux=list->head;
    char *search;
    int contador=0,i=0,op;
    while(aux){
        search=strstr(aux->nome,procura);
        if(search==NULL){
        }else{
            contador++;
        }
        aux=aux->next;
    }
    Node_disciplina **list_nomes=(Node_disciplina**)malloc(sizeof(Node_disciplina*)*contador);
    aux=list->head;
    while(aux){
        search=strstr(aux->nome,procura);
        if(search==NULL){
        }else{
            list_nomes[i]=aux;
            i++;
        }
        aux=aux->next;
    }
    if(contador==0){
        printf("Não existe essa Disciplina!\n");
        return NULL;
    }
    else{
        printf("Disciplinas encontrados:\n");
        for(i=0;i<contador;i++){
            printf("%d. %s.\n",i+1,list_nomes[i]->nome);
        }
        printf("Escolha o número da disciplina: ");
        scanf("%d",&op);
        return list_nomes[op-1];
    }
}

//Emite relatório geral do aluno.
void relatorio_geral(List_disciplina* list){
    Node_disciplina *node=list->head;
    int tr=0,ii=0,mi=0,mm=0,ms=0,ss=0;

    while(node){
        if(strcmp(node->mencao,"TR")==0){
            tr++;
        }
        if(strcmp(node->mencao,"II")==0){
            ii++;
        }
        if(strcmp(node->mencao,"MI")==0){
            mi++;
        }
        if(strcmp(node->mencao,"MM")==0){
            mm++;
        }
        if(strcmp(node->mencao,"MS")==0){
            ms++;
        }
        if(strcmp(node->mencao,"SS")==0){
            ss++;
        }
        node=node->next;
    }

    printf("Numero de disciplinas cursadas: %d.\n",list->size);
    printf("Numero de aprovações: %d.\n",mm+ms+ss);
    printf("Numero de reprovações: %d.\n",ii+mi);
    printf("Numero de disciplinas trancadas: %d.\n",tr);
}