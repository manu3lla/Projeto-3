#ifndef PROJETO_1_BIBLIOTECA_H
#define PROJETO_1_BIBLIOTECA_H
#endif //PROJETO_1_BIBLIOTECA_H
//Criação do struct dos elementos da tarefa, incluindo prioridade, categoria e descrição (com a quantidade máxima de caracteres em cada um)
typedef struct {
    int prioridade;
    char categoria[100];
    char descricao[300];
    char estado[100];
} tarefa;
// Criação do struct que une os elementos da tarefa, criando uma lista de tarefas
typedef struct {
    tarefa tarefas[100];
    int qtd;
} listadetarefas;

//Chamando as funções já explicadas em "biblioteca.c"
int criartarefa(listadetarefas *lt);
int deletartarefa(listadetarefas *lt);
int listartarefa(listadetarefas lt);
int alteratarefa(listadetarefas *lt);
int filtra_prioridade (listadetarefas *lt);
int filtra_estado (listadetarefas *lt);
int filtra_categoria (listadetarefas *lt);
int filtra_categoria_prioridade (listadetarefas *lt);
int exporta_prioridade (listadetarefas lt, char arquivo[100]);
int exporta_categoria (listadetarefas *lt, char arquivo[100]);
int exporta_categoria_prioridade (listadetarefas *lt);


int salvarlista(listadetarefas *lt, char nome[]);
int carregarlista(listadetarefas *lt, char nome[]);