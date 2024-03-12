/*
 * Queue.cpp
 *
 * Implementation of Queue class
 *
 * Written by Dyson Carter
 */

#include "Queue.hpp"
#include <iostream>

Queue::Queue() {
    head = &frameRing[0];
    tail = &frameRing[0];
    count = 0;
}

int Queue::enqueue(Frame& EnqueuedFrame) {
    if (isFull()) {
        std::cout << "------------------------------------------------------------\n";
        std::cout << "Overflow Error: Queue is full\n";
        std::cout << "------------------------------------------------------------\n";
        return -1;
    }

    *tail = EnqueuedFrame;
    count++;

    std::cout << "------------------------------------------------------------\n";
    std::cout << "Succesfully Enqueued Destination = " << tail->dest << " | Payload = " << tail->PL << "\n";
    std::cout << "------------------------------------------------------------\n";

    if (!isFull())
        increment(tail);

    return 0;
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "------------------------------------------------------------\n";
        std::cout << "Underflow Error: Queue is empty\n";
        std::cout << "------------------------------------------------------------\n";
        return -1;
    }

    if(isFull())
        increment(tail);

    std::cout << "------------------------------------------------------------\n";
    std::cout << "Succesfully Dequeued Destination = " << head->dest << " | Payload = " << head->PL << "\n";
    std::cout << "------------------------------------------------------------\n";

    *head = Frame(); // Resetting frame to default values
    increment(head);
    count--;

    return 0;
}

int Queue::showQueue() {
    if (isEmpty()) {
        std::cout << "------------------------------------------------------------\n";
        std::cout << "Queue is Empty, Nothing to Display\n";
        std::cout << "------------------------------------------------------------\n";
        return -1;
    }

    std::cout << "------------------------------------------------------------\n";

    int i = 1;
    Frame *temp = head;
    while (temp != tail) {
        std::cout << "Queue Space " << i << ": Destination = " << temp->dest << " | Payload = " << temp->PL << "\n";
        increment(temp);
        i++;
    }
    if (isFull())
        std::cout << "Queue Space " << i << ": Destination = " << tail->dest << " | Payload = " << tail->PL << "\n";

    std::cout << "------------------------------------------------------------\n";

    return 0;
}

bool Queue::isFull(){
    return count == MAX_QUEUE_SIZE;
}

bool Queue::isEmpty(){
    return count == 0;
}

int Queue::increment(Frame *&ptr){
    ptr++;
    if (ptr == &frameRing[MAX_QUEUE_SIZE]) {
        ptr = &frameRing[0];
    }
    return 0;
}
