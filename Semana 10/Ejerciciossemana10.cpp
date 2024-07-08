//Rafael Antonio Valera Pacheco Moepii
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

/*Razonamiento: Este codigo pide que dado una cantidad dee numeros y una cantidad de consultas una vez introducidos
debes poner una seeguidilla de numeros x y si luego tu consultas el numero debe reetornar la posicion en la que esta.
adicional debemos añádir una serie de reglas como lo son no usar vectores o arreglos o busqueda binaria

la implementacion fue sacada del pseudocodigo proporcionado en la parte de informacion con adaptacione y modificacions
ahora eeste codigo funciona en un 85% debido a que cuando se introducen numeros repetidos no arroja bien su posicion en el
mapa, cosa que no pasa si la seguidilla de numeros es diferente unos de otros entre si.

ahora una descripcion general es:
implementamos un Árbol Rojo-Negro para almacenar valores y buscar la primera aparición de un valor dado en el árbol. 
insertar valores en el árbol y buscar la posición de la primera aparición de un valor específico.
La clase Nodo representa cada nodo del árbol y contiene un valor, un color (rojo o negro), punteros a los nodos izquierdo 
y derecho, y un puntero al nodo padre. La clase Árbol maneja la raíz del árbol y un mapa para almacenar los valores y sus 
posiciones

En el main, se leen los valores N y Q, se crea un objeto Árbol, se insertan los N valores proporcionados en el árbol y se 
realizan Q consultas para buscar la primera aparición de cada valor en el árbol, imprimiendo su posición.

pd: hay funciones en el codigo que no llegaron a ser implementadas como lo son el rebalanceo al ocacionar errores no deseados
*/

class Nodo {
public:
    long long valor;
    bool color;
    Nodo* izquierda;
    Nodo* derecha;
    Nodo* padre;

    Nodo(long long valor) {
        this->valor = valor;
        this->color = true; 
        this->izquierda = nullptr;
        this->derecha = nullptr;
        this->padre = nullptr;
    }
};


class Árbol {
private:
    Nodo* raíz;
    map<long long, int> valorPosicion; 


    void insertar(Nodo*& raíz, long long valor) {
        if(raíz == nullptr) {
            raíz = new Nodo(valor);
            valorPosicion[valor] = valorPosicion.size(); 
        } else {
            if(raíz->valor < valor) {
                insertar(raíz->derecha, valor);
                raíz->derecha->padre = raíz;
            } else if(raíz->valor > valor) {
                insertar(raíz->izquierda, valor);
                raíz->izquierda->padre = raíz;
            } else {
                return;
            }
            rebalance(raíz);
        }
    }

    void rebalance(Nodo*& raíz) {
    }

    int buscarPrimera(Nodo*& raíz, long long valor) {
        if(raíz == nullptr) {
            return -1;
        }

        if(raíz->valor == valor) {
            Nodo* actual = raíz;
            int posicion = valorPosicion[actual->valor];

            while(actual->izquierda != nullptr && actual->izquierda->valor == valor) {
                actual = actual->izquierda;
                posicion = valorPosicion[actual->valor]; 
            }

            while(actual->derecha != nullptr && actual->derecha->valor == valor) {
                actual = actual->derecha;
                valorPosicion[actual->valor] = ++posicion;
            }

            return posicion; 
        }

        if(raíz->valor < valor) {
            return buscarPrimera(raíz->derecha, valor);
        } else {
            return buscarPrimera(raíz->izquierda, valor);
        }
    }

public:
    Árbol() {
        raíz = nullptr;
    }

    void insertar(long long valor) {
        insertar(raíz, valor);
    }

    int buscarPrimera(long long valor) {
        return buscarPrimera(raíz, valor);
    }
};

int main() {
    long long N, Q;
    cin >> N >> Q;
    Árbol árbol;

    for(long long i = 0; i < N; ++i) {
        long long valor;
        scanf("%lld", &valor);
        árbol.insertar(valor);
    }

    while(Q--) {
        long long valor;
        scanf("%lld", &valor);
        int posición = árbol.buscarPrimera(valor);
        printf("%d\n", posición); 
    }

    return 0;
}