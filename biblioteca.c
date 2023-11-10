//Manuella Filipe Peres R.A 24.123.036-6
#include "biblioteca.h"
#include <stdio.h>
#include <string.h>

//Limpa o buffer para novas informações serem armazenadas
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
        scanf(" %[^\n]", lt->tarefas[lt->qtd].categoria); // Usamos " %[^\n]" para ler o "scanf" com espaços, guardando o que o usuário informar como categoria na memória..
        printf("Descricao: ");
        scanf(" %[^\n]", lt->tarefas[lt->qtd].descricao); // Usamos " %[^\n]" para ler o "scanf" com espaços, guardando o que o usuário informar como descrição na memória.
        printf("Estado da tarefa (completo, em andamento, não iniciado): ");
        scanf(" %[^\n]", lt->tarefas[lt->qtd].estado); // Usamos " %[^\n]" para ler o "scanf" com espaços, guardando o que o usuário informar como estado na memória.
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
            printf("Estado (completo, em andamento, não iniciado): %s\n", lt.tarefas[i].estado); //Imprime o estado, procurando a  informação a partir da posição da tarefa na lista.
            printf("\n"); //Imprime um espaço para organizar a listagem
        }
    }
    return 0;
}

int alteratarefa(listadetarefas *lt) { //Função para editar as tarefas
    int escolha_tarefa;
    printf("Escolha o número da tarefa que quer editar: "); //Pede o número da tarefa que o usuário deseja editar e salva na variável
    scanf("%d", &escolha_tarefa);
    escolha_tarefa--; //Ajusta a posição da escolha de tarefa a ser editada do usuário para que corresponda ao indíce correto no "listadetarefas"
    if (escolha_tarefa >= 0 && escolha_tarefa < lt->qtd) { //Condição que verifica se a escolha da tarefa está dentro dos limites utilizáveis (maior ou igual a zero e menor que a quantidade de itens na "listadetarefas")
        int escolha_campo;
        printf("Qual campo deseja editar?\n"); //Pergunta qual campo o usuário deseja editar, mostrando cada um deles no momento atual na tarefa escolhida anteriormente para uma melhor visualização
        printf("1- Prioridade: %d\n", lt->tarefas[escolha_tarefa].prioridade);
        printf("2- Categoria: %s\n", lt->tarefas[escolha_tarefa].categoria);
        printf("3- Descrição: %s\n", lt->tarefas[escolha_tarefa].descricao);
        printf("4- Estado (completo, em andamento, não iniciado): %s\n", lt->tarefas[escolha_tarefa].estado);
        scanf("%d", &escolha_campo);
        if (escolha_campo == 1) { //Se o usuário escolher editar o campo 1, ele pede a nova prioridade e substitui a informação na variável prioridade dentro do array listadetarefas
            printf("Prioridade (0 a 10) nova: ");
            scanf("%d", &lt->tarefas[escolha_tarefa].prioridade);
            printf("Prioridade editada com sucesso!");
        } else if (escolha_campo == 2) {
            clearbuffer();
            printf("Categoria nova: ");//Se o usuário escolher editar o campo 2, ele pede a nova categoria e substitui a informação na variável categoria dentro do array listadetarefas
            scanf(" %[^\n]", lt->tarefas[escolha_tarefa].categoria);
            printf("Categoria editada com sucesso! ");
        } else if (escolha_campo == 3) {
            clearbuffer();
            printf("Descrição nova: "); //Se o usuário escolher editar o campo 3, ele pede a nova descrição e substitui a informação na variável descrição dentro do array listadetarefas
            scanf(" %[^\n]", lt->tarefas[escolha_tarefa].descricao);
            printf("Descrição editada com sucesso! ");
        } else if (escolha_campo == 4) {
            clearbuffer();
            printf("Novo estado: "); //Se o usuário escolher editar o campo 4, ele pede o novo estado e substitui a informação na variável estado dentro do array listadetarefas
            scanf(" %[^\n]", lt->tarefas[escolha_tarefa].estado);
            printf("Estado editado com sucesso! ");
        } else {
            printf("Escolha de campo inválida.\n"); //Caso o campo não exista cai nessa condição e printa essa mensagem
        }
    } else {
        printf("Tarefa não existente, tente novamente.\n"); //Caso a tarefa não exista cai nessa condição e printa essa mensagem
    }
    return 0;
}


