/*
Name: Ankita Singh
Roll No.: 23354
Batch: G-11
*/

#include <iostream>
using namespace std;

class Queue
{
    string *arr;
    int front, rear, n = 5;

public:
    Queue()
    {
        front = -1;
        rear = -1;
        arr = new string[5];
    }

    // Checking if the queue is full
    bool isFull()
    {
        if (front == 0 && rear == n - 1)
        {
            return true;
        }
        if (front == rear + 1)
        {
            return true;
        }
        return false;
    }

    // Checking if the queue is empty
    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Adding an element
    void enQueue(string element)
    {
        if (isFull())
        {
            cout << endl
                 << "Queue is full" << endl;
        }
        else
        {
            if (rear == -1)
            {
                front = 0, rear = 0;
            }
            else if (rear == n - 1)
            {
                rear = 0;
            }
            else
            {
                rear++;
            }
            arr[rear] = element;
            cout << endl
                 << "Inserted " << element << endl;
        }
    }

    // Deleting an element
    string deQueue()
    {
        string element;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return ("-1");
        }
        else
        {
            element = arr[front];
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            // Since Q has only one element, we reset the queue after deleting it.
            else if (front == n - 1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
            return (element);
        }
    }

    void display()
    {
        // Function to display Circular Queue
        int i;
        if (isEmpty())
        {
            cout << endl
                 << "Empty Queue" << endl;
        }
        else if (front > rear)
        {
            cout << endl
                 << "Items: ";
            for (int i = front; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
};

int main()
{
    Queue queue;

    while (true)
    {
        char option;
        string element;
        cout << endl
             << "Enter your choice : " << endl;
        cout << "1.EnQueue" << endl;
        cout << "2.DeQueue" << endl;
        cout << "3.Display the queue" << endl;
        cout << "4.Exit" << endl
             << endl;
        cout << "Your Option : ";
        cin >> option;
        cout << endl;
        switch (option)
        {
        case '1':
            cout << "Enter the name you want to insert in queue : ";
            cin >> element;
            queue.enQueue(element);
            break;
        case '2':
            element = queue.deQueue();
            if (element != "")
            {
                cout << "Deleted name from queue : " << element << endl;
            }
            break;
        case '3':
            queue.display();
            break;
        case '4':
            cout << "Exit" << endl;
            exit(0);
        default:
            cout << "Incorrect option." << endl;
            break;
        }
    }

    return 0;
}
