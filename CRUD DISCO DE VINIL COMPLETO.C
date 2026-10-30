/*
 * ============================================================
 *  LOJA DE DISCOS DE VINIL
 * ============================================================
 *  Projeto P2 - Algoritmos e Pensamento Computacional
 *  Checkpoint 1
 *
 *  QUEM FEZ CADA PARTE (sorteado):
 *  ------------------------------------------------------------
 *  Modulo DISCOS   (struct Disco)   -> Autor: Breno
 *  Modulo CLIENTES (struct Cliente) -> Autor: Felipe
 *  Modulo ARTISTAS (struct Artista) -> Autor: Breno
 *  Modulo VENDAS   (struct Venda)   -> Autor: Felipe
 *  Menu principal (main)            -> Autores: Breno e Felipe
 *  ------------------------------------------------------------
 *
 *  Os textos (strings) sao declarados com char, ex: char nome[50].
 *  Os textos sao lidos com fgets.
 *
 *  OBS: o fgets guarda o Enter (\n) dentro do texto. Por isso,
 *  nos printf dos textos nao tem \n no final.
 *
 *  OBS: depois de cada scanf tem um getchar(). Ele tira o Enter
 *  que sobra no teclado, senao o proximo fgets le so esse Enter.
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


/* ============================================================
 *  MODULO 3: ARTISTAS
 *  Autor do modulo: Breno
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
}


/* ============================================================
 *  MENU PRINCIPAL (main)
 *  Autores: Breno e Felipe
 *
 *  Cada opcao chama o submenu de um modulo:
 *    1 -> menuDiscos()    (modulo do Breno)
 *    2 -> menuClientes()  (modulo do Felipe)
 *    3 -> menuArtistas()  (modulo do Breno)
 *    4 -> menuVendas()    (modulo do Felipe)
 * ============================================================ */
int main() {
    int opcao;

    do {
        printf("\n=========== LOJA DE DISCOS DE VINIL ===========\n");
        printf("1 - Discos\n");
        printf("2 - Clientes\n");
        printf("3 - Artistas\n");
        printf("4 - Vendas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            menuDiscos();                // modulo Discos (Breno)
        } else if (opcao == 2) {
            menuClientes();              // modulo Clientes (Felipe)
        } else if (opcao == 3) {
            menuArtistas();              // modulo Artistas (Breno)
        } else if (opcao == 4) {
            menuVendas();                // modulo Vendas (Felipe)
        } else if (opcao == 0) {
            printf("Encerrando o sistema...\n");
        } else {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}