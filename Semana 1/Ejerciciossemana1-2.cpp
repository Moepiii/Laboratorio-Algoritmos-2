//Rafael Antonio Valera Pacheco (moepii)
#include<iostream>

/*Razonamiento:En clase se hizo ya uno con formato while
en la entraga de este se hizo con un for para demostrar
que hay mas de una manera de hacerlo*/

using namespace std;

int main(){
    int i;

    //for te pide inicializa la i asi que para saltar ese proceso
    //se le coloco true.
    for(true;true;){
        cin>>i;
        if(i==42){
          break;
        }    
        cout<<i<<endl;
    }


    return 0;
}