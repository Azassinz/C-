//
// Created by david on 2/15/2018.
//
#include<cstdio>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int main(){
    //peticion de la cadena
    printf("Dame la cadena DRM: ");
    char cadena[15000];
    //lectura de la cadena
    scanf("%s",cadena);
    //sacar tamaño de la cadena
    int tam = strlen(cadena);
    //printf("%i ",tam);


    //divide
    //mitad del tamaño
    int mitad = tam/2;
    //printf("%i ",mitad);
    //cadena de caracteres para guardar las mitades
    char m1[mitad];
    char m2[mitad];
    //inicializacion de la primer mitad
    for (int i = 0; i < (sizeof m1 / sizeof *m1); ++i) {
        m1[i] = cadena[i];
        //printf("%c",cadena[i]);
    }
    //printf("\n");
    //inicializacion de la segunda mitad
    int j = mitad;
    for (int i = 0; i < (sizeof m2 / sizeof *m2); ++i) {
        m2[i] = cadena[j];
        //printf("%c",cadena[j]);
        j++;
    }
/**
    printf("\n");
    printf("%s",m1);
    printf("\n");
    printf("%s",m2);
**/
    //rotate
    //mapa para asignar valores a cada caracter y luego accesar a ellos mediante el caracter.
    map<char , int> valores;
    valores.insert(make_pair('A',0));
    valores.insert(make_pair('B',1));
    valores.insert(make_pair('C',2));
    valores.insert(make_pair('D',3));
    valores.insert(make_pair('E',4));
    valores.insert(make_pair('F',5));
    valores.insert(make_pair('G',6));
    valores.insert(make_pair('H',7));
    valores.insert(make_pair('I',8));
    valores.insert(make_pair('J',9));
    valores.insert(make_pair('K',10));
    valores.insert(make_pair('L',11));
    valores.insert(make_pair('M',12));
    valores.insert(make_pair('N',13));
    valores.insert(make_pair('O',14));
    valores.insert(make_pair('P',15));
    valores.insert(make_pair('Q',16));
    valores.insert(make_pair('R',17));
    valores.insert(make_pair('S',18));
    valores.insert(make_pair('T',19));
    valores.insert(make_pair('U',20));
    valores.insert(make_pair('V',21));
    valores.insert(make_pair('W',22));
    valores.insert(make_pair('X',23));
    valores.insert(make_pair('Y',24));
    valores.insert(make_pair('Z',25));

    map<int , char > caracteres;
    caracteres.insert(make_pair(0,'A'));
    caracteres.insert(make_pair(1,'B'));
    caracteres.insert(make_pair(2,'C'));
    caracteres.insert(make_pair(3,'D'));
    caracteres.insert(make_pair(4,'E'));
    caracteres.insert(make_pair(5,'F'));
    caracteres.insert(make_pair(6,'G'));
    caracteres.insert(make_pair(7,'H'));
    caracteres.insert(make_pair(8,'I'));
    caracteres.insert(make_pair(9,'J'));
    caracteres.insert(make_pair(10,'K'));
    caracteres.insert(make_pair(11,'L'));
    caracteres.insert(make_pair(12,'M'));
    caracteres.insert(make_pair(13,'N'));
    caracteres.insert(make_pair(14,'O'));
    caracteres.insert(make_pair(15,'P'));
    caracteres.insert(make_pair(16,'Q'));
    caracteres.insert(make_pair(17,'R'));
    caracteres.insert(make_pair(18,'S'));
    caracteres.insert(make_pair(19,'T'));
    caracteres.insert(make_pair(20,'U'));
    caracteres.insert(make_pair(21,'V'));
    caracteres.insert(make_pair(22,'W'));
    caracteres.insert(make_pair(23,'X'));
    caracteres.insert(make_pair(24,'Y'));
    caracteres.insert(make_pair(25,'Z'));
    //suma de valores para m1
    int suma1 = 0;
    //printf("\n");
    for (int i = 0; i < mitad; ++i) {
        suma1 += valores[m1[i]];
        //printf("%i ",valores[m1[i]]);
    }
    //printf("\n");
    //suma de valores para m2
    int suma2 = 0;
    for (int i = 0; i < mitad; ++i) {
        suma2 += valores[m2[i]];
        //printf("%i ",valores[m2[i]]);
    }

    //comprobar suma de valores
    /**
    printf("\n");
    printf("%i",suma1);
    printf("\n");
    printf("%i",suma2);
    printf("\n");
     **/

    //hacer rotacion de caracteres para m1
    int valorInicial;
    for (int i = 0; i < mitad; ++i) {
        valorInicial = valores[m1[i]];
        valorInicial += suma1;
        while (valorInicial > 25){
            valorInicial-=26;
        }
        m1[i] = caracteres[valorInicial];
        //printf("%c",caracteres[valorInicial]);
    }
    //printf("\n");
    //hacer rotacion de caracteres para m2
    valorInicial = 0;
    for (int i = 0; i < mitad; ++i) {
        valorInicial = valores[m2[i]];
        valorInicial += suma2;
        while (valorInicial > 25){
            valorInicial-=26;
        }
        m2[i] = caracteres[valorInicial];
        //printf("%c",caracteres[valorInicial]);
    }
    //printf("\n");

    //merge
    //mitad = tam/2;
    //printf("%i",mitad);
    char mensaje[mitad];
    int nuevoValor = 0;
    for (int i = 0; i < mitad; ++i) {
        nuevoValor = (valores[m1[i]] + valores[m2[i]]);
        //printf("%i",nuevoValor);
        while (nuevoValor > 25){
            nuevoValor-=26;
        }
        mensaje[i] = caracteres[nuevoValor];
        printf("%c",caracteres[nuevoValor]);
        //printf("\n");
        nuevoValor = 0;
    }
    //printf("Mensaje desencriptado: %s",mensaje);

    return 0;
}

