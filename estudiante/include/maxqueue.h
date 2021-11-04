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
 * @param flujo Flujo de salida
 * @param e Element a mostrar
 * @return El flujo de salida
 */
ostream & operator<<(ostream &flujo, const element &e);

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
     * @page repMaxQueue Representación del TDA Sudoku Killer.
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
    stack<element> max_queue;

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
     * @brief Checkea el máximo en la cola
     * @return El máximo a almacenar
     */
    int getMax(int to_check);

    /**
     * @brief Indica si la cola está vacía
     * @return True si está vacía, False si no.
     */
    bool is_empty();

    element front();

    element front() const;

    element back();

    const element back() const;

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