#include<bits/stdc++.h>
using namespace std;
int searchInSortedRotedArray(vector<int>&arr,int target)
{
	int n=arr.size(); // size of Array

	int l=0,r=n-1;  // pointers for array traversal

	while(l<=r)
	{
		int mid=(l+r)/2;

		if(arr[mid]==target) return mid;

		else if(arr[r]>=arr[mid])
		{
			if(target>arr[mid] && target<=arr[r]) l=mid+1;
			else r=mid-1;
		}
		else
		{
			if(target<arr[mid] && target>=arr[l]) r=mid-1;
			else l=mid+1;
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
 int n,target;
 cin>>n>>target;

 vector<int>arr;

 for(int i=0;i<n;i++)
 {
 	int x;
 	cin>>x;
 	arr.push_back(x);
 }
 cout<<searchInSortedRotedArray(arr);
}