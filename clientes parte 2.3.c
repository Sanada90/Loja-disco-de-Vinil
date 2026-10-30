#include <stdio.h>
#include <string.h>

struct Cliente {
    int id;
    char nome[100];
    char telefone[20];
    int idade;
    int status;          // 1 = ativo, 0 = inativo
};

struct Cliente clientes[50];
int totalClientes = 0;
int proximoId = 1;

// Limpa o que sobrou no teclado até o Enter (ou até acabar a entrada)
void limparTeclado() {
    int c = getchar();                   // int (e não char) porque EOF não cabe em char
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

// Lê um texto com fgets e tira o \n do final
void lerTexto(char texto[], int tamanho) {
    if (fgets(texto, tamanho, stdin) == NULL) {
        texto[0] = '\0';                 // fgets falhou: deixa o texto vazio
        return;
    }

    int n = strlen(texto);               // quantas letras tem
    if (n > 0 && texto[n - 1] == '\n') {
        texto[n - 1] = '\0';             // tira o \n do final
    } else {
        // não tinha \n: o usuário digitou mais do que cabe,
        // então o resto ficou no teclado e precisa ser limpo
        limparTeclado();
    }
}

/* Autor: Breno */
void cadastrarCliente() {
    struct Cliente novo;                 // monta o cliente aqui e só copia no final
    int lido;

    if (totalClientes >= 50) {
        printf("Limite de clientes atingido!\n");
        return;
    }

    // repete enquanto o nome estiver vazio
    do {
        printf("Digite o nome do cliente: ");
        lerTexto(novo.nome, 100);
        if (strlen(novo.nome) == 0) {
            printf("O nome nao pode ficar vazio!\n");
        }
    } while (strlen(novo.nome) == 0);

    printf("Digite o telefone: ");
    lerTexto(novo.telefone, 20);

    // repete enquanto a idade for invalida (letra ou fora de 0 a 120)
    do {
        printf("Digite a idade do cliente: ");
        lido = scanf("%d", &novo.idade); // scanf devolve 1 quando leu o numero
        limparTeclado();

        if (lido != 1 || novo.idade < 0 || novo.idade > 120) {
            printf("Idade invalida! Digite um numero de 0 a 120.\n");
            lido = 0;                    // força repetir
        }
    } while (lido != 1);

    // só gasta um ID quando o cadastro deu certo
    novo.id = proximoId;
    novo.status = 1;

    clientes[totalClientes] = novo;      // copia a struct inteira
    totalClientes++;
    proximoId++;

    printf("Cliente cadastrado com ID %d!\n", novo.id);
}

/* Autor: Breno */
void listarClientes() {
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado\n");
        return;
    }

    printf("\n=========== LISTA DE CLIENTES ===========\n");

    for (int i = 0; i < totalClientes; i++) {
        printf("ID: %d\n", clientes[i].id);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Telefone: %s\n", clientes[i].telefone);
        printf("Idade: %d\n", clientes[i].idade);

        if (clientes[i].status == 1) {
            printf("Status: Ativo\n");
        } else {
            printf("Status: Inativo\n");
        }

        printf("-----------------------------------------\n");
    }
}

/* Autor: Breno */
void buscarCliente() {
    int id, lido;
    int posicao = -1;

    printf("Informe o ID do cliente: ");
    lido = scanf("%d", &id);
    limparTeclado();

    if (lido != 1) {
        printf("ID invalido!\n");
        return;
    }

    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == id) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("Cliente nao encontrado\n");
        return;
    }

    printf("\nCliente encontrado:\n");
    printf("ID: %d\n", clientes[posicao].id);
    printf("Nome: %s\n", clientes[posicao].nome);
    printf("Telefone: %s\n", clientes[posicao].telefone);
    printf("Idade: %d\n", clientes[posicao].idade);
    printf("Status: %s\n", (clientes[posicao].status == 1) ? "Ativo" : "Inativo");
}

/* Autor: Breno */
void editarCliente() {
    int id, lido;
    int posicao = -1;

    printf("Informe o ID do cliente a editar: ");
    lido = scanf("%d", &id);
    limparTeclado();

    if (lido != 1) {
        printf("ID invalido!\n");
        return;
    }

    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == id) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("Cliente nao encontrado\n");
        return;
    }

    // mostra os dados atuais pro usuario saber o que esta trocando
    printf("\nDados atuais:\n");
    printf("Nome: %s\n", clientes[posicao].nome);
    printf("Telefone: %s\n", clientes[posicao].telefone);
    printf("Idade: %d\n", clientes[posicao].idade);
    printf("Status: %s\n\n", (clientes[posicao].status == 1) ? "Ativo" : "Inativo");

    do {
        printf("Novo nome: ");
        lerTexto(clientes[posicao].nome, 100);
        if (strlen(clientes[posicao].nome) == 0) {
            printf("O nome nao pode ficar vazio!\n");
        }
    } while (strlen(clientes[posicao].nome) == 0);

    printf("Novo telefone: ");
    lerTexto(clientes[posicao].telefone, 20);

    do {
        printf("Nova idade: ");
        lido = scanf("%d", &clientes[posicao].idade);
        limparTeclado();

        if (lido != 1 || clientes[posicao].idade < 0 || clientes[posicao].idade > 120) {
            printf("Idade invalida! Digite um numero de 0 a 120.\n");
            lido = 0;
        }
    } while (lido != 1);

    do {
        printf("Novo status (1-Ativo / 0-Inativo): ");
        lido = scanf("%d", &clientes[posicao].status);
        limparTeclado();

        if (lido != 1 || (clientes[posicao].status != 0 && clientes[posicao].status != 1)) {
            printf("Status invalido! Digite 1 ou 0.\n");
            lido = 0;
        }
    } while (lido != 1);

    printf("Cliente editado\n");
}

/* Autor: Breno */
void removerCliente() {
    int id, lido;
    int posicao = -1;
    char resposta[10];

    printf("Informe o ID do cliente a remover: ");
    lido = scanf("%d", &id);
    limparTeclado();

    if (lido != 1) {
        printf("ID invalido!\n");
        return;
    }

    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == id) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("Cliente nao encontrado\n");
        return;
    }

    // remover nao tem volta, entao pergunta antes
    printf("Tem certeza que deseja remover %s? (s/n): ", clientes[posicao].nome);
    lerTexto(resposta, 10);

    if (resposta[0] != 's' && resposta[0] != 'S') {
        printf("Remocao cancelada\n");
        return;
    }

    // puxa cada cliente seguinte uma posicao pra tras, tapando o buraco
    for (int i = posicao; i < totalClientes - 1; i++) {
        clientes[i] = clientes[i + 1];
    }

    totalClientes--;
    printf("Cliente removido\n");
}

/* Autor: Breno */
void menuClientes() {
    int opcao = -1;
    int lido;

    do {
        printf("\n===== MENU CLIENTES =====\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Buscar cliente\n");
        printf("4 - Editar cliente\n");
        printf("5 - Remover cliente\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        lido = scanf("%d", &opcao);
        limparTeclado();

        if (lido != 1) {
            opcao = -1;                  // se digitou letra, cai no default
        }

        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                listarClientes();
                break;
            case 3:
                buscarCliente();
                break;
            case 4:
                editarCliente();
                break;
            case 5:
                removerCliente();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);
}

int main(void) {
    menuClientes();
    return 0;
}
