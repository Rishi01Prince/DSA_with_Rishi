vector<int> lis[100001]; 
int vis[100001]; 
void initialize(int n) 
{ 
    for (int i = 0; i <= n; i++) 
    { 
        lis[i].clear(); 
        vis[i] = 0; 
    } 
} 
set<int> found; 

void dfs(int node) 
{ 
    found.insert(node); 
    vis[node] = 1; 
    for (int child : lis[node]) 
    { 
        if (vis[child] == 0) 
        { 
            dfs(child); 
        } 
    } 
} 

vector<int> timeOfInfection(int n, int m, vector<int> initially_infected, vector<vector<int>> update) 
{ 
    vector<int> status(n, 0); 
    vector<int> ans(n, -1); 
    for (int i = 0; i < m; i++) 
    { 
        status[initially_infected[i]] = 1; 
        ans[initially_infected[i]]=0; 
    } 

    for (int i = 0; i < update.size(); i++) 
    { 
        int type = update[i][0]; 
        if (type == 0) 
        { 
            int a = update[i][1]; 
            int b = update[i][2]; 
            if (status[a] == 0 && status[b] == 0) 
            { 
                lis[a].push_back(b); 
                lis[b].push_back(a); 
            } 
            else if (status[a] == 1 && status[b] == 1) 
            { 
                lis[a].push_back(b); 
                lis[b].push_back(a); 
            } 
            else if (status[a] == 1) 
            { 
                found.clear(); 
                dfs(b); 
                for (auto x : found) 
                { 
                    ans[x] = i + 1; 
                    status[x] = 1; 
                } 
            } 
            else 
            { 
                found.clear(); 
                dfs(a); 
                for (auto x : found) 
                { 
                    ans[x] = i + 1; 
                    status[x] = 1; 
                } 
            } 
        } 
    } 
    for (int i = 0; i < update.size(); i++) 
    { 
        int type = update[i][0]; 
        if(type==1) 
        { 
            int a=update[i][1]; 
            if(i+1<ans[a]) 
            { 
                ans[a]=-1; 
            } 

        } 
    } 
    return ans; 
}