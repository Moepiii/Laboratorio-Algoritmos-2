//Rafael Antonio Valera Pacheco (moepii)
#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

/*Razonamiento:no hay mucho detras del razonamiento de este ejercicio porque se nos pidio directamente que efectuaramos la multi-
plicacion con el algoritmo de Strassen por lo tanto se siguio esa metodologia para realizarlo.
*/

using namespace std;

/*
Esta funcion tiene el unico trabajo de calcular el siguiente número mayor o igual a k que sea una potencia de 2. Como lo hace?
en clase se dio una explicacion de como se realizan desplazamientos de bits entonces se implemento esta funcion con eso en mente
lo unico nuevo seria que se hace un OR bit a bit que en resumen no es mas que establecer todos los bits menos significativos hasta 
el bit más significativo.
*/

int calculopotencia2(int p) {
    p--;
    p |= p >> 1;
    p |= p >> 2;
    p |= p >> 4;
    p |= p >> 8;
    p |= p >> 16;
    p++;
    return p;
}

/*
Esta funcion suma matrices que reciba para esto necesita dos matrices y el tamañó o las dimensiones. Para agilizar un poco la 
operaciones se usaron punteros, para esto nos apoyaremos del .data este accede a las filas de las matrices que es un vector de 
unsigned long long luego devuelve un puntero al primer elemento de esa fila, que es un unsigned long long.
*/

void Ayudasuma(const vector<vector<unsigned long long>>& A, const vector<vector<unsigned long long>>& B, vector<vector<unsigned long long>>& C, int tamano) {
    for (int i = 0; i < tamano; i++) {
        const unsigned long long* puntadeA = A[i].data();
        const unsigned long long* puntadeB = B[i].data();
        unsigned long long* puntadeC = C[i].data();
        for (int j = 0; j < tamano; j++) {
            puntadeC[j] = puntadeA[j] + puntadeB[j];
        }
    }
}

/*
Esta funcion sirve con la misma linea de pensasmiento que la que suma matrices solo que esta hace lo opuesto es decir resta
*/

void Ayudaresta(const vector<vector<unsigned long long>>& A, const vector<vector<unsigned long long>>& B, vector<vector<unsigned long long>>& C, int tamano) {
    for (int i = 0; i < tamano; i++) {
        const unsigned long long* puntadeA = A[i].data();
        const unsigned long long* puntadeB = B[i].data();
        unsigned long long* puntadeC = C[i].data();
        for (int j = 0; j < tamano; j++) {
            puntadeC[j] = puntadeA[j] - puntadeB[j];
        }
    }
}

/*
Esta funcion efectua una multiplicacion estandar de dos matrices solo se usara si las dimensiones de la matriz no superan
cierta cantidad, esto para no dejar todo el trabajo a la funcion Strassen que no es muy eficiente con matrices mas chicas
*/

void Multinormal(const vector<vector<unsigned long long>>& A, const vector<vector<unsigned long long>>& B, vector<vector<unsigned long long>>& C, int tamano) {
    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; j += 4) {
            C[i][j] = 0;
            C[i][j + 1] = 0;
            C[i][j + 2] = 0;
            C[i][j + 3] = 0;
            for (int k = 0; k < tamano; ++k) {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j + 1] += A[i][k] * B[k][j + 1];
                C[i][j + 2] += A[i][k] * B[k][j + 2];
                C[i][j + 3] += A[i][k] * B[k][j + 3];
            }
        }
    }
}

/*
Llegamos al algoritmo de Strassen es complejo todo lo que hace pero se explicara paso a paso para dar una idea al lector.

Primero tenemos un if este tiene el unico objetivo de que si la matriz no es tan grande se realice una multiplicacion normal entre
matrices

Ahora procedemos a dividir A,B y C en 4 submatrices Con el fin de hacer lo que indica Strassen que es hacer 7 operaciones mas 
pequeñás.

Luego inicializamos varios vectores (o matrices) como A11, B11, C11... etc esto con el fin de usarlos de almace para los datos
que en este caso seran las submatrices de A y B, tambien se crean otros 7 vectores para calculos realizados conforme avanza el
proceso

Ahora vendria la parte compleja el algoritmo de Strassen va a comenzar a llamarse de forma recursiva asi mismo para calcular
datos intermedios es decir calculoext1,calculoext2,calculoext3 etc..., y todos estos calculos se hacen con las funciones aux-
liares: Ayudasuma y Ayudaresta.

Finalmente una vez se efectuan todos estos calculos, se unan y se vuelve a generar una matriz que seria la matriz C justo lo que
necesitamos y asi finaliza la funcion stranssen.
*/

