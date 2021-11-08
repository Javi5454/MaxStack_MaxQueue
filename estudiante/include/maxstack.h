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
 * @param os Flujo de salida
 * @param e Element a mostrar
 * @return El os de salida
 */
ostream & operator<<(ostream &os, const element &e);

/**
 * @brief T.D.A MaxStack
 *
 * Una instancia del tipo de dato abstracto MaxStack nos permite usar una
 * cola de la misma manera que usamos una pila
 *
 * El TDA MaxStack proporciona distintos métodos para insertar, eliminar o
 * consultar elementos de la pila obteniendo siempre el máximo elemento
 * almacenado
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
     * @page repMaxStack Representación del TDA MaxStack.
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

public:

    /**
     * @brief Constructor por defecto
     */
    MaxStack();

    /**
     * @brief Constructor por copia
     * @param copy La pila que se copiará
     */
    MaxStack(const MaxStack &copy);

    /**
     * @brief El tamaño de la estructura en función de el número de datos
     * @return Un entero que representa el número de datos
     */
    int size() const;
    
    /**
     * @brief Checkea el máximo en la pila
     * @param to_check El elemento que se desea consultar para ver si es
     * el máximo o no
     * @return El máximo a almacenar
     */
    int getMax(int to_check);

    /**
     * @brief Indica si la pila está vacía
     * @return True si está vacía, False si no.
     */
    bool is_empty();

    /**
     * @brief Devuelve el último elemento insertado en la pila
     * @return Devuele un element
     */
    element top();

    /**
     * @brief Devuelve el último elemento insertado en la pila de tipo
     * constante
     * @return Devuele un element
     */
    const element top() const;

    /**
     * @brief Elimina el último elemento insertado en la pila
     * @post Debido a la implementación usada, no es necesario realizar
     * un nuevo cáclulo del máximo de la pila
     * @post El objeto implicito ha sido modificado
     * @post El tamaño del MaxStack decrementa en 1
     */
    void pop();

    /**
     * @brief Introduce un elemento en la pila
     * @param to_insert number to insert
     * @post La pila contendrá al nuevo elemento
     * @post El objeto implítico ha sido modificado
     * @post El tamaño del MaxStack aumenta en 1
     */
    void push(int to_insert);

};

#endif // _MAX_STACK_