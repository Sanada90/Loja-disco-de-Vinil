# clientes.c

Módulo de **cadastro de clientes** do projeto da loja de discos de vinil, feito em C.

Autor: Breno

## O que o programa faz

Um CRUD de clientes controlado por um menu no terminal:

| Opção | Ação |
|-------|------|
| 1 | Cadastrar cliente |
| 2 | Listar clientes |
| 3 | Buscar cliente pelo ID |
| 4 | Editar cliente |
| 5 | Remover cliente |
| 0 | Sair |

Os dados ficam só na memória. Quando o programa fecha, tudo é apagado.

## Como compilar e rodar

No terminal:

```
gcc -Wall -Wextra clientes.c -o clientes
./clientes
```

No Windows, o executável é `clientes.exe`.

No Code::Blocks: abra o `clientes.c`, e use **Build and run** (F9).

O código compila sem nenhum aviso com `-Wall -Wextra`.

## Como o cliente é guardado

```c
struct Cliente {
    int id;
    char nome[100];
    char telefone[20];
    int idade;
    int status;      // 1 = ativo, 0 = inativo
};
```

Variáveis globais:

- `clientes[50]`: vetor com no máximo 50 clientes.
- `totalClientes`: quantos clientes existem agora.
- `proximoId`: o ID que o próximo cliente vai receber. Começa em 1 e só aumenta, então um ID removido nunca é reutilizado.

## Funções

| Função | O que faz |
|--------|-----------|
| `limparTeclado()` | Descarta o que sobrou digitado até o Enter. Evita que um `scanf` atrapalhe o `fgets` seguinte. |
| `lerTexto(texto, tamanho)` | Lê uma linha com `fgets` e tira o `\n` do final. Se o usuário digitar mais do que cabe, descarta o excesso. |
| `cadastrarCliente()` | Pede nome, telefone e idade, e cria o cliente com status ativo e o próximo ID. |
| `listarClientes()` | Mostra todos os clientes, ou avisa que não há nenhum. |
| `buscarCliente()` | Pede um ID e mostra os dados do cliente, ou avisa que não achou. |
| `editarCliente()` | Pede um ID, mostra os dados atuais e pede os novos (nome, telefone, idade e status). |
| `removerCliente()` | Pede um ID, confirma com `s/n` e remove, puxando os seguintes uma posição para trás. |
| `menuClientes()` | Mostra o menu em repetição até a opção 0. |
| `main()` | Só chama o menu. É temporário e não vai para o trabalho final. |

## Regras e validações

- O limite é de 50 clientes. Passando disso, o cadastro é recusado.
- O nome não pode ficar vazio (cadastro e edição).
- A idade precisa ser um número de 0 a 120. Se não for, pergunta de novo.
- O status só aceita 1 (ativo) ou 0 (inativo).
- IDs digitados como letra são recusados com "ID invalido!".
- Letra no menu cai em "Opcao invalida!".
- O cliente só recebe ID depois que o cadastro termina, então um cadastro cancelado não gasta número.
- Remover pede confirmação, porque não tem como desfazer.

## Limitações conhecidas

- Sem arquivo ou banco de dados: os dados somem ao fechar.
- Se a entrada de teclado for encerrada de vez (Ctrl+Z no Windows, Ctrl+D no Linux), os loops de validação ficam repetindo. No uso normal isso não acontece.
- Sem acentos nas mensagens, para não dar problema de codificação no terminal.

## Exemplo de uso

```
===== MENU CLIENTES =====
1 - Cadastrar cliente
2 - Listar clientes
3 - Buscar cliente
4 - Editar cliente
5 - Remover cliente
0 - Sair
Escolha uma opcao: 1
Digite o nome do cliente: Ana
Digite o telefone: 4199999999
Digite a idade do cliente: 25
Cliente cadastrado com ID 1!
```
