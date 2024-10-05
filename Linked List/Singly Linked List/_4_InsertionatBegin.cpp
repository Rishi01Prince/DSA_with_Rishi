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

Node *insertion_at_Begin(Node *head,int element)
{
    Node *temp = new Node(element);
    temp->p = head;
    return temp;
}





int main()

{
    int a;

    // cout << "Please Enter the Number of linked list you want to enter : " << endl;
    cin >> a;
    Node *head = NULL;

    for (int i = 0; i < a; i++)

    {
        int element ;
        cin>>element;
        head = insertion_at_Begin(head, element);
    }
    Traversal(head);

    
    int num ;
    cin>>num;
    head = insertion_at_Begin(head, num);

    Traversal(head);
    return 0 ;

}