void Strassen(const vector<vector<unsigned long long>> &A, const vector<vector<unsigned long long>> &B, vector<vector<unsigned long long>> &C, int tamano, int usodestrassen)
{

    if (tamano <= usodestrassen)
    {
        Multinormal(A, B, C, tamano);
        return;
    }

    int dimensionesn = tamano / 2;

    vector<vector<unsigned long long>> A11(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> A12(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> A21(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> A22(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> B11(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> B12(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> B21(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> B22(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> C11(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> C12(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> C21(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> C22(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> calculoext1(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> calculoext2(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> calculoext3(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> calculoext4(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> calculoext5(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> calculoext6(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> calculoext7(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> RFinala(dimensionesn, vector<unsigned long long>(dimensionesn));
    vector<vector<unsigned long long>> RFinalb(dimensionesn, vector<unsigned long long>(dimensionesn));


    int i, j;
    for (i = 0; i < dimensionesn; i++)
    {
        for (j = 0; j < dimensionesn; j++)
        {
         
            A11[i][j] = A[i][j];         
            A12[i][j] = A[i][j + dimensionesn];        
            A21[i][j] = A[i + dimensionesn][j];
            A22[i][j] = A[i + dimensionesn][j + dimensionesn];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + dimensionesn];
            B21[i][j] = B[i + dimensionesn][j];
            B22[i][j] = B[i + dimensionesn][j + dimensionesn];
        }
    }

    Ayudasuma(A11, A22, RFinala, dimensionesn);
    Ayudasuma(B11, B22, RFinalb, dimensionesn);
    Strassen(RFinala, RFinalb, calculoext1, dimensionesn, usodestrassen);

    Ayudasuma(A21, A22, RFinala, dimensionesn);
    Strassen(RFinala, B11, calculoext2, dimensionesn, usodestrassen);

    Ayudaresta(B12, B22, RFinalb, dimensionesn);
    Strassen(A11, RFinalb, calculoext3, dimensionesn, usodestrassen);

    Ayudaresta(B21, B11, RFinalb, dimensionesn);
    Strassen(A22, RFinalb, calculoext4, dimensionesn, usodestrassen);

    Ayudasuma(A11, A12, RFinala, dimensionesn);
    Strassen(RFinala, B22, calculoext5, dimensionesn, usodestrassen);

    Ayudaresta(A21, A11, RFinala, dimensionesn);
    Ayudasuma(B11, B12, RFinalb, dimensionesn);
    Strassen(RFinala, RFinalb, calculoext6, dimensionesn, usodestrassen);

    Ayudaresta(A12, A22, RFinala, dimensionesn);
    Ayudasuma(B21, B22, RFinalb, dimensionesn);
    Strassen(RFinala, RFinalb, calculoext7, dimensionesn, usodestrassen);

    Ayudasuma(calculoext3, calculoext5, C12, dimensionesn);
    Ayudasuma(calculoext2, calculoext4, C21, dimensionesn);
    Ayudasuma(calculoext1, calculoext4, RFinala, dimensionesn);
    Ayudasuma(RFinala, calculoext7, RFinalb, dimensionesn);

    Ayudaresta(RFinalb, calculoext5, C11, dimensionesn);
    
    Ayudasuma(calculoext1, calculoext3, RFinala, dimensionesn);
    Ayudasuma(RFinala, calculoext6, RFinalb, dimensionesn);

    Ayudaresta(RFinalb, calculoext2, C22, dimensionesn);

    for (i = 0; i < dimensionesn; i++)
    {
        for (j = 0; j < dimensionesn; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + dimensionesn] = C12[i][j];
            C[i + dimensionesn][j] = C21[i][j];
            C[i + dimensionesn][j + dimensionesn] = C22[i][j];
        }
    }
}


/*
Nuestro main, aqui iremos por partes primero se declaran las variables y vectores a las cuales les cambiamos el tipo solo para 
no tener que  usar la biblioteca #include<cstdint> aunque no hay gran diferencia porque el ejercicio funciona exactamente igual
las cambies o no siempre que se haga el cambio respectivo en las funciones.

los primeros for anidados calculan los valores de A y B esto nos los da el ejercicio de base.

luego hay un int que se necesita porque el algoritmo de Strassen solo funciona con matrices cuadradas entonces hay que hacer tru-
quitos, esto porque los valores que tendran A Y B se calculan apartir de parametros que se meten por terminal por lo cual las
matrices no seran necesariamente cuadradas, entonces como se corrije esto bueno la idea seria Redimensiona las matrices a su tamaño
más cercano que sea una potencia de 2 usando calculopotencia2.Luego por medido de dos for anidados copiamos los valosres de A Y B calculados
en nuestras matrices redimensionadas.

Luego como Strassen funsiona bien es con matrices descomunales, en el caso de las matrices mas pequeñas se puede usar un metodo
mas normalito entonces vamos a fijar un limite adecuado que cuando se supere use Strassen y cuando no simplemente usa la 
multiplicacion tradicional, sin mas luego llamamos a nuestra funcion Strassen para realizar los calculos.

Luego se tiene otros dos for proporcionado por el ejercicio en si

por ultimo imprimimos nuestra respuesta con los espacios como lo pide el ejercicio

*/
int main() {

    unsigned int n, i, j, d1, calculoext1, r1, m1, d2, calculoext2, r2, m2;
    cin >> n >> calculoext1 >> d1 >> r1 >> m1 >> calculoext2 >> d2 >> r2 >> m2;


    vector<vector<unsigned int>> A(n, vector<unsigned int>(n));
    vector<vector<unsigned int>> B(n, vector<unsigned int>(n));
    vector<vector<unsigned long long>> C(n, vector<unsigned long long>(n));
    vector<unsigned long long> V(n, 0);

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            d1 = d1 * calculoext1 + r1;
            d2 = d2 * calculoext2 + r2;
            A[i][j] = d1 >> (32 - m1);
            B[i][j] = d2 >> (32 - m2);
        }
    }

    int dimensionesn = calculopotencia2(n);
    vector<unsigned long long> ini(dimensionesn);
    vector<vector<unsigned long long>> A_exp(dimensionesn, ini), B_exp(dimensionesn, ini), C_exp(dimensionesn, ini);


    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            A_exp[i][j] = static_cast<unsigned long long>(A[i][j]);
            B_exp[i][j] = static_cast<unsigned long long>(B[i][j]);
        }
    }

    int usodestrassen = 100; 
    Strassen(A_exp, B_exp, C_exp, dimensionesn, usodestrassen);

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            C[i][j] = C_exp[i][j];
        }
    }

    for (i = 0; i < n; ++i) {
        V[i] = 0;
        for (j = 0; j < n; ++j) {
            V[i] ^= C[i][j];
        }
    }

    for (i = 0; i < n; ++i) {
        cout << V[i] <<" ";
    }
    cout <<endl;

    return 0;
}