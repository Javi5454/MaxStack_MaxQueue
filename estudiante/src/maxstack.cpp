/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author
 */

#include "maxstack.h"

ostream & operator<<(ostream &flujo, const element &e){
    flujo << e.value << " | " << e.maximum << endl;

    return flujo;
}

int MaxStack::getMax(int to_check) {
    if(to_check > top().maximum){
        return to_check;
    }
    else{
        return top().maximum;
    }
}

element MaxStack::top() {
    return max_stack.back();
}

void MaxStack::pop() {
    queue<element> aux1;

    for (int i = 0; i < max_stack.size(); ++i) {
        aux1.push(max_stack.front());
        max_stack.pop();
    }

    aux1.pop();

    for (int i = 0; i < aux1.size(); ++i) {
        max_stack.push(aux1.front());
        aux1.pop();
    }
}