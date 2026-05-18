// Implementation of Stack using Array in C++

#include <iostream>
using namespace std;

#define N 50

int st[N];
int top = -1;

void push()
{
    int x;

    cout << "Enter The Element to push: ";
    cin >> x;

    if (top == N - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        st[top] = x;

        cout << x << " pushed to Stack" << endl;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        int item = st[top];
        top--;

        cout << "Popped: " << item << endl;
    }
}

void peek()
{
    if (top == -1)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Top Element: " << st[top] << endl;
    }
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is Empty" << endl;
        return;
    }

    cout << "Displaying Stack..." << endl;

    for (int i = top; i >= 0; i--)
    {
        cout << st[i] << " ";
    }

    cout << endl;
}

int main()
{
    int ch;

    while (1)
    {
        cout << "\n*** Stack Menu ***";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Display";
        cout << "\n4. Peek";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
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
