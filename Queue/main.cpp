/*
 * main.cpp
 *
 * Main program to show use of Queue data structure.
 * Enqueue, Dequeue, And show queue options
 * Queue is made up of Frames, containing a destination (int) and payload (char[6]
 *
 * Written by Dyson Carter
 */

#include <iostream>
#include <limits>
#include "Queue.hpp"

int main() {
    int choice = 0;
    Queue example;

    while (true) {
        std::cout << "What would you like to do?\n"
                     "Enqueue a Frame:      Enter 1\n"
                     "Dequeue a Frame:      Enter 2\n"
                     "Show the Queue:       Enter 3\n"
                     "Quit:                 Enter 0\n";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int frameDest;
                std::string framePL;

                while (true) {
                    std::cout << "Please enter the destination of your frame (int):\n";
                    std::cin >> frameDest;

                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        std::cout << "Invalid input. Please enter an integer.\n";
                        continue;
                    }

                    break;
                }

                std::cout << "Please enter the payload of your frame (Maximum length 6):\n";
                std::cin >> framePL;

                Frame enteredFrame;
                enteredFrame.dest = frameDest;
                enteredFrame.PL = framePL.substr(0, 6);

                example.enqueue(enteredFrame);
                break;
            }
            case 2:
                example.dequeue();
                break;
            case 3:
                example.showQueue();
                break;
            case 0:
                return 0;
            default:
                std::cout << "INPUT ERROR, please try again!\n";
                break;
        }
    }
}
