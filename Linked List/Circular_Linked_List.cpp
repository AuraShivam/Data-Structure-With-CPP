// Circular Linked List in C++

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *tail = NULL;

// Create Circular Linked List
void create()
{
    int n;

    cout << "How Many Elements You want to add: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        Node *newNode = new Node();

        cout << "Enter data for node " << i << ": ";
        cin >> newNode->data;

        if (tail == NULL)
        {
            tail = newNode;
            tail->next = tail;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }
}

// Display Linked List
void display()
{
    if (tail == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }

    Node *temp = tail->next;

    cout << "Linked List: ";

    do
    {
        cout << temp->data << " ";
        temp = temp->next;

    } while (temp != tail->next);

    cout << endl;
}

// Insert at Beginning
void insertAtBeg()
{
    Node *newNode = new Node();

    cout << "Enter the data you want to insert: ";
    cin >> newNode->data;

    if (tail == NULL)
    {
        tail = newNode;
        tail->next = tail;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

// Insert at End
void insertAtEnd()
{
    Node *newNode = new Node();

    cout << "Enter the data you want to insert: ";
    cin >> newNode->data;

    if (tail == NULL)
    {
        tail = newNode;
        tail->next = tail;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

// Insert at Position
void insertAtPos()
{
    int pos;

    cout << "Enter Position: ";
    cin >> pos;

    if (pos == 1)
    {
        insertAtBeg();
        return;
    }

    Node *temp = tail->next;

    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    Node *newNode = new Node();

    cout << "Enter data to be inserted: ";
    cin >> newNode->data;

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from Beginning
void delAtBeg()
{
    if (tail == NULL)
    {
        cout << "Linked List is Empty" << endl;
    }
    else if (tail->next == tail)
    {
        delete tail;
        tail = NULL;
    }
    else
    {
        Node *temp = tail->next;

        tail->next = temp->next;

        delete temp;
    }
}

// Delete from End
void delAtEnd()
{
    if (tail == NULL)
    {
        cout << "Linked List is Empty" << endl;
    }
    else if (tail->next == tail)
    {
        delete tail;
        tail = NULL;
    }
    else
    {
        Node *current = tail->next;

        while (current->next != tail)
        {
            current = current->next;
        }

        current->next = tail->next;

        delete tail;

        tail = current;
    }
}

// Delete at Position
void delAtPos()
{
    int pos;

    cout << "Enter Position to delete: ";
    cin >> pos;

    if (pos == 1)
    {
        delAtBeg();
        return;
    }

    Node *current = tail->next;

    for (int i = 1; i < pos - 1; i++)
    {
        current = current->next;
    }

    Node *temp = current->next;

    current->next = temp->next;

    delete temp;
}

// Search Element
void search()
{
    if (tail == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }

    int x, pos = 1;
    bool found = false;

    cout << "Enter element to search: ";
    cin >> x;

    Node *temp = tail->next;

    do
    {
        if (temp->data == x)
        {
            found = true;
            break;
        }

        temp = temp->next;
        pos++;

    } while (temp != tail->next);

    if (found)
    {
        cout << "Element found at position "
             << pos << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
}

// Length of Linked List
void get_length()
{
    if (tail == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }

    int count = 0;

    Node *temp = tail->next;

    do
    {
        count++;
        temp = temp->next;

    } while (temp != tail->next);

    cout << "Length of Linked List is "
         << count << endl;
}

// Reverse Circular Linked List
void reverse()
{
    if (tail == NULL || tail->next == tail)
    {
        display();
        return;
    }

    Node *prev = tail;
    Node *current = tail->next;
    Node *nextNode;

    do
    {
        nextNode = current->next;
        current->next = prev;

        prev = current;
        current = nextNode;

    } while (current != tail->next);

    tail = current;

    display();
}

int main()
{
    int opt;

    while (1)
    {
        cout << "\nWhich operation do you want to perform?" << endl;

        cout << "1. Create Linked List" << endl;
        cout << "2. Display" << endl;
        cout << "3. Search" << endl;
        cout << "4. Insert at Beginning" << endl;
        cout << "5. Insert at End" << endl;
        cout << "6. Insert at Position" << endl;
        cout << "7. Delete from Beginning" << endl;
        cout << "8. Delete from End" << endl;
        cout << "9. Delete at Position" << endl;
        cout << "10. Reverse" << endl;
        cout << "11. Length of Linked List" << endl;
        cout << "12. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            create();
            break;

        case 2:
            display();
            break;

        case 3:
            search();
            break;

        case 4:
            insertAtBeg();
            break;

        case 5:
            insertAtEnd();
            break;

        case 6:
            insertAtPos();
            break;

        case 7:
            delAtBeg();
            break;

        case 8:
            delAtEnd();
            break;

        case 9:
            delAtPos();
            break;

        case 10:
            reverse();
            break;

        case 11:
            get_length();
            break;

        case 12:
            return 0;

        default:
            cout << "Unknown Choice!!" << endl;
        }
    }

    return 0;
}
