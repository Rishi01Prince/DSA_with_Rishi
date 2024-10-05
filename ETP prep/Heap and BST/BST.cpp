#include <bits/stdc++.h>
using namespace std;

// Insetion and deletion in Heap
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

static TreeNode* inse(TreeNode* root, int val){
    if(root==NULL) {
        TreeNode* a = new TreeNode(val);
        return a;
    }

    if(root->val > val){
        root->left = inse(root->left, val);
    }
    else{
        root->right = inse(root->right, val);
    }
    return root;
}

static TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) return NULL;
    if (root->val == key) {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* cur = root->right;
        while (cur->left != NULL) cur = cur->left;
        root->val = cur->val;
        root->right = deleteNode(root->right, cur->val);
    }
    else if (root->val > key) {
        root->left = deleteNode(root->left, key);
    }
    else {
        root->right = deleteNode(root->right, key);
    }
    return root;
}

void BFS(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            cout<<curr->val<<" ";

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            

        }
        
        cout<<endl;
    }
    cout<<endl;
}

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = inse(root, v[i]);
    }
    BFS(root);
    root = deleteNode(root, 4);
    BFS(root);

}

int32_t main() {
    int T;
    cin>>T;

    while(T--){
        solve();
    }
    return 0;
}
