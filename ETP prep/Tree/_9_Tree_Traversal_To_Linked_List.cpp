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
    Node *head = NULL;
    // Node *curr = root;
    Node *prev = NULL;

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

    void Preorder(Node *curr)
    {
        if (curr != NULL)
        {
            cout << (curr->data) << " ";
            Preorder(curr->left);
            Preorder(curr->right);
        }
    }
    void Inorder(Node *curr)
    {
        if (curr != NULL)
        {
            Inorder(curr->left);
            cout << (curr->data) << " ";
            Inorder(curr->right);
        }
    }

    void Postorder(Node *curr)
    {
        if (curr != NULL)
        {
            Postorder(curr->left);
            Postorder(curr->right);
            cout << (curr->data) << " ";
        }
    }

    // Inorder Traversal

    Node *Tree_to_Inorder_Linked_List(Node *curr)
    {
        if (curr == NULL)
        {
            return curr;
        }

        Node *h = Tree_to_Inorder_Linked_List(curr->left);

        if (prev == NULL)
        {
            h = curr;
        }
        else
        {
            prev->right = curr;
            curr->left = prev;
        }
        prev = curr;

        Tree_to_Inorder_Linked_List(curr->right);
        return h;
    }

    Node *Tree_to_Postorder_Linked_List(Node *curr)
    {

        if (curr == NULL)
        {
            return curr;
        }

        Node *h = Tree_to_Postorder_Linked_List(curr->left);
        Tree_to_Postorder_Linked_List(curr->right);

        if (prev == NULL)
        {
            h = curr;
        }
        else
        {
            prev->right = curr;
            curr->left = root;
        }
        prev = curr;
        return h;
    }

    void Tree_to_Preorder_Linked_List(Node *curr)
    {
        if (curr != NULL)
        {
            Node* saviour = NULL;
            if (prev == NULL)
            {
                head = curr;
            }
            else
            {
                prev->right = curr;
                Node* saviour = curr->left;
                curr->left = prev;
            }
            prev = curr;
            if(saviour!=NULL)Tree_to_Preorder_Linked_List(saviour);
            else Tree_to_Preorder_Linked_List(curr->left);
            Tree_to_Inorder_Linked_List(curr->right);
        }
       
        // Node *h  = curr;
    }

    void Traversal_Of_Linked_List(Node *head)
    {
        if (head == NULL)
        {
            cout << "NULL" << endl;
            return;
        }
        Node *curr = head;

        while (curr != NULL)
        {
            cout << curr->data << " --> ";
            curr = curr->right;
        }
        cout << " NULL" << endl;
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
            t.head = t.Tree_to_Inorder_Linked_List(t.root);
            cout << "Your have converted Tree into Linked List " << endl;
            t.Traversal_Of_Linked_List(t.head);
        }

        else if (v == 3)
        {
            cout << "Preorder Traversal : ";
            t.Preorder(t.root);
            cout << endl;
        }

        else if (v == 4)
        {
            t.Tree_to_Preorder_Linked_List(t.root);
            cout << "Your have converted Tree into Linked List " << endl;
            t.Traversal_Of_Linked_List(t.head);
        }

        else if (v == 5)
        {
            cout << "Postorder Traversal : ";
            t.Postorder(t.root);
            cout << endl;
        }

        else if (v == 6)
        {
            t.head = t.Tree_to_Postorder_Linked_List(t.root);
            cout << "Your have converted Tree into Linked List " << endl;
            t.Traversal_Of_Linked_List(t.head);
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