int filtra_prioridade(listadetarefas lt) { //Função para filtrar a tarefa por prioridade
    int prioridade_escolhida;
    printf("Digite a prioridade escolhida: "); //Pede a prioridade que o usuário quer filtrar e guarda em uma variável
    scanf("%d", &prioridade_escolhida);
    int verifica = 0; //variável para verificar se há tarefas com a prioridade escolhida
    for (int i = 0; i < lt.qtd; i++) { //percorre a lista de tarefas
        if (lt.tarefas[i].prioridade == prioridade_escolhida) { //verifica se a prioridade escolhida existe na lista de tarefas
            printf("Tarefas com prioridade %d: \n", prioridade_escolhida); //printa as tarefas com a prioridade escolhida e sua categoria, descrição e estado
            verifica = 1; //aumentamos 1 na variável para dizer que existem tarefas com essa prioridade
            printf("\n");
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Descrição: %s\n", lt.tarefas[i].descricao);
            printf("Estado: %s\n", lt.tarefas[i].estado);
        }
    }
    if (verifica==0) { //caso não existam tarefas com essa prioridade essa condição é acionada
        printf("Não há tarefas com essa prioridade.\n");
    }
}

int filtra_estado (listadetarefas *lt){ //Função para filtrar a tarefa por estado
    int procura_estado=0; //variável para verificar se há tarefas com o estado escolhido
    char estado_escolhido[50];
    printf("Digite o estado escolhido: \n"); //Pede o estado que o usuário quer filtrar e guarda em uma variável
    scanf(" %[^\n]", estado_escolhido);
    for (int procuraestado=0; procuraestado< lt->qtd; procuraestado++){ //percorre a lista de tarefas
        if (strcmp(lt->tarefas[procuraestado].estado, estado_escolhido) == 0){ //verifica por meio do strcmp se existe um estado igual ao escolhido pelo usuário na lista de tarefas
            procura_estado=1; //aumentamos 1 na variável para dizer que existem tarefas com esse estado
            printf("Tarefas com estado %s: \n", estado_escolhido); //printa as tarefas com o estado escolhido e sua categoria, descrição e prioridade
            printf("\n");
            printf("Prioridade: %d\n", lt->tarefas[procuraestado].prioridade);
            printf("Categoria: %s\n", lt->tarefas[procuraestado].categoria);
            printf("Descrição: %s\n", lt->tarefas[procuraestado].descricao);
            printf("Estado: %s\n", lt->tarefas[procuraestado].estado);
            }
        }
        if(procura_estado==0){ //caso não existam tarefas com essa prioridade essa condição é acionada
            printf("Não há tarefas com o estado escolhido.\n");
    }
}

int filtra_categoria (listadetarefas *lt){ //Função para filtrar a tarefa por categoria
    int procura_categoria=0; //variável para verificar se há tarefas com a categoria escolhida
    char categoria_escolhida[200];
    printf("Digite a categoria escolhida: \n"); //Pede a categoria que o usuário quer filtrar e guarda em uma variável
    scanf("%s", categoria_escolhida);
    for (int decrescente = 10; decrescente >= 0 ; decrescente--){ //for criado com o intuito de printar de maneira decrescente a prioridade a partir da categoria escolhida, percorrendo-as e ordenando da maneira escolhida (do maior pro menor)
        for (int procuracategoria=0; procuracategoria< lt->qtd; procuracategoria++){ //percorre a lista de tarefas
            if (strcmp(lt->tarefas[procuracategoria].categoria,categoria_escolhida)==0){ //verifica se a categoria escolhida existe na lista de tarefas
                if(lt->tarefas[procuracategoria].prioridade==decrescente){ //verifica a prioridade dentro da categoria escolhida e utiliza o primeiro for da função para printar a prioridade de maneira decrescente
                    printf("\n");
                    printf("Tarefas com categoria %s: \n", categoria_escolhida); //printa as tarefas com a categoria escolhida e seu estado, descrição e prioridade
                    printf("Prioridade: %d\n", lt->tarefas[procuracategoria].prioridade);
                    printf("Categoria: %s\n", lt->tarefas[procuracategoria].categoria);
                    printf("Descrição: %s\n", lt->tarefas[procuracategoria].descricao);
                    printf("Estado: %s\n", lt->tarefas[procuracategoria].estado);
                    procura_categoria=1; //aumentamos 1 na variável para dizer que existem tarefas com essa categoria
                }
                
                }
            }

    }  if(procura_categoria==0){ //caso não existam tarefas com essa categoria essa condição é acionada
            printf("Não há tarefas com a categoria escolhida.\n");
    }
  
}

