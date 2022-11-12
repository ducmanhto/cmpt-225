/* 
 * BinaryHeap.h
 *
 * Description: min Binary Heap ADT class.
 *
 * Class Invariant:  Always a min Binary Heap.
 * 
 * Author: Duc Manh To
 * Last Modification: November 2022
 *
 */  

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include "EmptyDataCollectionException.h"

template <class ElementType>
class BinaryHeap {

    private:
        ElementType* elements; 
        const static unsigned int INITIAL_CAPACITY = 5;
        unsigned int capacity = INITIAL_CAPACITY;
        unsigned int elementCount = 0;
        unsigned int root = 0;

        bool expandBH();
        void reHeapDown(unsigned int indexOfRoot); // Recursively put the array back into a min Binary Heap when removing
        void reHeapUp(unsigned int indexOfBottom);   // Recursively put the array back into a min Binary Heap when inserting
    public:
        // Description: Default constructor
        BinaryHeap();

        // Description: Destructor
        ~BinaryHeap();

        // Description: Returns the number of elements in the Binary Heap.
        // Postcondition: The Binary Heap is unchanged by this operation.
        // Time Efficiency: O(1)
        unsigned int getElementCount() const;

        // Description: Inserts newElement into the Binary Heap. 
        //              It returns true if successful, otherwise false.      
        // Time Efficiency: O(log2 n)
        bool insert(ElementType & newElement);
            
        // Description: Removes (but does not return) the necessary element.
        // Precondition: This Binary Heap is not empty.
        // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
        // Time Efficiency: O(log2 n)
        void remove();

        // Description: Retrieves (but does not remove) the necessary element.
        // Precondition: This Binary Heap is not empty.
        // Postcondition: This Binary Heap is unchanged.
        // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
        // Time Efficiency: O(1) 
        ElementType & retrieve() const;
        
};

#include "BinaryHeap.cpp"
#endif