/* 
 * Queue.cpp - Does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Duc Manh To
 * Date: October 2022
 */
 
#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

// Description: Constructor
Queue::Queue() 
{
    elements = NULL;
}

// Description: Destructor
Queue::~Queue()
{
    delete[] elements;
    elements = nullptr;
    elementCount = 0;
    frontindex = 0;                  
    backindex = 0; 
}

// Description: Create a new array double the size of the previous
void Queue::expandQ(){
    // Copy elements into a new array
    int* newElements = new int[2*capacity];
    for (int i = 0; i < elementCount; i++)
    {
        newElements[i] = elements[(i+frontindex) % capacity];
    }

    // Set the parameters of the array
    frontindex = 0;
    backindex = elementCount;
    capacity *= 2;
    delete[] elements;
    elements = newElements;

    return;
}

// Description: Create a new array half the size of the old one
void Queue::shrinkQ(){
    // Copy elements into a smaller array
    int * newArr = new int[capacity / 2];
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

// Description: Inserts element x at the back of Queue
// Time Efficiency: O(1)
void Queue::enqueue(int x) {

    if (elements == nullptr) {
        elements = new int[capacity];
        if (elements == nullptr) {
            return;
        }
    }
    
    //Expand the Queue if needed
    if (elementCount >= capacity)
        expandQ();

    elementCount++;
    elements[backindex] = x;
    backindex = (backindex + 1) % capacity;   

    return;
} 

// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
void Queue::dequeue() {
    //Check for precondition
    if (isEmpty())
        return;
    
    //Remove the element
    elementCount--;
    frontindex = (frontindex + 1) % capacity;

    //Shrink the Queue if needed
    if ((elementCount < capacity/4) && (capacity/2 >= INITIAL_CAPACITY))
        shrinkQ();
    
    return;
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
int Queue::peek() const {
    //Check for precondition
    if (isEmpty())
        return -1;

    return elements[frontindex];    
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
bool Queue::isEmpty() const {
    return elementCount == 0;
}
