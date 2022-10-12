/* 
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Duc Manh To
 * Date: October 2022
 */
#ifndef STACK_H
#define STACK_H

class Stack {

    private:

        // Description:  Nodes for a singly-linked list
        class StackNode {
            public:
                int data;
                StackNode * next;
        };

        // Description: Top pointer of the stack
        StackNode* head;     
        
    public:

        Stack();
        ~Stack();
        void push(int x);
        void pop();
        int peek() const;
        bool isEmpty() const;
}; 
#endif
