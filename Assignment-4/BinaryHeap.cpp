/* 
 * BinaryHeap.cpp
 *
 * Description: min Binary Heap ADT class.
 *
 * Class Invariant:  Always a min Binary Heap.
 * 
 * Author: Duc Manh To
 * Last Modification: November 2022
 *
 */  

#include <iostream>
#include "BinaryHeap.h"  // Header file

using std::cout;
using std::endl;
  
// Description: Default constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap(){
   elements =  nullptr;
}

// Description: Destructor
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap(){
   delete[] elements;
}

// Description: Returns the number of elements in the Binary Heap.
// Postcondition: The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const{
   return elementCount;
}

// Description: Inserts newElement into the Binary Heap. 
//              It returns true if successful, otherwise false.      
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType & newElement){

   bool inserted = false;
   if (elementCount == 0)
   {
      elements = new ElementType[INITIAL_CAPACITY];
      if (elements == nullptr)
         return inserted;
      elements[root] = newElement;
      elementCount++;
   }
   else
   {
      if (elementCount >= capacity)
        if (expandBH())
            inserted = true;

      int indexOfBottom = elementCount;
      elements[indexOfBottom] = newElement;
      elementCount++;
      reHeapUp( indexOfBottom );
   }
   
   return inserted;
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {  

   if(elementCount == 0) 
      throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");

   elements[0] = elements[elementCount - 1];
   elementCount--;
   reHeapDown(0);
   
   return;   
}

// Description: Retrieves (but does not remove) the necessary element.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1) 
template <class ElementType>
ElementType & BinaryHeap<ElementType>::retrieve() const{
   if (elements == nullptr)
      throw EmptyDataCollectionException("");
   else
      return elements[root];
}

// Utility method
//Description: Expand the Heap when it is full
template <class ElementType>
bool BinaryHeap<ElementType>::expandBH(){
   // Copy elements into a new array
   ElementType* newElements = new ElementType[2*capacity];
   if (newElements == nullptr)
      return false;
   for (unsigned int i = 0; i < elementCount; i++)
   {
      newElements[i] = elements[i];
   }

   // Set the parameters of the array
   capacity *= 2;
   delete[] elements;
   elements = newElements;

   return true;
}

// Description: Recursively put the array back into a min Binary Heap when removing
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

   unsigned int indexOfMinChild = indexOfRoot;
   
   // Find indices of children.
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild >= elementCount) return;

   // If we need to swap, select the smallest child
   // If (elements[indexOfRoot] > elements[indexOfLeftChild])
   if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) )
      indexOfMinChild = indexOfLeftChild;

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) {
      // if (elements[indexOfMinChild] > elements[indexOfRightChild])
      if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
         indexOfMinChild = indexOfRightChild;
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot) {
      
      ElementType temp = elements[indexOfRoot];
      elements[indexOfRoot] = elements[indexOfMinChild];
      elements[indexOfMinChild] = temp;
      
      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
} 

// Description: Recursively put the array back into a min Binary Heap when inserting
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfBottom){

   // If the element has a parent and …
   if ( indexOfBottom > root )
   {
      int indexOfParent = (indexOfBottom - 1) / 2;
      // … search key value of child <= search key value of parent then …
      if ( elements[indexOfBottom] <= elements[indexOfParent] )
      {
         //… swap the element with its parent
         ElementType temp = elements[indexOfParent];
         elements[indexOfParent] = elements[indexOfBottom];
         elements[indexOfBottom] = temp;
         reHeapUp( indexOfParent );
      }
   }
   return;
}