int filtra_categoria_prioridade (listadetarefas *lt){ //Função para filtrar a tarefa por categoria e prioridade
    int procura_categoria_prioridade=0; //variável para verificar se há tarefas com a categoria e prioridade escolhidas
    char categoria_escolhida[200];
    printf("Digite a categoria escolhida: \n"); //Pede a categoria que o usuário quer filtrar e guarda em uma variável
    scanf(" %[^\n]", categoria_escolhida);
    int prioridade_escolhida;
    printf("Digite a prioridade escolhida: \n"); //Pede a prioridade que o usuário quer filtrar e guarda em uma variável
    scanf("%d", &prioridade_escolhida);
    for (int procuracp=0; procuracp< lt->qtd; procuracp++){ //percorre a lista de tarefas
        if (lt->tarefas[procuracp].prioridade == prioridade_escolhida){ //verifica se a prioridade escolhida existe na lista de tarefas
            if(strcmp(categoria_escolhida,lt->tarefas[procuracp].categoria)==0){ // caso a prioridade escolhida exista verifica se a categoria escolhida existe na lista de tarefas
                procura_categoria_prioridade=1; //aumentamos 1 na variável para dizer que existem tarefas com essa categoria e prioridade
                printf("Tarefas com categoria %s e prioridade %d: \n", categoria_escolhida, prioridade_escolhida);
                printf("\n");
                printf("Prioridade: %d\n", lt->tarefas[procuracp].prioridade); //printa as tarefas com a categoria e prioridade escolhida e seu estado e descrição
                printf("Categoria: %s\n", lt->tarefas[procuracp].categoria);
                printf("Descrição: %s\n", lt->tarefas[procuracp].descricao);
                printf("Estado: %s\n", lt->tarefas[procuracp].estado);
                }
            }
        }  
        if(procura_categoria_prioridade==0){ //caso não existam tarefas com essa categoria e prioridade simultaneamente essa condição é acionada
            printf("Não há tarefas com a categoria e prioridade escolhida.\n");
    }
}


