#include <iostream>
using namespace std;

struct node
{
    int roll_no;
    node *next;
};

int main()
{
    node *head = NULL;
    node *nn;

    nn = new node;

    cout << "Enter Roll Number: ";
    cin >> nn->roll_no;

    nn->next = NULL;

    if (head == NULL)
    {
        head = nn;
    }

    cout << "Linked List: ";

    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->roll_no << " -> ";
        temp = temp->next;
    }

    cout << "NULL";

    return 0;
}