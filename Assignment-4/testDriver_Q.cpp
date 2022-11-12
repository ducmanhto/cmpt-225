/*
 * testDriver_Q.cpp
 *
 * Description: Test driver for template Queue class 
 *
 * Author: Huu Hoang Duong Nguyen 
 * Date: November 6, 2022
*/

#include "Queue.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main() {
    Queue<string> * test = new Queue<string>();
    string str;
    str = "first";
    test->enqueue(str);
    str = "second";
    test->enqueue(str);
    str = "third";
    test->enqueue(str);

    while (!test->isEmpty()) {
        cout << test->peek() << " ";
        test->dequeue();
    }
    cout << endl;

    str = "fourth";
    test->enqueue(str);
    str = "fifth";
    test->enqueue(str);
    str = "sixth";
    test->enqueue(str);

    while (!test->isEmpty()) {
        cout << test->peek() << " ";
        test->dequeue();
    }
    cout << endl;

    for (str = "a"; str <= "z"; str[0]++) {
        test->enqueue(str);
    }
    while (!test->isEmpty()) {
        cout << test->peek() << " ";
        test->dequeue();
    }
    cout << endl;


    try {
        test->dequeue();
    }
    catch (EmptyDataCollectionException& e) {
        cout << e.what() << endl;
    }
    delete test;
    return 0;
}