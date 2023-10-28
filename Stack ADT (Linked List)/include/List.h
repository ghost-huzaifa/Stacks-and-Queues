//List.h

#ifndef LIST_H
#define LIST_H

// Node Structure
template <class T>
struct Node{
	public:
		T data;
		Node* next;
};

template <class T>
// List Class Declaration
class List
{
    public:
        // constructor
        List();
        // destructor
        virtual ~List();
        // copy constructor
        List(const List& other);

        // boolean function
        bool empty() const;
        // access functions
        T headElement() const;
        // add to the head
        void addHead(T newdata);
        // delete the head
        void delHead();

        // utility function to get length of list
        int length() const;
        // display the list
        void print() const;

    private:
        Node<T>* head;
};

#endif // LIST_H
