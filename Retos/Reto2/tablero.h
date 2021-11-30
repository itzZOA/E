//Reto 2 ED

#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>

using namespace std;

/**
 * @brief Tablero
 *
 * Clase para la cración del tablero principal, formado por 81 casillas ya que sus dimensiones son de 9x9.
 *
 * @author Claudia Salado Méndez
 * @date October 2021
*/

class Tablero{
  private:
      Casilla tablero[9][9];
  public:

    /**
     * @brief Constructor sin parametros
     */
    Tablero();

    /**
     * @brief Destructor
     */
    ~ Tablero();

    /**
     * @brief Devuelve la casilla correspondiente a la fil y col introducidas.
     * @param fil fila a la que donde esta situada la casilla
     * @param col columna donde esta situada la casillas
     * @pre fil > 0 && not Null
     * @pre col > 0 && not Null
     */
    Casilla getCasilla(int fil, int col);

    /**
     * @brief Devuelve true si todas las casillas de la fila de la matriz estan rellenas.
     * @param fila, fila a la que donde esta situada la casilla
     * @pre fila > 0 && not Null
     */
    bool filaCompleta(int fila);

    /**
     * @brief Devuelve true si todas las casillas de la columna de la matriz estan rellenas.
     * @param columna, columna a la que donde esta situada la casilla
     * @pre columna > 0 && not Null
     */
    bool columnaCompleta(int columna);

    /**
     * @brief Devuelve true si el cuadrante eal que pertenece la casilla esta completo.
     * un cuadrante es una submatrix 3*3, en el sudoku hay un total de 9 cuadrantes.
     * @param casilla, casilla de la que queremos saber si el cuadrante esta completo.
     * @pre casilla not Null
     */
    bool cuadranteCompleto(Casilla casilla);

    /**
     * @brief Devuelve la diferencia entre la suma de la pieza correspondiente y la suma de los valores de las casillas que la forman
     * si el resultado es cerro significa que esta relleno y son correctos los valores
     * @param columna, columna a la que donde esta situada la casilla
     * @param fila, fila a la que donde esta situada la casilla
     * @pre fila > 0 && not Null
     * @pre columna > 0 && not Null
     */
    int diferenciaSumas(int fila, int columna);

    /**
     * @brief Devuelve true si el resto de casillas que forman parte de la misma pieza que la casilla que hemos introducido tienen ya un valor asignado
     * @param columna, columna a la que donde esta situada la casilla
     * @param fila, fila a la que donde esta situada la casilla
     * @pre fila > 0 && not Null
     * @pre columna > 0 && not Null
     */
    bool piezaCompleta(int fila, int columna);

    /**
     * @brief Calcular el valor correspondiente de la casilla que hay en la pos fil y col.
     * @param columna, columna a la que donde esta situada la casilla
     * @param fila, fila a la que donde esta situada la casilla
     * @pre fila > 0 && not Null
     * @pre columna > 0 && not Null
     * @pos valor > 0
     */
    int calcularValorCasilla(int fila, int columna);

    /**
     * @brief le da un valor a la casilla de la columna y de la fila especificadas
     * @param columna, columna a la que donde esta situada la casilla
     * @param fila, fila a la que donde esta situada la casilla
     * @param valor, numero que le asignamos a la casilla
     * @pre fila > 0 && not Null
     * @pre columna > 0 && not Null
     * @pre valor >= 0;
     */
    void rellenarCasilla(int fila, int columna, int valor);

    /**
     * @brief Muestra el tablero 
     */
    void mostrarTablero();
}
