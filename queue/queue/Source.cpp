#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cstdlib> 
#include <stdexcept>
#include <iostream>
#include "doctest.h"
using namespace std;


 //якщо повна то якось вирішити проблему
class Queue
{
    int* arr;       
    int capacity;   // maximum capacity of the queue
    int front;      // points to the front element in the queue 
    int rear;       // points to the last element in the queue
    int count;      // current size of the queue

public:
    
    Queue(int size)   // Constructor to initialize a queue
    {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }
    
    ~Queue() 
    {
        delete[] arr;
    }
    // returning the front element of the queue
    int peek()
    {
        if (isEmpty())
        {
            throw logic_error("Data structure is empty");
        }
        return arr[front];
    }
    // returning the size of the queue
    int size() 
    {
        return count;
    }

    // checking if the queue is empty or not
    bool isEmpty() 
    {
        return (size() == 0);
    }

    // checking if the queue is full or not
    bool isFull() 
    {
        return (size() == capacity);
    }

    // adds an item to the queue
    void insert(int item)
    {
       /* try
        {*/
            // check for queue overflow
            if (isFull())
            {
                throw logic_error("Data structure is full");
            }
            rear = (rear + 1) % capacity;
            arr[rear] = item;
            count++;
       /* }
        catch (logic_error e)
        {
            cerr << "Error:" << e.what() << endl;
        }*/
    }
    // removes the front element and returns it
    int remove()
    {
        /*try
        {*/
            // check for queue underflow
            if (isEmpty())
            {
                throw logic_error("Data structure is empty");
            }

            int x = arr[front];
            front = (front + 1) % capacity;
            count--;
            return x;
        }
  /*        catch (logic_error e)
      {
          cerr << "Error:" << e.what() << endl;
      }
    }*/
};
//TEST_CASE("Erasing values from table")
//{
//    Table table;
//    table.Set(1, "Hello");
//    table.Set(2, "World");
//    table.Set(3, "!");
//    table.EraseByKey(1);
//    table.EraseByKey(2);
//    table.EraseByKey(3);
//    CHECK_THROWS(table.Get(1));
//    CHECK_THROWS(table.Get(2));
//    CHECK_THROWS(table.Get(3));
//}
TEST_CASE("Queue initialization and size check")
{
    Queue q(5);
    CHECK(q.size() == 0);
}

TEST_CASE("Inserting elements into queue")
{
    Queue q(3);
    q.insert(10);
    q.insert(20);
    q.insert(30);
    // Trying to insert into a full queue should throw an exception
    CHECK_THROWS(q.insert(40));
}

TEST_CASE("Removing elements from queue")
{
    Queue q(3);
    q.insert(10);
    q.insert(20);
    q.insert(30);
    CHECK(q.remove() == 10);
    CHECK(q.remove() == 20);
    CHECK(q.remove() == 30);
    // Trying to remove from an empty queue should throw an exception
    CHECK_THROWS(q.remove());
    q.insert(10);
    q.insert(20);
    q.insert(30);
    CHECK(q.remove() == 10);
    q.insert(30);
    CHECK(q.remove() == 20);
    
}

TEST_CASE("Peeking into the front of the queue")
{
    Queue q(3);
    q.insert(10);
    q.insert(20);
    q.insert(30);
    CHECK(q.peek() == 10);
    q.remove();
    CHECK(q.peek() == 20);
    q.remove();
    CHECK(q.peek() == 30);
    q.remove();
    // Trying to peek into an empty queue should throw an exception
    CHECK_THROWS(q.peek());
}
