//Rafael Antonio Valera Pacheco (moepii)
#include <iostream>
#include <vector>
#include <utility>

/*Razonamiento: Es complicado explicarlo sin mostrar antes que hace cada una de las partes, 
pero la idea a seguir es esta: Usamos los pares. En este caso un par que dentro
uno de sus componentes (el segundo) es otro par de forma que el primer elemento del par es el 
numero en si y el segundo que es otro par su primer elemento es cuantas veces aparecio y el 
segundo seria su posicion, una vez aclarado esto por medio de un for que guarda ciertos datos
como el numero, cuantas veces aparecio y su asignacion y tambien interviene una funcion 
booleana en un for distinto que ordena para retornar la respuesta deseada*/

using namespace std;

/*
Se hace una funcion de tipo booleano que trabajara con dos pares que a su vez dentro
de ellos tienes otro par, la intencion de esto es que compare numeros, pero de momento
lo unico que hace es en caso de que el primer elemento del par interno de numero1 sea diferente al primer
elemento del par interno numero 2 retorne una instruccion y de alli al ser evaluada de True o False,
tambien hay un returm en caso de que no se entre en el if.
*/

bool comparacion(const pair<int, pair<int, int>>& numero1, const pair<int, pair<int, int>>& numero2) {
    if (numero1.second.first!= numero2.second.first) {
        return numero1.second.first > numero2.second.first;
    }
    return numero1.second.second < numero2.second.second;
}

/*
Ahora creamos nuestro main, ingresamos los valores solicitados
que sera n y c, siendo n la cantidas de numeros que meteremos en un vector con un 
formato par luego, y un c que el ejercicio plantea como el número de la descripción de la tarea.
*/

int main() {
    int n, c;
    cin >> n >> c;
    vector<pair<int, pair<int, int>>> desorden(n);
   
    /*
    Aqui lo complejo, debido a que los valores solicitados deben salir en cierto orden
    no basta solo con ordenarlos en forma ascendente, entonces tenemos que guardarlos
    de una forma particular, declaramos un int este nos dira la posicion a futuro
    y vamos a guardar los numeros en nuestro vector por medio de unas condiciones
    para esto necesitamos de 2 for.
    */

    int posicion = 0;

    for (int i = 0; i < n; i++) {

        /*
        guardador guarda los numeros que se coloquen en la terminal luego del n y el c
        necesitamos un booleano para entrar en dos if distintos segun el caso
        entonces hacemos un for que recorre el vector de desoren, pero como desorde
        no es un vector normal si no que tiene pares hay que ir guardando los numeros
        en la forma que necesitamos.
        */

        int guardando;
        cin >> guardando;
        bool casos = false;
        for (auto& reccorre : desorden) {
            
            /*
            Este if se encarga de ver con que frecuencia aparecio el elemnto
            */
            if (reccorre.first == guardando) {
                reccorre.second.first++;
                casos = true;
                break;
            }
        }

        /*
        Este if se encarga de 3 cosas, asigan un valor al primer elemento del par
        a la posicion 1 de la segunda posicion del par le asiga 1 que va a ir aumentando
        con el if de arriba segun el caso y por ultimo guarda la posicion.
        */
        if (!casos) {
            posicion++;
            desorden[posicion - 1].first = guardando;
            desorden[posicion - 1].second.first = 1;
            desorden[posicion - 1].second.second = i;
        }
    }

     /*
     Una vez hecho el proceso de guardado y ver repeticiones y demas viene lo mas
     "facil" ordenarlos como se solicita, aqui entra en juego nuestra funcion booleana
     externa, que dependiendo de si da true o false va a intercambiar los elementos o no.
     */

     for (int j = 0; j < posicion - 1; j++) {
        for (int k = 0; k < posicion - j - 1; k++) {
            if (!comparacion(desorden[k], desorden[k + 1])) {
                swap(desorden[k], desorden[k + 1]);
            }
        }
    }
    
    /*
    finalmente se imprime la respuesta que solicita el ejercicio por medio de un ultimo
    for esto porque el imput es una secuencia de numero.
     */
    
    
    for (int i = 0; i < posicion; i++) {
        int final = desorden[i].second.first;
        while (final--) {
            cout << desorden[i].first<<" ";
        }
    }
    return 0;
    
}