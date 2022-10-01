/*
 * List.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - Sort using phone number (ascending order)
 *                   - Value-oriented list
 *
 * Author: Duc Manh To
 * Last modified: Sept. 2022
 */

#include <iostream> 
#include <string>
#include "List.h"

using std::cout;
    
    // Default constructor
    List::List(){

    }
	
    // Destructor
    // Description: Destruct a List object, releasing heap-allocated memory.
    List::~List(){
        this->clear();
    }

    // Description: Returns the total number of elements currently stored in List.
    unsigned int List::getElementCount() const{
        return this->elementCount;
    }

    // Description: Insert an element.
    // Precondition: newElement must not already be in data collection.  
    // Postcondition: newElement inserted in its proper place in List
    //                and elementCount has been incremented.   
    bool List::insert( Member& newElement ){
        bool ableToInsert =  elementCount < CAPACITY;
        
        // Allocate memory for new list
        if ( elements == NULL ) 
        {
            elements = new Member[CAPACITY];
            if (elements == NULL) 
            {
                ableToInsert = false;
                return ableToInsert;
            }            		
        }
        if (ableToInsert)
        {
            //Check if newElement already exists
            if (this->search(newElement) != NULL)
            {
                ableToInsert = false;
                return ableToInsert;
            }
            else
            {
                //Insert directly if the system is empty
                if (elementCount == 0)
                {
                    elements[0] = newElement;
                    elementCount++;
                    ableToInsert = true;
                    return ableToInsert;
                }
                else
                {
                    //Shift existing elements and then insert the newElement if not empty 
                    unsigned int i;
                    for (i = 0; i < elementCount; i++)
                    {
                        if (elements[i] > newElement)
                        {
                            for (unsigned int j = elementCount; j > i; j--)
                            {
                                elements[j] = elements[j-1];
                            }
                            elements[i] = newElement;
                            elementCount++;
                            return ableToInsert;
                        }

                    }
                    elements[i] = newElement;
                    elementCount++;
                    return ableToInsert;
                }
            }
        }
        return ableToInsert;
    }

    // Description: Remove an element. 
    // Postcondition: toBeRemoved is removed (leaving no gap in the data structure of List)
    //                and elementCount has been decremented.	
    bool List::remove( Member& toBeRemoved ){
        bool ableToRemove = elementCount != 0 && elements != NULL;

        if (ableToRemove)
        {
            //Check if the element is in the list
            Member* target = search(toBeRemoved);
            if (target == NULL)
            {
                ableToRemove = false;
                return ableToRemove;
            }
            //Remove the element by shifting the remaining elements back
            for (unsigned int i = 0; i < this->elementCount; i++)
            {
                if (elements[i] == *target)
                    elements[i] = elements[i+1];
            }
        }
        --elementCount;
        return ableToRemove;
    }
	
    // Description: Remove all elements.
    // Postcondition: List is back to the state it was right after being constructed.
    void List::removeAll(){
        this->clear();
    }
   
    // Description: Search for target element.
    //              Returns a pointer to the element if found,
    //              otherwise, returns NULL.
    Member* List::search( Member& target ){
        Member* key = NULL;
        //Check if the system is empty and return if it is
        if (elementCount == 0)
            return key;

        //Binary search for the target
        int start = 0, end = this->elementCount - 1, mid = 0;
        
        while (start <= end)
        {
            mid = (start + end)/2;

            if (elements[mid] == target)
            {
                key = &(elements[mid]);
                break;
            }
            else if (elements[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return key;
    }
	
    // Description: Prints all elements stored in List by descending order of search key.
    // Time Efficiency: O(n)
    void List::printList(){
        for (int i = this->elementCount-1; i >= 0; i--)
        {
            cout << elements[i] ;
        }
    }
    
    // Description: Call to remove or destroy all elements from the List.
    void List::clear() {
        delete [] elements;
        elements = NULL;   
        elementCount = 0;
        return;
    } 
// End of List.cpp