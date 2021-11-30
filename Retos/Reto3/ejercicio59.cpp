/*
 *En este ejercicio habia que intercalar dos listas, teniendo como requisitos, que se empieza por el primer elemento de L1
 *La lista L1 tiene el resultado final y L2 esta vacia, y que si una lista es mayor que otra al final de L1 estaran los elementos de la lista larga
 *
 * @author Claudia Salado Méndez
 */

#include <list>
#include <cstdlib>
#include <iostream>

using namespace std;

//Esta funcion sirve para imrpimir una lista por pantalla
void MostrarLista(list<char> & L1){
  list<char>::iterator it;
  it=L1.begin();
  while(it!=L1.end()){
    cout<<*it<<" ";
    it ++;
  }
}

void peinarlistas(list<char> & L1, list<char> & L2){
    list<char> aux;
    int tam;
    int tam_max=L1.size()+L2.size(); //Calcula cual va a ser el nuevo tamaño de la lista final
    list<char>::iterator it;//Creamos el iterador
    it=L1.begin();//Inicializamos el iterador

    while(it!=L1.end()){//Copiamos el contenido de L1 en aux
      aux.push_back(*it);
      it ++;
    }


    if(L1.size() > L2.size()) //Calcula cual es la lista mas pequeña para en la hora en la que esta se quede sin elementos y la otra siga teniendo
      tam=L2.size();
    else
      tam=L1.size();

    L1.clear();//Deja vacia L1 para meter los datos de las dos listas unidas en esta
  for (int i =0; i<tam_max;i++ ){
      if(i<=tam){
          if(i%2==0){//Mete en las posiciones pares los elementos de L1 mientras ambas no esten vacias
            L1.push_back(aux.front());
            aux.pop_front();
          }else if(i%2!=0){//Mete en las posiciones impares los elementos de L2 mientras ambas no esten vacias
            L1.push_back(L2.front());
            L2.pop_front();
          }
      }else if(!L2.empty()){ //Si L2 no esta vacia y aux, si llena L1 con lo restante de L2
        L1.push_back(L2.front());
        L2.pop_front();
      }else if(!aux.empty()){ //Si aux no esta vacia y L2, si llena L1 con lo restante de L2
        L1.push_back(aux.front());
        aux.pop_front();
      }
    }
    MostrarLista(L1);
}//Fin del algoritmo

int main(){
  list<char>A;
  list<char>B;
  char a,b;

 //Guarda los datos de la primera lista, finaliza con *
  while(a!='*'){
    cout<<"Ingrese una letra en la lista L1 (para terminar con el ingreso introduzca ' * ')"<<endl;
    cin>>a;
    if(a!='*')
      A.push_back(a);
  }

  //Guarda los datos de la segunda lista, finaliza con *
  while(b!='*'){
    cout<<"Ingrese una letra en la lista L2 (para terminar con el ingreso introduzca ' * ')"<<endl;
    cin>>b;
    if(b!='*')
      B.push_back(b);
  }

  //Llamamos a la funcion
  cout<<"El resultado de unir ambas listas es: "<<endl;
  peinarlistas(A,B);


}
