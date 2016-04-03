#include "container.h"

/* IMPLEMENTATION OF CONTAINER */

Container::Container() : first(0), last(0) {}

void Container::insertHead(Article* a) {
    if(first) {
        first = new Node(a, first);
    }
    else { // empty list
        first = new Node(a,0);
        last = first;
    }
}

void Container::insertBack(Article* a) {
    if(first) {
        Node* p = new Node(a,0);
        last->next = p;
        last = p;
    }
    else { // empty list
        first = new Node(a,0);
        last = first;
    }
}

void Container::removeHead() {
    if(!first)
        qDebug() << "List is Empty";
    else {
        Node * temp = first;
        first = first->next;
        temp->next = 0;
        delete temp;
    }
}

bool Container::isEmpty() const { return first==0; }

Container::Iterator Container::begin() const {
    Iterator aux;
    aux.ptr = first; //friend
    return aux;
}

Container::Iterator Container::end() const {
    Iterator aux;
    aux.ptr = 0; // friend
    return aux;
}

Article* Container::operator [](Container::Iterator it) const {
    return it.ptr->info; // friend
}

/* IMPLEMENTATION OF NODE */

Container::Node::Node(Article* i, Node* n) : info(i), next(n) {}

Container::Node::~Node() { if (next) delete next; }

/* IMPLEMENTATION OF ITERATOR */

bool Container::Iterator::operator ==(const Iterator& i) const { return ptr == i.ptr; }

bool Container::Iterator::operator !=(const Iterator& i) const { return ptr != i.ptr; }

Container::Iterator& Container::Iterator::operator++() { if(ptr) ptr = ptr->next; return *this; }

Container::Iterator Container::Iterator::operator++(int) { Iterator aux = *this; if(ptr) ptr = ptr->next; return aux; }
