#include "biblioteca.h"
#include <stdio.h>
#include <string.h>

void clearbuffer(){
   int lt; 
   while((lt = getchar()) != '\n' && lt != EOF); 
}
//Função para criar a tarefa onde o usuário pode declarar a prioridade, categoria e descrição do lembrete;
int criartarefa(listadetarefas *lt){
    if (lt->qtd < 100) { //se a quantidade de tarefas for menor que cem (o máximo) o programa irá pedir a prioridade da tarefa, sua categoria e descrição.
        printf("Prioridade (0 a 10): ");
        scanf("%d", &lt->tarefas[lt->qtd].prioridade); //Pedimos a prioridade da tarefa e guardamos a informação na memória.
        printf("Categoria: ");
        scanf(" %[^\n]", lt->tarefas[lt->qtd].categoria); // Usamos " %[^\n]" para ler o "scanf" com espaços, guardando o que o usuário informar como prioridade na memória..
        printf("Descricao: ");
        scanf(" %[^\n]", lt->tarefas[lt->qtd].descricao); // Usamos " %[^\n]" para ler o "scanf" com espaços, guardando o que o usuário informar como prioridade na memória.
        printf("Estado da tarefa (completo, em andamento, não iniciado): ");
        scanf(" %[^\n]", lt->tarefas[lt->qtd].estado);
        lt->qtd++; //A quantidade de tarefas aumenta quando o usuário terminar de descrever sua tarefa.
        printf("Tarefa cadastrada!\n"); //Quando o usuário terminar de descrever a tarefa essa mensagem aparece.
    } else {
        printf("A lista de tarefas esta cheia! Nao e possivel adicionar mais tarefas.(MAXIMO 100)\n"); //Caso haja mais de 100 tarefas é informado que foi atingida a capacidade máxima.
    }
    return 0;
}


int deletartarefa(listadetarefas *lt){ //Função para deletar tarefas
    int posicao;
    printf("Digite o numero da tarefa que deseja deletar (de 1 a %d): ", lt->qtd); //Pedindo pro usuário informar a tarefa que deve ser deletada.
    scanf("%d", &posicao);//Usuário informa qual é sua tarefa e ela é deletada a partir da posição que está na lista de tarefas (encontramos ela na lista por sua posição).
    if (posicao >= 1 && posicao <= lt->qtd) { //Se a posição da tarefa foi maior que 1 e menor ou igual que a quantidade, poderá ser encontrada (pois ela existe)
        posicao--; //Apaga a tarefa
        for (int i = posicao; i < lt->qtd - 1; i++) { //Um "for" para iterar entre as posições , e enquanto for menor que a quantidade da lista de tarefas, ele apaga e corrige a posição da tarefa na lista.
            lt->tarefas[i] = lt->tarefas[i + 1];
        }
        lt->qtd--; //Diminui a quantidade de tarefas.
        printf("Tarefa deletada!\n"); //Informa que ela foi deletada com sucesso
    } else {
        printf("Essa tarefa nao existe!\n"); //Caso a tarefa não for encontrada (for menor que 1 ou maior que a quantidade atual), será informado que ela não existe.
    }
    return 0;
}


int listartarefa(listadetarefas lt){ //Função para listar as tarefas previamente adicionadas
    if (lt.qtd == 0) {
        printf("A lista de tarefas esta vazia.\n"); //Se a quantidade de tarefas for 0 aparecerá essa mensagem
    } else {
        printf("Lista de tarefas:\n"); //Caso a quantidade de tarefas for maior que 0, pegamos a tarefa por sua posição (i) e listamos.
        for (int i = 0; i < lt.qtd; i++) {
            printf("Tarefa %d:\n", i + 1);//Imprime a tarefa em ordem cronológica (começando por "Tarefa 1"), assim, conforme o número de tarefas cresce é somado o número da tarefa anterior à 1.
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade); //Imprime a prioridade, procurando a  informação a partir da posição da tarefa na lista.
            printf("Categoria: %s\n", lt.tarefas[i].categoria); //Imprime a categoria, procurando a  informação a partir da posição da tarefa na lista.
            printf("Descricao: %s\n", lt.tarefas[i].descricao); //Imprime a descrição, procurando a  informação a partir da posição da tarefa na lista.
            printf("Estado (completo, em andamento, não iniciado): %s\n", lt.tarefas[i].estado);
            printf("\n"); //Imprime um espaço para organizar a listagem
        }
    }
    return 0;
}

