#include <stdio.h>
#include <string.h>

#define MAX_STOCK_ITEMS 100

struct StockItem {
    char name[50];
    int quantity;
    char category[50];
    float sellingPrice;
    char setor[50];
};

void addProduct(struct StockItem stock[], int *numItems) {
    if (*numItems >= MAX_STOCK_ITEMS) { 
        printf("Estoque cheio Nao e possivel adicionar mais itens\n");
        return;
    }

    printf("Digite o nome do produto: ");
    scanf("%s", stock[*numItems].name);

    printf("Digite a quantidade: ");
    scanf("%d", &stock[*numItems].quantity);

    printf("Digite a categoria: ");
    scanf("%s", stock[*numItems].category);

    printf("Digite o preco de venda: ");
    scanf("%f", &stock[*numItems].sellingPrice);

    printf("Digite o setor de armazenamento: ");
    scanf("%s", stock[*numItems].setor);

    (*numItems)++;
    printf("Produto adicionado com sucesso\n");
}

void displayProducts(struct StockItem stock[], int numItems) {
    if (numItems == 0) {
        printf("Estoque vazio\n");
        return;
    }

    printf("Itens em estoque:\n");
    printf("%-20s %-10s %-10s %-15s %-10s\n", "Nome", "Quantidade", "Categoria", "Preco de Venda", "Setor");

    for (int i = 0; i < numItems; i++) {
        printf("%-20s %-10d %-10s %-15.2f %-10s\n", stock[i].name, stock[i].quantity, stock[i].category,
                                                   stock[i].sellingPrice, stock[i].setor);
    }
}

void searchProduct(struct StockItem stock[], int numItems) {
    char searchName[50];
    printf("Digite o nome do produto para buscar: ");
    scanf("%s", searchName);

    for (int i = 0; i < numItems; i++) {
        if (strcmp(stock[i].name, searchName) == 0) {
            printf("Produto encontrado\n");
            printf("%-20s %-10s %-10s %-15s %-10s\n", "Nome", "Quantidade", "Categoria", "Preco de Venda", "Setor");
            printf("%-20s %-10d %-10s %-15.2f %-10s\n", stock[i].name, stock[i].quantity, stock[i].category,
                                                       stock[i].sellingPrice, stock[i].setor);
            return;
        }
    }
    printf("Produto nao encontrado\n");
}

void generateReport(struct StockItem stock[], int numItems) {
    if (numItems == 0) {
        printf("Estoque vazio Nenhum relatorio para mostrar\n");
        return;
    }

    int totalQuantity = 0;
    float totalValue = 0.0;

    printf("Relatorio de Estoque:\n");
    printf("%-20s %-10s %-10s %-15s %-10s\n", "Nome", "Quantidade", "Categoria", "Preco de Venda", "Setor");

    for (int i = 0; i < numItems; i++) {
        printf("%-20s %-10d %-10s %-15.2f %-10s\n", stock[i].name, stock[i].quantity, stock[i].category,
                                                   stock[i].sellingPrice, stock[i].setor);
        totalQuantity += stock[i].quantity;
        totalValue += stock[i].quantity * stock[i].sellingPrice;
    }

    printf("\nTotal de itens no estoque: %d\n", totalQuantity);
    printf("Valor total do estoque: R$ %.2f\n", totalValue);
}

int main() {
    struct StockItem stock[MAX_STOCK_ITEMS];
    int numItems = 0;
    int choice;

    do {
        printf("\n--- Gerenciador de Estoque ---\n");
        printf("1 Cadastrar Produto\n");
        printf("2 Exibir Produtos\n");
        printf("3 Buscar Produto\n");
        printf("4 Gerar Relatorio\n");
        printf("5 Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(stock, &numItems);
                break;
            case 2:
                displayProducts(stock, numItems);
                break;
            case 3:
                searchProduct(stock, numItems);
                break;
            case 4:
                generateReport(stock, numItems);
                break;
            case 5:
                printf("Encerrando o programa\n");
                break;
            default:
                printf("Opcao invalida Tente novamente\n");
        }
    } while (choice != 5);

    return 0;
}