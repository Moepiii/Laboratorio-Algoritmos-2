//Rafael Antonio Valera Pacheco (moepii)
#include <iostream>
#include <vector>
#include <utility>

/*Razonamiento: Este codigo se hizo con anterioridad especificamente en semana dos, en esta ocacion se solicita implementar uno
de los dos algoritmos de ordenamiento que pueden ser heapsort o quicksort, como el ejercicio de semana 2 se hizo sin un algoritmo
de ordenamiento tenemos que implementarlo en esta ocacion y para eso escogi usar quicksort. como muchas de la funsionalidades
son las mismas solo se explicaran la nuevas cosas agregadas como el quicksort o cambios e interaciones de funciones con el
quicksort*/

using namespace std;

/*
misma funcion creada en el ejercicio de semana dos, ir a el ejerciossemana2-2 para mas detalles.
*/

bool comparacion(const pair<int, pair<int, int> >& numero1, const pair<int, pair<int, int>>& numero2) {
    if (numero1.second.first != numero2.second.first) {
        return numero1.second.first > numero2.second.first;
    }
    return numero1.second.second < numero2.second.second;
}

/*
Quicksort funciona muy parecido a Mergertsort con algunas diferencia y la principal es que hay que escoger un pivote en quicksort
y aqui se generan debate de cual es la mejor eleccion a la hora de escoger un pivote se llego a la conclusion que elijas el que
elijas hay una probabilidad del 60% (+ o -) de que escojas un buen pivote y que si se usaba un selector random a cambio de un pe-
queñó costo seria una buena implementacion pero en mi codigo decidi omitir esta opcion por simpleza a la hora de lectura del codigo, 
escogi como pivote el ultimo elemento al que llame final que este dento del vector numerosdesordenados, claramente esta no es la
mejor opcion porque si te toca un mal pivote aumentaras en gran medida la complejidad pero es funcional para lo solicitado en este
codigo por lo cual se procede con normalidad.
*/

int separacion(vector<pair<int, pair<int, int> > >& numerosdesordenados, int inicio, int final) {
       
    pair<int, pair<int, int> > pivote = numerosdesordenados[final];
    int i = inicio - 1;

    /*
    aqui se crea un for donde interactua la funcion comparacion. Comparado con el de semana dos se puede ver que este interactua
    con el pivote a diferencia del anterior que se usaba de otra forma y hay una reduccion de un for. un resumen de este for es 
    si se activa el if que tiene la funcion comparacion se ejecuta un swap entre numerosdesordenados[i] y numerosdesordenados[j]
    en caso de que no se active el if se procede con normalidad una vez se cumpla el ciclo for se ejecuta un ultimo swap entre
    numerosdesordenados[i + 1], numerosdesordenados[final].
    */

    for (int j = inicio; j < final; j++) {
        if (comparacion(numerosdesordenados[j], pivote)) {
            i++;
            swap(numerosdesordenados[i], numerosdesordenados[j]);
        }
    }
    swap(numerosdesordenados[i + 1], numerosdesordenados[final]);
    return (i + 1);
}

/*
finalmente la funcion quicksort esta funciona parecido a Mergesort en estructura y lo que recibe pero con diferencias,
si bien el if del inicio es usado igual que el mergersort la declaracion del entero no porque esta se usa para saber
cual es el indice del pivote que depende de como se implemente puede estar en sitios diferentes y este se usa en las
llamadas recursivas del quicksort.
*/

void quicksort(vector<pair<int, pair<int, int>>>& numerosdesordenados, int inicio, int final) {
    if (inicio < final) {
        int indicepivote = separacion(numerosdesordenados, inicio, final);

        quicksort(numerosdesordenados, inicio, indicepivote - 1);
        quicksort(numerosdesordenados, indicepivote + 1, final);
    }
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<pair<int, pair<int, int>>> desorden(n);

    int posicion = 0;
    for (int i = 0; i < n; i++) {
        int guardando;
        cin >> guardando;
        bool casos = false;
        for (auto& reccorre : desorden) {
            if (reccorre.first == guardando) {
                reccorre.second.first++;
                casos = true;
                break;
            }
        }
        if (!casos) {
            posicion++;
            desorden[posicion - 1].first = guardando;
            desorden[posicion - 1].second.first = 1;
            desorden[posicion - 1].second.second = i;
        }
    }

    /*
    Unico cambio en el main con repecto al hecho en semana dos, es  la funcion encargada de hacer el trabajo necesario
    para tener el resultado deseado.
    */
    quicksort(desorden, 0, posicion - 1);

    for (int i = 0; i < posicion; i++) {
        int final = desorden[i].second.first;
        while (final--) {
            cout << desorden[i].first <<" ";
        }
    }
    return 0;
}

