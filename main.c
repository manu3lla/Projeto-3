// Manuella Filipe Peres (24.123.036-6)

#include <stdio.h>
#include "biblioteca.h"

int main() {
    //Declarando variáveis
    int cod;
    char arquivo[] = "tarefas";
    listadetarefas lt;

    cod = carregarlista(&lt, arquivo);
    if(cod == 1) //Se o "return" for 1, a lista de tarefas é igualada a zero para iniciar as funções
        lt.qtd = 0;

    int opcao;

    // Declaramos um while para o usuário decidir qual função ele quer no momento.
    while (1){
        printf("Opcoes de escolha:\n");
        printf("1. Cadastrar.\n");
        printf("2. Deletar.\n");
        printf("3. Listar.\n");
        printf("4. Editar.\n");
        printf("5. Filtrar tarefas por prioridade.\n");
        printf("6. Filtrar tarefas por estado.\n");
        printf("7. Filtrar tarefas por categoria.\n");
        printf("8. Filtrar tarefas por prioridade e categoria.\n");
        printf("9. Exportar tarefas por prioridade.\n");
        printf("10. Exportar tarefas por categoria.\n");
        printf("12. Sair \n");

        printf("Escolha uma opcao (1 a 12): ");
        scanf("%d", &opcao); //Usuário digita a opção dele e ela é salva na mamória.

        // Dependendo da escolha do usuário, a função roda para realizar o cadastro, listagem ou deletar o lembrete
        if (opcao==0){
        } else if (opcao==1){
            criartarefa(&lt); //Na opção 1, a função criar tarefa é utilizada
        } else if (opcao==2){
            deletartarefa(&lt); //Na opção 2, a função deletar tarefa é utilizada
        } else if (opcao==3){
            listartarefa(lt); //Na opção 3, a função listar tarefa é utilizada
        } else if (opcao==4){
            alteratarefa(&lt);
            }
        else if (opcao==5){
            filtra_prioridade(&lt);
            }
        else if (opcao==6){
            filtra_estado(&lt);
            }
        else if (opcao==7){
            filtra_categoria(&lt);
            }
        else if (opcao==8){
            filtra_categoria_prioridade(&lt);
            }
        else if (opcao==9){
            exporta_prioridade(lt, "arquivo_prioridade");
            }
        else if (opcao==10){
            exporta_categoria(&lt, "arquivo_categoria");
            }
        else if (opcao==12){ //Para o usuário salvar o arquivo, ele deve apertar a opção 12 ("Sair"), sendo que quando acessar o programa novamente, todas as informações fornecidas antes de sair serão listadas
            salvarlista(&lt, "arquivo.txt");
            break;
        }
        
          
        else{
            printf("Erro! Escolha um numero valido! \n"); //Caso o usuário escolha um número fora do intervalo de 1 a 4, essa mensagem aparece na tela
        }
    }

    cod = salvarlista(&lt,arquivo); //Salva as informações na lista
    if (cod !=0) //Se o "return" for diferente de zero, a tarefa não é cadastrada
        printf("Erro ao cadastrar as tarefas!");

}
