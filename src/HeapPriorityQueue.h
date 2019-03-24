
#ifndef _heappriorityqueue_h
#define _heappriorityqueue_h

#include <iostream>
#include <string>
#include "PQEntry.h"
using namespace std;

class HeapPriorityQueue {
public:
    HeapPriorityQueue();
    ~HeapPriorityQueue();
    void changePriority(string value, int newPriority); // Complexity - O(n + log(n))
    void clear(); // Complexity - O(n)
    string dequeue(); // Complexity - O(log(n))
    void enqueue(string value, int priority); // Complexity - O(log(n))
    bool isEmpty() const; // Complexity - O(1)
    string peek() const; // Complexity - O(1)
    int peekPriority() const; // Complexity - O(1)
    int size() const; // // Complexity - O(1)
    friend ostream& operator <<(ostream& out, const HeapPriorityQueue& queue);

private:
    PQEntry* array[10];
    int length;
    string toString() const;
    void bubbleUp(int index);
    void bubbleDown();
    int getSmallestChildIndex(int parentIndex) const;
};

#endif
