/* Queue.cpp
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Duc Manh To
 * Date: November 2022
 */
 
#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

// Description: Constructor
template <class ElementType>
Queue<ElementType>::Queue() 
{
    elements = NULL;
}

// Description: Destructor
template <class ElementType>
Queue<ElementType>::~Queue()
{
    delete[] elements;
    elements = nullptr;
    elementCount = 0;
    frontindex = 0;                  
    backindex = 0; 
}

// Description: Create a new array double the size of the previous
template <class ElementType>
bool Queue<ElementType>::expandQ(){

    // Copy elements into a new array
    ElementType* newElements = new ElementType[2*capacity];
    if (newElements == nullptr)
        return false;
    for (unsigned int i = 0; i < elementCount; i++)
    {
        newElements[i] = elements[(i+frontindex) % capacity];
    }

    // Set the parameters of the array
    frontindex = 0;
    backindex = elementCount;
    capacity *= 2;
    delete[] elements;
    elements = newElements;

    return true;
}

// Description: Create a new array half the size of the old one
template <class ElementType>
void Queue<ElementType>::shrinkQ(){
    // Copy elements into a smaller array
    ElementType* newArr = new ElementType[capacity / 2];
    for (unsigned int i = 0; i < elementCount; i++) 
    {
        newArr[i] = elements[(i+frontindex) % capacity];
    }

    // Set the parameters of teh array
    frontindex = 0;
    backindex = elementCount;
    capacity /= 2;
    delete[] elements;
    elements = newArr;

    return;
}

// Description: Inserts newElement at the "back" of this Queue 
//              (not necessarily the "back" of this Queue's data structure) 
//              and returns true if successful, otherwise false.
// Time Efficiency: O(1)}}
template <class ElementType>
bool Queue<ElementType>::enqueue(ElementType& newElement) {

    bool inserted = false;
    if (elements == nullptr) {
        elements = new ElementType[capacity];
        if (elements == nullptr) {
            return false;
        }
    }
    
    //Expand the Queue if needed
    if (elementCount >= capacity)
        if (expandQ())
            inserted = true;

    elementCount++;
    elements[backindex] = newElement;
    backindex = (backindex + 1) % capacity;   

    return inserted;
} 

// Description: Removes (but does not return) the element at the "front" of this Queue 
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
// Time Efficiency: O(1)
template <class ElementType>
void Queue<ElementType>::dequeue() {
    //Check for precondition
    if (isEmpty())
        throw EmptyDataCollectionException("");
    
    //Remove the element
    elementCount--;
    frontindex = (frontindex + 1) % capacity;

    //Shrink the Queue if needed
    if ((elementCount < capacity/4) && (capacity/2 >= INITIAL_CAPACITY))
        shrinkQ();
    
    return;
} 

// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType& Queue<ElementType>::peek() const {
    //Check for precondition
    if (isEmpty())
        throw EmptyDataCollectionException("");

    return elements[frontindex];    
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return elementCount == 0;
}
