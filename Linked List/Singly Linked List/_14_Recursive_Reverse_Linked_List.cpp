#include <bits/stdc++.h>
using namespace std;



struct Node{
    int data ; 
    Node* p;
    Node(int x){
        data = x;
        p =NULL;
    }

};


void insertion(Node *head , int y){
    Node* curr = head ;

    while (curr->p!=NULL)
    {
        curr=curr->p;
        
    }
    curr->p = new Node(y);

}
void Traversal (Node* head){
    Node *curr = head;
    

    while (curr!=NULL)
    {
        cout<<curr->data<<" -> ";
        curr = curr->p;
    }
    cout<<"NULL"<<endl;
    
}

Node* Reverse(Node *head){
    Node *curr = head;
    if(curr == NULL  || curr ->p == NULL) return head;

    Node *temp = curr->p;
    curr->p = NULL;

    while (temp !=NULL)
    {
        Node* swap = temp->p;
        temp->p = curr ;
        curr = temp;
        temp = swap;
    }

    return curr;
    
}



int32_t main() {
    int n ; cin>>n;
    Node *head = NULL;
    for (int i = 0; i <n; i++)
    {
        int y ;cin>>y;
        
        if(i==0){
            head = new Node(y);
        }
        else{
            insertion(head , y);
        }
        
    }

    Traversal(head);
    head = Reverse(head);
    Traversal(head);
    
    
  
    return 0;
}