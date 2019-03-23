// This is a .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include "ArrayPriorityQueue.h"

ArrayPriorityQueue::ArrayPriorityQueue() {
    array[10] = new PQEntry[10];
    pqSize = 0;
}

ArrayPriorityQueue::~ArrayPriorityQueue() {
    // TODO: implement
    //delete[] array;

}

void ArrayPriorityQueue::changePriority(string value, int newPriority) {
    // TODO: implement

}

void ArrayPriorityQueue::clear() {
    // TODO: implement

}

string ArrayPriorityQueue::dequeue() {
    int index = getHigherEntryIndex();
    if(index == -1) throw ("string exception - empty queue");
    PQEntry* desiredEntry = array[index];
    array[index] = array[pqSize-1]; // move the last value
    array[pqSize-1] = nullptr; // cut the last value
    pqSize--;
    return desiredEntry->value;
}

int ArrayPriorityQueue::getHigherEntryIndex() const{
    int lowestPriority = 10000;
    int index = -1;
    for(int i=0 ; i< pqSize; i++){
        if(lowestPriority > array[i]->priority){
            lowestPriority = array[i]->priority;
            index = i;
        }
    }
    return index;
}

void ArrayPriorityQueue::enqueue(string value, int priority) {
    PQEntry* newEntry = new PQEntry(value, priority);
    array[pqSize] = newEntry;
    pqSize++;
}

bool ArrayPriorityQueue::isEmpty() const {
    return (pqSize == 0);
}

string ArrayPriorityQueue::peek() const {
    int index = getHigherEntryIndex();
    if(index == -1) throw ("string exception - empty queue");
    return array[index]->value;
}

int ArrayPriorityQueue::peekPriority() const {
    int index = getHigherEntryIndex();
    if(index == -1) throw ("string exception - empty queue");
    return array[index]->priority;
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
