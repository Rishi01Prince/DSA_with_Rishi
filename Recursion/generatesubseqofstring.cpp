#include <bits/stdc++.h>
using namespace std;

void sub(string str,string curr,int count)
{
    if(count == str.length()){
        cout<<curr<<" ";
        return;
    }
    

    
    sub(str, curr + str[count],count+1);
    sub( str,curr,count+1);
    
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string str;
        cin >> str;
        int i = 0;
        string cur=" ";
        
        sub(str,cur,0);
    }
    return 0;
}