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

    void Preorder(TreeNode *curr)
    {
        if (curr != NULL)
        {
            cout << (curr->data) << " ";
            Preorder(curr->left);
            Preorder(curr->right);
        }
    }

    //         1
    //      2     3
    //    4  5   6  7
    //  8             9
    // root left right
    //1 2 4 8 5 3 6 7 9 
    // Time Complexity : theta(n);
    // Auxilary Space : O(h);

    void Iterative_Preorder(TreeNode *now)
    {
        // It is important to copy the address of root else each time
        // root will traverse through the tree
        TreeNode *curr = now;
        if (curr == NULL)
        {
            cout << "NULL" << endl;
            return;
        }

        stack<TreeNode *> st;
        st.push(curr);

        while ((st.empty() != 1))
        {
            curr= st.top();
            cout<<curr->data<<" ";
            if(curr->left!=NULL) st.push(curr->left);
            if(curr->right!=NULL) st.push(curr->right);
            st.pop();
        }
    }
};

int main()
{

    Binary_Tree t;
    t.Default_Tree();

    t.Preorder(t.root);
    cout << endl;
    t.Iterative_Preorder(t.root);

    return 0;
}