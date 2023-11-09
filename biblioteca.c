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
    int escolha;
    printf("Escolha o número da tarefa que quer editar: ");
    scanf("%d", &escolha);
    if (escolha<lt->qtd) {
        printf("Qual campo deseja editar?\n");
        printf("1- Prioridade: %d\n", lt->tarefas[escolha].prioridade);
        printf("2- Categoria: %s\n", lt->tarefas[escolha].categoria);
        printf("3- Descrição: %s\n", lt->tarefas[escolha].descricao);
        printf("4- Estado (completo, em andamento, não iniciado): %s\n", lt->tarefas[escolha].estado);
        scanf("%d", &escolha);
        if (escolha == 1) {
            printf("Prioridade (0 a 10) nova: ");
            scanf("%d", &lt->tarefas[escolha].prioridade);
            printf("Prioridade editada com sucesso!");
        } else if (escolha == 2) {
            clearbuffer();
            printf("Categoria nova: ");
            scanf(" %[^\n]", lt->tarefas[escolha].categoria);
             printf("Categoria editada com sucesso! ");
        } else if (escolha == 3) {
            clearbuffer();
            printf("Descrição nova: ");
            scanf(" %[^\n]", lt->tarefas[escolha].descricao);
             printf("Descrição editada com sucesso! ");
        } else if (escolha == 4) {
            clearbuffer();
            printf("Novo estado: ");
            scanf(" %[^\n]", lt->tarefas[escolha].estado);
             printf("Estado editado com sucesso! ");
        }
    } else {
        printf("Tarefa não existente, tente novamente.\n");
    }
    return 0;
}

int filtra_prioridade(listadetarefas lt) {
    int prioridade_escolhida;
    printf("Digite a prioridade escolhida: ");
    scanf("%d", &prioridade_escolhida);
    int verifica = 0;
    for (int i = 0; i < lt.qtd; i++) {
        if (lt.tarefas[i].prioridade == prioridade_escolhida) {
            printf("Tarefas com prioridade %d: \n", prioridade_escolhida);
            verifica = 1;
            printf("\n");
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Descrição: %s\n", lt.tarefas[i].descricao);
            printf("Estado: %s\n", lt.tarefas[i].estado);
        }
    }
    if (verifica==0) {
        printf("Não há tarefas com essa prioridade.\n");
    }
}

int filtra_estado (listadetarefas *lt){
    int procura_estado=0;
    char estado_escolhido[50];
    printf("Digite o estado escolhido: \n");
    scanf(" %[^\n]", estado_escolhido);
    for (int procuraestado=0; procuraestado< lt->qtd; procuraestado++){
        if (strcmp(lt->tarefas[procuraestado].estado, estado_escolhido) == 0){
            procura_estado=1;
            printf("Tarefas com estado %s: \n", estado_escolhido);
            printf("\n");
            printf("Prioridade: %d\n", lt->tarefas[procuraestado].prioridade);
            printf("Categoria: %s\n", lt->tarefas[procuraestado].categoria);
            printf("Descrição: %s\n", lt->tarefas[procuraestado].descricao);
            printf("Estado: %s\n", lt->tarefas[procuraestado].estado);
            }
        }
        if(procura_estado==0){
            printf("Não há tarefas com o estado escolhido.\n");
    }
}

int filtra_categoria (listadetarefas *lt){
    int procura_categoria=0;
    char categoria_escolhida[200];
    printf("Digite a categoria escolhida: \n");
    scanf("%s", categoria_escolhida);
    for (int decrescente = 10; decrescente >= 0 ; decrescente--){
        for (int procuracategoria=0; procuracategoria< lt->qtd; procuracategoria++){
            if (strcmp(lt->tarefas[procuracategoria].categoria,categoria_escolhida)==0){
                if(lt->tarefas[procuracategoria].prioridade==decrescente){
                    printf("\n");
                    printf("Tarefas com categoria %s: \n", categoria_escolhida);
                    printf("Prioridade: %d\n", lt->tarefas[procuracategoria].prioridade);
                    printf("Categoria: %s\n", lt->tarefas[procuracategoria].categoria);
                    printf("Descrição: %s\n", lt->tarefas[procuracategoria].descricao);
                    printf("Estado: %s\n", lt->tarefas[procuracategoria].estado);
                    procura_categoria=1;
                }
                
                }
            }

    }  if(procura_categoria==0){
            printf("Não há tarefas com a categoria escolhida.\n");
    }
  
}

int filtra_categoria_prioridade (listadetarefas *lt){
    int procura_categoria_prioridade=0;
    char categoria_escolhida[200];
    printf("Digite a categoria escolhida: \n");
    scanf(" %[^\n]", categoria_escolhida);
    int prioridade_escolhida;
    printf("Digite a prioridade escolhida: \n");
    scanf("%d", &prioridade_escolhida);
    for (int procuracp=0; procuracp< lt->qtd; procuracp++){
        if (lt->tarefas[procuracp].prioridade == prioridade_escolhida){
            if(strcmp(categoria_escolhida,lt->tarefas[procuracp].categoria)==0){
                procura_categoria_prioridade=1;
                printf("Tarefas com categoria %s e prioridade %d: \n", categoria_escolhida, prioridade_escolhida);
                printf("\n");
                printf("Prioridade: %d\n", lt->tarefas[procuracp].prioridade);
                printf("Categoria: %s\n", lt->tarefas[procuracp].categoria);
                printf("Descrição: %s\n", lt->tarefas[procuracp].descricao);
                printf("Estado: %s\n", lt->tarefas[procuracp].estado);
                }
            }
        }  
        if(procura_categoria_prioridade==0){
            printf("Não há tarefas com a categoria e prioridade escolhida.\n");
    }
}


