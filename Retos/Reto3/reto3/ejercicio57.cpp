/*
 *En este ejercicio habia que intercalar dos pilas, teniendo como requisitos, que se empieza por el primer elemento de pila 1
 * y que si una lista es mayor que otra al final de la pila reesultante estaran los elementos de la lista larga
 *
 * @author Claudia Salado Méndez
 */

#include <stack>
#include <iostream>

using namespace std;


stack <int> coctel(stack<int> &A, stack<int> &B){
    stack<int> aux; //pila auxiliar
    int tam;
    int tam_max=A.size()+B.size();  //Tamaño que va a tener la pila finaliza

    if(A.size() > B.size())//Comprueba que pila se terminara antes de insertar
      tam=B.size();
    else
      tam=A.size();

    for (int i =0; i<tam_max;i++ ){
      if(i<=tam){ //Mientras esten las dos pilas con elementos
          if(i%2==0){ //En las posiciones pares iran los elementos de la primera lista
            aux.push(B.top());
            B.pop();
          }else if(i%2!=0){ //En las posiciones impares iran los elementos de la segunda lista
            aux.push(A.top());
            A.pop();
          }
      }else if(!B.empty()){ //Cuando la segunda lista tenga elementos y la primera no, se añadiran al final de la pila los restantes
        aux.push(B.top());
        B.pop();
      }else if(!A.empty()){//Cuando la primera lista tenga elementos y la segunda no, se añadiran al final de la pila los restantes
        aux.push(A.top());
        A.pop();
      }

    }
    return aux;
}//Fin del algoritmo

int main(){
  stack<int>A;
  stack<int>B;
  stack<int>prueba;
  int a=0,b=0;

  //Insertamos los valores de la primera pila, finalizamos con un -1
  while(a>=0){
    cout<<"Ingrese un dato en la pila A (para terminar con el ingreso introduzca un valor negativo)"<<endl;
    cin>>a;
    if(a>=0)
      A.push(a);
  }

  //Insertamos los valores de la segunda pila, finalizamos con un -1
  while(b>=0){
    cout<<"\nIngrese un dato en la pila B (para terminar con el ingreso introduzca un valor negativo)"<<endl;
    cin>>b;
    if(b>=0)
      B.push(b);
  }

  //Llamamos a la funcion
  cout<<"El resultado de unir ambas pilas es: "<<endl;
  prueba = coctel(A,B);

  //Mostramos en pantalla la pila resultante
  while(!prueba.empty()){
    cout<<prueba.top()<<" ";
    prueba.pop();
  }

}
