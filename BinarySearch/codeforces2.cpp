#include<bits/stdc++.h>
using namespace std;
bool help(vector<int>&arr,int sum)
{  int n=arr.size();
    if(arr[n-1]>sum) return false;
     int take=0,give=0;
        for(int i=n-1;i>=0;i--)
        {
            if(give<take) return false;
            if(arr[i]<sum) give+=sum-arr[i];
            else if(arr[i]>sum) take+=arr[i]-sum;
        }
        return true;
}
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>arr;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            sum+=x;
            arr.push_back(x);
        }
         sum/=n;
           
           if(help(arr,sum))  cout<<"YES\n";
         else cout<<"NO\n";
     }
}