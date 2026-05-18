// Circular Queue using Linked List in C++

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

// Enqueue Operation
void enqueue()
{
    int x;

    cout << "Enter Data to be Enqueued: ";
    cin >> x;

    Node *newNode = new Node();

    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
        rear->next = front;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    cout << x << " inserted into Queue" << endl;
}

// Dequeue Operation
void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        cout << "Queue is Empty" << endl;
    }
    else if (front == rear)
    {
        Node *temp = front;

        cout << "Deleted Element: " << temp->data << endl;

        front = rear = NULL;

        delete temp;
    }
    else
    {
        Node *temp = front;

        cout << "Deleted Element: " << temp->data << endl;

        front = front->next;
        rear->next = front;

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
        cout << "Front Element is " << front->data << endl;
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
        Node *temp = front;

        cout << "Queue Elements are: ";

        do
        {
            cout << temp->data << " ";
            temp = temp->next;

        } while (temp != front);

        cout << endl;
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
