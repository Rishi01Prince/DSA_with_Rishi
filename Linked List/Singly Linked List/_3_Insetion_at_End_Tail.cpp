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

    Node *temp =  new Node(element);
    tail->p = temp;


    return temp;
}

int main()

{
    int a;
    cin >> a;

    // Let us do using tail Pointer

    Node *tail = NULL;
    Node *head =NULL;

    for (int i = 0; i < a; i++)
    {
        int element;
        cin >> element;
        if(i==0){
            head = new Node(element);
            tail = head;
        }
        else{
            tail = insertion_at_End_tail(tail, element);
        }
        
    }

    Traversal(head);

    int num;
    cin >> num;
    tail = insertion_at_End_tail(tail, num);

    Traversal(head);
}
