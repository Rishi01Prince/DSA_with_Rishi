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

        // root->left->left->left = new Node(8);
        // root->right->right->right = new Node(9);
    }


    // Time Complexity : O(logn * logn)
    //Auxilary Space : O(h)
    // It olny traverses the the two extremeties that is most left and most right if height  is same on both side
    //then nodes = pow(2, h)-1 else follow the naive approach to count nodes

    int Count_Nodes(Node *curr ){
        if(curr==NULL) return 0;
        int lh = 0 , rh =0;
        Node *yo = curr;
        Node *ho = curr;
        //checking leftmost height
        while(yo!=NULL){
            lh++;
            yo = yo->left;
        }
        //checking right most height
        while(ho!=NULL){
            rh++;
            ho=ho->right;
        }
        //if same apply the formula

        if(lh == rh){
            return (pow(2,lh) -1);
        }
        //else counting the nodes nodes like we count for a binary tree
        return 1 + Count_Nodes(curr->left)+Count_Nodes(curr->right);
    }

    



    
};

int main()
{

    Binary_Tree t;
    t.Default_Tree();

    
    cout<<t.Count_Nodes(t.root)<<endl;

    return 0;
}