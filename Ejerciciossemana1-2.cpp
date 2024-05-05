//Rafael Antonio Valera Pacheco (moepii)
//En clase se hizo con while por eso se intento hacer con for
#include<iostream>

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