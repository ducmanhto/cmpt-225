// /*
//  * testDriver_BH.cpp
//  *
//  * Description: Test driver for template Binary Heap class 
//  *
//  * Author: Huu Hoang Duong Nguyen
//  * Date: November 7, 2022
// */

// #include "BinaryHeap.h"
// #include <iostream>
// #include <string>

// using std::cout;
// using std::endl;

// int main() {
//     BinaryHeap<int> * heap = new BinaryHeap<int>();

//     int a = 9;
//     heap->insert(a);
//     a = 8;
//     heap->insert(a);
//     a = 2;
//     heap->insert(a);
//     a = 7;
//     heap->insert(a);
//     a = 5;
//     heap->insert(a);
//     a = 1;
//     heap->insert(a);
//     a = 3;
//     heap->insert(a);
//     a = 2;
//     heap->insert(a);
//     a = 10;
//     heap->insert(a);
//     a = 6;
//     heap->insert(a);


//     heap->print();


//     cout << "Retrieve until empty." << endl;

//     // BinaryHeap<int> * heap2 = new BinaryHeap<int>(*heap);

//     while (heap->getElementCount() > 0) {
//         cout << "Retrieved: " << heap->retrieve() << endl;
//         heap->remove();
//         heap->print();
//     }

//     // while (heap2->getElementCount() > 0) {
//     //     cout << "Retrieved: " << heap2->retrieve() << endl;
//     //     heap2->remove();
//     //     //heap2->print();
//     // }

//     delete heap;
//     //delete heap2;
//     return 0;
// }