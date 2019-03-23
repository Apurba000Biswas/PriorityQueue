// This is a .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include "ArrayPriorityQueue.h"

ArrayPriorityQueue::ArrayPriorityQueue() {
    // TODO: implement
    array[10] = new PQEntry[10];
    pqSize = 0;
}

ArrayPriorityQueue::~ArrayPriorityQueue() {
    // TODO: implement

}

void ArrayPriorityQueue::changePriority(string value, int newPriority) {
    // TODO: implement

}

void ArrayPriorityQueue::clear() {
    // TODO: implement

}

string ArrayPriorityQueue::dequeue() {
    PQEntry* desiredEntry = nullptr;
    int lowestPriority = 10000;
    int index = 0;
    for(int i=0 ; i< pqSize; i++){
        if(lowestPriority > array[i]->priority){
            desiredEntry = array[i];
            lowestPriority = array[i]->priority;
            index = i;
        }
    }
    if(desiredEntry == nullptr) throw ("string exception");
    array[index] = array[pqSize-1]; // move the last value
    array[pqSize-1] = nullptr;
    pqSize--;
    return desiredEntry->value;
}

void ArrayPriorityQueue::enqueue(string value, int priority) {
    // TODO: implement
    PQEntry* newEntry = new PQEntry(value, priority);
    array[pqSize] = newEntry;
    pqSize++;
}

bool ArrayPriorityQueue::isEmpty() const {
    return (pqSize == 0);
}

string ArrayPriorityQueue::peek() const {
    // TODO: implement
    return "";   // remove this
}

int ArrayPriorityQueue::peekPriority() const {
    // TODO: implement
    return 0;   // remove this
}

int ArrayPriorityQueue::size() const {
    return pqSize;
}

//{"t":2 , "b":4, "m":5, "q":5, "x":5, "a":8}
string ArrayPriorityQueue::toString() const{
    string out = "{";
    for(int i=0; i<pqSize; i++){
        PQEntry* cur = array[i];
        out = out + "\"" + cur->value + "\":" + to_string(cur->priority);
        if( i != pqSize-1){
            out = out + ", ";
        }
    }
    out = out + "}";
    return out;
}

ostream& operator<<(ostream& out, const ArrayPriorityQueue& queue) {
    out << queue.toString();
    return out;
}
