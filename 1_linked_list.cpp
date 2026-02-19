#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertattheHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertAttheTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    cout << "null" << endl;
}




int main()
{
    node *head = NULL;
    insertAttheTail(head, 1);
    insertAttheTail(head, 2);
    insertAttheTail(head, 3);
    display(head);

    return 0;
}
