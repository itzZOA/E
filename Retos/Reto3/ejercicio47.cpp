/*
 *En este ejercicio habia que crear una cola ordenada a partir de otras dos
 *
 * @author Claudia Salado Méndez
 */

#include <queue>
#include <iostream>

using namespace std;

//Esta funcion comprueba que llas colas no estan vacias, ninguna de las dos
bool noVacios(queue<int> A, queue<int> B){
  bool noVacio=true;
  if (A.empty()){
    if (B.empty())
      noVacio=false;
  }
  return noVacio;
  }

//Une dos colas ordenadas
queue <int> mergeSortedqueues(queue<int> A, queue<int> B){
    queue<int> aux;
    int num=0;

    //Miranos cual es el numero menor para ir ingresando en la cola
    if(A.front() >= B.front())
      num=B.front();
    else
      num=A.front();


    while(noVacios(A,B)){//Mientras ambas no esten vacias


      while(num==A.front()){ //Mientras el numero sea igual al primero de A se añade
          aux.push(num);
          A.pop();
      }

      while(num==B.front()){ //Mientras el numero sea igual al primero de B se añade
          aux.push(num);
          B.pop();
      }

      num++;  //Si el numero ya no es igual al front de ninguna cola se aumenta;

  }
    return aux;
}//Fin del algoritmo

int main(){
  queue<int>A;
  queue<int>B;
  queue<int>prueba;
  int a,b;

  //Insertamos los valores de la primera cola, finalizamos con un -1
  while(a>=0){
    cout<<"Ingrese un dato en la cola A de menor a mayor (para terminar con el ingreso introduzca un valor negativo)"<<endl;
    cin>>a;
    if(a>=0)
      A.push(a);
  }

  //Insertamos los valores de la segunda cola, finalizamos con un -1
  while(b>=0){
    cout<<"\nIngrese un dato en la cola B de menor a mayor(para terminar con el ingreso introduzca un valor negativo)"<<endl;
    cin>>b;
    if(b>=0)
      B.push(b);
  }

  //Llamamos a la funcion
  cout<<"El resultado de unir ambas colas es: "<<endl;
  prueba = mergeSortedqueues(A,B);

  //Mostramos por pantalla el resultado y borramos
  while(!prueba.empty()){
    cout<<prueba.front()<<" ";
    prueba.pop();
  }

}
