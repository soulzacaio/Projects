#ifndef WASTE_H
#define WASTE_H
#include <stdexcept>
#include <string>
#include <sstream>
#include "linkedListIterator.h"



template <class t>
class waste
{
public:
    waste();
    waste(const waste<t> &otherList);
    void insert(const t &newInfo);

    ~waste();
    void initialize();
    bool isEmpty() const;
    std::string print() const;
    int length() const;
    void destroy();
    // t *front() const;
    t getTopCard() const;
    void operator--();
    linkedListIterator<t> begin();
    linkedListIterator<t> end();//returns tail, not null

    //!think i might need a -- operator here to play from waste, also need overload in the classes

protected:
    doubly<t> *head;
    doubly<t> *tail;
    int count;
private:
};
template<class t>
bool waste<t>::isEmpty() const
{
    return (head == nullptr);
}

template <class t>
waste<t>::waste()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template <class t>
void waste<t>::destroy()
{
    doubly<t> *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    count = 0;
}

template <class t>
void waste<t>::initialize()
{
    destroy();
}

template<class t>
std::string waste<t>::print() const
{
    std::ostringstream out;
    doubly<t> *current;
    current = head;
    while (current != nullptr)
    {
        out << *(current->data) << " ";
        current = current->next;
    }
    return out.str();
}

template <class t>
int waste<t>::length() const
{
    return count;
}

template <class t>
t waste<t>::getTopCard() const
{
    if (this->isEmpty())
        throw std::out_of_range("Cannot get last item of an empty list");
    return *tail->data;
}

template<class t>
void waste<t>::operator--()
{
    if (this->isEmpty())
        throw std::out_of_range("Cannot get last item of an empty list operator--Waste");


    if (count == 1)
        destroy();

    else
    {
        //?NOT WORKING PROPERLY
        doubly<t> *temp = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = nullptr;

        delete temp;
        count--;
    }
}

template <class t>
linkedListIterator<t> waste<t>::begin()
{
    linkedListIterator<t> temp(head);
    return temp;
}

template <class t>
linkedListIterator<t> waste<t>::end()
{
    linkedListIterator<t> temp(tail);
    return temp;
}


template <class t>
waste<t>::~waste()
{
    destroy();
}



template <class t>
waste<t>::waste(const waste<t> &otherList)
{
    head = nullptr;
    copyList(otherList);
}

template <class t>
void waste<t>::insert(const t &newItem)
{
    doubly<t> *newNode;
    newNode = new doubly<t>;
    newNode->data = new t(newItem);
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (this->isEmpty())
    {
        this->head = newNode;
        this->tail = newNode;
        this->count++;
    }
    else
    {
        this->tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = newNode;
        this->count++;
    }
}


#endif
