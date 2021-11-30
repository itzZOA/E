//Reto 2 ED

#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>

using namespace std;

/**
 * @brief Pieza
 *
 * Clase para la cración de piezas estas estan asignadas a todas las casillas del tablero formando asi pequeños conjuntos de casillas que tendran que sumar una cantidad con sus valores asignados.
 *
 * @author Claudia Salado Méndez
 * @date October 2021
*/

class Pieza{
  private:
      int suma;
      int filas;
      int columnas;

  public:

    /**
     * @brief Constructor sin parametros
     */
    Pieza();

    /**
     * @brief Constructor con parametros, filas columnas y la suma
     * @param fils numero de filas que tendra la Pieza
     * @param cols numero de columnas que tendra la Pieza
     * @param sum es la suma de los valores de las casillas que forman la Pieza
     * @pre fils > 0 && not Null
     * @pre cols > 0 && not Null
     * @pre sum > 0 && not Null
     */
    Pieza(int fils, int cols, int sum);

    /**
     * @brief Destructor
     */
    ~ Pieza();

    /**
     * @brief Devuelve la suma de los valores de todas las casillas que forman parte de la pieza
     */
    int getSuma();

    /**
     * @brief Devuelve el numero de filas que tiene la pieza
     */
    int getFilas();

    /**
     * @brief Devuelve el numero de columnas que tiene la pieza
     */
    int getColumnas();

    /**
     * @brief Devuelve el numero de casillas que hay dentro de la pieza
     */
    int numCasillas();
}
