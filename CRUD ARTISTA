/*
 * ============================================================
 *  LOJA DE DISCOS DE VINIL - CRUD DE ARTISTAS
 * ============================================================
 *  Projeto P2 - Algoritmos e Pensamento Computacional
 *  Checkpoint 1
 *
 *  Autor deste arquivo: Breno
 *
 *  Este arquivo NAO tem main. A main do projeto deve chamar
 *  a funcao menuArtistas() para abrir o submenu.
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
 *  MODULO 3: ARTISTAS
 *  Autor do modulo: Breno SILVA BARBOSA RGM 04952082-2
 * ============================================================ */

// Struct com os dados de UM artista
// Autor: Breno
struct Artista {
    int id;                              // codigo do artista
    char nome[100];                      // nome do artista
    char generoMusical[50];              // genero musical (rock, jazz...)
    int anoInicio;                       // ano em que comecou a carreira
    float nota;                          // nota de 0 a 10 dada pela loja
};

struct Artista artistas[50];             // vetor global de artistas
int totalArtistas = 0;                   // quantos artistas existem agora
int proximoIdArtista = 1;                // proximo ID livre

// Criar: cadastra um artista novo
// Autor: Breno
void cadastrarArtista() {
    int p = totalArtistas;               // posicao livre no vetor

    if (totalArtistas >= 50) {
        printf("Limite de artistas atingido!\n");
        return;
    }

    artistas[p].id = proximoIdArtista;

    printf("Nome do artista: ");
    fgets(artistas[p].nome, 100, stdin);

    printf("Genero musical: ");
    fgets(artistas[p].generoMusical, 50, stdin);

    printf("Ano de inicio da carreira: ");
    scanf("%d", &artistas[p].anoInicio);
    getchar();

    printf("Nota (0 a 10): ");
    scanf("%f", &artistas[p].nota);
    getchar();

    printf("Artista cadastrado com ID %d!\n", artistas[p].id);

    totalArtistas++;
    proximoIdArtista++;
}

// Listar: mostra todos os artistas
// Autor: Breno
void listarArtistas() {
    if (totalArtistas == 0) {
        printf("Nenhum artista cadastrado.\n");
        return;
    }

    printf("\n--- LISTA DE ARTISTAS ---\n");

    for (int i = 0; i < totalArtistas; i++) {
        printf("ID: %d\n", artistas[i].id);
        printf("Nome: %s", artistas[i].nome);
        printf("Genero: %s", artistas[i].generoMusical);
        printf("Inicio da carreira: %d\n", artistas[i].anoInicio);
        printf("Nota: %.1f\n", artistas[i].nota);
        printf("------------------------\n");
    }
}

// Buscar: procura um artista pelo ID
// Autor: Breno
void buscarArtista() {
    int id;
    int achou = 0;

    printf("Digite o ID do artista: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalArtistas; i++) {
        if (artistas[i].id == id) {
            printf("\nNome: %s", artistas[i].nome);
            printf("Genero: %s", artistas[i].generoMusical);
            printf("Inicio da carreira: %d\n", artistas[i].anoInicio);
            printf("Nota: %.1f\n", artistas[i].nota);
            achou = 1;
        }
    }

    if (achou == 0) {
        printf("Artista nao encontrado.\n");
    }
}

// Editar: troca os dados de um artista
// Autor: Breno
void editarArtista() {
    int id;
    int achou = 0;

    printf("Digite o ID do artista que deseja editar: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalArtistas; i++) {
        if (artistas[i].id == id) {
            achou = 1;

            printf("Novo nome: ");
            fgets(artistas[i].nome, 100, stdin);

            printf("Novo genero musical: ");
            fgets(artistas[i].generoMusical, 50, stdin);

            printf("Novo ano de inicio: ");
            scanf("%d", &artistas[i].anoInicio);
            getchar();

            printf("Nova nota (0 a 10): ");
            scanf("%f", &artistas[i].nota);
            getchar();

            printf("Artista editado!\n");
        }
    }

    if (achou == 0) {
        printf("Artista nao encontrado.\n");
    }
}

// Remover: apaga um artista do vetor
// Autor: Breno
void removerArtista() {
    int id;
    int posicao = -1;

    printf("Digite o ID do artista que deseja remover: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalArtistas; i++) {
        if (artistas[i].id == id) {
            posicao = i;
        }
    }

    if (posicao == -1) {
        printf("Artista nao encontrado.\n");
    } else {
        // puxa cada artista seguinte uma posicao pra tras, tapando o buraco
        for (int i = posicao; i < totalArtistas - 1; i++) {
            artistas[i] = artistas[i + 1];
        }

        totalArtistas--;
        printf("Artista removido!\n");
    }
}

// Submenu de artistas
// Autor: Breno
void menuArtistas() {
    int opcao;

    do {
        printf("\n===== MENU ARTISTAS =====\n");
        printf("1 - Cadastrar artista\n");
        printf("2 - Listar artistas\n");
        printf("3 - Buscar artista\n");
        printf("4 - Editar artista\n");
        printf("5 - Remover artista\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            cadastrarArtista();
        } else if (opcao == 2) {
            listarArtistas();
        } else if (opcao == 3) {
            buscarArtista();
        } else if (opcao == 4) {
            editarArtista();
        } else if (opcao == 5) {
            removerArtista();
        } else if (opcao == 0) {
            printf("Voltando ao menu principal...\n");
        } else {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}