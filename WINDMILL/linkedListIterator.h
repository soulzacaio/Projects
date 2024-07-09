#ifndef ITERATOR_H
#define ITERATOR_H

template <class t>
struct doubly
{
	t *data;
	doubly<t> *next;
	doubly<t> *prev;
	~doubly()
	{
		delete data;
	}
};

template <class t>
class linkedListIterator
{
public:
	linkedListIterator();
	//Default constructor //Postcondition: current = nullptr;
	linkedListIterator(doubly<t> *ptr);
	//Constructor with a parameter. //Postcondition: current = ptr;
	t operator*(); //Function to overload the dereferencing operator *. //Postcondition: Returns the data contained in the doubly.
	linkedListIterator<t> operator++(); //Overload the pre-increment operator. //Postcondition: The iterator is advanced to the next //	doubly.
	linkedListIterator<t> operator--();
	bool operator==(const linkedListIterator<t> &right) const; //Overload the equality operator. //Postcondition: Returns true if this iterator is equal to //	the iterator specified by right,
	//	otherwise it returns false.
	bool operator!=(const linkedListIterator<t> &right) const; //Overload the not equal to operator. //Postcondition: Returns true if this iterator is not equal //	to the iterator specified by right,
	//	otherwise it returns false.
private:
	doubly<t> *current; //pointer to point to the current
	//doubly in the linked list
};

template <class t>
linkedListIterator<t>::linkedListIterator()
{
	current = nullptr;
}

template <class t>
linkedListIterator<t>::linkedListIterator(doubly<t> *ptr)
{
	current = ptr;
}

template <class t>
t linkedListIterator<t>::operator*()
{
	return *current->data;
}

template <class t>
linkedListIterator<t> linkedListIterator<t>::operator++()
{
	current = current->next;
	return *this;
}

template<class t>
bool linkedListIterator<t>::operator==(const linkedListIterator<t> &right) const
{
	return (current == right.current);
}

template <class t>
bool linkedListIterator<t>::operator!=(const linkedListIterator<t> &right) const
{
	return (current != right.current);
}



template<class t>
linkedListIterator<t> linkedListIterator<t>::operator--()
{
	current = current->prev;
	return *this;
}

#endif