/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author Adrián Jaén
 * @author Javier Gómez
 */

#ifndef _MAXQUEUE_H_
#define _MAXQUEUE_H_

#include <stack>
#include <iostream>

using namespace std;

/**
 * @brief Struct que representa cada elemento de la cola
 * @var value Valor que se almacena
 * @var Valor máximo de la cola en el momento de la inserción
 */

struct element{
    int value; //Current value to store
    int maximum; //Current max value in the structure
};

/**
 * @brief Sobrecarga de operador << para el struct element
 * @param os Flujo de salida
 * @param e Element a mostrar
 * @return El os de salida
 */
ostream & operator<<(ostream &os, const element &e);

/**
 * @brief T.D.A MaxQueue
 *
 * Una instancia del tipo de dato abstracto MaxStack nos permite usar una
 * pila de la misma manera que usamos una cola
 *
 * Para poder usar el TDA MaxStack se debe incluir el fichero
 *
 * \#include <maxstack.h>
 *
 * @author Adrián Jaén
 * @author Javier Gómez
 * @date Noviembre 2021
 */

class MaxQueue{
    /**
     * @page repMaxQueue Representación del TDA MaxQueue.
     *
     * @section invMaxStack Invariante de la representación.
     *
     * En nuestra MaxQueue, se usará una pila basada en la filosofia
     * FIFO (First in First out) en lugar de una LIFO (Last in First out)
     *
     * @section faMaxQueue Función de abstración
     *
     * fa: tipo_rep ----> MaxQueue
     *     stack<int> ----> _stack
     *
     *     La estructura stack<int> representa a la MaxStack
     */

private:
    /**
     * @brief Pila formada por datos de tipo element
     */
    stack<element> _stack;

public:

    /**
     * @brief Constructor por defecto
     */
    MaxQueue();

    /**
     * @brief Constructor por copia
     * @param copy La cola que se copiará
     */
    MaxQueue(const MaxQueue &copy);

    /**
     * @brief Sobrecarga del operador de asignacion
     * @param copy cola a copiar
     * @return Referencia al elemento donde se copia
     */
    MaxQueue& operator= (const MaxQueue &copy);

    /**
     * @brief El número de elementos de la cola
     * @return Un entero
     */
    int size();

    /**
     * @brief Checkea el máximo en la cola
     * @return El máximo a almacenar
     */
    int getMax(int to_check);

    /**
     * @brief Indica si la cola está vacía
     * @return True si está vacía, False si no.
     */
    bool is_empty();

    /**
     * @brief Devuelve el último elemento insertado en la cola
     * @return Devuele un element
     */
    element front();

    /**
     * @brief Elimina el primer elemento en la cola
     */
    void pop();

    /**
     * @brief Introduce un elemento en la cola
     * @param to_insert number to insert
     */
    void push(int to_insert);
};


#endif // _MAXQUEUE_H_