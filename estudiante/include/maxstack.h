/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author Adrián Jaén
 * @author Javier Gómez
 */

#ifndef _MAXSTACK_H_
#define _MAXSTACK_H_

#include <queue>
#include <iostream>

using namespace std;

/**
 * @brief Struct que representa cada elemento de la pila
 * @var value Valor que se almacena
 * @var Valor máximo de la pila en el momento de la inserción
 */
struct element{
    int value; //Current value to store
    int maximum; //Current max value in the structure
};

/**
 * @brief Sobrecarga de operador << para el struct element
 * @param flujo Flujo de salida
 * @param e Element a mostrar
 * @return El flujo de salida
 */
ostream & operator<<(ostream &flujo, const element &e);

/**
 * @brief T.D.A MaxStack
 *
 * Una instancia del tipo de dato abstracto MaxStack nos permite usar una
 * cola de la misma manera que usamos una pila
 *
 * Para poder usar el TDA MaxStack se debe incluir el fichero
 *
 * \#include <maxstack.h>
 *
 * @author Adrián Jaén
 * @author Javier Gómez
 * @date Noviembre 2021
 */
class MaxStack{
    /**
     * @page repMaxStack Representación del TDA Sudoku Killer.
     *
     * @section invMaxStack Invariante de la representación.
     *
     * En nuestra MaxStack, se usará una cola basada en la filosofia
     * LIFO (Last in First out) en lugar de una FIFO (First in First out)
     *
     * @section faMaxStack Función de abstración
     *
     * fa: tipo_rep ----> MaxStack
     *     queue<int> ----> max_stack
     *
     *     La estructura queue<int> representa a la MaxStack
     */

private:
    /**
     * @brief Cola formada por datos de tipo element
     */
    queue<element> max_stack;

    /**
     * @brief Checkea el máximo en la pila teniendo en cuenta un elemento
     * a insertar
     * @param to_check Número que se quiere insertar
     * @return El máximo a almacenar
     */
    int getMax(int to_check);

public:
    /**
     * @brief Devuelve el último elemento insertado en la pila
     * @return Devuele un element
     */
    element top();

    /**
     * @brief Elimina el último elemento insertado en la pila
     */
    void pop();

    /**
     * @brief Introduce un elemento en la pila
     * @param to_insert
     */
    void push(int to_insert);
};

#endif // _MAX_STACK_