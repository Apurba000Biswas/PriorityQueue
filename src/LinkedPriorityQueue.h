// This is a .h file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#ifndef _linkedpriorityqueue_h
#define _linkedpriorityqueue_h

#include <cstddef>    // for NULL
#include <iostream>
#include <string>
#include "ListNode.h"
#include "PQEntry.h"
using namespace std;

/*
 * For documentation of each member, see VectorPriorityQueue.h.
 */
class LinkedPriorityQueue {
public:
    LinkedPriorityQueue();
    ~LinkedPriorityQueue();
    void changePriority(string value, int newPriority); // O(n2)
    void clear(); // O(n)
    string dequeue(); // O(1)
    void enqueue(string value, int priority); // O(n)
    bool isEmpty() const;// O(1)
    string peek() const; // O(1)
    int peekPriority() const; //O(1)
    int size() const; // O(n)
    friend ostream& operator <<(ostream& out, const LinkedPriorityQueue& queue);

private:
    // TODO: add any other member functions/variables necessary
    ListNode* front;
    string toString() const;
    void removeAllNodes();
};

#endif
