#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 100
#define MAX_CIDADES 100

// Definição da struct
typedef struct {
    char nome[MAX_NOME];
    int populacao;
    double area;
    double pib;
    int pontosTuristicos;
} Cidade;

// Função para exibir os dados
void exibirDados(Cidade c) {
    printf("Cidade: %s\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Número de pontos turísticos: %d\n", c.pontosTuristicos);
    printf("-----------------------------\n");
}

int main() {
    Cidade cidades[MAX_CIDADES];
    int quantidade;

    printf("Quantas cidades deseja cadastrar? ");
    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++) {
        printf("\nCadastro da cidade %d:\n", i + 1);

        printf("Nome: ");
        getchar(); // limpar buffer do ENTER
        fgets(cidades[i].nome, MAX_NOME, stdin);

        // remover \n do fgets
        char *p = cidades[i].nome;
        while (*p) {
            if (*p == '\n') { *p = '\0'; break; }
            p++;
        }

        printf("População: ");
        scanf("%d", &cidades[i].populacao);

        printf("Área (km²): ");
        scanf("%lf", &cidades[i].area);

        printf("PIB (em bilhões): ");
        scanf("%lf", &cidades[i].pib);

        printf("Número de pontos turísticos: ");
        scanf("%d", &cidades[i].pontosTuristicos);
    }

    printf("\n===== Cartas de Cidades Cadastradas =====\n");
    for (int i = 0; i < quantidade; i++) {
        exibirDados(cidades[i]);
    }

    return 0;
}
