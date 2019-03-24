// This is a .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include "LinkedPriorityQueue.h"

LinkedPriorityQueue::LinkedPriorityQueue() {
    // TODO: implement
    front = nullptr;
}

LinkedPriorityQueue::~LinkedPriorityQueue() {
    // TODO: implement

}

void LinkedPriorityQueue::changePriority(string value, int newPriority) {
    // TODO: implement

}

void LinkedPriorityQueue::clear() {
    // TODO: implement

}

string LinkedPriorityQueue::dequeue() {
    if(front == nullptr) throw ("string exception");
    ListNode* data = front;
    front = front->next;
    string value = data->value;
    delete data;
    return value;
}

void LinkedPriorityQueue::enqueue(string value, int priority) {
    if(isEmpty()){
        front = new ListNode(value, priority, nullptr);
    }else{
        ListNode* current = front;
        ListNode* previuos = nullptr;
        ListNode* newNode = new ListNode(value, priority, nullptr);

        while (*current <= *newNode) {
            if(current->next == nullptr){
                break;
            }
            previuos = current;
            current = current->next;
        }
        if(*newNode < *current){
            // insert it before current
            newNode->next = current;
            if(previuos != nullptr){
                previuos->next = newNode;
            }else{
                front = newNode;
            }
         } else {
            // insert it after current
            newNode->next = current->next;
            current->next = newNode;
         }
    }
}

bool LinkedPriorityQueue::isEmpty() const {
    return (front == nullptr);
}

string LinkedPriorityQueue::peek() const {
    // TODO: implement
    return "";   // remove this
}

int LinkedPriorityQueue::peekPriority() const {
    // TODO: implement
    return 0;   // remove this
}

int LinkedPriorityQueue::size() const {
    // TODO: implement
    return 0;   // remove this
}

// {"t":2 , "b":4, "m":5, "q":5, "x":5, "a":8}
string LinkedPriorityQueue::toString() const {
    ListNode* current = front;
    string out = "{";
    while (front != nullptr) {
        out = out + "\"" + current->value + "\":" + to_string(current->priority);
        if(current->next == nullptr)break;
        out = out + ", ";
        current = current->next;
    }
    return out + "}";
}

ostream& operator<<(ostream& out, const LinkedPriorityQueue& queue) {
    out << queue.toString();
    return out;
}
