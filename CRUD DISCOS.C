/*
 * ============================================================
 *  LOJA DE DISCOS DE VINIL - CRUD DE DISCOS
 * ============================================================
 *  Projeto P2 - Algoritmos e Pensamento Computacional
 *  Checkpoint 1
 *
 *  Autor deste arquivo: Breno
 *
 *  Este arquivo NAO tem main. A main do projeto deve chamar
 *  a funcao menuDiscos() para abrir o submenu.
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
 *  MODULO 1: DISCOS
 *  Autor do modulo: Breno
 * ============================================================ */

// Struct com os dados de UM disco
// Autor: Breno
struct Disco {
    int id;                              // codigo do disco
    char titulo[50];                     // titulo do disco
    char artista[50];                    // nome do artista
    float preco;                         // preco em reais
    int estoque;                         // quantidade em estoque
};

struct Disco discos[50];                 // vetor global de discos
int totalDiscos = 0;                     // quantos discos existem agora
int proximoIdDisco = 1;                  // proximo ID livre

// Criar: cadastra um disco novo
// Autor: Breno
void cadastrarDisco() {
    int p = totalDiscos;                 // posicao livre no vetor

    if (totalDiscos >= 50) {
        printf("Limite de discos atingido!\n");
        return;
    }

    discos[p].id = proximoIdDisco;

    printf("Titulo: ");
    fgets(discos[p].titulo, 50, stdin);

    printf("Artista: ");
    fgets(discos[p].artista, 50, stdin);

    printf("Preco: R$ ");
    scanf("%f", &discos[p].preco);
    getchar();

    printf("Estoque: ");
    scanf("%d", &discos[p].estoque);
    getchar();

    printf("Disco cadastrado com ID %d!\n", discos[p].id);

    totalDiscos++;
    proximoIdDisco++;
}

// Listar: mostra todos os discos
// Autor: Breno
void listarDiscos() {
    if (totalDiscos == 0) {
        printf("Nenhum disco cadastrado.\n");
        return;
    }

    printf("\n--- LISTA DE DISCOS ---\n");

    for (int i = 0; i < totalDiscos; i++) {
        printf("ID: %d\n", discos[i].id);
        printf("Titulo: %s", discos[i].titulo);
        printf("Artista: %s", discos[i].artista);
        printf("Preco: R$ %.2f\n", discos[i].preco);
        printf("Estoque: %d\n", discos[i].estoque);
        printf("------------------------\n");
    }
}

// Buscar: procura um disco pelo ID
// Autor: Breno
void buscarDisco() {
    int id;
    int achou = 0;                       // 0 = nao achou, 1 = achou

    printf("Digite o ID do disco: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalDiscos; i++) {
        if (discos[i].id == id) {
            printf("\nTitulo: %s", discos[i].titulo);
            printf("Artista: %s", discos[i].artista);
            printf("Preco: R$ %.2f\n", discos[i].preco);
            printf("Estoque: %d\n", discos[i].estoque);
            achou = 1;
        }
    }

    if (achou == 0) {
        printf("Disco nao encontrado.\n");
    }
}

// Editar: troca os dados de um disco
// Autor: Breno
void editarDisco() {
    int id;
    int achou = 0;

    printf("Digite o ID do disco que deseja editar: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalDiscos; i++) {
        if (discos[i].id == id) {
            achou = 1;

            printf("Novo titulo: ");
            fgets(discos[i].titulo, 50, stdin);

            printf("Novo artista: ");
            fgets(discos[i].artista, 50, stdin);

            printf("Novo preco: R$ ");
            scanf("%f", &discos[i].preco);
            getchar();

            printf("Novo estoque: ");
            scanf("%d", &discos[i].estoque);
            getchar();

            printf("Disco editado!\n");
        }
    }

    if (achou == 0) {
        printf("Disco nao encontrado.\n");
    }
}

// Remover: apaga um disco do vetor
// Autor: Breno
void removerDisco() {
    int id;
    int posicao = -1;                    // -1 = ainda nao achou

    printf("Digite o ID do disco que deseja remover: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalDiscos; i++) {
        if (discos[i].id == id) {
            posicao = i;
        }
    }

    if (posicao == -1) {
        printf("Disco nao encontrado.\n");
    } else {
        // puxa cada disco seguinte uma posicao pra tras, tapando o buraco
        for (int i = posicao; i < totalDiscos - 1; i++) {
            discos[i] = discos[i + 1];
        }

        totalDiscos--;
        printf("Disco removido!\n");
    }
}

// Submenu de discos
// Autor: Breno
void menuDiscos() {
    int opcao;

    do {
        printf("\n===== MENU DISCOS =====\n");
        printf("1 - Cadastrar disco\n");
        printf("2 - Listar discos\n");
        printf("3 - Buscar disco\n");
        printf("4 - Editar disco\n");
        printf("5 - Remover disco\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            cadastrarDisco();
        } else if (opcao == 2) {
            listarDiscos();
        } else if (opcao == 3) {
            buscarDisco();
        } else if (opcao == 4) {
            editarDisco();
        } else if (opcao == 5) {
            removerDisco();
        } else if (opcao == 0) {
            printf("Voltando ao menu principal...\n");
        } else {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}