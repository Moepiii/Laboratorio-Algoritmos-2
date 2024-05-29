//Rafael Antonio Valera Pacheco (moepii)
#include <iostream>
#include <vector>
#include <utility>

/*Razonamiento:Bueno como se quiere allar una distancia la linea de pensamiento es vamos a ordenar el vector
que nos den en primera instancia con un algoritmo eficiente y luego por medio de una busqueda binaria (medio 
alterada)encontrar la distancia minima maxima.*/

using namespace std;

/*
Comenzamos implementando un Mergesort hay un par de variaciones dependiendo de como se implementa pero en 
esta ocacion seria el mas basico.
*/

/*
Al ser Mergesort recursivo vamos a hacer primero la funcion encargada de ordenar los arreglos pequeñós, es 
decir quien ordena los numeros del vector antes de unir y dar la respuesta final. Esta funcion se llama 
Merge y resive un vector de enteros y 3 enteros.
*/

void Merge(vector<int>& vechiquito, int primerE, int medio, int ultimoE) {
    
    /*
    Primero calculamos el tamaño que tendran nuestros dos vectores aqui entran en juego los 3 enteros siendo 
    primerE la posicion de nuestro primer elemento del vector, medio es el valor del medio y ultimo la posicion
    del ultimo.
    */

    int Tamano1 = medio - primerE + 1;
    int Tamano2 = ultimoE - medio;

    /*
    Ahora que tenemos sus tamaños podemos proceder con la creacion de sus respectivos vectores junto a los valores
    que van almacenaos en ellos, se llamaran almacen 1 y 2.
    */

    vector<int> almacen1(Tamano1), almacen2(Tamano2);
    
    /*
    Estos dos for no hacen nada muy interesante solo asignan los valores que vienen en vechiquito a nuestro vectores 
    que almacenan.
    */

    for (int i = 0; i < Tamano1; i++){
        almacen1[i] = vechiquito[primerE + i];
    }

    for (int j = 0; j < Tamano2; j++){
        almacen2[j] = vechiquito[medio + 1 + j];
    }
   
    /*
    Esta parte seria el corazon de esta funcion que es como organizar tanto los numeros que van dentro de nuestros 
    almacenes y como deben estar organizados una vez unidos, vamos a inicializar i,j,k esto basicamente porque aunque 
    se declararon en los for ellos solo pertenecen alli adentro su alcance no es externo por lo que si queremos usarlos 
    hay que volver a declararlos, los necesitamos para recorrer nuestros almacenes y ordenar.
    */

    int i = 0, j = 0, k = primerE;
    
    /*
    Nuestro primer while es el encargado de retornar y el vector ordenado por medio de un if se comparan los almacenes 1 y 2 
    y dependiendo de quien sea mayor se van asignando al vechiquito, este proceso permite que ya esten ordenados.
    */

    while (i < Tamano1 && j < Tamano2) {
        if (almacen1[i] <= almacen2[j]) {
            vechiquito[k] = almacen1[i];
            i++;
        } else {
            vechiquito[k] = almacen2[j];
            j++;
        }
        k++;
    }
    
    /*
    Estos dos while solo verifican si quedan elementos dentro de almacen 1 y 2 en caso de que si los asigna a vechiquito.
    */

    while (i < Tamano1) {
        vechiquito[k] = almacen1[i];
        i++;
        k++;
    }

    while (j < Tamano2) {
        vechiquito[k] = almacen2[j];
        j++;
        k++;
    }
}

/*
Nuestra funcion MergeSort esta es la encargada de dividir el vector que reciba tal como se indica en su metodo un arreglo 
(en este caso un vector) de tamañó 1 se considera ordenado que ocurre entonces bueno esta funcion se va a llamar asi misma 
hasta que la condicion del if deje de cumplirse y nuestra funcion Merge se encarga de ir uniendo las mitades que se dividieron, 
para retornar un vector ordenado.
*/

