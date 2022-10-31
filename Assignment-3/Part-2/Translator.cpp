/*
 * Translator.cpp
 * 
 * Description: Drives the code to translate English word
 *              into the Dothraki language
 *
 * Author: Duc Manh To
 * Last Modification Date: Oct. 2022
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "Dictionary.h"

using std::cin;
using std::cout;
using std::ifstream;

void display(WordPair& anElement) {
    cout << anElement;
} 

int main(int argc, char *argv[]) {

    Dictionary* dictionary = new Dictionary();
        
    string aLine = "";
    string aWord = "";
    string englishW = "";
    string dothrakiW = "";
    string filename = "myDataFile.txt";
    string delimiter = ":";
    size_t pos = 0;
    WordPair translated;
    
    //Open myDataFile.txt and read the word pairs
    ifstream myfile (filename);
    if (myfile.is_open()) {
        while ( getline (myfile,aLine) )
        {
            pos = aLine.find(delimiter);
            englishW = aLine.substr(0, pos);
            aLine.erase(0, pos + delimiter.length());
            dothrakiW = aLine; 
            WordPair aWordPair(englishW, dothrakiW);
            // insert aWordPair into the dictionary using a try/catch block
            try {
                dictionary->put(aWordPair);
            }
            catch (ElementAlreadyExistsException& anException){
            }
        }
        myfile.close();

        // If user entered "display" at the command line ...
        if ( ( argc > 1 ) && ( strcmp(argv[1], "display") == 0) ) {
            // ... then display the content of the BST.
            dictionary->displayContent(display);
        }
        else if (argc == 1) {
            // while user has not entered CTRL+D
            while ( getline(cin, aWord) ) {   

            WordPair aWordPair(aWord);
            // retrieve aWordPair from the dictionary using a try/catch block
            // print aWordPair
                try {
                    aWordPair = dictionary->get(aWordPair);
                    cout << aWordPair;
                }
                catch (EmptyDataCollectionException& anException) {
                }
                catch (ElementDoesNotExistException& anException) {
                    cout << "***Not Found***!" << endl;
                }
            }
        }
    }

    delete dictionary;
    return 0;
}
