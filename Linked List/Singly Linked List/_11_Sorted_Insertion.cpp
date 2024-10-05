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
// Insertion at the End using tail Recursion O(1)

Node *insertion_at_End_tail(Node *tail, int element)
{

    Node *temp = new Node(element);
    tail->p = temp;

    return temp;
}

Node *Sorted_Insertion(Node *dummy, int element)
{
    Node *dummy_default = dummy;
    bool x = false;
    if (dummy->p == NULL)
    {
        Node *temp = new Node(element);
        dummy->p = temp;
        return dummy_default;
    }
    
    if(element < ((dummy->p)->data)){
       
        Node *temp = new Node(element);
        temp->p = dummy->p;
        dummy->p = temp;
        return dummy_default;

    }
    

    Node *curr = dummy->p->p;
    dummy = dummy->p;
    
    while (curr->p != NULL)
    {
        if ((dummy->data <= element)  && (element<=curr->data))
        {
            Node *temp = new Node(element);
            temp->p = curr;
            dummy->p = temp;
            x = true;
            return dummy_default;
        }

        dummy= curr;
        curr = curr->p;
    }

    if (x == false)
    {
        Node *temp = new Node(element);
        curr->p = temp;
        return dummy_default;
    }
}

int main()

{
    int a;
    cin >> a;

    Node *tail = NULL;
    Node *head = NULL;
    Node *dummy = new Node(-1);

    for (int i = 0; i < a; i++)
    {
        int element;
        cin >> element;
        if (i == 0)
        {
            head = new Node(element);
            dummy->p = head;
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
    dummy = Sorted_Insertion(dummy, element);
    head = dummy->p;
    Traversal(head);
    return 0;
}
