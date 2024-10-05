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
    //Auxialary Space : O(n)

    //But this approach is having defect that both the number must be present in the Tree

    Node* LCS(Node *curr, int num1 , int num2){
        //Agar null hai to return karenge or kya
        if(curr==NULL) return NULL;

        //agar present node kisi ek num me se ek hai to pakka ya hi node hai Lcs kyoki right or left iske baade na dekhenge
        //ye to pahle hi pakra gaya to mtlb ye hi lcs kyo e node khud ancestor ho gaya
        if(curr->data == num1 || curr->data == num2){
            return curr;
        }
        

        //Chaliye daaye baye v no ka bata lgwate hai
        Node* l = LCS(curr->left , num1 , num2);
        Node* r = LCS(curr->right, num1, num2);

        // agar aisa ho raha hai ki daye me ek node hai or baaye me ek node hai to pakaa yahi humara LCS hai 
        if(l!=NULL && r!=NULL){
            return curr;
        }
        //agar upar wala condition met ni hua hai to ek node left me mila ya right me mila usi ko return kr rahe hai

        if(l!=NULL){
            return l;
        }
        if(r!=NULL){
            return r;
        }
        // agar kahi ni hai dono me se node to kya kr to NULL return 
        return NULL;
    }



    
};

int main()
{

    Binary_Tree t;
    t.Default_Tree();

    

   Node* x = t.LCS(t.root,  9, 5);
    if(x!=NULL){
        cout<<(x->data)<<endl;
    }


    Node* y = t.LCS(t.root,  9, 1);
    if(y!=NULL){
        cout<<(y->data)<<endl;
    }

    return 0;
}