int exporta_prioridade (listadetarefas lt, char arquivo[100]){
    int prioridade_escolhida;
    int verifica=0;
    printf("Digite a prioridade escolhida: \n");
    scanf("%d", &prioridade_escolhida);
      for (int buscaprio=0; buscaprio< lt.qtd; buscaprio++){
        if (lt.tarefas[buscaprio].prioridade == prioridade_escolhida){
            verifica=1;
            break;
        }
    }
    if(verifica==0){
        printf("Não existe a prioridade escolhida atualmente.\n");
        return 1;
    }
    FILE *f = fopen("arquivo_prioridade", "w"); //Abre um arquivo no formato binário
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n"); //Caso o arquivo não exista, esta mensagem aparece no terminal alertando o usuário
        return 1;
    }
    for (int buscaprio=0; buscaprio< lt.qtd; buscaprio++){
        if (lt.tarefas[buscaprio].prioridade == prioridade_escolhida){
            fprintf(f, "Prioridade: %d / Categoria: %s / Estado: %s / Descricao: %s\n", lt.tarefas[buscaprio].prioridade, lt.tarefas[buscaprio].categoria, lt.tarefas[buscaprio].estado, lt.tarefas[buscaprio].descricao);
        }
    }
    printf("Tarefas exportadas por prioridade.\n");
    fclose(f); //Fecha o arquivo
    return 0;
        
}
int exporta_categoria(listadetarefas *lt, char arquivo[100]){
    char categoria_escolhida[200];
    int verifica = 0;
    printf("Digite a categoria escolhida: \n");
    scanf(" %[^\n]", categoria_escolhida);
    for (int buscacat = 0; buscacat < lt->qtd; buscacat++) {
        if (strcmp(lt->tarefas[buscacat].categoria, categoria_escolhida) == 0) {
            verifica = 1;
            break;
        }
    }
    if (verifica == 0) {
        printf("Não existe a categoria escolhida atualmente.\n");
        return 1;
    }
    FILE *f = fopen(arquivo, "w"); // Abre um arquivo no formato binário
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n"); // Caso o arquivo não exista, esta mensagem aparece no terminal alertando o usuário
        return 1;
    }
    for (int decrescente = 10; decrescente >= 0; decrescente--) {
        for (int buscacat = 0; buscacat < lt->qtd; buscacat++) {
            if (strcmp(lt->tarefas[buscacat].categoria, categoria_escolhida) == 0) {
                if (lt->tarefas[buscacat].prioridade == decrescente) {
                    fprintf(f, "Prioridade: %d / Categoria: %s / Estado: %s / Descricao: %s\n", lt->tarefas[buscacat].prioridade, lt->tarefas[buscacat].categoria, lt->tarefas[buscacat].estado, lt->tarefas[buscacat].descricao);
                }
            }
        }
    }
    printf("Tarefas exportadas por categoria.\n");
    fclose(f); // Fecha o arquivo
    return 0;
}
int exporta_categoria_prioridade(listadetarefas *lt, char arquivo[100]) {
    int verifica = 0;
    int prioridade_escolhida;
    printf("Digite a prioridade escolhida: \n");
    scanf("%d", &prioridade_escolhida);
    char categoria_escolhida[200];
    printf("Digite a categoria escolhida: \n");
    scanf(" %[^\n]", categoria_escolhida);
    for (int buscacp = 0; buscacp < lt->qtd; buscacp++) {
        if (lt->tarefas[buscacp].prioridade == prioridade_escolhida) {
            if (strcmp(categoria_escolhida, lt->tarefas[buscacp].categoria) == 0) {
                verifica = 1;
            }
        }
    }
    FILE *f = fopen(arquivo, "w"); // Abre um arquivo no formato binário
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n"); // Caso o arquivo não exista, esta mensagem aparece no terminal alertando o usuário
        return 1;
    }
    for (int buscacp = 0; buscacp < lt->qtd; buscacp++) {
        if (lt->tarefas[buscacp].prioridade == prioridade_escolhida) {
            if (strcmp(categoria_escolhida, lt->tarefas[buscacp].categoria) == 0) {
                fprintf(f, "Prioridade: %d / Categoria: %s / Estado: %s / Descricao: %s\n", lt->tarefas[buscacp].prioridade, lt->tarefas[buscacp].categoria, lt->tarefas[buscacp].estado, lt->tarefas[buscacp].descricao);
            }
        }
    }
    if (verifica == 0) {
        printf("Não existe a categoria ou a prioridade escolhida atualmente.\n");
        return 1;
    }
    else{
        fclose(f); // Fecha o arquivo
        printf("Tarefas exportadas por categoria e prioridade.\n");
        
    }return 0;
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
