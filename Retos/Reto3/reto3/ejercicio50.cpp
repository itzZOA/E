/*
 *En este ejercicio habia que hacer crear lista que se dividia en rangos de pares e impares consecutivos, dejando el primero de cada rango
 *
 * @author Claudia Salado Méndez
 */

#include <iostream>
#include <list>

using namespace std;

//Esta funcion sirve para imrpimir una lista por pantalla
void MostrarLista(list<int> & L1){
  list<int>::iterator it;
  it=L1.begin();
  while(it!=L1.end()){
    cout<<*it<<" ";
    it ++;
  }
}

//Esta funcion comprueba si un numero es par
bool esPar(int v){
    bool par=false;
    if(v%2==0)
        par=true;
return par;
}

void deja1solo(list<int> &L){
    list<int>  aux; // Lista auxiliar para el resultado
    list<int>::iterator it; //Declaramos el iterador

    bool anterior_par = esPar(L.front()); // Comprobamos si el primer valor de la lista es par o no
    aux.push_back(L.front()); // Se introduce

    for(it=L.begin(); it!=L.end();++it){
        if(anterior_par){  // Si el anterior numero era par, busca un impar
            if(!esPar(*it)){  // Si es impar, lo introducimos en aux y poenmos el bool a false
                aux.push_back(*it);
                anterior_par = false;
            }
        }else{  // Si el anterior es impar, busca un par
            if(esPar(*it)){ // Comprueba si es par, si lo es lo introduce y cambia el bool
                aux.push_back(*it);
                anterior_par = true;
            }
        }
    }

    L.swap(aux); //Intercambiamos las listas
    aux.clear(); //Vaciamos la auxiliar
}

int main(){
    //Guardamos los datos en vectores para comprobar que funcione
    int enteros1[] = {5,4,5,3,4,9,10,4,9,3,2,10,3,7,5,3};
    int enteros2[] = {10,10,1,9,7,4,4,10,7,1,1,4,10,1,1,7};

    //Inicializo las listas
    list<int> lista1, lista2;
    lista1.assign(enteros1, enteros1+16);
    lista2.assign(enteros2, enteros2+16);

    //Llamamos a la funcion
    deja1solo(lista1);
    deja1solo(lista2);

    //Mostramos el resultado
    cout <<"Datos de la Lista1:"<< endl;
    MostrarLista(lista1);
    cout << endl;
    cout <<"Datos de la Lista2:"<< endl;
    MostrarLista(lista2);
    cout << endl;
    return 0;
}
