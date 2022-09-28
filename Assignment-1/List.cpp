/*
 * List.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - Sort using phone number (order)
 *                   - Value-oriented list
 *
 * Author: AL/Duc Manh To
 * Last modified: Sept. 2022
 */

#include <iostream> 
#include <string>
#include "List.h"
    // 
    void List::clear() {

    delete [] elements;
    elements = NULL;   
    elementCount = 0;
    return;
    } 
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

    }

    // Description: Insert an element.
    // Precondition: newElement must not already be in data collection.  
    // Postcondition: newElement inserted in its proper place in List
    //                and elementCount has been incremented.   
    bool List::insert( Member& newElement ){

    }

    // Description: Remove an element. 
    // Postcondition: toBeRemoved is removed (leaving no gap in the data structure of List)
    //                and elementCount has been decremented.	
    bool List::remove( Member& toBeRemoved ){

    }
	
    // Description: Remove all elements.
    // Postcondition: List is back to the state it was right after being constructed.
    void List::removeAll(){

    }
   
    // Description: Search for target element.
    //              Returns a pointer to the element if found,
    //              otherwise, returns NULL.
    Member* List::search( Member& target ){

    }
	
    // Description: Prints all elements stored in List by descending order of search key.
    // Time Efficiency: O(n)
    void List::printList(){

    }