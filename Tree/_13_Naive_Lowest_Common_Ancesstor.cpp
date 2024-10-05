#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Binary_Tree
{
public:
    Node *root = NULL;

    void Default_Tree()
    {
        root = new Node(1);

        root->left = new Node(2);
        root->right = new Node(3);

        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right->left = new Node(6);
        root->right->right = new Node(7);

        root->left->left->left = new Node(8);
        root->right->right->right = new Node(9);
    }


    //Time Complexity : O(n),  As it is Simple Tree Traversal with some Constraints

    bool LCS_path(Node* curr, vector<Node *> &v,int num){
        if (curr == NULL) return false;
        //Curr value hai ki ni num ke barabar
        v.push_back(curr);
        
        bool b1 = (curr->data) == num;

        //Left or Right me se kisi se poocho ki kya uske ki node me hai ye num
        bool b2 = LCS_path(curr->left, v, num);
        bool b3 = LCS_path(curr->right, v, num);


        //kisi ek ke pass v hai to thik
        if(b1||b2||b3){
            return true;
        }

        // agar ni hai kisi ke paas nikalo path me se isko
        v.pop_back();
        return false;
    }

    Node* LCS(Node *curr, int num1 , int num2){
        vector<Node *> p, q;

        cout<<LCS_path(curr , p , num1)<<" ";
        cout<<LCS_path(curr , q , num2)<<endl;
        cout<<p.size()<<" "<<q.size()<<endl;
        

        if((LCS_path(curr , p , num1)==false) || (LCS_path(curr , q , num2) == false)){
            cout<<"NULL"<<endl;
            return NULL;
        }
       

        for (int i = 0; i < min(p.size(),q.size()); i++){
            //root ke liye hai ye 
            if(i+1 == p.size()){
                return p[i];
            }
            //root ke liye hai ye  v
            if(i+1 == q.size()){
                return q[i];
            }
            if(p[i+1]->data != q[i+1]->data  ){
                // cout<<q[i]->data<<endl;
                return q[i];
            }
            
        }
        return NULL;

    }

};

int main()
{

    Binary_Tree t;
    t.Default_Tree();

    // Node* x = t.LCS(t.root,  1, 7);
    // if(x!=NULL){
    //     cout<<(x->data)<<endl;
    // }

    //  x = t.LCS(t.root,  1, 9);
    // if(x!=NULL){
    //     cout<<(x->data)<<endl;
    // }

    // x = t.LCS(t.root,  1, 2);
    // if(x!=NULL){
    //     cout<<(x->data)<<endl;
    // }

   Node* x = t.LCS(t.root,  9, 10);
    if(x!=NULL){
        cout<<(x->data)<<endl;
    }

    return 0;
}