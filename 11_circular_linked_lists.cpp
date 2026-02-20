#include <iostream>

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
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertattheTail(node *&head, int val)
{

    if (head == NULL)
    {
        insertattheHead(head, val);
        return;
    }
    node *n = new node(val);

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void display(node *head)
{
    node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp->next != head);

    cout << endl;
}

void deleteattheHead(node *&head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    node *toDelete = head;
    temp->next = head->next;
    delete toDelete;
}
void deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteattheHead(head);
        return;
    }

    node *temp = head;
    int count = 1;
    while (count != pos - 1)
    {
        temp = temp->next;
    }
    node *toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}

int main()
{
    node *head = NULL;

    insertattheTail(head, 1);
    insertattheTail(head, 2);
    insertattheTail(head, 3);
    insertattheTail(head, 4);
    insertattheTail(head, 5);
    display(head);
    deletion(head, 2);
    display(head);

    return 0;
}