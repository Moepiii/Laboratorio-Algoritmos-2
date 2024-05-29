//Rafael Antonio Valera Pacheco (moepii)
#include <iostream>
#include <vector>
#include <utility>

/*Razonamiento: En este ejercicio la logica a implementar fue sencilla, si se enfoca desde el punto de vista en el que se ve cual
numero es mayor y que serie de reglas implica ser el mayor se puede sacar un codigo sencillo, ejemplo: ente el 8 y el 3 el 8 es
mayor por lo cual el 8 va a tene el score de 1 si ampliamos esa logica a mas numero y le aplicamos las reglas que exige el ejer-
cicio se puede sacar facilmente, para resumer se ve cual numero es mayor cual es el menor y aplicarle sus respectivas reglas
dependiendo de la posicion donde esten colocados.*/

using namespace std;

/*
Nuestra funcion merger no es tan diferente respecto al que se hizo con anterioridad mas alla del uso de for para simplificar
algunos procesos,tambien un cambio importante es que este merger resive un vector de pares que contien un long long y un entero,
por lo cual a la hora de organizar las partes dividas actua un poco distito al estandar.
*/

void merge(vector<pair<long long, int>>& Vectorconpares, int izquierda, int medio, int derecha) {
    
    int i = izquierda, j = medio + 1;

    vector<pair<long long, int>> almacen(derecha - izquierda + 1);
    
    /*
    Este for solo guarda los elementos en el vector de pares almace que tiene el tamañós especificado en el parentesis
    y aprovecha y los organiza.
    */

    for (int k = 0; k < almacen.size(); k++) {
        if (i > medio) {
            almacen[k] = Vectorconpares[j++];
        } else if (j > derecha) {
            almacen[k] = Vectorconpares[i++];
        } else if (Vectorconpares[i].first < Vectorconpares[j].first) {
            almacen[k] = Vectorconpares[i++];
        } else if (Vectorconpares[i].first == Vectorconpares[j].first && Vectorconpares[i].second < Vectorconpares[j].second) {
            almacen[k] = Vectorconpares[i++];
        } else {
            almacen[k] = Vectorconpares[j++];
        }
    }
    
    /*
    devuelve los elementos ordenados al vector original que entro es decir "Vectorconpares"
    */

    for (int k = 0; k < almacen.size(); k++) {
        Vectorconpares[izquierda + k] = almacen[k];
    }
}

/*
mergersot la funcion encargada de dividir el arreglo, ya se explico con anterioridad en el ejercicio 3-1 subido a github.
Los unicos cambios es que recibe un vector con pares.
*/

void mergeSort(vector<pair<long long, int>>& Vectorconpares, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        mergeSort(Vectorconpares, izquierda, medio);
        mergeSort(Vectorconpares, medio + 1, derecha);
        merge(Vectorconpares, izquierda, medio, derecha);
    }
}

/*
El main en esta ocacion es necesario hacerle un par de explicaciones porque la logica de algunos for puede complicarse
*/

int main() {
    int Ejecuaciones;
    cin >> Ejecuaciones;
    
    while (Ejecuaciones--) {
        int n;
        cin >> n;
        
        vector<long long> guardarscore(n);
        for (int i = 0; i < n; i++) {
            cin >> guardarscore[i];
        }

        /*
        Hasta esta parte no se hizo nada relevante mas alla de pedir los datos por terminal y guardarlos en variable o vecotres
        */

       /*
       Vamos a crear un vector de tipo par a conveniencia el cual va a guardar los valores de guardarscore. y como se logra esto?
       bueno hay un comando en c++ llamado make_pair este te permite o bueno lo use asi, agarrar un vector y guarar el numero que 
       este en una posicion es decir posicion[i] y tambien guarda su indice es decir en que posicion del arreglo esta. con esto 
       tenemos ya la condiciones que necesitamos para guardarlo en ese vector es decir que el vector de long long se convierta en
       un vector con pares y luego lo mandaremos a nuestro mergesort.
       */
        
        vector<pair<long long, int>> Vectorconpares(n);
        for (int i = 0; i < n; i++) {
            Vectorconpares[i] = make_pair(guardarscore[i], i);
        }
        
        mergeSort(Vectorconpares, 0, n - 1);

        /*
        Aqui es donde uno comienza lo complejo nosotros necesitamos de alguna manera la suma acumulada de los numeros y esto
        porque por ejemplo en un arreglo de 4 elementos la suma del elemento de la 3re posicion con todos los anteriores supera
        el valor del ultimo elemento se añade +1 al score entonces que se hizo, bueno el merger nos retorna nuestro vector
        ordenado, creamos un vector que guarde los elementos .first de nuestro vector con pares y el for se encarga de ir
        ejecutando la suma acumulada.
        */
        
        vector<long long> apoyo(n);
        apoyo[0] = Vectorconpares[0].first;
        for (int i = 1; i < n; i++) {
            apoyo[i] = apoyo[i-1] + Vectorconpares[i].first;
        }

        /*
        Final vamos con la respuesta creamos dos vectores uno que nos a el score final que tiene cada numero y otro que sirve como
        apoyo para los indices entonces, cremos el for la lines que tiene el push_back simplemente asigna los indices que tiene ese
        vector a el vector de apoyo a su vez vamos a crear un condicional donde si se cumple alguna de esas condiciones se ejecuta
        un for interno que en resumen Asigna los índices del vector de apoyo al vector scorefinal con el valor actual de i y bueno
        clear limpia mi vector para un proximo recorrido.
        */
        
        vector<long long> scorefinal(n, -1);
        vector<int> recuerdaindices;

        for (int i = 0; i < n; i++) {
            recuerdaindices.push_back(Vectorconpares[i].second);
            if (i == n-1 || apoyo[i] < Vectorconpares[i+1].first) {
                for (int idx : recuerdaindices) {
                    scorefinal[idx] = i;
                }
                recuerdaindices.clear();
            }
        }
        
        /*
        imprime nuestra respuesta.
        */
        for (long long x : scorefinal) {
            cout << x << " ";
        }
  
    }
    
    return 0;
}


