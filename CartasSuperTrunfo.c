#include <iostream>
#include <vector>
#include <string>

class Cidade {
private:
    std::string nome;
    int populacao;
    double area;
    double pib;
    int pontosTuristicos;

public:
    // Construtor
    Cidade(std::string n, int pop, double a, double p, int pt)
        : nome(n), populacao(pop), area(a), pib(p), pontosTuristicos(pt) {}

    // Método para exibir os dados
    void exibirDados() const {
        std::cout << "Cidade: " << nome << "\n";
        std::cout << "População: " << populacao << "\n";
        std::cout << "Área: " << area << " km²\n";
        std::cout << "PIB: R$ " << pib << " bilhões\n";
        std::cout << "Número de pontos turísticos: " << pontosTuristicos << "\n";
        std::cout << "-----------------------------\n";
    }
};

int main() {
    std::vector<Cidade> cidades;
    int quantidade;

    std::cout << "Quantas cidades deseja cadastrar? ";
    std::cin >> quantidade;

    for (int i = 0; i < quantidade; i++) {
        std::string nome;
        int populacao;
        double area;
        double pib;
        int pontosTuristicos;

        std::cout << "\nCadastro da cidade " << (i + 1) << ":\n";
        std::cout << "Nome: ";
        std::cin.ignore(); // limpar buffer
        std::getline(std::cin, nome);

        std::cout << "População: ";
        std::cin >> populacao;

        std::cout << "Área (km²): ";
        std::cin >> area;

        std::cout << "PIB (em bilhões): ";
        std::cin >> pib;

        std::cout << "Número de pontos turísticos: ";
        std::cin >> pontosTuristicos;

        cidades.emplace_back(nome, populacao, area, pib, pontosTuristicos);
    }

    std::cout << "\n===== Cartas de Cidades Cadastradas =====\n";
    for (const auto& cidade : cidades) {
        cidade.exibirDados();
    }

    return 0;
}
