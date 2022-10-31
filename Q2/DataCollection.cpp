/*
 * D203+D204
 * DataCollection.cpp
 *
 * Description: Implementation of a linked list-based Data Collection ADT class - SHSL list
 * Class Invariant: No class invariant!
 *
 * Author: AL
 * Date: Oct. 2022
 */

#include <iostream>
#include <cmath>   
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"
#include "DataCollection.h"

using std::cout;
using std::cin;
using std::endl;


// Description: Default constructor. Constructs a DataCollection object.
DataCollection::DataCollection(){
   // cout << "DataCollection Default constructor called!" << endl;
}

// Description: Copy constructor creates a new DataCollection object as a copy of an existing DataCollection object.
DataCollection::DataCollection(const DataCollection & DC){
   // cout << "DataCollection Copy constructor called!" << endl;

   head = nullptr;
   if (DC.head != nullptr){
      Node *current = DC.head;
      while (current != nullptr){
         this->append(current->data); 
         current = current->next; 
      }
   }
}

// Description: Destructs a DataCollection object, releasing all heap-allocated memory.
DataCollection::~DataCollection(){
   // cout << "DataCollection Destructor called!" << endl;

   Node * temp = nullptr;
   for ( Node * toBeDeleted = head; toBeDeleted != nullptr; ) {
      temp = toBeDeleted->next;
      delete toBeDeleted;
      toBeDeleted = temp;
   }
   head = nullptr;
}

// Description: Appends an element (newElement) to the DataCollection.
// Exception Handling: Throws UnableToInsertException.
void DataCollection::append(int newElement){
   Node * newNode = new Node(newElement); 
   if ( newNode == nullptr )  
      throw UnableToInsertException(" in append(): new failed, newNode cannot be allocated heap memory."); 
   if (head == nullptr){
      head = newNode;
   }else{
      Node * current = head;
      while (current->next != nullptr){
         current = current->next;
      }
      current->next = newNode;
   }
   return;
}

// Description: Prepends an element (newElement) to the DataCollection.
// Exception Handling: Throws UnableToInsertException.
void DataCollection::prepend(int newElement){
   Node * newNode = new Node(newElement); 
   if ( newNode == nullptr )  
      throw UnableToInsertException("in prepend(): new failed, newNode cannot be allocated heap memory."); 
   if (head != nullptr) newNode->next = head;
   head = newNode;

   return;
}
 
// Description: Remove and returns the element located in the middle of the DataCollection.
//              The position of the elements in DataCollection ranges from [1 .. "total number of elements"].               
//              When computing the position of the middle element, round up to nearest integral value.              
// Exception Handling: Throws EmptyDataCollectionException.s
int DataCollection::removeMiddle() {

   

   if(head == nullptr)
      throw EmptyDataCollectionException();
   else{
      int removed;
      //Find the middle element index
      int elementCount = 1,midIndex = 1;
      Node* cursor = head;
      while (cursor->next != nullptr)
      {
         cursor = cursor->next;
         elementCount++;
      }

      if(elementCount % 2 == 0)
         midIndex = elementCount / 2;
      else
         midIndex = (elementCount / 2) + 1;

      //Remove middle element and connect the data collection
      if(elementCount == 1){
         removed = head->data;
         delete head;
         head = nullptr;

         return removed;
      }
      else{
         Node* connect = head;
         for (int i = 1; i < midIndex - 1;i++)
            connect  = connect ->next;
         
         Node* toBeRemoved = head;
         for (int i = 1; i < midIndex ;i++)
            toBeRemoved = toBeRemoved->next;
         
         removed = toBeRemoved->data;
         connect->next = toBeRemoved->next;
         delete toBeRemoved;

         return removed;
      }
   }
   
   return -1; // You can change this statement!
}
      
// Bonus Method: Will be marked only if you have implemented and submitted the above method.
// Description: Computes and returns the average of the values of all elements found in the DataCollection.
// Exception Handling: Throws EmptyDataCollectionException.
float DataCollection::average() {

   // Put your code here!
   
   return 0.0;   // You can change this statement!
}

// Description: Prints the content of this DataCollection "thisDC".
ostream & operator<<(ostream & os, const DataCollection & thisDC) {

   DataCollection::Node *current = thisDC.head;
   cout << "{"; //Nice format!
   // Traverse the DataCollection
   while (current != nullptr){
      cout << current -> data; // Print data
      current = current -> next; // Go to next Node
      if (current != nullptr){
         cout << ","; // Print a comma unless at the end of DataCollection
      }
   }
   cout << "}"; // Don't print a newline - it might not be needed.

   return os;

} 
