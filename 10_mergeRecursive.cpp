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

node *merge(node *head1, node *head2)
{
    node *ptr1 = head1;
    node *ptr2 = head2;

    node *dummyNode = new node(-1);
    node *ptr3 = dummyNode;

    while (ptr1->next != NULL && ptr2->next != NULL)
    {
        if (ptr1->data < ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    while (ptr1->next != NULL)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }

    while (ptr2->next != NULL)
    {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }
    return dummyNode->next;
}

node *mergeRecursive(node *head1, node *head2)
{

    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    return result;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    insertAttheTAil(head1, 1);
    insertAttheTAil(head1, 4);
    insertAttheTAil(head1, 5);
    insertAttheTAil(head1, 7);
    insertAttheTAil(head1, 9);
    insertAttheTAil(head2, 2);
    insertAttheTAil(head2, 3);
    insertAttheTAil(head2, 6);
    insertAttheTAil(head2, 10);

    node *newHead = mergeRecursive(head1, head2);
    display(newHead);

    return 0;
}