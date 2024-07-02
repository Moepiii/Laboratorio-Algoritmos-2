//Rafael Antonio Valera Pacheco (moepii)
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*Razonamiento:Este problema en principio es similar al anterior que se encuentra en esta carpeta, la diferencia es que
este solicita hacerlo con stack que tiene una forma de operar algo distintas por lo que explicaremos la clase de forma mas
detallada y el main no tanto porque actua muy similar que el problema anterior

la clase: tenemos una clase que se divide en privada y publica en la privada declaramos un vector de int llamado data
y en la publica una serie de metodos entonces:

push: Agrega un elemento al tope de la pila.
pop: Elimina el elemento del tope de la pila, si la pila no está vacía.
top: Devuelve el elemento del tope de la pila, o -1 si la pila está vacía.
empty: Devuelve true si la pila está vacía, false en caso contrario.

aclarado los metodos vamos con el main

lo mas notorio es el     ios_base::sync_with_stdio(false); y cin.tie(NULL); segun investigue eso  
Desactiva la sincronización entre cin y cout para mejorar el rendimiento entonces decidi implementarlo para mejorar los
resultados en cuestion de tiempo

luego se declara un entero t y se guarda, tambien llamamos a nuestra clase stack y se la asignamos a datos y por ultimo 
un string que dara el resultado, el resto de la implementacion del codigo funciona de forma similar al anterior.
*/

class Stack {
private:
    vector<int> data;

public:
    void push(int valor) {
        data.push_back(valor);
    }

    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
    }

    int top() {
        if (!data.empty()) {
            return data.back();
        }
        return -1;
    }

    bool empty() {
        return data.empty();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    Stack datos;
    string Resultado;

    while (t--) {
        int t;
        cin >> t;
        if (t == 1) {
            int n;
            cin >> n;
            datos.push(n);
        } else if (t == 2) {
            if (!datos.empty()) {
                datos.pop();
            }
        } else {
            if (datos.empty()) {
                Resultado += "Empty!\n";
            } else {
                Resultado += to_string(datos.top());
                Resultado += "\n";
            }
        }
    }

    cout << Resultado;

    return 0;
}