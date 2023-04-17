#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
#include "doctest.h"
using namespace std;

class PriorityQueue 
{
private:
    struct Item 
    {
        int value;
        int priority;
    };

    vector<Item> pr; // Store the elements of the priority queue
    int size; // Number of elements in the priority queue

public:
    // Constructor
    PriorityQueue() {
        size = 0;
    }

    // Function to insert a new element
    void enqueue(int value, int priority) {
        Item newItem;
        newItem.value = value;
        newItem.priority = priority;
        pr.push_back(newItem);
        size++;
    }

    // Function to check the index of the top element
    int peek() {
        if (size == 0) {
            cerr << "Error: Priority queue is empty." << endl;
            return -1; // Return an invalid index
        }

        int highestPriority = INT_MIN;
        int ind = -1;

        // Check for the element with highest priority
        for (int i = 0; i < size; i++) {
            if (highestPriority == pr[i].priority && ind > -1 && pr[ind].value < pr[i].value) {
                highestPriority = pr[i].priority;
                ind = i;
            }
            else if (highestPriority < pr[i].priority) {
                highestPriority = pr[i].priority;
                ind = i;
            }
        }

        return ind;
    }

    // Function to remove the element with the highest priority
    void dequeue() {
        if (size == 0) {
            cerr << "Error: Priority queue is empty." << endl;
            return;
        }

        int ind = peek(); // Find the position of the element with the highest priority

        // Shift the elements one index before the position of the element with the highest priority
        for (int i = ind; i < size - 1; i++) {
            pr[i] = pr[i + 1];
        }

        pr.pop_back();
        size--;
    }

    // Function to resize the priority queue
    void resize(int newSize)
    {
        pr.resize(newSize);
        size = min(size, newSize);
    }

    // Function to check if the priority queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to get the number of elements in the priority queue
    int getSize() {
        return size;
    }
};
TEST_CASE("Testing enqueue function")
{
    PriorityQueue pq;
    pq.enqueue(5, 2);
    pq.enqueue(3, 1);
    pq.enqueue(7, 3);
    CHECK(pq.getSize() == 3);
}

TEST_CASE("Testing dequeue function")
{
    PriorityQueue pq;
    pq.enqueue(5, 2);
    pq.enqueue(3, 1);
    pq.enqueue(7, 3);
    pq.dequeue();
    CHECK(pq.getSize() == 2);
    CHECK(pq.peek() == 0);
}

TEST_CASE("Testing resize function")
{
    PriorityQueue pq;
    pq.enqueue(5, 2);
    pq.enqueue(3, 1);
    pq.enqueue(7, 3);
    pq.resize(2);
    CHECK(pq.getSize() == 2);
    CHECK(pq.peek() == 0);
}