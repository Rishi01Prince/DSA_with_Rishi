#include <bits/stdc++.h>
using namespace std;

int maxsub(int arr[],int n)
{
    

    int res = 0;
    int mend = arr[0];
    for (int i = 1; i < n; i++)
    {
        mend = max(arr[i], mend + arr[i]);
        res = max(mend, res);
    }

   return res ;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        int arr[n];
        int arr2[n];
        int arr_sum=0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr2[i]=-arr[i];
            arr_sum+=arr[i];
        }
        
        maxsub(arr,n);
        int maxnormal = maxsub(arr,n);
        if(maxnormal<0){
            cout<<maxnormal<<endl;
            continue; 
        }


        int minsubarr= maxsub(arr2,n);

        int max_circular_subarr = arr_sum+minsubarr;
        int maximum_of_all=max(max_circular_subarr,maxnormal);
        cout<<max_circular_subarr<<endl;
        cout<<maxnormal<<endl;
        cout<<maximum_of_all<<endl<<endl;

    }
    return 0;
}