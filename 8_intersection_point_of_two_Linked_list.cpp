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
void intersect(node *head1, node *head2, int pos)
{
    node *temp1 = head1;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int intersection(node *head1, node *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return -1;
    }
    node *temp1 = head1;
    node *temp2 = head2;
    while (temp1 != temp2)
    {
        temp1 = (temp1 == NULL) ? head2 : temp1->next;
        temp2 = (temp2 == NULL) ? head1 : temp2->next;
    }
    return (temp1 != NULL) ? temp1->data : -1; // Return the data of the intersection point or -1 if no intersection
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    insertAttheTAil(head1, 1);
    insertAttheTAil(head1, 2);
    insertAttheTAil(head1, 3);
    insertAttheTAil(head1, 4);
    insertAttheTAil(head1, 5);
    insertAttheTAil(head2, 6);
    insertAttheTAil(head2, 9);
    insertAttheTAil(head2, 10);
    intersect(head1, head2, 3);
    display(head1);
    display(head2);
    cout << intersection(head1, head2) << endl; // Should print the intersection point's data
    return 0;
}