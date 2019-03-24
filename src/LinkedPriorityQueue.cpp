
#include "LinkedPriorityQueue.h"

LinkedPriorityQueue::LinkedPriorityQueue() {
    front = nullptr;
}

LinkedPriorityQueue::~LinkedPriorityQueue() {
    if(front != nullptr)removeAllNodes();
    delete front;
}

void LinkedPriorityQueue::changePriority(string value, int newPriority) {
    if(front == nullptr) throw ("Priority Queue is empty");
    ListNode* current = front;
    ListNode* previous = nullptr;
    while (true) {
        if(current->value == value){
            cout << "Ok Found" << endl;
            if(current->priority < newPriority) throw ("new priority cannot be greater than old priority");
            if(previous != nullptr){
                previous->next = current->next;
            }else{
                front = current->next;
            }
            enqueue(value, newPriority);
            delete current;
            break;
        }
        previous = current;
        if(current->next == nullptr) throw ("The given value is not found in this priority queue");
        current = current->next;
    }
}

void LinkedPriorityQueue::clear() {
    if(front != nullptr){
        removeAllNodes();
        front = nullptr;
    }
}

void LinkedPriorityQueue::removeAllNodes(){
    ListNode* current = front;
    while(current->next != nullptr){
        ListNode* toClearNode = current;
        current = current->next;
        delete toClearNode;
    }
    delete current;
}

string LinkedPriorityQueue::dequeue() {
    if(front == nullptr) throw ("Priority Queue is empty");
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
    if(front == nullptr) throw ("Priority Queue is empty");
    return front->value;
}

int LinkedPriorityQueue::peekPriority() const {
    if(front == nullptr) throw ("Priority Queue is empty");
    return front->priority;
}

int LinkedPriorityQueue::size() const {
    if(front == nullptr) return 0;
    ListNode* current = front;
    int size = 0;
    while (current->next != nullptr) {
        size ++;
        current = current->next;
    }
    size ++;
    return size;
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
