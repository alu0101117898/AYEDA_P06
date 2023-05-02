#include <iostream>
#include "../include/ABB.h"
#include "../include/AVL.h"

int main() {
    std::cout << "¿Qué tipo de árbol desea crear? (ABB o AVL)" << std::endl;
    std::string tipo;
    std::cin >> tipo;

    AB<long>* arbol;
    if (tipo == "ABB") {
        arbol = new ABB<long>();
    } else if (tipo == "AVL") {
        arbol = new AVL<long>();
    } else {
        std::cout << "Tipo de árbol no válido" << std::endl;
        return 0;
    }

    int opcion = -1;
    while (opcion != 0) {
        std::cout << "Menú:" << std::endl;
        std::cout << "[0] Salir" << std::endl;
        std::cout << "[1] Insertar clave" << std::endl;
        std::cout << "[2] Buscar clave" << std::endl;
        std::cout << "[3] Mostrar árbol inorden" << std::endl;

        std::cin >> opcion;
        switch (opcion) {
            case 0:
                std::cout << "Saliendo..." << std::endl;
                break;
            case 1: {
                std::cout << "Introduzca la clave a insertar:" << std::endl;
                long clave;
                std::cin >> clave;
                if (arbol->insertar(clave)) {
                    std::cout << "Clave insertada correctamente" << std::endl;
                    std::cout << *arbol;
                } else {
                    std::cout << "La clave ya existe en el árbol" << std::endl;
                }
                break;
            }
            case 2: {
                std::cout << "Introduzca la clave a buscar:" << std::endl;
                long clave;
                std::cin >> clave;
                if (arbol->buscar(clave)) {
                    std::cout << "La clave se encuentra en el árbol" << std::endl;
                } else {
                    std::cout << "La clave no se encuentra en el árbol" << std::endl;
                }
                break;
            }
            case 3:
                std::cout << "Árbol inorden: ";
                arbol->inorden();
                std::cout << *arbol;
                break;
            default:
                std::cout << "Opción no válida" << std::endl;
                break;
        }
    }

    delete arbol;
    return 0;
}
