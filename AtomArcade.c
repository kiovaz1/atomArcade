#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maximoprodutos 50
#define maximoVendas 100 // estabeleci um limite de vendas para não puxar muita memória

void clearConsole(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseConsole() {
    printf("Digite uma tecla para continuar...");
    getchar();
    getchar(); // limpar o buffer do teclado
}

typedef struct {                  // definir strutura para produto
    char nome[50];
    char plataforma[20];
    float preco;
    int quantidade;
    int codigo;
} Produto;

typedef struct {                // definir estrutura para armazenar as vendas
    int codigoProduto;
    int quantidadeVendida;
    float valorTotal;
} Venda;

void cadastroProdutos(Produto produtos[], int *totalProdutos) {           // funcao para cadastro de produtos
    if (*totalProdutos >= maximoprodutos) {
        printf("Estoque Cheio.\n");
        return;
    }

    Produto novoProduto;

    printf("\nDigite o nome do produto: ");
    scanf("%49s", novoProduto.nome);

    printf("\nDigite a plataforma do produto: ");
    scanf("%19s", novoProduto.plataforma);

    printf("\nDigite o preco do produto: ");
    scanf("%f", &novoProduto.preco);

    printf("\nDigite a quantidade do produto: ");
    scanf("%d", &novoProduto.quantidade);

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &novoProduto.codigo);

    
    for (int i = 0; i < *totalProdutos; i++) {                              // leitura para verificar se ja tem um produto cadastrado com o mesmo código
        if (produtos[i].codigo == novoProduto.codigo) {
            printf("Produto com codigo %d ja esta cadastrado.\n", novoProduto.codigo);
            return;
        }
    }

    produtos[*totalProdutos] = novoProduto;                     // adicionando um novo produto no armazenamento de produtos
    (*totalProdutos)++;

    printf("\nProduto cadastrado com sucesso!\n");
    printf("\nResumo do Produto Cadastrado:\n");
    printf("Nome: %s\n", novoProduto.nome);
    printf("Plataforma: %s\n", novoProduto.plataforma);
    printf("Preço: $%.2f\n", novoProduto.preco);
    printf("Quantidade: %d\n", novoProduto.quantidade);
    printf("Código: %d\n", novoProduto.codigo);
}

void consultaEstoque(Produto produtos[], int *totalProdutos) {                  // funcao para consulta estoque
    if (*totalProdutos == 0) {
        printf("Estoque vazio.\n");
        return;
    }

    printf("\nDeseja buscar por:\n");
    printf("\n1. Nome\n");
    printf("\n2. Plataforma\n");
    printf("\n3. Código\n");
    printf("\nEscolha uma opcao: ");
    int opcaobuscar;
    scanf("%d", &opcaobuscar);
    getchar();
    char criterio[50];
    int codigo;
    int encontrado = 0;

    switch (opcaobuscar) {                              // switch para filtrar busca entre codigo / nome / plataforma 
        case 1:
            printf("\nDigite o nome do produto: ");
            scanf("%49s", criterio);
            for (int i = 0; i < *totalProdutos; i++) {
                if (strcmp(produtos[i].nome, criterio) == 0) {
                    printf("Produto encontrado:\n");
                    printf("Nome: %s\n", produtos[i].nome);
                    printf("Plataforma: %s\n", produtos[i].plataforma);
                    printf("Preço: $%.2f\n", produtos[i].preco);
                    printf("Quantidade: %d\n", produtos[i].quantidade);
                    printf("Codigo: %d\n", produtos[i].codigo);
                    printf("----------------------------------------\n");
                    encontrado = 1;
                }
            }
            break;
        case 2:
            printf("\nDigite a plataforma do produto: ");
            scanf("%19s", criterio);
            for (int i = 0; i < *totalProdutos; i++) {
                if (strcmp(produtos[i].plataforma, criterio) == 0) {
                    printf("Produto encontrado:\n");
                    printf("Nome: %s\n", produtos[i].nome);
                    printf("Plataforma: %s\n", produtos[i].plataforma);
                    printf("Preço: $%.2f\n", produtos[i].preco);
                    printf("Quantidade: %d\n", produtos[i].quantidade);
                    printf("Codigo: %d\n", produtos[i].codigo);
                    printf("----------------------------------------\n");
                    encontrado = 1;
                }
            }
            break;
        case 3:
            printf("\nDigite o codigo do produto: ");
            scanf("%d", &codigo);
            for (int i = 0; i < *totalProdutos; i++) {
                if (produtos[i].codigo == codigo) {
                    printf("Produto encontrado:\n");
                    printf("Nome: %s\n", produtos[i].nome);
                    printf("Plataforma: %s\n", produtos[i].plataforma);
                    printf("Preço: $%.2f\n", produtos[i].preco);
                    printf("Quantidade: %d\n", produtos[i].quantidade);
                    printf("Codigo: %d\n", produtos[i].codigo);
                    printf("----------------------------------------\n");
                    encontrado = 1;
                }
            }
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }

    if (!encontrado) {
        printf("Nenhum produto encontrado com o criterio: %s\n", criterio);
    }
}

