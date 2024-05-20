//Rafael Antonio Valera Pacheco (moepii)
#include <iostream>
#include <vector>

/*Razonamiento: Como la entrada es un orden aleatorio primero los ordenamos en forma ascendente con
una funcion bubblesort y hecho eso es tan simple como tomar el primer y ultimo elemeno y retornar su diferencia
por que se hace esto? porque cuando efectuas el calculo que pide el ejecicio (a2−a1)+(a3−a2)=(2−1)+(3−2)=2
puedes darte cuenta que da lo mismo que restara (a3-a1) directamente (a3-a1)=(3-1)=2.*/

using namespace std;

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
        int n;
        cin >> n;

        vector<int> guardador(n);
        for (int j = 0; j < n; j++) {
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
        int posiultimo = guardador[n-1];

        int respuesta = posiultimo - posiprimero;

        cout<<respuesta <<endl;
    }

    return 0;
}
