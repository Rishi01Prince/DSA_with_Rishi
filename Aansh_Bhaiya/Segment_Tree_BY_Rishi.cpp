#include <bits/stdc++.h>
using namespace std;


//Segment Tree for sum of range
void Build_Tree(vector<int> &segment_tree ,vector<int> &v , int start , int end , int node  ){
    if(start ==end){
        segment_tree[node] = v[start];
        return;
    }
    int mid = (start + end)/2;

    Build_Tree(segment_tree , v , start , mid , 2*node +1);
    Build_Tree(segment_tree , v , mid+1 , end , 2*node +2);

    segment_tree[node] = segment_tree[2*node +1] + segment_tree[2*node +2];
}


// updating any value at a particular index with a value 
void update(vector<int>& segment_tree ,int start , int end , int node ,int ind , int value ){
    
    if(ind < start || ind > end){
        return;
    }
    if(start == end){
        segment_tree[node] += value;
        return;
    }
    segment_tree[node] += value;

    int mid = (start + end)/2;
    update(segment_tree , start , mid , 2*node +1 , ind , value);
    update(segment_tree , mid+1 , end , 2*node +2 , ind , value);
}

//get sum of range 

int get_sum(vector<int>& segment_tree ,int start , int end , int node , int left , int right ){
    if(left > end || right < start){
        return 0;
    }

    if(start >= left && end <= right){
        return segment_tree[node];
    }

    int mid = (start + end)/2;
    int sum_left = get_sum(segment_tree , start , mid , 2*node +1 , left , right);
    int sum_right = get_sum(segment_tree , mid+1 , end , 2*node +2 , left , right);

    return sum_left + sum_right;
}



void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> segment_tree(4 * n + 1, 0);

    Build_Tree(segment_tree, v, 0, n - 1, 0);

    for (int i = 0; i < 4 * n + 1; i++)
    {
        cout << segment_tree[i] << " ";
    }
    cout<<endl;

    cout<<get_sum(segment_tree , 0 , n-1 , 0 , 1 , 3)<<endl;
    update(segment_tree , 0 , n-1 , 0 ,2 , 10);
    cout<<get_sum(segment_tree , 0 , n-1 , 0 , 1 , 3)<<endl;

    for(int i=0;i<4*n+1;i++){
        cout<<segment_tree[i]<<" ";
    }
    cout<<endl;

    //25
    //9    16  
    //4  5    7 9
    //1 3     
  

    
}

int32_t main()
{
    solve();
    return 0;
}