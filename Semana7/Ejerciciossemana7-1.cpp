//Rafael Antonio Valera Pacheco (moepii)
#include <iostream>
#include <vector>
using namespace std;

/*Razonamiento: Bien comenzando dando el contexto del ejercicio para simplificar la explicacion se resume a vamos a colocar un 
numero del 1 al 3 y por ultimo un numero cualquiera al que se le aplicara el comando correspondiente es decir el numero que 
seleccionaste del 1 al 3

comandos de cada uno 

1 Agrega el elemento x a la cola.
2 Elimina el elemento al frente de la cola.
3 Imprime el elemento al frente de la cola, si no hay nada entonces coloca "Empty!"

Dicho esto comenzamos con el razonamiento, dado que no podemos usar la biblioteca Queue necesitamos crear una structura o 
clase, en nuestro caso usamos una clase esta tiene una parte privada(solo para probar lo de publico y privado) y otra publica
en la privada hay un vector que almacena enteros y dos intereso llamados frente y cola.

Ahora para la parte publica hay una serie de metodos comenzando con:

push: Este método agrega un elemento al final de la cola.
pop: Este método elimina el elemento al frente de la cola, si la cola no está vacía.
peek: Este método devuelve el elemento al frente de la cola, sin eliminarlo. Si la cola está vacía, devuelve -1.
empty: Este método devuelve true si la cola está vacía, y false en caso contrario.

explicado esto vamos con el main

aqui ocurrio un cambio importante a lo largo del curso se uso cin y cout para guardar datos o imprimirlos, que ocurre
si bien cumplen su funcion llegados a este punto hay reemplazarlos por metodos que nos ahorren una milesimas de tiempo
aunque no sea mucho y es alli donde entra el scanf y printf estos dos cumple la funcion de cin y cout pero de una forma mas
rapida su forma correcta de uso seria scanf("%d",&x) y printf("%d\n", q.peek()) por ejemplo aclarado eso continuamos

en el main declaramos la variable t que es el numero de datos que vamos a meter por consola luego vamos a crear una variable
que sera regida por nuestra clase queue particular llamada dato, hecho eso abrimos un bucle, adentro declaramos una variable
x que es la que recibe los comandos (es decir el numero del 1 al 3) y por medio de un if vamos abriando caso por caso
entonces ejemplo

x=1 entonces a dato le hacemos un push, que hace push? lo que le asignamos en nuestra clase
x=2 entonces a dato le ocurren si es distinto de vacio  elimina el elemento enfrente de la cola
x=cualquier otro numero, en nuestro caso el 3 si la lista esta vacia devuelve empty y si tiene algo devuelve el elemento
que queda o el que vendria en orden.
con esto finalza el codigo una vez sele introducen los numeros necesarios
*/

class Queue {
private:
    vector<int> almacen;
    int Frente, fcola;

public:
    Queue() {
        Frente = 0;
        fcola = 0;
    }

    void push(int x) {
        almacen.push_back(x);
        fcola++;
    }

    void pop() {
        if (Frente != fcola) {
            Frente++;
        }
    }

    int peek() {
        if (Frente != fcola) {
            return almacen[Frente];
        } else {
            return -1;
        }
    }

    bool empty() {
        return Frente == fcola;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    Queue dato;
    while (t--) {
        int x;
        scanf("%d", &x);
        if (x == 1) {
            scanf("%d", &x);
            dato.push(x);
        } else if (x == 2) {
            if (!dato.empty())
                dato.pop();
        } else {
            if (dato.empty())
                printf("Empty!\n");
            else
                printf("%d\n", dato.peek());
        }
    }
    return 0;
}