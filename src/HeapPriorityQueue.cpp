// This is a .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include "HeapPriorityQueue.h"

// constructor
HeapPriorityQueue::HeapPriorityQueue() {
    array[10] = new PQEntry[10];
    length = 0;
}

HeapPriorityQueue::~HeapPriorityQueue() {
    // TODO: implement

}

void HeapPriorityQueue::changePriority(string value, int newPriority) {
    // TODO: implement

}

void HeapPriorityQueue::clear() {
    // TODO: implement

}

string HeapPriorityQueue::dequeue() {
    // TODO: implement
    return "";   // remove this
}

void HeapPriorityQueue::enqueue(string value, int priority) {
    PQEntry* entry = new PQEntry(value, priority);
    length++;
    array[length] = entry;
    if(length > 1){
        bubbleUp();
    }
}

// this method will always bubble the last element until its in order
void HeapPriorityQueue::bubbleUp(){
    int childIndex = length;
    int parentIndex = length/2;

    PQEntry parentData = *array[parentIndex];
    PQEntry ChildData = *array[childIndex];
    while(parentData > ChildData){
        // swap it
        PQEntry* parentDataPointer = array[parentIndex];
        PQEntry* childDataPointer = array[childIndex];
        array[childIndex] = parentDataPointer;
        array[parentIndex] = childDataPointer;

        childIndex = parentIndex;
        parentIndex = childIndex/2;

        if(parentIndex <= 0 || childIndex <= 0) break;

        parentData = *array[parentIndex];
        ChildData = *array[childIndex];
    }
}

bool HeapPriorityQueue::isEmpty() const {
    // TODO: implement
    return false;   // remove this
}

string HeapPriorityQueue::peek() const {
    // TODO: implement
    return "";   // remove this
}

int HeapPriorityQueue::peekPriority() const {
    // TODO: implement
    return 0;   // remove this
}

int HeapPriorityQueue::size() const {
    // TODO: implement
    return 0;   // remove this
}

//{"t":2 , "b":4, "m":5, "q":5, "x":5, "a":8}
string HeapPriorityQueue::toString() const{
    string out = "{";
    for (int i=1; i <=length; i++) {
        out = out + "\"" + array[i]->value + "\":" + to_string(array[i]->priority);
        if(i != length) out = out + ", ";
    }
    return out + "}";
}

ostream& operator<<(ostream& out, const HeapPriorityQueue& queue) {
    out << queue.toString();
    return out;
}
