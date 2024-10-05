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
    // Node *curr = root;

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

    void Insertion(int data, Node *curr)
    {
        if (root == NULL)
        {
            Node *temp = new Node(data);
            root = temp;
            cout << "First Element which is Root is Inserted " << endl;
            return;
        }

        bool b = true;
        cout << "The root is " << root->data << endl;

        while (b)
        {
            cout << "Now ,Please Give the direction : ";
            int inp;
            cin >> inp;

            if (inp == 1)
            {
                if (curr->left == NULL)
                {
                    cout << "Sorry, No Node is there  , Please Retry" << endl;
                }
                else
                {
                    curr = curr->left;
                    cout << "The current node is " << curr->data << endl;
                }
            }
            else if (inp == 2)
            {
                if (curr->right == NULL)
                {
                    cout << "Sorry, No Node is there  , Please Retry" << endl;
                }
                else
                {
                    curr = curr->right;
                    cout << "The current node is " << curr->data << endl;
                }
            }
            else if (inp == 3)
            {

                if (curr->left != NULL)
                {
                    cout << "Sorry, There is already a node which is " << curr->left->data << " , Please Retry" << endl;
                }
                else
                {
                    Node *temp = new Node(data);
                    curr->left = temp;
                    cout << "Node Inserted Successfully " << endl;
                    b = false;
                }
            }
            else if (inp == 4)
            {
                if (curr->right != NULL)
                {
                    cout << "Sorry, There is already a node which is " << curr->right->data << " , Please Retry" << endl;
                }
                else
                {
                    Node *temp = new Node(data);
                    curr->right = temp;
                    cout << "Node Inserted Successfully " << endl;
                    b = false;
                }
            }
            else if (inp == 9)
            {
                b = false;
                cout << "we are quiting the process of Insertion " << endl;
            }
            else
            {
                cout << "Invalide Input Please Retry" << endl;
            }
        }
    }

    //Time complexity : - O(n)
    //Auxilary Space : O(height of binary Tree)

    void Inorder(Node *curr)
    {
        if (curr != NULL)
        {
            Inorder(curr->left);
            cout << (curr->data) <<  " ";
            Inorder(curr->right);
        }
    }

    void Preorder(Node *curr){

        if (curr != NULL)
        {
            cout << (curr->data) << " ";
            Preorder(curr->left);
            Preorder(curr->right);
        }
    }

    void Postorder(Node *curr){
        if (curr != NULL)
        {
            Postorder(curr->left);
            Postorder(curr->right);
            cout << (curr->data) << " ";
        }
    }

    //Time Complexity : O(no .of nodes in tree)
    // Auxilary Space : O(h+1) where h = height of Binary tree 

    int tree_height(Node *curr)
    {
        if (curr == NULL)
        {
            return 0;
        }
        return (max(tree_height(curr->left), tree_height(curr->right)) + 1);
    }


    //Time Complexity : O(no. of nodes in tree)
    // Auxilary Space : O(h+1) where h = height of  Binary Tree

    void Elements_at_Distance_K(Node *curr, int k)
    {
        if (curr == NULL)
        {
            return;
        }
        if (k == 0){
            cout << (curr->data) << " ";
            return;
        }
        Elements_at_Distance_K(curr->left, k - 1);
        Elements_at_Distance_K(curr->right, k - 1);
    }

    //Inefficient way of Level Order Traversal  By Rishi Raj

    void Tree_Traversal(Node *curr)
    {
        if (curr == NULL)
        {
            cout << "NULL" << endl;
            return;
        }
        int h = tree_height(root);

        for (int i = 0; i < h; i++)
        {
            Elements_at_Distance_K(root, i);
            cout << endl;
        }
    }

    // Tree Traeversal by Sandeep Jain Sir
    // Time Complexity : theta(n) where n = no. of nodes in tree
    // Auxilary Tree : O(n) or theta(w) where w = width of Auxilary Tree

    void BFS_Traversal(Node *curr)
    {
        queue<Node *> q;
        if (curr == NULL){
            cout << "NULL" << endl;
            return;
        }

        q.push(curr);
        while (q.empty() == false)
        {
            cout << q.front()->data << " ";

            if (q.front()->left != NULL)
            {
                q.push(q.front()->left);
            }

            if (q.front()->right != NULL)
            {
                q.push(q.front()->right);
            }

            q.pop();
        }
    }
    //Time Complexity : O(n)
    //Auxilary Space  : O(h)

    int size(Node *curr){
        if(curr==NULL){
            return 0;
        }
        return 1 + size(root->left) +size(root->right);

    }
};

int main()
{

    Binary_Tree t;
    cout << "                                                                                     Welcome to Tree World" << endl;
    t.Default_Tree();

    cout << endl;

    bool q = true;

    while (q)
    {
        cout << "Please enter the option : ";
        int v;
        cin >> v;

        if (v == 0)
        {
            cout << "Functions are :- " << endl;
            cout << "1--> Inorder Traversal " << endl;
            cout << "2--> Postorder Traversal  " << endl;
            cout << "3--> Preorder Traversal  " << endl;
            cout << "4--> Insertion " << endl;
            cout << "5--> Tree Height  " << endl;
            cout << "6--> Node at Distance k  " << endl;
            cout << "7---> Tree Traversal " << endl;

            cout << "9-->Quit" << endl;
        }
        else if (v == 1)
        {

            cout << "Inorder Traversal : ";
            t.Inorder(t.root);
            cout << endl;
        }
        else if (v == 2)
        {
            cout << "Postorder Traversal : ";
            t.Postorder(t.root);
            cout << endl;
        }
        else if (v == 3)
        {
            cout << "Preorder Traversal : ";
            t.Preorder(t.root);
            cout << endl;
        }
        else if (v == 4)
        {
            cout << "1 --> Left traversal" << endl;
            cout << "2 --> Right traversal" << endl;
            cout << "3 --> Left Side Insertion" << endl;
            cout << "4 --> Right Side Insertion" << endl;

            cout << "Enter data : ";
            int x;
            cin >> x;
            t.Insertion(x, t.root);
            cout << endl;
        }

        else if (v == 5)
        {
            cout << "Tree Height : " << t.tree_height(t.root) << endl;
            cout << endl;
        }

        else if (v == 6)
        {
            cout << "Enter the distance : ";
            int k;
            cin >> k;
            t.Elements_at_Distance_K(t.root, k);

            cout << endl;
        }
        else if (v == 7)
        {

            t.Tree_Traversal(t.root);

            cout << endl;
        }
        else if (v == 8)
        {

            t.BFS_Traversal(t.root);

            cout << endl;
        }

        else if (v == 9)
        {
            cout << "                                                        Thank you we are done" << endl;
            q = false;
        }
        else
        {
            q = false;
        }
    }

    cout << endl;
    return 0;
}

// 1 - 2