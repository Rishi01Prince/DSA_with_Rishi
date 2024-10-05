#include <bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node *f;
    Node *b;


    Node(int x){
        data =x;
        f=NULL;
        b=NULL;
    }
};

Node *Insertion_At_Front(Node *head,  int data){

    if(head == NULL){
        return head;
    }
    Node *temp = new Node(data);
    temp->f = head;
    head->b  = temp;

    return temp;
}

void Traversal(Node *head){
    Node *curr = head;
    while(curr!=NULL ){
        cout<<curr->data<<" -> ";
        curr= curr->f;

    }
    cout<<"NULL"<<endl;
}

int main() {
    int n;cin>>n;

    Node *head = NULL;
    Node *tail = NULL;


    for (int i = 0; i < n; i++)
    {
        if(i==0){
            int element ; cin>>element;
            head = new Node(element);
            tail = head;
        }
        else{
            int element ; cin>>element;
            head  = Insertion_At_Front(head,  element);
            
        }
    }

    Traversal(head);
    
    return 0;
}