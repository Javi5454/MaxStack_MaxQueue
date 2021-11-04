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

MaxStack::MaxStack() {
    max_stack;
}

MaxStack::MaxStack(const MaxStack &copy) {
    max_stack = (copy.max_stack);
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
    if(max_stack.empty()){
        element empty = {0,0};

        return empty;
    }
    else {
        return max_stack.front();;
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

    MaxStack aux(*this);
    max_stack.push(pair_to_insert);
    int num = max_stack.size() - 1;

    for (int i = 0; i < num; ++i) {
        max_stack.pop();
    }

    for (int i = 0; i < num; ++i) {
        max_stack.push(aux.top());
        aux.pop();
    }
}

bool MaxStack::is_empty(){
    return max_stack.empty();
}

MaxStack &MaxStack::operator=(const MaxStack &copy) {
    if(&copy != this){
        max_stack = copy.max_stack;
    }

    return *this;
}
