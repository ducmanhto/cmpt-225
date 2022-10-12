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

#include "Stack.h"
#include <iostream>

//Description: Default constructor
Stack::Stack()
{
    head = NULL;
}

//Description: Destructor
Stack::~Stack()
{
    StackNode *p = head;
        while (p != NULL) {
            head = head->next;
            delete p;
            p = head;
        }
}

//Description: Insert an element onto the top of the Stack
void Stack::push(int x)
{
    if (isEmpty())
    {
        //Create a new Node
        StackNode* newhead = new StackNode;
        newhead->data = x;
        newhead->next = NULL;

        head = newhead;
    }
    else
    {
    //Traverse to the top of the Stack
    StackNode* top = head;
    while (top->next != NULL)
    {
        top = top->next;
    }
    
    //Create a new Node
    StackNode* newhead = new StackNode;
    newhead->data = x;
    newhead->next = NULL;

    //Push the new Node to the top of the Stack
    top->next = newhead;
    }
}

//Description: Remove the topmost element of the Stack
void Stack::pop()
{
    if (isEmpty())
        return;
    else 
    {
    //Traverse to the top of the Stack
    StackNode* newTop = head;
    StackNode* top = head->next;
    if (top != NULL)
    {
        while (top->next != NULL)
        {
            top = top->next;
            newTop = newTop->next;
        }
        //Remove the top Node and return the top of the Stack
        delete top;
        newTop->next = NULL; 
    }
    else
    {
        delete newTop;
        head = NULL;
    }
    }
}

//Description: Gives access to the topmost element of the Stack
int Stack::peek() const
{
    //Traverse to the top of the Stack
    StackNode* top = head;
    while (top->next != NULL)
    {
        top = top->next;
    }

    return top->data;
}

//Description: Check if the Stack is empty
bool Stack::isEmpty() const
{
    return (head == NULL);
}


