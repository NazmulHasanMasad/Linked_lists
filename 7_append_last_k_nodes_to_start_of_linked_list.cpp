#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        next = NULL;
    }
};

void insertatHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;

    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

void insertAttheTAil(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        insertatHead(head, val);
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

void deleteAttheHead(node *&head)
{
    node *toDelete = head;
    head = head->next;
    head->prev = NULL;
    delete toDelete;
}

void deletion(node *head, int pos)
{
    if (head == NULL)
    {
        return;
    }
    if (pos == 1)
    {
        deleteAttheHead(head);
    }

    node *temp = head;
    int count = 1;
    while (temp != 0 && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;

    if (temp->next != 0)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

int length(node *head)
{
    node *temp = head;
    int l = 0;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

node *kappend(node *&head, int k)
{
    node *newTail;
    node *newHead;
    node *tail = head;

    int l = length(head);
    k = k % l;
    int count = 1;
    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newTail = tail;
        }
        if (count == l - k + 1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

int main()
{
    node *head = NULL;
    insertAttheTAil(head, 1);
    insertAttheTAil(head, 2);
    insertAttheTAil(head, 3);
    insertAttheTAil(head, 4);
    insertAttheTAil(head, 5);
    display(head);

    node *newH = kappend(head, 3);
    display(newH);

    return 0;
}