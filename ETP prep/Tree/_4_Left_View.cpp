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
    int max_level = 0;

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

    int tree_height(Node *curr)
    {
        if (curr == NULL)
        {
            return 0;
        }
        return (max(tree_height(curr->left), tree_height(curr->right)) + 1);
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

    // Iterative Solution takes Time coplexity : - theta(n)  and Space Complexity :- O (width of tree ) == O(n/2) ;
    // Auxilary Space  : O(n/2)

    void Left_View(Node *curr)
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
                if (i == 0){
                    cout << q.front()->data << " ";
                }
                if (q.front()->left != NULL){
                    q.push(q.front()->left);
                }
                if (q.front()->right != NULL){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            cout << endl;
        }
    }

    //Time Complexity :  theta(n)

    void Left_View_Recursive(Node *curr, int level)
    {
        if (curr == NULL){
            return;
        }

        if (max_level < level){
            cout << (curr->data) << " ";
            max_level = level;
        }

        Left_View_Recursive(curr->left, level + 1);
        Left_View_Recursive(curr->right, level + 1);
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
            cout << "1--> Level Traversal   " << endl;
            cout << "2--> Tree Height  " << endl;
            cout << "3--> Insertion " << endl;
            cout << "4--> Left View : " << endl;
            cout << "5--> Left_View_Recursive  : " << endl;

            cout << "9-->Quit" << endl;
        }

        else if (v == 1)
        {
            cout << "Level Traversal   :- " << endl;
            t.Level_Traversal(t.root);
            cout << endl;
        }

        else if (v == 2)
        {
            cout << "Tree Height : " << t.tree_height(t.root) << endl;
            cout << endl;
        }
        else if (v == 3)
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
        else if (v == 4)
        {
            cout << "Left View : " << endl;

            t.Left_View(t.root);

            cout << endl;
        }
        else if (v == 5)
        {
            cout << "Left View Recursive : " << endl;

            t.Left_View_Recursive(t.root, 1);
            t.max_level =0;

            cout << endl;
        }

        else if (v == 9)
        {

            q = false;
            cout << "                                                        Thank you we are done" << endl;
        }
        // else
        // {
        //     q = false;
        //     cout << "                                                        Thank you we are done" << endl;
        // }
    }

    cout << endl;
    return 0;
}