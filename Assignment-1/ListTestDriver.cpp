/*
 * FitStudioReg.cpp - Assignment 1
 *
 * Class Description: Fitness Studio Registration System
 *
 * Author: Duc Manh To
 * Last modified: Sept. 2022
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Member.h"
#include "List.h"

using std::cout;
using std::endl;

int main(){
    //Test case 1: Create a list with the default constructor
    cout << endl <<"Test case 1" << endl;
    cout << "Expected result: Empty list created, no members in the list, nothing is printed" << endl;
    List* Members = new List();
    cout << "Actual result: " << endl;
    cout << "Member count: " << Members->getElementCount() << endl;
    Members->printList();

    //Test case 2: Adding a valid member to the list
    //List empty, elementCount is 0, inserting 1 profile:
    //Marie Lower, 778-778-7788, marie@somewhere.ca, 5674 7890 2345 1276
    cout << endl <<"Test case 2" << endl;
    cout << "Create a member with the correct phone number format XXX-XXX-XXXX" << endl;
    cout << "Expected result: Insert successful, the printed list contains 1 member" << endl;
    cout << "Actual result: " << endl;

    Member client1 = Member("Marie Lower", "778-778-7788", "marie@somewhere.ca", "5674 7890 2345 1276");
    if (Members->insert(client1))
        cout << "First insert successful" << endl;
    else
        cout << "First insert failed" << endl;
    cout << "The studio has " << Members->getElementCount() << " member(s)" << endl;
    Members->printList();

    //Test case 3: Adding a member with invalid phone number to the list
    //List not empty, elementCount is 1, inserting 1 member:
    //Xiao Wong, 77a-123-1234, xw123@coldmail.com, 9876 5432 1234 5678
    cout << endl <<"Test case 3" << endl;
    cout << "Create a member with the incorrect phone number format 77a-123-1234" << endl;
    cout << "Expected result: Insert successful, the printed list contains 2 members in descending order, one member was added with default phone number" << endl;
    cout << "Actual result: " << endl;

    Member client2 = Member("Xiao Wong", "77a-123-1234", "xw123@coldmail.com", "9876 5432 1234 5678");
    if (Members->insert(client2))
        cout << "Second insert successful" << endl;
    else
        cout << "Second insert failed" << endl;
    cout << "The studio has " << Members->getElementCount() << " member(s)" << endl;
    Members->printList();

    //Test case 4: Adding a member with invalid phone number to the list
    //List not empty, elementCount is 2, inserting 1 member:
    //Louis Pace, 6046853-1423, louis@nowhere.com, 1234 5678 9098 7654
    cout << endl <<"Test case 4" << endl;
    cout << "Create a member with the incorrect phone number format 6046853-1423" << endl;
    cout << "Expected result: Insert fails, the printed list contains 2 members in descending order, failed member has the default phone number" << endl;
    cout << "Actual result: " << endl;

    Member client3 = Member("Louis Pace", "6046853-1423", "louis@nowhere.com", "1234 5678 9098 7654");
    if (Members->insert(client3))
        cout << "Third insert successful" << endl;
    else
        cout << "Third insert failed" << endl;
    cout << "The failed member phone number " << client3.getPhone() << endl;
    cout << "The studio has " << Members->getElementCount() << " member(s)" << endl;
    Members->printList();

    //Test case 5: Adding a member with invalid phone number to the list
    //List not empty, elementCount is 2, inserting 1 member:
    //Louis Pace, 604-853-142, louis@nowhere.com, 1234 5678 9098 7654
    cout << endl <<"Test case 5" << endl;
    cout << "Create a member with the incorrect phone number length 604-853-142" << endl;
    cout << "Expected result: Insert fails, the printed list contains 2 members in descending order, failed member has the default phone number" << endl;
    cout << "Actual result: " << endl;

    Member client4 = Member("Louis Pace", "604-853-142", "louis@nowhere.com", "1234 5678 9098 7654");
    if (Members->insert(client4))
        cout << "Fourth insert successful" << endl;
    else
        cout << "Fourth insert failed" << endl;
    cout << "The failed member phone number " << client4.getPhone() << endl;
    cout << "The studio has " << Members->getElementCount() << " member(s)" << endl;
    Members->printList();

    //Test case 6: Adding a member with valid phone number to the list
    //List not empty, elementCount is 2, inserting 1 member:
    //Louis Pace, 804-853-1423, louis@nowhere.com, 1234 5678 9098 7654
    cout << endl <<"Test case 6" << endl;
    cout << "Create a member with the correct phone number format" << endl;
    cout << "Expected result: Insert successful, the printed list contains 3 members in descending order" << endl;
    cout << "Actual result: " << endl;

    Member client5 = Member("Louis Pace", "804-853-1423", "louis@nowhere.com", "1234 5678 9098 7654");
    if (Members->insert(client5))
        cout << "Fifth insert successful" << endl;
    else
        cout << "Fifth insert failed" << endl;
    cout << "The studio has " << Members->getElementCount() << " member(s)" << endl;
    Members->printList();   

    //Test case 7: Adding 3 members with valid phone number to the list
    //List not empty, elementCount is 3, inserting 3 members:
    //1. Arwinder Singh, 604-231-4548, meow@telthem.com, 2375 8765 9843 1208
    //2. Michael Scott, 721-423-4369, scott@dundermifflin.co, 4325 1614 7842 9015
    //3. Toby Flenderson, 362-673-7914, flenderson@dundermifflin.co, 8941 1237 7525 8916
    cout << endl <<"Test case 7" << endl;
    cout << "Create 3 members with the correct phone number format" << endl;
    cout << "Expected result: 2 insert successful, 1 insert fails, the printed list contains 5 members in descending order" << endl;
    cout << "Actual result: " << endl;

    Member client6 = Member("Arwinder Singh", "604-231-4548", "meow@telthem.com", "2375 8765 9843 1208");
    if (Members->insert(client6))
        cout << "Sixth insert successful" << endl;
    else
        cout << "Sixth insert failed" << endl;

    Member client7 = Member("Michael Scott", "721-423-4369", "scottm@duddermiflin.co", "4325 1614 7842 9015");
    if (Members->insert(client7))
        cout << "Seventh insert successful" << endl;
    else
        cout << "Seventh insert failed" << endl;

    Member client8 = Member("Toby Flenderson", "362-673-7914", "flenderson@dundermifflin.co", "8941 1237 7525 8916");
    if (Members->insert(client8))
        cout << "Eighth insert successful" << endl;
    else
        cout << "Eighth insert failed" << endl;

    cout << "The studio has " << Members->getElementCount() << " member(s)" << endl;
    Members->printList();

    //Test case 8: Search for a member using their phone number, target exists in the system
    //Search target: Michael Scott, 721-423-4369, scott@dundermifflin.co, 4325 1614 7842 9015
    cout << endl <<"Test case 8" << endl;
    cout << "Search for the member with the phone number 721-423-4369" << endl;
    cout << "Expected result: The member exists in the system, print the information of the member" << endl;
    cout << "Actual result: " << endl;

    Member* target1 = Members->search(client7);
    if(target1 != NULL)
    {
        cout << "Search successful" << endl;
        cout << "The member you are searching for: " << *target1 << endl;
    }
    else
        cout << "Search unsuccessful. The client you are searching for doesn't exist in the system." << endl;
    
    //Test case 9: Search for a member using their phone number, target doesn't exist in the system
    //Search target: Toby Flenderson, 362-673-7914, flenderson@dundermifflin.co, 8941 1237 7525 8916
    cout << endl <<"Test case 9" << endl;
    cout << "Search for the member with the phone number 362-673-7914" << endl;
    cout << "Expected result: The member doesn't exist in the system, print error message" << endl;
    cout << "Actual result: " << endl;

    Member* target2 = Members->search(client8);
    if(target2 != NULL)
    {
        cout << "Search successful" << endl;
        cout << "The member you are searching for: " << *target2 << endl;
    }
    else
        cout << "Search unsuccessful. The client you are searching for doesn't exist in the system." << endl;
    
    //Test case 10: Remove a member using their phone number, target exists in the system
    //List is full, elementCount is 5, removing 1 member:
    //Removal target: Michael Scott, 721-423-4369, scott@dundermifflin.co, 4325 1614 7842 9015
    cout << endl <<"Test case 10" << endl;
    cout << "Remove the member with the phone number 721-423-4369" << endl;
    cout << "Expected result: The member is removed from the system, print list in descending order" << endl;
    cout << "Actual result: " << endl;

    if(Members->remove(client7))
    {
        cout << "Removal successful" << endl;
        Members->printList();
    }
    else
    {
        cout << "Removal failed. The client you are removing doesn't exist in the system." << endl;
        Members->printList();
    }

    //Test case 11: Remove a member using their phone number, target doesn't exist in the system
    //List not empty, elementCount is 4, removing 1 non-exsting member:
    //Search target: Toby Flenderson, 362-673-7914, flenderson@dundermifflin.co, 8941 1237 7525 8916
    cout << endl <<"Test case 11" << endl;
    cout << "Remove the member with the phone number 362-673-7914" << endl;
    cout << "Expected result: The member doesn't exist in the system, print error message" << endl;
    cout << "Actual result: " << endl;

    if(Members->remove(client8))
    {
        cout << "Removal successful" << endl;
        Members->printList();
    }
    else
    {
        cout << "Removal failed. The client you are removing doesn't exist in the system." << endl;
        Members->printList();
    }

    //Test case 12: Remove every member from the system
    //List not empty, elementCount is 4, removing all members
    cout << endl <<"Test case 12" << endl;
    cout << "Remove every member in the system" << endl;
    cout << "Expected result: The list is reset. Nothing to print in the list" << endl;
    cout << "Actual result: " << endl;

    Members->removeAll();
    if (Members->getElementCount() == 0)
        Members->printList();
    else
    {
        cout << "Remove all failed. Printing the members remaining: " << endl;
        Members->printList();
    }

    delete Members;
    return 0;
}