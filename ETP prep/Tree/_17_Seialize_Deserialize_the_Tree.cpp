#include <bits/stdc++.h>
using namespace std;



struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Binary_Tree
{
public:
    TreeNode *root = NULL;
    // TreeNode *curr = root;

    void Default_Tree()
    {
        root = new TreeNode(1);

        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(7);

        root->left->left->left = new TreeNode(8);
        root->right->right->right = new TreeNode(9);
    }
    
    void Postorder(TreeNode *curr)
    {
        if (curr != NULL)
        {
            Postorder(curr->left);
            Postorder(curr->right);
            cout << (curr->data) << " ";
        }
    }

    
    

    void Inorder(TreeNode *curr)
    {
        if (curr != NULL)
        {
            Inorder(curr->left);
            cout << (curr->data) <<  " ";
            Inorder(curr->right);
        }
    }

    void Preorder(TreeNode *curr)
    {
        if (curr != NULL)
        {
            cout << (curr->data) << " ";
            Preorder(curr->left);
            Preorder(curr->right);
        }
    }

    void Serialize_Preorder(TreeNode* curr, vector<int>& a){
        if (curr != NULL)
        {
            // cout << (curr->data) << " ";
            a.push_back(curr->data);
            Serialize_Preorder(curr->left, a);
            Serialize_Preorder(curr->right,a);
        }
        else{
            a.push_back(-1);
            return;
            
        }

    }

    TreeNode* Deserialize_Preorder( vector<int>& a, int i){

        if(i == a.size()) return NULL;

        int val = a[i];
        i++;
        if(val == -1) return NULL;
        

        TreeNode* now = new TreeNode(val);
        now->left =  Deserialize_Preorder( a, i);
        now->right = Deserialize_Preorder( a, i);
        return now;
    }
    

    
};

int main()
{

    Binary_Tree t;
    t.Default_Tree();

    t.Preorder(t.root);cout<<endl;
    vector<int> a ,b,c;

    t.Serialize_Preorder(t.root , a);
    for(auto it: a) cout<<it<<" ";
    cout<<endl;

    TreeNode* rudra = t.Deserialize_Preorder(a,0);
    // cout<<rudra->data<<endl;
    t.Preorder(rudra);
  
    return 0;
}