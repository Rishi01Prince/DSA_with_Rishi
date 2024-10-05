#include <bits/stdc++.h>
using namespace std;


struct Node{
    vector<Node *> v(26,NULL);
    isEnd = false;
    Node(){
        isEnd = false;
    }
};
class Trie {
public:
    Node *root ;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *curr = root;
        int n = word.length();

        for(int i = 0 ; i<n ;i++){
            int ind  = word[i] - 'a';
            if(curr->v[ind] == NULL){
                curr->v[ind] = new Node();
            }
            curr= curr->v[ind];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node *curr = root;
        int n = word.length();
        for(int i = 0 ; i< n ;i++){
            int ind = word[i]-'a';
            if(curr->v[ind] == NULL) return false;
            curr= curr->v[ind];
        }
        return curr->isEnd;
        
    }
    
    bool startsWith(string prefix) {
        Node *curr = root;
        int n = word.length();
        for(int i = 0 ; i< n ;i++){
            int ind = word[i]-'a';
            if(curr->v[ind] == NULL) return false;
            curr= curr->v[ind];
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

//#define int long long int
// unordered_map<int,int> mpp;
// sort(v.begin(),v.end());

void solve(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
}

int32_t main()
{
    int T;
    cin >> T;

    while (T--)
    {

        string str;cin>>str; 
        vector<int> v;
        for (int i=0; i< str.length();i++)
        {
            if ((str[i] != ',') && (str[i] != '[') && (str[i] != ']')  ){
                v.push_back(int(str[i]-'0'));
            }   
        }
       
        solve(v);
    }
    return 0;
}