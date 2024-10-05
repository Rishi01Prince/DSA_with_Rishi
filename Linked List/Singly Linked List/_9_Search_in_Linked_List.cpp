#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *p;
    Node(int x)
    {
        data = x;
        p = NULL;
    }
};

void Traversal(Node *head)
{
    while (head != NULL)
    {
        cout << (head->data) << " -> ";
        head = (head->p);
    }
    cout << " NULL " << endl;
}
Node *insertion_at_End_tail(Node *tail, int element)
{

    Node *temp = new Node(element);
    tail->p = temp;

    return temp;
}

int Search_Linked_List(Node *head, int element)
{
    int i = 0;

    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == element)
        {
            return i;
        }
        curr = curr->p;
        i++;
    }
    return -1;
}

int Recursive_Search_Linked_List(Node *head, int element, int i)
{

    if (head == NULL)
    {
        return -1;
    }
    else if (element == head->data)
    {

        return i;
    }
    else
    {

        return Recursive_Search_Linked_List(head->p, element, i + 1);
    }
}

int main()
{
    int a;

    cin >> a;
    Node *tail = NULL;
    Node *head = NULL;

    for (int i = 0; i < a; i++)
    {
        int element;
        cin >> element;
        if (i == 0)
        {
            head = new Node(element);
            tail = head;
        }
        else
        {
            tail = insertion_at_End_tail(tail, element);
        }
    }

    Traversal(head);

    int element;
    cin >> element;

    cout << "Linear Search : " << Search_Linked_List(head, element) << endl;
    cout << "Recursive Search :" << Recursive_Search_Linked_List(head, element, 0) << endl;

    return 0;
}
