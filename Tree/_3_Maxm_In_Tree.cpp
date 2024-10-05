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
    void Preorder(Node *curr)
    {
        if (curr != NULL)
        {
            cout << (curr->data) << " ";
            Preorder(curr->left);
            Preorder(curr->right);
        }
    }
    int tree_height(Node *curr)
    {
        if (curr == NULL)
        {
            return 0;
        }
        return (max(tree_height(curr->left), tree_height(curr->right)) + 1);
    }

    void Elements_at_Distance_K(Node *curr, int k)
    {
        if (curr == NULL)
        {
            return;
        }
        if (k == 0)
        {
            cout << (curr->data) << " ";
            return;
        }

        Elements_at_Distance_K(curr->left, k - 1);
        Elements_at_Distance_K(curr->right, k - 1);
    }

    // Tree Traeversal by Sandeep Jain Sir

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
            if (q.front()->left != NULL){
                q.push(q.front()->left);
            }
            if (q.front()->right != NULL){
                q.push(q.front()->right);
            }

            q.pop();
        }
    }

    

    void Level_Traversal(Node *curr)
    {
        queue<Node *> q;
        if (curr == NULL)
        {
            cout << "NULL" << endl;
            return;
        }

        q.push(curr);
        // q.push(NULL);
        while (q.empty() == false)
        {
            int s = q.size();

            for (int i = 0; i < s; i++)
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
            cout << endl;
        }
    }

    int size(Node *curr){
        if(curr==NULL){
            return 0;
        }
        return 1 + size(curr->left) + size(curr->right);
    }

    int maximum_Element(Node *curr){
        if(curr==NULL){
            return  INT_MIN;
        }
        
        return max(curr->data,(max(maximum_Element(curr->left),maximum_Element(curr->right))));
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
            cout << "1--> Level Traversal W1 " << endl;
            cout << "2--> Level Traversal W2  " << endl;
            cout << "3--> Preorder Traversal  " << endl;
            cout << "4--> BFS_Traversal " << endl;
            cout << "5--> Tree Height  " << endl;
            cout << "6--> Insertion " << endl;
            cout << "7---> Node at Distance k" << endl;
            cout << "9-->Quit" << endl;
            
        }
        else if (v == 1)
        {
            cout << "Maximum Element  : ";
            cout<<t.maximum_Element(t.root);
            cout << endl;

            
        }
        else if (v == 2)
        {
            cout << "Tree Breadth Wise Traversal  way2  :- "<<endl;
            t.Level_Traversal(t.root);
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

            t.BFS_Traversal(t.root);
            cout << endl;
        }
        else if (v == 5)
        {
            cout << "Tree Height : " << t.tree_height(t.root) << endl;
            cout << endl;
        }
        else if (v == 6)
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

        else if (v == 7)
        {
            cout << "Enter the distance : ";
            int k;
            cin >> k;
            t.Elements_at_Distance_K(t.root, k);

            cout << endl;
        }
        else if(v==8){
            cout<<"Size : ";
            cout<<t.size(t.root);
            cout<<endl;
        }

        else if (v == 9)
        {
            cout << "                                                        Thank you we are done" << endl;
            q = false;
        }
        else
        {
            q = false;
            cout << "                                                        Thank you we are done" << endl;
        }
    }

    cout << endl;
    return 0;
}