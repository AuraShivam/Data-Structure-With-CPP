// Circular Queue using Array in C++

#include <iostream>
using namespace std;

#define N 50

int q[N];

int front = -1;
int rear = -1;

// Enqueue Operation
void enqueue()
{
    int x;

    cout << "Enter data to be enqueued: ";
    cin >> x;

    // Queue Full Condition
    if ((rear + 1) % N == front)
    {
        cout << "Queue is Full" << endl;
    }

    // First Element Insertion
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        q[rear] = x;
    }

    // Normal Insertion
    else
    {
        rear = (rear + 1) % N;
        q[rear] = x;
    }
}

// Dequeue Operation
void dequeue()
{
    // Queue Empty Condition
    if (front == -1 && rear == -1)
    {
        cout << "Queue Underflow" << endl;
    }

    // Only One Element Present
    else if (front == rear)
    {
        cout << "Dequeued Element: " << q[front] << endl;

        front = rear = -1;
    }

    // Normal Deletion
    else
    {
        cout << "Dequeued Element: " << q[front] << endl;

        front = (front + 1) % N;
    }
}

// Peek Operation
void peek()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Front Element: " << q[front] << endl;
    }
}

// Display Operation
void display()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        int i = front;

        cout << "Queue Elements are: ";

        while (i != rear)
        {
            cout << q[i] << " ";
            i = (i + 1) % N;
        }

        cout << q[rear] << endl;
    }
}

int main()
{
    int ch;

    while (1)
    {
        cout << "\n*** Queue Menu ***" << endl;

        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Peek" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            peek();
            break;

        case 5:
            return 0;

        default:
            cout << "Wrong Choice!!" << endl;
        }
    }

    return 0;
}