int alteratarefa(listadetarefas *lt) {
    int lugar;
    int escolha;
    printf("Escolha o número da tarefa que quer editar: ");
    scanf("%d", &lugar);
    if (lugar >= 1 && lugar <= lt->qtd) {
        lugar--;
        printf("Qual campo deseja editar?\n");
        printf("1- Prioridade: %d\n", lt->tarefas[lugar].prioridade);
        printf("2- Categoria: %s\n", lt->tarefas[lugar].categoria);
        printf("3- Descrição: %s\n", lt->tarefas[lugar].descricao);
        printf("4- Estado (completo, em andamento, não iniciado): %s\n", lt->tarefas[lugar].estado);
        scanf("%d", &escolha);
        if (escolha == 1) {
            printf("Prioridade (0 a 10) nova: ");
            scanf("%d", &lt->tarefas[lugar].prioridade);
            printf("Prioridade editada com sucesso!");
        } else if (escolha == 2) {
            clearbuffer();
            printf("Categoria nova: ");
            scanf(" %[^\n]", lt->tarefas[lugar].categoria);
             printf("Categoria editada com sucesso! ");
        } else if (escolha == 3) {
            clearbuffer();
            printf("Descrição nova: ");
            scanf(" %[^\n]", lt->tarefas[lugar].descricao);
             printf("Descrição editada com sucesso! ");
        } else if (escolha == 4) {
            clearbuffer();
            printf("Novo estado: ");
            scanf(" %[^\n]", lt->tarefas[lugar].estado);
             printf("Estado editado com sucesso! ");
        }
    } else {
        printf("Tarefa não existente, tente novamente.\n");
    }
    return 0;
}

int filtra_prioridade (listadetarefas *lt){
    int prioridade_escolhida;
    printf("Digite a prioridade escolhida: ");
    scanf("%d", &prioridade_escolhida);
    for (int i=0; i< lt->qtd; i++){
        if (lt->tarefas[i].prioridade == prioridade_escolhida){
            printf("Tarefas com prioridade %d: \n", prioridade_escolhida);
            printf("\n");
            printf("Prioridade: %d\n", lt->tarefas[i].prioridade);
            printf("Categoria: %s\n", lt->tarefas[i].categoria);
            printf("Descrição: %s\n", lt->tarefas[i].descricao);
            printf("Estado (completo, em andamento, não iniciado): %s\n", lt->tarefas[i].estado);
        }
        else{
            printf("Não há tarefas com essa prioridade.\n");
        }
    }


}

int filtra_estado (listadetarefas *lt){
    char estado_escolhido[100];
    printf("Digite o estado escolhido (completo, em andamento, não iniciado): ");
    scanf("%s", estado_escolhido);
    for (int i=0; i< lt->qtd; i++){
        if (strcmp(lt->tarefas[i].estado, estado_escolhido)==0){
            printf("Tarefas com estado %s: \n", estado_escolhido);
            printf("Prioridade: %d\n", lt->tarefas[i].prioridade);
            printf("Categoria: %s\n", lt->tarefas[i].categoria);
            printf("Descrição: %s\n", lt->tarefas[i].descricao);
            printf("Estado (completo, em andamento, não iniciado): %s\n", lt->tarefas[i].estado);
        }
        else{
            printf("Não há tarefas com o estado escolhido.\n");
        }
    }


}



int salvarlista(listadetarefas *lt, char nome[]){ //Função para salvar a lista no arquivo
    FILE *f = fopen(nome, "wb"); //Abre um arquivo no formato binário
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n"); //Caso o arquivo não exista, esta mensagem aparece no terminal alertando o usuário
        return 1;
    }
    fwrite(lt, sizeof(listadetarefas), 1, f); //Este comando escreve no arquivo em formato binário as informações dadas pelo usuário
    fclose(f); //Fecha o arquivo
    return 0;
}


int carregarlista(listadetarefas *lt, char nome[]){ //Função para carregar a lista de tarefas
    FILE *f = fopen(nome, "rb"); //Abre o arquivo em formato de leitura binária
    if (f == NULL) {
        printf("Arquivo nao encontrado.\n"); //Caso o arquivo não exista, esta mensagem aparece no terminal alertando o usuário
        return 1;
    }
    fread(lt, sizeof(listadetarefas), 1, f); //Este comando le o arquivo binário
    fclose(f); //Fecha o arquivo
    return 0;
}