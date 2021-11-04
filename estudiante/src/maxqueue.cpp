/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author
 */

#include "maxqueue.h"

ostream & operator<<(ostream &flujo, const element &e){
    flujo << e.value << " | " << e.maximum << endl;

    return flujo;
}


MaxQueue::MaxQueue() {
    max_queue;
}

MaxQueue::MaxQueue(const MaxQueue &copy) {
    max_queue = copy.max_queue;
}

MaxQueue &MaxQueue::operator=(const MaxQueue &copy) {
    if (&copy != this)
        max_queue = copy.max_queue;

    return *this;
}

int MaxQueue::getMax(int to_check) {
    if(to_check > front().maximum){
        return to_check;
    }
    else{
        return front().maximum;
    }
}

bool MaxQueue::is_empty() {
    return max_queue.empty();
}

element MaxQueue::front() {
    if(max_queue.empty()){
        element empty = {0,0};

        return empty;
    }
    else {
        return max_queue.top();;
    }
}

element MaxQueue::front() const {
    return max_queue.top();
}

element MaxQueue::back() {

}

const element MaxQueue::back() const {

}

void MaxQueue::pop() {

}

void MaxQueue::push(int to_insert) {

}
