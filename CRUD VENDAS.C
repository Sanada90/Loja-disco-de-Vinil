/*
 * ============================================================
 *  LOJA DE DISCOS DE VINIL - CRUD DE VENDAS
 * ============================================================
 *  Projeto P2 - Algoritmos e Pensamento Computacional
 *  Checkpoint 1
 *
 *  Autor deste arquivo: Felipe
 *
 *  Este arquivo NAO tem main. A main do projeto deve chamar
 *  a funcao menuVendas() para abrir o submenu.
 *
 *  Os textos (strings) sao declarados com char e lidos com fgets.
 *  O fgets guarda o Enter (\n) dentro do texto, por isso os printf
 *  dos textos nao tem \n no final.
 *  Depois de cada scanf tem um getchar() para tirar o Enter que
 *  sobra no teclado.
 * ============================================================
 */

#include <stdio.h>


/* ============================================================
 *  MODULO 4: VENDAS
 *  Autor do modulo: Felipe
 * ============================================================ */

// Struct com os dados de UMA venda
// Autor: Felipe
struct Venda {
    int id;                              // codigo da venda
    int idCliente;                       // ID do cliente que comprou
    int idDisco;                         // ID do disco vendido
    int quantidade;                      // quantos discos foram vendidos
    float valorTotal;                    // valor total da venda em reais
    int status;                          // 1 = ativa, 0 = cancelada
};

struct Venda vendas[50];                 // vetor global de vendas
int totalVendas = 0;                     // quantas vendas existem agora
int proximoIdVenda = 1;                  // proximo ID livre

// Criar: cadastra uma venda nova
// Autor: Felipe
void cadastrarVenda() {
    int p = totalVendas;                 // posicao livre no vetor

    if (totalVendas >= 50) {
        printf("Limite de vendas atingido!\n");
        return;
    }

    vendas[p].id = proximoIdVenda;

    printf("ID do cliente: ");
    scanf("%d", &vendas[p].idCliente);
    getchar();

    printf("ID do disco: ");
    scanf("%d", &vendas[p].idDisco);
    getchar();

    printf("Quantidade: ");
    scanf("%d", &vendas[p].quantidade);
    getchar();

    printf("Valor total: R$ ");
    scanf("%f", &vendas[p].valorTotal);
    getchar();

    vendas[p].status = 1;                // toda venda nova comeca ativa

    printf("Venda cadastrada com ID %d!\n", vendas[p].id);

    totalVendas++;
    proximoIdVenda++;
}

// Listar: mostra todas as vendas
// Autor: Felipe
void listarVendas() {
    if (totalVendas == 0) {
        printf("Nenhuma venda cadastrada.\n");
        return;
    }

    printf("\n--- LISTA DE VENDAS ---\n");

    for (int i = 0; i < totalVendas; i++) {
        printf("ID da venda: %d\n", vendas[i].id);
        printf("ID do cliente: %d\n", vendas[i].idCliente);
        printf("ID do disco: %d\n", vendas[i].idDisco);
        printf("Quantidade: %d\n", vendas[i].quantidade);
        printf("Valor total: R$ %.2f\n", vendas[i].valorTotal);

        if (vendas[i].status == 1) {
            printf("Status: Ativa\n");
        } else {
            printf("Status: Cancelada\n");
        }

        printf("------------------------\n");
    }
}

// Buscar: procura uma venda pelo ID
// Autor: Felipe
void buscarVenda() {
    int id;
    int achou = 0;

    printf("Digite o ID da venda: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalVendas; i++) {
        if (vendas[i].id == id) {
            printf("\nID do cliente: %d\n", vendas[i].idCliente);
            printf("ID do disco: %d\n", vendas[i].idDisco);
            printf("Quantidade: %d\n", vendas[i].quantidade);
            printf("Valor total: R$ %.2f\n", vendas[i].valorTotal);

            if (vendas[i].status == 1) {
                printf("Status: Ativa\n");
            } else {
                printf("Status: Cancelada\n");
            }

            achou = 1;
        }
    }

    if (achou == 0) {
        printf("Venda nao encontrada.\n");
    }
}

// Editar: troca os dados de uma venda
// Autor: Felipe
void editarVenda() {
    int id;
    int achou = 0;

    printf("Digite o ID da venda que deseja editar: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalVendas; i++) {
        if (vendas[i].id == id) {
            achou = 1;

            printf("Novo ID do cliente: ");
            scanf("%d", &vendas[i].idCliente);
            getchar();

            printf("Novo ID do disco: ");
            scanf("%d", &vendas[i].idDisco);
            getchar();

            printf("Nova quantidade: ");
            scanf("%d", &vendas[i].quantidade);
            getchar();

            printf("Novo valor total: R$ ");
            scanf("%f", &vendas[i].valorTotal);
            getchar();

            printf("Novo status (1 - Ativa / 0 - Cancelada): ");
            scanf("%d", &vendas[i].status);
            getchar();

            printf("Venda editada!\n");
        }
    }

    if (achou == 0) {
        printf("Venda nao encontrada.\n");
    }
}

// Remover: apaga uma venda do vetor
// Autor: Felipe
void removerVenda() {
    int id;
    int posicao = -1;

    printf("Digite o ID da venda que deseja remover: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalVendas; i++) {
        if (vendas[i].id == id) {
            posicao = i;
        }
    }

    if (posicao == -1) {
        printf("Venda nao encontrada.\n");
    } else {
        // puxa cada venda seguinte uma posicao pra tras, tapando o buraco
        for (int i = posicao; i < totalVendas - 1; i++) {
            vendas[i] = vendas[i + 1];
        }

        totalVendas--;
        printf("Venda removida!\n");
    }
}

// Submenu de vendas
// Autor: Felipe
void menuVendas() {
    int opcao;

    do {
        printf("\n===== MENU VENDAS =====\n");
        printf("1 - Cadastrar venda\n");
        printf("2 - Listar vendas\n");
        printf("3 - Buscar venda\n");
        printf("4 - Editar venda\n");
        printf("5 - Remover venda\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            cadastrarVenda();
        } else if (opcao == 2) {
            listarVendas();
        } else if (opcao == 3) {
            buscarVenda();
        } else if (opcao == 4) {
            editarVenda();
        } else if (opcao == 5) {
            removerVenda();
        } else if (opcao == 0) {
            printf("Voltando ao menu principal...\n");
        } else {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);