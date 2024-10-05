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

    void Inorder(TreeNode* curr)
    {
        if (curr != NULL)
        {
            Inorder(curr->left);
            cout << (curr->data) << " ";
            Inorder(curr->right);
        }
    }

    //         1
    //      2     3
    //    4   5  6  7
    //  8            9    
    // left root right
    

    //Time Complexity : theta(n);
    //Auxilary Space : O(h);

    void Iterative_Inorder(TreeNode* now)
    {
        //It is important to copy the address of root else each time
        //root will traverse through the tree
        TreeNode* curr = now;
        if (curr == NULL)
        {
            cout << "NULL" << endl;
            return;
        }
        
        stack<TreeNode* > st;

        while ((curr!=NULL) || (st.empty()!=1))
        {
            while (curr!=NULL)
            {
                st.push(curr);
                curr= curr->left;
            }

            curr = st.top() ;
            st.pop();
            
            cout<<curr->data<<" ";
            curr= curr->right;
    
        }
        



    }
};

int main()
{

    Binary_Tree t;
    t.Default_Tree();

    t.Inorder(t.root);
    cout << endl;
    t.Iterative_Inorder(t.root);

    return 0;
}