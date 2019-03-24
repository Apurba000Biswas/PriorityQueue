

#include "ArrayPriorityQueue.h"

ArrayPriorityQueue::ArrayPriorityQueue() {
    array[10] = new PQEntry[10];
    pqSize = 0;
}

ArrayPriorityQueue::~ArrayPriorityQueue() {
    for(int i=0; i<pqSize; i++){
        delete array[i];
    }
}

void ArrayPriorityQueue::changePriority(string value, int newPriority) { // complexity - O(n)
    int index = getIndex(value);
    PQEntry* entry = array[index];
    if(index == -1 || entry->priority < newPriority) throw ("Priority Queue is empty");
    entry->priority = newPriority;
}

int ArrayPriorityQueue::getIndex(string value) const {
    int index = -1;
    for(int i=0; i<pqSize; i++){
        if(array[i]->value == value){
            index = i;
            break;
        }
    }
    return index;
}

void ArrayPriorityQueue::clear() { // complexity - O(n)
    for(int i=0; i<pqSize; i++){
        array[i] = nullptr;
    }
    pqSize = 0;
}

string ArrayPriorityQueue::dequeue() { // complexity - O(n)
    int index = getHigherEntryIndex();
    if(index == -1) throw ("Priority Queue is empty");
    PQEntry* desiredEntry = array[index];
    array[index] = array[pqSize-1]; // move the last value
    array[pqSize-1] = nullptr; // cut the last value
    pqSize--;
    return desiredEntry->value;
}

int ArrayPriorityQueue::getHigherEntryIndex() const{ // complexity - O(n)
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

void ArrayPriorityQueue::enqueue(string value, int priority) { // complexity - O(1)
    PQEntry* newEntry = new PQEntry(value, priority);
    array[pqSize] = newEntry;
    pqSize++;
}

bool ArrayPriorityQueue::isEmpty() const { // complexity - O(1)
    return (pqSize == 0);
}

string ArrayPriorityQueue::peek() const { // complexity - O(n)
    int index = getHigherEntryIndex();
    if(index == -1) throw ("Priority Queue is empty");
    return array[index]->value;
}

int ArrayPriorityQueue::peekPriority() const { // complexity - O(n)
    int index = getHigherEntryIndex();
    if(index == -1) throw ("Priority Queue is empty");
    return array[index]->priority;
}

int ArrayPriorityQueue::size() const { // complexity - O(n)
    return pqSize;
}

//{"t":2 , "b":4, "m":5, "q":5, "x":5, "a":8}
string ArrayPriorityQueue::toString() const{ // complexity - O(n)
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
