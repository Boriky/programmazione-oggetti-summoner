#ifndef CONTAINER_H
#define CONTAINER_H

#include "article.h"
#include "QDebug"

class Container {
    friend class Iterator;
private:
    class Node {
    public:
        Article* info;
        Node* next;
        Node(Article* i, Node* n);
        ~Node();
    };

    Node* first;
    Node* last;
public:
    Container();
    void insertHead(Article*);
    void insertBack(Article*);
    void removeHead();
    bool isEmpty() const;

    class Iterator {
        friend class Container;
    public:
        bool operator==(const Iterator& i) const;
        bool operator!=(const Iterator& i) const;
        Iterator& operator++();
        Iterator operator++(int);
    private:
        Container::Node* ptr; // node pointed by iterator
    };
    // ATTENTION: the declariation of class Iterator must preceed the declaration of the methods
    //            that are going to use the Iterator type in their signature.

    Iterator begin() const;
    Iterator end() const;
    Article* operator [](Iterator) const;
};

#endif // CONTAINER_H
