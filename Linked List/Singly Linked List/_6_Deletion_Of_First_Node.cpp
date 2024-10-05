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

Node *Deletion_at_Begin(Node *head)
{
    if(head == NULL ){
        return NULL;
    }
    else{
        
        Node *temp = head->p;
        delete head;
        return temp;
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

    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        head = Deletion_at_Begin(head);
    }

    Traversal(head);
    return 0;
}
