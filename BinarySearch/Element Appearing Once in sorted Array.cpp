#include<bits/stdc++.h>
using namespace std;
int ElementOcurringOnce(vector<int>&arr)
{
	int n=arr.size();
	if(n==1) return arr[0];
	if(arr[0]!=arr[1]) return arr[0];
	if(arr[n-1]!=arr[n-2]) return arr[n-1];
	int l=0,r=n-1;
	while(l<=r)
	{
		int mid=(l+r)/2;

		if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]) return arr[mid];

		if(mid%2==0 && arr[mid]==arr[mid+1] || mid%2 && arr[mid]==arr[mid-1])
		{
             r=mid-1;
		}
		else
		{
              l=mid+1;
		}
	}
	return -1;

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
 int n;
 cin>>n;
 vector<int>arr;
 for(int i=0;i<n;i++)
 {
 	int x;
 	cin>>x;
arr.push_back(x);
 }

 cout<<ElementOcurringOnce(arr);
 
}