//Rafael Antonio Valera Pacheco (moepii)
#include <iostream>
#include <vector>

using namespace std;

/*
Nuestro plan de accion fue el siguiente: como la entrada es un orden aleatorio primero los ordenamos con
una funcion bubblesort y hecho eso es tan simple como tomar el primer y ultimo elemeno y retornar su diferencia
*/

/*nuestra funcion bubblesort,funciona tal cual lo indica en libros de texto, lo mas relevante
aqui seria el & que aparece dentro del primer parentesis.Que hace ese &?, es una referencia 
en otras palabras en vez de crearse una copia en la memoria este trabaja directamente sobre los datos
que se le asignen.
*/

void bubblesort(vector<int>& arreglando) {
    int tamañó = arreglando.size();
    for (int i = 0; i < tamañó-1; i++) {

        for (int j = 0; j < tamañó-i-1; j++) {

            if (arreglando[j] > arreglando[j+1]) {
                int help = arreglando[j];
                arreglando[j] = arreglando[j+1];
                arreglando[j+1] = help;
            }
            
        }

    }

}

/*
Este programa funciona muy igual al programa de semana 1 que se refiere a cartas
almenos inicialmente con los parametros que recibe -1 y como se guardan los valores
en un vector.
*/

int main() {
    int x;
    cin >> x;

    while (x--) {
        int c;
        cin >> c;

        vector<int> guardador(c);
        for (int j = 0; j < c; j++) {
            cin >> guardador[j];
        }
        
        /*
        Una vez guardado hacemos uso de nuestra funcion bubblesort
        */

        bubblesort(guardador);

        /*
        Luego de ordenados agarro el primero elemento, el ultimo los restamos
        y esa seria la respuesta que necesitamos.
        */

        int posiprimero = guardador[0];
        int posiultimo = guardador[c-1];

        int respuesta = posiultimo - posiprimero;

        cout<<respuesta <<endl;
    }

    return 0;
}
