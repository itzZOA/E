//Reto 2 ED

#ifndef CASILLA_H
#define CASILLA_H
#include <iostream>

using namespace std;
  /**
   * @brief Casilla
   *
   * Clase para crear los objetos casilla que formaran parte del tablero de 9x9, estas estan formada por el valor y por una pieza que sera de la que formara parte junto a otras casillas.
   *
   * @author Claudia Salado Méndez
   * @date October 2021
  */

class Casilla{
  private:
      int valor;
      Pieza p;

  public:

    /**
     * @brief Constructor sin parametros
     */
    Casilla();

    /**
     * @brief Constructor con parametros, valor y pieza
     * @param v valor correspondiente a esa casilla
     * @param pieza es la pieza a la que pertenece dicha casilla
     * @pre pieza not Null
     * @pre v > 0
     */
    Casilla(int v, Pieza pieza);

    /**
     * @brief Destructor
     */
    ~ Casilla();

    /**
     * @brief Devuelve el valor de la casilla
     */
    int getValor();

    /**
     * @brief pone el valor correspondiente a la casilla
     * @param v es el valor que queremos ponerle
     * @pre v >= 0, si es cero significa que queremos quitarle el valor que le habiamos, es como si estuviera vacia.
     */
    void setValor(int v);

    /**
     * @brief Devuelve la pieza a la que pertenece la casilla
     */
    Pieza getPieza();

    /**
     * @brief Devuelve true si la casilla esta vacia.
     */
    bool estaLibre();

}
