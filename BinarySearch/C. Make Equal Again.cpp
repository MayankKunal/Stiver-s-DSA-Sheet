#include<bits/stdc++.h>
using namespace std;
int help(vector<int>&arr)
{
	int n=arr.size();
	int l=0,r=n-1;
	int count=1;
	
	int frontcount=1;
	int front=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]==front) frontcount++;
		else break;
	}
	int back=arr[n-1];
	int backcount=1;
	for(int i=n-2;i>=0;i--)
	{
		if(arr[i]==back) backcount++;
		else break;
	}
	if(front==back && frontcount<n) count=frontcount+backcount;
         // cout<<"cout<<"<<count<<"frontcount"<<frontcount<<"backcount"<<backcount<<"\n";
	return max(count,max(frontcount,backcount));
}
int main()
{
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
        cout<<n-help(arr)<<"\n";

     }
}