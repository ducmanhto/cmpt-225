/*
 * BST.cpp
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Inspired from our textbook
 * Date of last modification: Oct. 2022
 */
 
#include "BST.h"
#include "WordPair.h"

// You cannot change the prototype of the public methods of this class.
// Remember, if you add public methods to this class, our test driver 
// - the one we will use to mark this assignment - will not know about them
// since we will use these public method prototypes to create our test driver.

/* Constructors and destructor */

   // Default constructor
   BST::BST() { }            

   // Copy constructor
   BST::BST(BST& aBST) {
     
      root = copyR(aBST.root);
      this->elementCount = aBST.getElementCount();
   }

   // Destructor 
   BST::~BST() {

      destructR(this->root);
   }                
   
   
/* Getters and setters */

   // Description: Returns the number of elements currently stored in the binary search tree.   
   // Time efficiency: O(1)   
   unsigned int BST::getElementCount() const {     

     return this->elementCount;
   }
   

/* BST Operations */

   // Description: Inserts an element into the binary search tree.
   //              This is a wrapper method which calls the recursive insertR( ).
   // Precondition: "newElement" does not already exist in the binary search tree.
   // Exception: Throws the exception "ElementAlreadyExistsException" 
   //            if "newElement" already exists in the binary search tree.
   // Time efficiency: O(log2 n)   
   void BST::insert(WordPair & newElement) {
     
      // Binary search tree is empty, so add the new element as the root
      if (elementCount == 0) {
         root = new BSTNode(newElement);
         elementCount++;
      }
      else {
         if ( !insertR(newElement, root) ) {
           //cout << "BST:insert( )" << newElement << " already in BST!" << endl; // For testing purposes
           throw ElementAlreadyExistsException("Element already exists in the data collection.");
         }
      }
      return;
   }

   // Description: Recursive insertion into a binary search tree.
   //              Returns true when "anElement" has been successfully inserted into the 
   //              binary search tree. Otherwise, returns false.
   bool BST::insertR(WordPair & anElement, BSTNode * current) { 
      
	   bool inserted;
	
	   // if the given pair is less than the current node, recur for the left subtree;
	   // if the given pair is bigger than the current node, recur for the right subtree
      // return false if the element already exists
	   if (anElement < current->element) {
         if (current->left == nullptr)
	      {
            current->left = new BSTNode(anElement);
            elementCount++;
            inserted = true;
	      }
         else
	         return insertR(anElement, current->left);
	   }
	   else if (anElement > current->element)
      {
         if (current->right == nullptr)
         {
            current->right = new BSTNode(anElement);
            elementCount++;
            inserted = true;
         }
         else
	         return insertR(anElement, current->right);
	   }
      else if (anElement == current->element)
         return inserted = false;
      
      return inserted;
   }

   
   // Description: Retrieves "targetElement" from the binary search tree.
   //           This is a wrapper method which calls the recursive retrieveR( ).
   // Precondition: Binary search tree is not empty.
   // Exception: Throws the exception "EmptyDataCollectionException" 
   //         if the binary search tree is empty.
   // Exception: Throws (propagates) the exception "ElementDoesNotExistException" 
   //         thrown from the retrieveR(...)
   //         if "targetElement" is not in the binary search tree.
   // Time efficiency: O(log2 n)
   WordPair& BST::retrieve(WordPair & targetElement) const {
      
     if (elementCount == 0)  
        throw EmptyDataCollectionException("Binary search tree is empty.");
	
     WordPair& translated = retrieveR(targetElement, root);
     return translated;
   }

   // Description: Recursive retrieval from a binary search tree.
   // Exception: Throws the exception "ElementDoesNotExistException" 
   //         if "targetElement" is not found in the binary search tree.
   WordPair& BST::retrieveR(WordPair & targetElement, BSTNode * current) const {

      BSTNode* retrieved = NULL;
      //Throw exception if the element is not found
      if (current == nullptr)
         throw ElementDoesNotExistException("The element does not exist in the tree");
		
      //Return element if the current element is equak to the target
      //Otherwise recur to the appropriate subtree
      if (targetElement == current->element)
         retrieved = current;
      else if (targetElement < current->element) {
	      return retrieveR(targetElement, current->left);
	   }
	   else
      {
	      return retrieveR(targetElement, current->right);
	   }
      
      return retrieved->element;
   } 
         
   
   // Description: Traverses the binary search tree in order.
   //           This is a wrapper method which calls the recursive traverseInOrderR( ).
   //           The action to be done on each element during the traverse is the function "visit".
   // Precondition: Binary search tree is not empty.
   // Exception: Throws the exception "EmptyDataCollectionException" 
   //         if the binary search tree is empty.
   // Time efficiency: O(n)     
   void BST::traverseInOrder(void visit(WordPair &)) const {
     
     if (elementCount == 0)  
       throw EmptyDataCollectionException("Binary search tree is empty.");

     traverseInOrderR(visit, root);
     
     return;
   }

   // Description: Recursive in order traversal of a binary search tree.   
   void BST::traverseInOrderR(void visit(WordPair &), BSTNode* current) const { 
      
      if (current == nullptr) 
         return;

      //First recur on left subtree 
      traverseInOrderR(visit, current->left);
      //Then vist the data of child
      visit(current->element); 
      // Recur on the right subtree
      traverseInOrderR(visit, current->right);
   }

   // Description: Recursive copy every node in aBST.
   BSTNode* BST::copyR(BSTNode* current) const{
      if (current)
      {
         BSTNode *newNode = new BSTNode(current->element);
         newNode->left = copyR(current->left);
         newNode->right = copyR(current->right);
         return newNode;
      }
      return NULL;
   }

   // Description: Recursive delete every node in BST.
   void BST::destructR(BSTNode* current){
      
      if (current->isLeaf())
         delete current;
      if (current->hasLeft())
         destructR(current->left);
      if (current->hasRight())
         destructR(current->right);
      
   }