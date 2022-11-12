/* 
 * PriorityQueue.h
 *
 * Description: Priority Queue ADT class.
 *
 * 
 * Author: Duc Manh To
 * Last Modification: November 2022
 *
 */  

#include "PriorityQueue.h"

// Description: Default constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(){
    elements = new BinaryHeap<ElementType>();
}

// Description: Destructor
template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue(){
    delete elements;
}

// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const{
    // if new failed in constructor
    if (elements == nullptr)
        return true;
    return elements->getElementCount() == 0;
}

// Description: Inserts newElement in this Priority Queue and 
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType & newElement){
    bool enqueued = true;
    // if new failed in constructor, try again
    if (elements == nullptr) 
        enqueued = false;
    if (enqueued)
        enqueued = elements->insert(newElement);
    return enqueued;
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void PriorityQueue<ElementType>::dequeue(){
    // Check if the Priority queue is empty
    if (elements == nullptr)
        throw EmptyDataCollectionException("");
    elements->remove();
    return;
}

// Description: Returns (but does not remove) the element with the next 
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType & PriorityQueue<ElementType>::peek() const{
    // check if the Priority Queue is empty
    if (elements == nullptr)
        throw EmptyDataCollectionException("");
    return elements->retrieve();
}