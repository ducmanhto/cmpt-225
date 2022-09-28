/*
 * Member.cpp
 * 
 * Class Description: Models a Fitness Studio Registration System.
 * Class Invariant: Each member has a unique cell phone number.
 *                  This cell phone number must have 12 digits.
 *                  This cell phone number must have the following format: XXX-XXX-XXXX.
 *                  This cell phone number cannot be modified. 
 *
 * Author: AL/Duc Manh To
 * Last modified: Sept. 2022
 */


#include <iostream>
#include <string>
#include "Member.h"

// Default Constructor
    // Description: Create a member with a cell phone number of "000-000-0000". 
    // Postc4ondition: All data members set to an empty string, 
    //                except the cell phone number which is set to "000-000-0000".
    Member::Member(){
    }

    // Parameterized Constructor
    // Description: Create a member with the given cell phone number.
    // Postcondition: If aPhone does not have 12 digits, then aPhone is set to "000-000-0000".
    //                All other data members set to an empty string.
    Member::Member(string aPhone){
        this->phone = aPhone;
    }
	
    // Parameterized Constructor
    // Description: Create a member with the given name, cell phone number, email and credit card number.
    // Postcondition: If aPhone does not have 12 digits, then aPhone is set to "000-000-0000".
    Member::Member(string aName, string aPhone, string anEmail, string aCreditCard){
        this->name = aName;
        this->phone = aPhone;
        this->email = anEmail;
        this->creditCard = aCreditCard;
    }


    // Getters and setters
    // Description: Returns member's name.
    string Member::getName() const{
        return this->name;
    }

    // Description: Returns member's phone.
    string Member::getPhone() const{
        return this->phone;
    }

    // Description: Returns member's email.
    string Member::getEmail() const{
        return this->email;
    }
	
    // Description: Returns member's credit card.
    string Member::getCreditCard() const{
        return this->creditCard;
    }

    // Description: Sets the member's name.
    void Member::setName(const string aName){
        this->name = aName;
    }

    // Description: Sets the member's email.
    void Member::setEmail(const string anEmail){
        this->email = anEmail;
    }
	
    // Description: Sets the member's credit card number.
    void Member::setCreditCard(const string aCreditCard){
        this->creditCard = aCreditCard;
    }

// Overloaded Operators
// Description: Comparison operator. Compares "this" Member object with "rhs" Member object.
//              Returns true if both Member objects have the same cell phone number.
bool Member::operator == (const Member & rhs) {

    return this->phone == rhs.getPhone();
}
	
// Description: Greater than operator. Compares "this" Member object with "rhs" Member object.
//              Returns true if the cell phone number of "this" Member object is > the 
//              cell phone number of "rhs" Member object.
bool Member::operator > (const Member & rhs) {

    return this->phone > rhs.getPhone();
} 

// Description: Less than operator. Compares "this" Member object with "rhs" Member object.
//              Returns true if the cell phone number of "this" Member object is < the 
//              cell phone number of "rhs" Member object.
bool Member::operator < (const Member & rhs) {
	
    return this->phone < rhs.getPhone();
} 

// For testing purposes!
// Description: Prints the content of "this".
// Example: Louis Pace, 604-853-1423, louis@nowhere.com, 1234 5678 9098 7654 
ostream & operator<<(ostream & os, const Member & p) {
	
    os << p.name << ", " << p.phone << ", " << p.email << ", " << p.creditCard << endl;  
	     
    return os;
} 

// end of Member.cpp
