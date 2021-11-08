/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author
 */

#include "maxstack.h"

ostream & operator<<(ostream &flujo, const element &e){
    flujo << e.value << "," << e.maximum;

    return flujo;
}

MaxStack::MaxStack() {
    max_stack;
}

MaxStack::MaxStack(const MaxStack &copy) {
    max_stack = (copy.max_stack);
}

int MaxStack::getMax(int to_check) {
    if(size() != 0){
        if (top().maximum >= to_check){
            return top().maximum;
        }
        else{
            return to_check;
        }
    }
    else{
        return to_check;
    }
}

int MaxStack::size() const {
    return max_stack.size();
}

element MaxStack::top() {
    if(max_stack.empty()){
        element empty = {0,0};
        return empty;
    }
    else{
        return max_stack.front();
    }
}

const element MaxStack::top() const{
    return max_stack.front();
}

void MaxStack::pop() {
    max_stack.pop();
}

void MaxStack::push(int to_insert) {
    element pair_to_insert;

    pair_to_insert.value = to_insert;

    if(getMax(to_insert) == to_insert){
        pair_to_insert.maximum = to_insert;
    }
    else{
        pair_to_insert.maximum = top().maximum;
    }

    queue<element> aux;
    aux.push(pair_to_insert);

    while(!is_empty()){
        aux.push(max_stack.front());
        pop();
    }

    while(!aux.empty()){
        max_stack.push(aux.front());
        aux.pop();
    }
}

bool MaxStack::is_empty(){
    return max_stack.empty();
}