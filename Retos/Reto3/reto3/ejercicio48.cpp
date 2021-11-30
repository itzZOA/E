/*
 *En este ejercicio habia que hacer crear una cola que fuera la interseccion de otras dos
 *
 * @author Claudia Salado Méndez
 */

#include <queue>
#include <iostream>

using namespace std;

  //Esta funcion comprueba que los dos primeros elementos dela cola son iguales
  bool Iguales(queue<int> A, queue<int> B){
    bool iguales=false;
    if (A.front()==B.front())
      iguales=true;
    return iguales;
    }


//Crea una nueva cola con la intersección de las otras dos introducidas
queue <int> multi_interseccion(queue<int> A, queue<int> B){
    queue<int> aux; //Creamos la cola auxiliar
    int num=0;

    //Comprobamos cual es la cola mas pequeña
    if(A.size() > B.size())
      num=B.size();
    else
      num=A.size();


    for(int i=0; i < num; i++){//La cola tendra como maximo el mismo numero de items que la cola mas pequeña
      if(Iguales(A,B)){//Si son iguales metemos en la nueva cola el numero y lo eliminamos de las otras dos
        aux.push(A.front());
        A.pop();
        B.pop();
      }else if (A.front()<B.front()){ //si el numero de la cola A es mas pequeño se borra para poder continuar
        A.pop();
      }else if (B.front()<A.front()){ //si el numero de la cola B es mas pequeño se borra para poder continuar
        B.pop();
      }
    }
     //Las colas ya estan vacias
    return aux;
}//Fin del algoritmo

int main(){
  queue<int>A;
  queue<int>B;
  queue<int>prueba;
  int a=0,b=0;

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

  //llamamos a la funcion
  cout<<"El resultado de unir ambas colas es: "<<endl;
  prueba = multi_interseccion(A,B);

  //Mostramos por pantalla y borramos
  while(!prueba.empty()){
    cout<<prueba.front()<<" ";
    prueba.pop();
  }

}
