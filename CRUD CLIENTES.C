/*
 * ============================================================
 *  LOJA DE DISCOS DE VINIL - CRUD DE CLIENTES
 * ============================================================
 *  Projeto P2 - Algoritmos e Pensamento Computacional
 *  Checkpoint 1
 *
 *  Autor deste arquivo: Felipe
 *
 *  Este arquivo NAO tem main. A main do projeto deve chamar
 *  a funcao menuClientes() para abrir o submenu.
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
 *  MODULO 2: CLIENTES
 *  Autor do modulo: Felipe
 * ============================================================ */

// Struct com os dados de UM cliente
// Autor: Felipe
struct Cliente {
    int id;                              // codigo do cliente
    char nome[100];                      // nome do cliente
    char telefone[20];                   // telefone do cliente
    int idade;                           // idade do cliente
    int status;                          // 1 = ativo, 0 = inativo
};

struct Cliente clientes[50];             // vetor global de clientes
int totalClientes = 0;                   // quantos clientes existem agora
int proximoIdCliente = 1;                // proximo ID livre

// Criar: cadastra um cliente novo
// Autor: Felipe
void cadastrarCliente() {
    int p = totalClientes;               // posicao livre no vetor

    if (totalClientes >= 50) {
        printf("Limite de clientes atingido!\n");
        return;
    }

    clientes[p].id = proximoIdCliente;

    printf("Nome: ");
    fgets(clientes[p].nome, 100, stdin);

    printf("Telefone: ");
    fgets(clientes[p].telefone, 20, stdin);

    printf("Idade: ");
    scanf("%d", &clientes[p].idade);
    getchar();

    clientes[p].status = 1;              // todo cliente novo comeca ativo

    printf("Cliente cadastrado com ID %d!\n", clientes[p].id);

    totalClientes++;
    proximoIdCliente++;
}

// Listar: mostra todos os clientes
// Autor: Felipe
void listarClientes() {
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("\n--- LISTA DE CLIENTES ---\n");

    for (int i = 0; i < totalClientes; i++) {
        printf("ID: %d\n", clientes[i].id);
        printf("Nome: %s", clientes[i].nome);
        printf("Telefone: %s", clientes[i].telefone);
        printf("Idade: %d\n", clientes[i].idade);

        if (clientes[i].status == 1) {
            printf("Status: Ativo\n");
        } else {
            printf("Status: Inativo\n");
        }

        printf("------------------------\n");
    }
}

// Buscar: procura um cliente pelo ID
// Autor: Felipe
void buscarCliente() {
    int id;
    int achou = 0;

    printf("Digite o ID do cliente: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == id) {
            printf("\nNome: %s", clientes[i].nome);
            printf("Telefone: %s", clientes[i].telefone);
            printf("Idade: %d\n", clientes[i].idade);

            if (clientes[i].status == 1) {
                printf("Status: Ativo\n");
            } else {
                printf("Status: Inativo\n");
            }

            achou = 1;
        }
    }

    if (achou == 0) {
        printf("Cliente nao encontrado.\n");
    }
}

// Editar: troca os dados de um cliente
// Autor: Felipe
void editarCliente() {
    int id;
    int achou = 0;

    printf("Digite o ID do cliente que deseja editar: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == id) {
            achou = 1;

            printf("Novo nome: ");
            fgets(clientes[i].nome, 100, stdin);

            printf("Novo telefone: ");
            fgets(clientes[i].telefone, 20, stdin);

            printf("Nova idade: ");
            scanf("%d", &clientes[i].idade);
            getchar();

            printf("Novo status (1 - Ativo / 0 - Inativo): ");
            scanf("%d", &clientes[i].status);
            getchar();

            printf("Cliente editado!\n");
        }
    }

    if (achou == 0) {
        printf("Cliente nao encontrado.\n");
    }
}

// Remover: apaga um cliente do vetor
// Autor: Felipe
void removerCliente() {
    int id;
    int posicao = -1;

    printf("Digite o ID do cliente que deseja remover: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == id) {
            posicao = i;
        }
    }

    if (posicao == -1) {
        printf("Cliente nao encontrado.\n");
    } else {
        // puxa cada cliente seguinte uma posicao pra tras, tapando o buraco
        for (int i = posicao; i < totalClientes - 1; i++) {
            clientes[i] = clientes[i + 1];
        }

        totalClientes--;
        printf("Cliente removido!\n");
    }
}

// Submenu de clientes
// Autor: Felipe
void menuClientes() {
    int opcao;

    do {
        printf("\n===== MENU CLIENTES =====\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Buscar cliente\n");
        printf("4 - Editar cliente\n");
        printf("5 - Remover cliente\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            cadastrarCliente();
        } else if (opcao == 2) {
            listarClientes();
        } else if (opcao == 3) {
            buscarCliente();
        } else if (opcao == 4) {
            editarCliente();
        } else if (opcao == 5) {
            removerCliente();
        } else if (opcao == 0) {
            printf("Voltando ao menu principal...\n");
        } else {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}