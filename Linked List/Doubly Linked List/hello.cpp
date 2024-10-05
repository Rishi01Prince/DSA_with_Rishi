#include <bits/stdc++.h>
using namespace std;


bool comp(map<int, int> m ,map<pair<char,int>, int> n ){

    if(m.second() < n->second()){
        
    }

}

void solve()
{

    string str;
    cin >> str;
    string hmm = str;
    map<pair<char,int>, int> mpp;

    unordered_map<char, int> ind;
    unordered_map<char, int> co;

    for (int i = 0; i < str.length(); i++)
    {
        mpp[str[i]] = int(str[i] - 'a') + 1;
        ind[str[i]] = i;
        co[str[i]]++;
    }
    int num1 = (int(str[0] - '0'));
    int num2 = int(str[str.length() - 1] - '0');
    // sort(str.begin(), str.end());

    // int count =

    if (num1 < num2)
    {
        

        int ans1 = abs(num1-num2);
        int ans2 = 0;
        for (auto it : mpp)
        {
            if (num1<= it.second()<=num2){
                cout<<"hello"<<endl;
                if()

            }
        }
    }
    else
    {
        int ans1 = abs((int(str[0] - '0') - int(str[str.length() - 1] - '0')));
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}