#include <iostream>
#include <vector>
#include <string>

// Definição de cores para o terminal
#define RESET   "\033[0m"
#define PINK    "\033[38;5;205m" // Rosa brilhante
#define BOLD    "\033[1m"
#define CURSIVE "\033[3m"

void mostrarCabecalho() {
    std::cout << PINK << BOLD;
    std::cout << "========================================" << std::endl;
    std::cout << "    🌸  MY CUTIE TO-DO LIST  🌸" << std::endl;
    std::cout << "========================================" << RESET << std::endl;
}

int main() {
    std::vector<std::string> tarefas;
    int opcao;

    do {
        mostrarCabecalho();
        std::cout << PINK << " 1." << RESET << " Adicionar algo fofo\n";
        std::cout << PINK << " 2." << RESET << " Ver minhas tarefas\n";
        std::cout << PINK << " 3." << RESET << " Tchau tchau (Sair)\n";
        std::cout << PINK << "\n Escolha: " << RESET;
        
        if (!(std::cin >> opcao)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        std::cin.ignore();

        if (opcao == 1) {
            std::string novaTarefa;
            std::cout << PINK << "  o que temos para hoje? " << RESET;
            std::getline(std::cin, novaTarefa);
            tarefas.push_back(novaTarefa);
            std::cout << PINK << " salvo com sucesso! \n" << RESET;
        } 
        else if (opcao == 2) {
            std::cout << PINK << "\n --- MINHAS ANOTAÇÕES 🎀 ---" << std::endl;
            if (tarefas.empty()) {
                std::cout << "  (Ainda não há nada aqui...) " << std::endl;
            } else {
                for (int i = 0; i < tarefas.size(); i++) {
                    std::cout << PINK << " [" << i + 1 << "] " << RESET << CURSIVE << tarefas[i] << RESET << std::endl;
                }
            }
            std::cout << PINK << " ------------------------------\n" << RESET;
        }
    } while (opcao != 3);

    std::cout << PINK << "\nAté logo!" << RESET << std::endl;
    return 0;
}
