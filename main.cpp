#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <vector>
#include <string>
#include "MenuCliente.h"
#include "MenuTrufa.h"
#include "DatabaseService.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    if (connect_database() != 0) {
        return 1; // erro na conex�o
    }

    int opcao;
    do {
        system("cls");
        std::cout << "\n===== MENU GERAL =====\n";
        std::cout << "1. �rea de Clientes \n";
        std::cout << "2. �rea de Trufas\n";
        std::cout << "3. �rea de Pedidos\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
            case 1: MenuCliente::mostrarMenu(); break;
            case 2: MenuTrufa::mostrarMenu(); break;
            case 3: MenuCliente::mostrarMenu(); break;
            case 0: std::cout << "Saindo...\n"; break;
            default: std::cout << "Op��o inv�lida.\n";
        }
    } while (opcao != 0);

    fecharBanco();
    return 0;
}

