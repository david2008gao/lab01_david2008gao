// intlist.cpp
// Implements class IntList
// David Gao 10/8/2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
    head = nullptr;
    Node* n = source.head;
    while (n){
        (*this).push_back(n -> info);
        n = n -> next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
    Node* n = head;
    while (n){
        Node* nextNode = n -> next;
        delete n;
        n = nextNode;
    }
    head = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    int total = 0;
    Node *n = head;
    while (n){
        total += n-> info;
        n = n -> next;
    }
    return total; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    bool found = false;
    Node* n = head;
    while (n){
        if (n -> info == value){
            found = true;
            return found;
        }
        n = n -> next;
    }
    return found; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max = 0;
    Node* n = head;
    while (n){
        if (n -> info > max){
            max = n -> info;
        }
        n = n -> next;
    }
    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (count() == 0) { 
        return 0.0;
    }
    return sum() / count(); // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    // IMPLEMENT
    Node* n = new Node();
    n->info = value;
    n->next = head;
    head = n;
}

// append value at end of list
void IntList::push_back(int value) {
    // IMPLEMENT
    Node* n = head;
    Node* m = new Node();
    m->info = value;
    m->next = nullptr;
    if (head == nullptr){
        head = m;
        return;
    }
    while (n->next != nullptr){
        n = n->next;
    }
    n -> next = m;
}

// return count of values
int IntList::count() const {
   //IMPLEMENT THIS
   int count = 0;
   Node *n = head;
   while (n) {
       count++;
       n = n->next;
   }
   return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    Node* m = head;
    while (m){
        Node* nextNode = m -> next;
        delete m;
        m = nextNode;
    }
    head = nullptr;
    //IMPLEMENT
    Node* n = source.head;
    while (n){
        (*this).push_back(n -> info);
        n = n -> next;
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    //IMPLEMENT THIS 
    head = nullptr;
}

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

