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


Node *reverse_The_Linked(Node *head )
{
    if(head == NULL || head ->p ==NULL){
        return head;
    }

    Node *curr = head ; 
    Node *temp = head->p;

    curr->p = NULL;

    while(temp != NULL){

        Node *saviour_Next_Element = temp->p;

        temp->p = curr;
        
        curr = temp;
        temp = saviour_Next_Element;
    }
    return curr;
}



int main()

{
    int a;
    cin >> a;

   
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

    head = reverse_The_Linked(head);

    
    Traversal(head);


    return 0;
}