void registroVendas(Produto produtos[], int *totalProdutos, Venda vendas[], int *totalVendas) {                 // funcao para registro de vendas
    if (*totalVendas >= maximoVendas) {
        printf("Limite maximo de vendas atingido.\n");
        return;
    }

    int codigoProduto, quantidade;
    printf("\nDigite o codigo do produto vendido: ");
    scanf("%d", &codigoProduto);

    int encontrado = -1;
    for (int i = 0; i < *totalProdutos; i++) {
        if (produtos[i].codigo == codigoProduto) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("Digite a quantidade vendida: ");
    scanf("%d", &quantidade);

    if (produtos[encontrado].quantidade < quantidade) {
        printf("Estoque insuficiente.\n");
        return;
    }

    produtos[encontrado].quantidade -= quantidade;                      // subtracao de venda do armazenamento

    vendas[*totalVendas].codigoProduto = codigoProduto;
    vendas[*totalVendas].quantidadeVendida = quantidade;
    vendas[*totalVendas].valorTotal = quantidade * produtos[encontrado].preco;
    (*totalVendas)++;                                                                           // aumenta quantidade de vendas realizadas

    printf("Venda registrada com sucesso!\n");
    printf("Produto: %s | Quantidade: %d | Valor Total: $%.2f\n",                               // printa a venda para o usuario
    produtos[encontrado].nome, quantidade, vendas[*totalVendas - 1].valorTotal);
}

int main() {
    int totalProdutos = 15;
    int totalVendas = 0;
    int escolhaOpcao;

    Produto produtos[maximoprodutos] = {                                                            // vetor com produtos pré registrados
        {"The Legend of Zelda: Breath of the Wild", "NintendoSwitch", 59.99, 10, 1},
        {"God of War", "PlayStation4", 49.99, 8, 2},
        {"Red Dead Redemption 2", "XboxOne", 39.99, 5, 3},
        {"Minecraft", "Multiplatforma", 19.99, 15, 4},
        {"The Witcher 3: Wild Hunt", "PC", 24.99, 7, 5},
        {"Super Mario Odyssey", "NintendoSwitch", 59.99, 12, 6},
        {"Fortnite", "Multiplatforma", 0.00, 100, 7},
        {"FIFA 22", "PlayStation5", 49.99, 20, 8},
        {"Apex Legends", "Multi-platform", 0.00, 80, 9},
        {"Assassin's Creed Valhalla", "XboxSeriesX", 59.99, 3, 10},
        {"Animal Crossing: New Horizons", "NintendoSwitch", 49.99, 4, 11},
        {"Horizon Zero Dawn", "PlayStation4", 19.99, 6, 12},
        {"Among Us", "Multiplatforma", 4.99, 25, 13},
        {"Ghost of Tsushima", "PlayStation4", 39.99, 5, 14},
        {"Resident Evil Village", "PC", 59.99, 2, 15}
    };
    Venda vendas[maximoVendas];

    do {
        clearConsole();

        printf(" ______   ______  ______   __    __       ______   ______   ______   ______   _____    ______    \n");
        printf("/\\  __ \\ /\\__  _\\/\\  __ \\ /\\ \"-./  \\     /\\  __ \\ /\\  == \\ /\\  ___\\ /\\  __ \\ /\\  __-. /\\  ___\\   \n");
        printf("\\ \\  __ \\\\/_/\\ \\/\\ \\ \\/\\ \\\\ \\ \\-./\\ \\    \\ \\  __ \\\\ \\  __< \\ \\ \\____\\ \\  __ \\\\ \\ \\/\\ \\\\ \\  __\\   \n");               // logo da loja ficticia
        printf(" \\ \\_\\ \\_\\  \\ \\_\\ \\ \\_____\\\\ \\_\\ \\ \\_\\    \\ \\_\\ \\_\\\\ \\_\\ \\_\\\\ \\_____\\\\ \\_\\ \\_\\\\ \\____- \\ \\_____\\ \n");
        printf("  \\/_/\\/_/   \\/_/  \\/_____/ \\/_/  \\/_/     \\/_/\\/_/ \\/_/ /_/ \\/_____/ \\/_/\\/_/ \\/____/  \\/_____/ \n");
        printf("                                                                                                  \n");
        printf("\n---------- Gerenciamento de Estoque e Vendas ----------\n");
        printf("\n1. Cadastrar Produto\n");
        printf("2. Consultar Estoque\n");
        printf("3. Registrar Venda\n");                                                     //  interface do menu
        printf("4. Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &escolhaOpcao);

        switch (escolhaOpcao) {                                         // switch para decisão do que fazer no menu
            case 1:
                clearConsole();
                printf("\n----------Cadastrar Produto----------\n");
                cadastroProdutos(produtos, &totalProdutos);
                pauseConsole();
                break;
            case 2:
                clearConsole();
                printf("----------Consultar Estoque----------\n");
                consultaEstoque(produtos, &totalProdutos);
                pauseConsole();
                break;
            case 3:
                clearConsole();
                printf("----------Registrar Venda----------\n");
                registroVendas(produtos, &totalProdutos, vendas, &totalVendas);
                pauseConsole();
                break;
            case 4:
                clearConsole();
                printf("Saindo...\n");
                pauseConsole();
                break;
            default:
                clearConsole();
                printf("Opcao invalida! Tente novamente.\n");
                pauseConsole();
                break;
        }
    } while (escolhaOpcao != 4);

    return 0;
}




