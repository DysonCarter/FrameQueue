/*
 * Queue.hpp
 *
 * Include file of Queue class using Ring Buffer Method
 *
 * Written by Dyson Carter
 */

#ifndef QUEUE_QUEUE_HPP
#define QUEUE_QUEUE_HPP

#include <string>

const int MAX_QUEUE_SIZE = 6;

struct Frame {
    int dest;
    std::string PL;
};

class Queue {
private:
    Frame frameRing[MAX_QUEUE_SIZE]; //Queue
    Frame *head; // first element in the queue
    Frame *tail; // where next element will be inserted
    int count; // Number of elements currently in the queue

    /**
     * checks if Queue is full
     * @retval true if full, false if not
     */
    bool isFull();
    /**
     * checks if Queue is empty
     * @retval true if full, false if not
     */
    bool isEmpty();
    /**
     * increments the pointer using the ring buffer method
     * @param[in/out] ptr reference of pointer to be incremented
     * @retval 0 for success, -1 for failure
     */
    int increment(Frame *&ptr);
public:
    /**
     * Constructor for Queue class
     */
    Queue();
    /**
     * Enqueues Given Frame into Queue
     * @param[in] EnqueuedFrame reference of Frame to be enqueued
     * @retval 0 for success, -1 for failure
     */
    int enqueue(Frame& EnqueuedFrame);
    /**
     * Dequeues first Frame in
     * @retval 0 for success, -1 for failure
     */
    int dequeue();
    /**
     * Shows all Frames in Queue
     * @retval 0 for success, -1 for failure
     */
    int showQueue();
};

#endif //QUEUE_QUEUE_HPP
