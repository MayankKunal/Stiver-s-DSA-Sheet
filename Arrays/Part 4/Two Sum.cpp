#include<bits/stdc++.h>
using namespace std;
string TwoSum(int n, vector<int> arr, int target)
{
    sort(arr.begin(),arr.end());

    int l=0,r=n-1;

    while(l<r)
    {
        if(arr[l]+arr[r]==target) return "YES";

        else if(arr[l]+arr[r]<target) l++;
        else r--;
    }
    return "NO";
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif

    int n,target;
    cin>>n>>target;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
    	int x;
    	cin>>x;
    	arr.push_back(x);
    }

    cout<<TwoSum(n,arr,target);

}