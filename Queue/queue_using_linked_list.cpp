// Queue using Linked List in C++

#include <iostream>
using namespace std;

struct Queue
{
    int data;
    Queue *next;
};

Queue *front = NULL;
Queue *rear = NULL;

// Enqueue Operation
void enqueue(int x)
{
    Queue *newNode = new Queue();

    newNode->data = x;
    newNode->next = NULL;

    // Queue Empty Condition
    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << x << " inserted into Queue" << endl;
}

// Dequeue Operation
void dequeue()
{
    // Queue Empty Condition
    if (front == NULL && rear == NULL)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        Queue *temp = front;

        cout << "Element dequeued is "
             << front->data << endl;

        front = front->next;

        // If Queue becomes empty
        if (front == NULL)
        {
            rear = NULL;
        }

        delete temp;
    }
}

// Peek Operation
void peek()
{
    if (front == NULL && rear == NULL)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Front Element is "
             << front->data << endl;
    }
}

// Display Operation
void display()
{
    if (front == NULL && rear == NULL)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        Queue *temp = front;

        cout << "Queue Elements are: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
}

int main()
{
    int opt, value;

    while (1)
    {
        cout << "\nWhich operation do you want to perform?" << endl;

        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> value;

            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid Choice" << endl;
        }
    }

    return 0;
}
