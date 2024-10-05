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

    // Here You can also use
    // Node *curr = head
    while (head != NULL)
    {
        cout << (head->data) << " -> ";
        head = (head->p);
    }
    cout << " NULL " << endl;
}

// Recursive way to Print Linked List

void Recursive_Traversal(Node *head)
{

    if (head == NULL)
    {
        cout << "  NULL " << endl;
        return;
    }
    else
    {
        cout << (head->data) << " -> ";
        Recursive_Traversal(head->p);
    }
}

void Insertion(Node *head,int ele,int pos)
{
    Node *temp = new Node(ele);
    int i =0;
    while (i<pos-1)
    {
        i++;
        head = (head->p);
    }
    Node *t =head->p;
    head->p = temp;
    temp->p = t;
    

    
}

int main()
{
    cout << "Please Enter the Number of linked list you want to enter : " << endl;

    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(40);
    Node *d = new Node(30);

    a->p = b;
    b->p = c;
    c->p = d;
    Traversal(a);
    cout << "Recursive Traversal  " << endl;
    Recursive_Traversal(a); 

    int element, position;
    cin>>element>>position;

    Insertion(a, element, position);
     Traversal(a);
    return 0 ;
}