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
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void evenafterOdd(node *&head)
{
    node *odd = head;
    node *even = head->next;
    node *evenstart = even;
    while (odd->next != 0 && even->next != 0)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenstart;
    if (even->next != NULL)
    {
        even->next = NULL;
    }
}

int main()
{
    node *head = NULL;
    insertAttheTail(head, 1);
    insertAttheTail(head, 2);
    insertAttheTail(head, 3);
    insertAttheTail(head, 4);
    insertAttheTail(head, 5);
    insertAttheTail(head, 6);
    evenafterOdd(head);
    display(head);

    return 0;
}
