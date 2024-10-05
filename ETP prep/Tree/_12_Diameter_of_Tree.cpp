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
    int tree_height(Node *curr){
        if (curr == NULL){
            return 0;
        }
        return (max(tree_height(curr->left), tree_height(curr->right)) + 1);
    }

    // Time Complexity = O(n^2)
    // Auxilary Space: O(h)
    // T(n) = T(n-1) + theta(n)

    int Brute_Force_Diameter(Node *curr)
    {
        if (curr == NULL)
        {
            return 0;
        }
        int l = tree_height(curr->left);
        int h = tree_height(curr->right);
        int d1 = Brute_Force_Diameter(curr->left);
        int d2 = Brute_Force_Diameter(curr->right);

        return max({l + h + 1, d1, d2});
    }

    // Time Complexity = O(n)
    // Space Complextity : O(n) ::-> Precomputing Height of each node in a Hash Map
    // Auxilary Space: O(h)
    int Precompute_height_of_node(Node* curr , map<Node *, int>& mpp)
    {
        if (curr == NULL)
        {
            return 0;
        }

        mpp[curr->left]  =  tree_height(curr->left);
        mpp[curr->right] =  tree_height(curr->right);
        return mpp[curr]  = (max(mpp[curr->left], mpp[(curr->right)]) + 1);
    }

    int Diameter_with_Map(Node *curr, map<Node *, int> &mpp){
        if (curr == NULL) return 0;

        int l = mpp[curr->left];
        int h = mpp[curr->right];
        // cout<<l<<" "<<h<<endl;

        int d1 = Diameter_with_Map(curr->left,mpp);
        int d2 = Diameter_with_Map(curr->right,mpp);

        return max({l + h + 1, d1, d2});
    }

    // Time Complexity = O(n)
    // Auxilary Space: O(h)
    //Just Same as Height Function;
    int Diameter(Node *curr, int& ans){
        if (curr == NULL) return 0;

        int l = Diameter(curr->left , ans);
        int h = Diameter(curr->right , ans);

        // Only this Line is Different from height
        ans = max( ans , l+h+1 );
        return 1 + max(l,h);
    }
};

void solve()
{
    Binary_Tree t;

    cout << "                                                                                     Welcome to Tree World" << endl;
    t.Default_Tree();
    cout << endl;

    map<Node* , int > mpp ;
    t.Precompute_height_of_node( t.root , mpp);
   
    

    // Approach 1 : -
     cout<<t.Brute_Force_Diameter(t.root)-1<<endl;

    // Approach 2 :-
    cout<<t.Diameter_with_Map(t.root,mpp)-1<<endl;

    // Approach 3 :-
    int ans = 0;
    t.Diameter(t.root,ans);
    cout<<ans-1<<endl;



}

int main()
{
    solve();

    return 0;
}