int exporta_prioridade (listadetarefas lt, char arquivo[100]){ //função para exportar tarefa por prioridade
    int prioridade_escolhida;
    int verifica=0; //variável para verificar se há tarefas com a prioridade escolhida
    printf("Digite a prioridade escolhida: \n"); //Pede a prioridade que o usuário quer filtrar e guarda em uma variável
    scanf("%d", &prioridade_escolhida);
      for (int buscaprio=0; buscaprio< lt.qtd; buscaprio++){ //percorre a lista de tarefas, essa função difere da segunda pois ela é feita para verificar se existe a tarefa com a prioridade escolhida, já a outra serve para printar as informações no arquivo criado
        if (lt.tarefas[buscaprio].prioridade == prioridade_escolhida){ //verifica se a prioridade escolhida existe na lista de tarefas
            verifica=1; //aumentamos 1 na variável para dizer que existem tarefas com essa prioridade
            break;
        }
    }
    
    FILE *f = fopen("arquivo_prioridade", "w"); //Abre um arquivo no formato binário
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n"); //Caso o arquivo não exista, esta mensagem aparece no terminal alertando o usuário
        return 1;
    }
    for (int buscaprio=0; buscaprio< lt.qtd; buscaprio++){ //percorre a lista de tarefas
        if (lt.tarefas[buscaprio].prioridade == prioridade_escolhida){ //verifica se a prioridade escolhida existe na lista de tarefas e printa
            fprintf(f, "Prioridade: %d / Categoria: %s / Estado: %s / Descricao: %s\n", lt.tarefas[buscaprio].prioridade, lt.tarefas[buscaprio].categoria, lt.tarefas[buscaprio].estado, lt.tarefas[buscaprio].descricao); //informações da tarefa com a prioridade escolhida são printadas no arquivo
        }
    }
    if(verifica==0){ //caso não existam tarefas com essa prioridade essa condição é acionada
        printf("Não existe a prioridade escolhida atualmente.\n");
        return 1;
    }
    else{ //caso existam tarefas com essa prioridade essa condição é acionada
        fclose(f); // Fecha o arquivo
        printf("Tarefas exportadas por prioridade.\n");
        
    }return 0;
        
}
int exporta_categoria(listadetarefas *lt, char arquivo[100]){ //função para exportar tarefa por categoria
    char categoria_escolhida[200];
    int verifica = 0; //variável para verificar se há tarefas com a categoria escolhida
    printf("Digite a categoria escolhida: \n"); //Pede a categoria que o usuário quer filtrar e guarda em uma variável
    scanf(" %[^\n]", categoria_escolhida);
    for (int buscacat = 0; buscacat < lt->qtd; buscacat++) { //percorre a lista de tarefas
        if (strcmp(lt->tarefas[buscacat].categoria, categoria_escolhida) == 0) {  //verifica se a categoria escolhida existe na lista de tarefas
            verifica = 1; //aumentamos 1 na variável para dizer que existem tarefas com essa categoria
            break;
        }
    }
    FILE *f = fopen(arquivo, "w"); // Abre um arquivo no formato binário
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n"); // Caso o arquivo não exista, esta mensagem aparece no terminal alertando o usuário
        return 1;
    }
    
    for (int decrescente = 10; decrescente >= 0; decrescente--) { //for criado com o intuito de printar de maneira decrescente a prioridade a partir da categoria escolhida, percorrendo-as e ordenando da maneira escolhida (do maior pro menor)
        for (int buscacat = 0; buscacat < lt->qtd; buscacat++) { //percorre a lista de tarefas
            if (strcmp(lt->tarefas[buscacat].categoria, categoria_escolhida) == 0) { //verifica se a categoria escolhida existe na lista de tarefas
                if (lt->tarefas[buscacat].prioridade == decrescente) { //verifica a prioridade dentro da categoria escolhida e utiliza o primeiro for da função para printar a prioridade de maneira decrescente
                    fprintf(f, "Prioridade: %d / Categoria: %s / Estado: %s / Descricao: %s\n", lt->tarefas[buscacat].prioridade, lt->tarefas[buscacat].categoria, lt->tarefas[buscacat].estado, lt->tarefas[buscacat].descricao);  //informações da tarefa com a categoria escolhida são printadas no arquivo
                }
            }
        }
    }
    if (verifica == 0) { //caso não existam tarefas com essa categoria essa condição é acionada
        printf("Não existe a categoria escolhida atualmente.\n");
        return 1;
    }
    else{ //caso existam tarefas com essa categoria essa condição é acionada
        fclose(f); // Fecha o arquivo
        printf("Tarefas exportadas por categoria.\n");
        
    }return 0;
}
int exporta_categoria_prioridade(listadetarefas *lt, char arquivo[100]) { //função para exportar tarefa por categoria e prioridade
    int verifica = 0; //variável para verificar se há tarefas com a categoria e prioridade escolhida
    int prioridade_escolhida; 
    printf("Digite a prioridade escolhida: \n"); //Pede a prioridade que o usuário quer filtrar e guarda em uma variável
    scanf("%d", &prioridade_escolhida); 
    char categoria_escolhida[200]; 
    printf("Digite a categoria escolhida: \n"); //Pede a categoria que o usuário quer filtrar e guarda em uma variável
    scanf(" %[^\n]", categoria_escolhida);
    for (int buscacp = 0; buscacp < lt->qtd; buscacp++) { //percorre a lista de tarefas
        if (lt->tarefas[buscacp].prioridade == prioridade_escolhida) { //verifica se a prioridade escolhida existe na lista de tarefas
            if (strcmp(categoria_escolhida, lt->tarefas[buscacp].categoria) == 0) { // caso a prioridade escolhida exista verifica se a categoria escolhida existe na lista de tarefas
                verifica = 1; //aumentamos 1 na variável para dizer que existem tarefas com essa categoria
            }
        }
    }
    FILE *f = fopen(arquivo, "w"); // Abre um arquivo no formato binário
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n"); // Caso o arquivo não exista, esta mensagem aparece no terminal alertando o usuário
        return 1;
    }
    for (int buscacp = 0; buscacp < lt->qtd; buscacp++) { //percorre a lista de tarefas
        if (lt->tarefas[buscacp].prioridade == prioridade_escolhida) { //verifica se a prioridade escolhida existe na lista de tarefas
            if (strcmp(categoria_escolhida, lt->tarefas[buscacp].categoria) == 0) { // caso a prioridade escolhida exista verifica se a categoria escolhida existe na lista de tarefas
                fprintf(f, "Prioridade: %d / Categoria: %s / Estado: %s / Descricao: %s\n", lt->tarefas[buscacp].prioridade, lt->tarefas[buscacp].categoria, lt->tarefas[buscacp].estado, lt->tarefas[buscacp].descricao); //informações da tarefa com a categoria escolhida são printadas no arquivo
            }
        }
    }
    if (verifica == 0) { //caso não existam tarefas com essa categoria essa condição é acionada
        printf("Não existe a categoria ou a prioridade escolhida atualmente.\n");
        return 1;
    }
    else{ //caso existam tarefas com essa categoria essa condição é acionada
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
