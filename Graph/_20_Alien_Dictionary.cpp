//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
//How to make set timeout
//link :- https://practice.geeksforgeeks.org/problems/alien-dictionary/1#
class Solution{
    public:
    static void BFS_Topo(vector<vector<int>> &adj ,vector<int> &indeg , vector<bool> &vis , int o ,string &ans){
        queue<int> q;
        q.push(o);
        vis[o]=true;
        while(!q.empty()){
            int x = q.front();
            ans.push_back(char(x+'a'));
            q.pop();
            for(auto v : adj[x]){
                indeg[v]--;
                if(vis[v] == false  && indeg[v] == 0 ){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    string findOrder(string dict[], int n, int k) {
        vector<vector<int>> adj(k);
        vector<bool> vis(k , false);
        vector<int> indeg (k);
        string ans = "";
        
        
        for(int i = 0 ; i< n-1 ; i++){
            string a = dict[i];
            string b = dict[i+1];
            int m = min(a.length(),b.length());
            for(int j = 0 ; j<m ;j++ ){
                if(a[j] != b[j]){
                    adj[a[j]-'a'].push_back(b[j]-'a');
                    indeg[b[j]-'a']++;
                    break;
                } 
            }
        }
        
        
        for(int i = 0 ; i< k ; i++){
            if(vis[i] == false && indeg[i]==0 ){
                BFS_Topo(adj,indeg,vis,i,ans);
            }
        }
        // cout<<ans<<endl;
        return ans;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends