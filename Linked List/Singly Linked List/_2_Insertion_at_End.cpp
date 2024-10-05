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

// Using head Pointer O(n)

Node *insertion_at_End(Node *head, int element)
{

    if (head == NULL)
    {
        Node *temp = new Node(element);
        return temp;
    }
    Node *temp2 = head;

    while (head->p != NULL)
    {
        head = (head->p);
        
    }

    Node *temp = new Node(element);
    head->p = temp;

    return temp2;
}

int main()

{
    int a;
    cin >> a;


    Node *head = NULL;

    for (int i = 0; i < a; i++)
    {
        int element;
        cin >> element;
        head = insertion_at_End(head, element);
    }
    Traversal(head);

    int num;
    cin >> num;
    head = insertion_at_End(head, num);

    Traversal(head);


    return 0;
}
