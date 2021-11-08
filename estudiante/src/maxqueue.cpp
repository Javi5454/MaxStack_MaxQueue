/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author
 */

#include "maxqueue.h"

ostream & operator<<(ostream &os, const element &e){
    os << e.value << "," << e.maximum;

    return os;
}

int MaxQueue::size(){
    return _stack.size();
}

MaxQueue::MaxQueue() {
    _stack;
}

MaxQueue::MaxQueue(const MaxQueue &copy) {
    _stack = copy._stack;
}

MaxQueue &MaxQueue::operator=(const MaxQueue &copy) {
    if (&copy != this)
        _stack = copy._stack;

    return *this;
}

int MaxQueue::getMax(int to_check) {
    if(to_check > front().maximum)
        return to_check;
    else
        return front().maximum;
}

bool MaxQueue::is_empty() {
    return _stack.empty();
}

element MaxQueue::front() {
    if(_stack.empty()){
        element empty = {0,0};
        return empty;
    }
    else {
        return _stack.top();
    }
}

void MaxQueue::pop() {
    _stack.pop();
}

void MaxQueue::push(int to_insert) {

    element e_to_insert{};
    e_to_insert.value = to_insert;
    e_to_insert.maximum = to_insert;

    stack<element> aux;

    while (!is_empty()){
        aux.push({front().value, getMax(to_insert)});
        _stack.pop();
    }

    aux.push(e_to_insert);

    while (!aux.empty()){
        _stack.push(aux.top());
        aux.pop();
    }
}
