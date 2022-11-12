/* 
 * BankSimApp.cpp
 *
 * Description: Simulation of a bank using a bank line queue and an event priority queue
 *
 * Author: Duc Manh To  
 * Date: November 2022
 */

#include <iostream>
#include <iomanip>
#include "BinaryHeap.h"
#include "Event.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "EmptyDataCollectionException.h"

using std::cout;
using std::cin;
using std::setw;

int main(){

    Queue<Event>* bankLine = new Queue<Event>();    //Bank line
    PriorityQueue<Event>* eventPriorityQueue = new PriorityQueue<Event>();  //Event Queue

    bool tellerAvailable = true;

    //Create and add arrival event to the event queue
    int t,l;    
    int numCustomer = 0, sumOfWait = 0;
    while (cin >> t)
    {
        cin >> l;
        Event newArrivalEvent = Event('A', t, l);
        eventPriorityQueue->enqueue(newArrivalEvent);
        numCustomer++;
    }

    cout << "Simulation Begins" << endl;

    //Event loop
    while (!eventPriorityQueue->isEmpty())
    {
        Event newEvent = eventPriorityQueue->peek();

        //Get current time
        int currentTime = newEvent.getTime();

        if (newEvent.isArrival())
        {
            //Remove this event from the event queue
            cout << "Processing an arrival event at time:" << setw(6) << currentTime << endl;
            eventPriorityQueue->dequeue();

            //Process customer if line is empty anb teller is available or add customer to the bank line 
            if (bankLine->isEmpty() && tellerAvailable)
            {
                int departureTime = currentTime + newEvent.getLength();
                Event newDepartureEvent = Event('D', departureTime);
                eventPriorityQueue->enqueue(newDepartureEvent);
                tellerAvailable = false;
            }
            else
                bankLine->enqueue(newEvent);
        }
        else
        {
            //Remove the event from the event queue
            cout << "Processing a departure event at time:" << setw(5) << currentTime << endl;
            eventPriorityQueue->dequeue();

            if (!bankLine->isEmpty())
            {
                //Customer at the front of the line begins transaction
                Event customer = bankLine->peek();
                sumOfWait += (currentTime - customer.getTime());
                bankLine->dequeue();
                int departureTime = currentTime + customer.getLength();
                Event newDepartureEvent = Event('D', departureTime);
                eventPriorityQueue->enqueue(newDepartureEvent);
            }
            else
                tellerAvailable = true;
        }
    }
    
    cout << "Simulation Ends" << endl;

    cout << endl << "Final Statistics:" << endl ;

    cout << endl << "\t" << "Total number of people processed: " << numCustomer << endl;
    cout << "\t" << "Average amount of time spent waiting: " << static_cast<float>(sumOfWait)/static_cast<float>(numCustomer) << endl;
    return 0;
}