void MergeSort(vector<int>& vecgrande, int primero, int ultimo) {
    if (primero < ultimo) {
        int mitad = primero + (ultimo - primero) / 2;

        MergeSort(vecgrande, primero, mitad);
        MergeSort(vecgrande, mitad + 1, ultimo);

        Merge(vecgrande, primero, mitad, ultimo);
    }
}

/*
Ahora vendria la parte de la busqueda binaria, pero por si sola la busqueda binaria no nos daria la respuesta asi que necesitamos 
antes un verificador, esta tiene el objetivo de ver si podemos colocar la cantidad de vacas que nos piden en los establos, su 
funcion es sencilla, recibe un vector y 3 enteros donde el vector es el que se introduce en el main, un entero es cuantas vacas 
queremos guardar, otro es la distancia entre vacas, este ultimo lodetermina busqueda binaria, y la cantidad de establos. entonces 
dentro de la funcion declaramos un int que sera una vaca y otro que representa su posicion en el establo entonces dentro de un for
que comenzara una posicion mas adelante que la vaca asignada colocamos un if donde basicamente simulamos que colocamos otra vaca 
en la posision i del arreglo y restamos ambas posiciones si ese valor no es mayor que la distacia no se puede poner la vaca, en 
caso contrario si y sumamos uno a la cantidad de vacas y ahora partimos de esa posicion, todo esto con el fin de retornar por medio
 de un true o false si se puede ejecutar esa accion que se pide.
*/

bool verificar(const vector<int>& posicion, int cantidad, int vacasnecesarias, int distancia) {
    int vaca = 1;
    int establo = posicion[0];
    for (int i = 1; i < cantidad; i++) {
        if (posicion[i] - establo >= distancia) {
            vaca++;
            establo = posicion[i];
        }
    }
    return vaca >= vacasnecesarias;
}

/*
Finalmente la busqueda binaria es la que nos permite una vez arreglado el vector encontrar cual es la distancia minima maxima entre
vacas todo esto con ayuda de  la funcion verificar.Esta funcion trabaja en si con los imput que se solicitan es decir el vector, la 
cantidad de establos y numero de vacas.
*/

int Busquedabinaria(const vector<int>& numerocorral, int n, int cantidadv) {

    /*
    Primero necesitamos un rango de busqueda para esto necesitamos dos variables a una le asignaremos el valor de 0 y otra sea el 
    valor que este en el vector n-1, por ultimo una ultima variable que iniciamos en -1 esta variable comienza  asi porque es la 
    responsable del resultado y en caso que la operaciones no sean posibles retorna ese valor, es una manera de decir que no se 
    pudo con la operacion.
    */

    int inicio = 0, final = numerocorral[n - 1], Respuesta = -1;
    
    /*
    Bucle que se mantiene en ejecucion mientras la condicion se cumple andentro de ese bucle declaramos una variable encargada de 
    sacar justo la mitad luego de eso por medio de un if donde interviene verificar pueden pasar dos cosas: que devuelva true 
    entonces inicio se vuelve la mitad + 1 y respuesta es igual al maximo valo entre la respuesta y la mitad. En caso de que 
    verificar tire false final sera el valor de la mitad -1.Una vez se deja de cumplir este while retornamos la respuesta que 
    queremos que es la distancia minima maxima.
    */

    while (inicio <= final) {
        int mitad = (inicio + final) / 2;
        if (verificar(numerocorral, n, cantidadv, mitad)) {
            Respuesta = max(Respuesta, mitad);
            inicio = mitad + 1;
        } else {
            final = mitad - 1;
        }
    }
    return Respuesta;
}


/*
La funcion main, no hay mucho que decir en esta porque todos los procesos complejos lo hacen funciones externas que ella 
llama. Solo tiene los datos solicitados y como llama a las funciones para retornar la respuesta.
*/

int main() {
    
    int T;
    cin >> T;

    while (T--) {
        
        int n, c;
        cin >> n >> c;

        vector<int> Establosd(n);

        for (int i = 0; i < n; i++){
            cin >> Establosd[i];
        }

        MergeSort(Establosd, 0, n - 1);
        
        int Fin = Busquedabinaria(Establosd, n, c);

        cout << Fin << endl;
    }
    return 0;
}