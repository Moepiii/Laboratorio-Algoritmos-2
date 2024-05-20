//Rafael Antonio Valera Pacheco (moepii)
#include <iostream>
#include <vector>

/*Razonamiento: Basicamente en el analisis del ejercicios se puede concluir que
sea cuales sean los valores introducidos solo tienes dos posibles resultados que son
K-1 o n entonces este razonamiento se basa en distingir en que caso se activa la respuesta
k-1 o n y esto se logra dependiendo si se activa cierto proceso en el programa o no,dicho
proceso se explica mas afondo en comentarios del propio programa.*/

using namespace std;

int main() {
    /*
    El problema inicialmente solicita 3 cosas:Debemos decirle el numero de casos
    Tambien debemos decirle cuantas cartas seran usadas y cuantas son las que puedo juntar para
    eliminar y hacer el cambio por otras en caso de ser similares. 
    */

    int x;
    cin>>x;

    while(x--){
      
       int n,k;
       cin>>n>>k;

     /*
       Ahora toca lo complejo.
       Necesitamos algo que nos permita guardar los valores que van a tener las cartas que 
       es proporcional al valor que coloquemos en n, esto lo lograremos con un vector que
       vamos a enlazar con el valor de n.Tambien necesitamos implementar el proceso de guardado
       esto se logra con un for.
     */
      
      vector<int> valorcartas(n);

      for (int i = 0; i < n; i++){
        cin >> valorcartas[i];
      }
       
      /*
       vamos a definir una constante de tipo entero que no va a variar
       esto para posteriormente crear un vector con un tamañó maximo
       en principio este vector va a guardar cuantas veces se repite un numero
       por medio de un for que va viendo si los valores son iguales o no.
     */

      const int maximo = 800; 
      vector<int> repetidos(maximo, 0);

      for (int veces : valorcartas){
       repetidos[veces]++;
      }        
      

      /*
      Finalmente lograremos la resolucion por medio de un ultimo for
      para esto declaramos un int contador que se le sumara 1 cada vez
      que la condicion del if se cumpla, que basicamente si el vector 
      repetidos en la posicion 1 es >= k sumarle uno a contador
      aqui es donde puede que sea deficiente porque este for se ejecuta hasta
      que alcance el valor de maximo que es colocado por nosotros.
      */
    
       int contador = 0;
       for (int i = 0; i <maximo; i++) {
         if (repetidos[i] >= k) {
            contador++;
          }
        }

      /*
      En el resultado pueden pasar dos cosas que sea directamente el valor de n o
      ser k-1 entonces es necesario el if para casos.
      */
        
       int respuesta;
       if (contador > 0) {
       respuesta = k - 1;
       } else {
       respuesta = n;
       }
       cout << respuesta << endl;
       
    }

    return 0;
}

