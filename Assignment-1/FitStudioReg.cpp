/*
 * FitStudioReg.cpp - Assignment 1
 *
 * Class Description: Fitness Studio Registration System
 *
 * Author: AL/Duc Manh To
 * Last modified: Sept. 2022
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Member.h"
#include "List.h"

using std::cout;
using std::cin;
using std::endl;

//Description: Add a new member into the system
void add (List* Members){
    //Check if new member already exists
    string aPhone;
    cout << "Enter the phone number of the new member: ";
    cin.ignore();
    getline(cin, aPhone);
    Member newClient = Member(aPhone);
    Member* result = Members->search(newClient);

    //Create new member if they don't already exists
    if (result != NULL) {
        cout << "--- Member already exist. Please add a new client ---" << endl;
        cout << *result << endl;
        return;
    }
    else {
        cout << "--- Not an existing member. Continue ---" << endl;
        string aName, anEmail, aCreditCard;
        cout << "Enter the new member's..." << endl;
        cout << "Name: ";
        getline(cin, aName);
        cout << "Email: ";
        getline(cin, anEmail);
        cout << "Credit card number: ";
        getline(cin, aCreditCard);
        newClient = Member(aName, aPhone, anEmail, aCreditCard);
    }

    //Add client into list
    if (Members->insert(newClient))
    {
        cout << "New member added successfully:" << newClient;
    }
    else
    {
        cout << "Failed to add new member. System full." << endl;
    }
    return;
}

//Description: Remove an exsting member from the system
void remove(List* Members){
    //Check if the system is empty
    if (Members->getElementCount() == 0) {
        cout << "--- The system is empty ---" << endl;
        return;
    }

    //Remove the member from the system
    string aPhone;
    cout << "Enter the phone number you want to remove: ";
    cin.ignore();
    getline(cin,aPhone);
    Member target = Member(aPhone);

    if (Members->remove(target))
        cout << "--- Removal successful ---" << endl;
    else
        cout << "--- Removal failed. ---" << endl;
    return;
}

//Description: Search for a record of an existing member
void search(List* Members){
    //Check if the system is empty
    if (Members->getElementCount() == 0) {
        cout << "--- The system is empty ---" << endl;
        return;
    }

    //Search for the member with the phone number
    string aPhone;
    cout << "Enter the phone number you want to search for: ";
    cin.ignore();
    getline(cin,aPhone);
    Member target = Member(aPhone);
    Member* result = Members->search(target);

    if (result != NULL)
    {
        cout << "Member found: " << *result;
    }
    else
        cout << "No member with this phone number found." << endl;
    return;
}

//Description: Modify the information on a member
void modify(List* Members){
    //Check if the system is empty
    if (Members->getElementCount() == 0) {
        cout << "--- The system is empty. ---" << endl;
        return;
    }

    //Ask for the member the user want to modify
    string aPhone;
    cout << "Enter the phone number of the member you want to modify: ";
    cin.ignore();
    getline(cin,aPhone);
    Member target = Member(aPhone);
    Member* result = Members->search(target);

    //Modify the details of the member if found
    if (result != NULL) 
    {
        string changeTo;
        char input = '\0';
        bool done = false;

        while (!done)
        {
            //Print menu for modification
            cout << endl << "Enter ..." << endl << endl;
            cout << "n -> to change the name of the member" << endl;
            cout << "e -> to change the email of the member" << endl;
            cout << "c -> to change the credit card number of the member" << endl;
            cout << "x -> to go to main menu" << endl;

            cout << endl << "Your choice: ";
            cin >> input;
            input = tolower(input);

            switch (input)
            {
                case 'n':
                    cout << "Enter the member's new name: ";
                    cin.ignore();
                    getline(cin, changeTo);
                    result->setName(changeTo);
                    cout << "The member's name was changed to " << result->getName();
                    break;
                case 'e':
                    cout << "Enter the member's new email: ";
                    cin.ignore();
                    getline(cin, changeTo);
                    result->setEmail(changeTo);
                    cout << "The member's email was changed to " << result->getEmail();
                    break;
                case 'c':
                    cout << "Enter the member's new credit card number: ";
                    cin.ignore();
                    getline(cin, changeTo);
                    result->setCreditCard(changeTo);
                    cout << "The member's name was changed to " << result->getCreditCard();
                    break;
                case 'x':
                    cout << endl << "Modified member: " << endl << *result << endl;
                    cout << "Exiting to main menu..." << endl;
                    done = true;
                    break;

                default:
                    cout << " Invalid input. Try again." << endl;
                    break;
            } 
        }
    }
    else
        cout << "No member with this phone number found." << endl;
    return;
}

//Description: Print the records of all members in descending order of phone numbers
void print(List* Members){
    if (Members->getElementCount() == 0) {
        cout << "--- The system is empty ---" << endl;
        return;
    }
    cout << " Printing the member(s) in the system" << endl;
    Members->printList();
    return;
}

int main() {

    // Variables declaration
    List* Members = new List();
    bool done = false;
    char input = 0;

    // Keep going until the user exits
    while (not done) {
        // Print menu to stdout
        cout << endl << "----Welcome to the Fitness Studio Registration System!" << endl;
        cout << endl << "Enter ..." << endl << endl;
        cout << "a -> to add a new member" << endl;
        cout << "r -> to remove a member" << endl;
        cout << "s -> to search for a member" << endl;
        cout << "m -> to modify the record of a member" << endl;
        cout << "p -> to print all members" << endl;
        cout << "x -> to exit\n" << endl;

        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
		switch(input) {
            case 'a': add(Members); break;
            case 'r': remove(Members); break;
            case 's': search(Members); break;
            case 'm': modify(Members); break;
            case 'p': print(Members); break;
            case 'x': cout << "\n----Bye!\n" << endl; done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }

    delete Members;
    return 0;
}
