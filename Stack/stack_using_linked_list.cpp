// Implementation of Stack using Linked List in C++

#include <iostream>
using namespace std;

struct Stack
{
    int data;
    Stack *next;
};

Stack *top = NULL;

// Push Operation
void push()
{
    int x;

    cout << "Enter Element to be pushed: ";
    cin >> x;

    Stack *newNode = new Stack();

    newNode->data = x;
    newNode->next = top;

    top = newNode;

    cout << x << " pushed into stack" << endl;
}

// Pop Operation
void pop()
{
    if (top == NULL)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        Stack *temp = top;

        cout << "Popped Element is " << top->data << endl;

        top = top->next;

        delete temp;
    }
}

// Peek Operation
void peek()
{
    if (top == NULL)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Top Element is " << top->data << endl;
    }
}

// Display Operation
void display()
{
    if (top == NULL)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        Stack *temp = top;

        cout << "Stack Elements are: ";

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
    int opt;

    while (1)
    {
        cout << "\nWhich operation do you want to perform?" << endl;

        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cin >> opt;

        switch (opt)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
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
            cout << "Unknown Operation" << endl;
        }
    }

    return 0;
}
