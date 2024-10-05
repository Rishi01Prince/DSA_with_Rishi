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

    Node *temp =  new Node(element);
    tail->p = temp;


    return temp;
}


 
Node *insertion_at_Given_Position(Node *head, int element,int position)
{
    int i =0;
    Node *curr = head;
    while (i<(position-1))
    {
        curr= curr->p;       
        i++;
    }
    Node *temp = new Node(element);
    temp->p = curr->p;
    curr->p = temp;
    

    return head;
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

    int element,position;
    cin >> element>>position;

    head = insertion_at_Given_Position(head, element, position);
    //   head=       deleteMiddle(head);
      Traversal(head);
    Traversal(head);
    return 0;
}
