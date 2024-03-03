#include<bits/stdc++.h>
using namespace std;
void method1(vector<int>&arr1,vector<int>&arr2)
{
    int n=arr1.size();
    int m=arr2.size();
   vector<int>ans;
   int i=0,j=0;
   while(i<n && j<m)
   {
   	 if(arr1[i]<=arr2[j])
   	 {
   	 	ans.push_back(arr1[i++]);
   	 }
   	 else
   	 {
   	 	ans.push_back(arr2[j++]);
   	 }
   }
   while(i<n)
   {
   	ans.push_back(arr1[i++]);
   }
   while(j<m)
   	 ans.push_back(arr2[j++]);

   arr1=ans;
}
void method2(vector<int>&arr1,vector<int>&arr2)
{
	int n=arr1.size();

	int m=arr2.size();
   int i=n-1,j=m-1;
      
	int k=n+m-1;
     arr1.resize(k+1);
	while(j>=0)
	{
		if(i>=0 && arr1[i]>=arr2[j])
		{
			arr1[k--]=arr1[i--];
		}
		else
		{
			arr1[k--]=arr2[j--];
		}
	}
}
void mergeTwoSortedArray(vector<int>&arr1,vector<int>&arr2)
{
   
   // Using O(N) extra Space
	// method1(arr1,arr2);
    //using No extraSpace
    method2(arr1,arr2);

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
   int n, m;
   cin>>n>>m;
    vector<int>arr1;
    vector<int>arr2;

    for(int i=0;i<n;i++)
    {
    	int x;
    	cin>>x;
    	arr1.push_back(x);
    }

    for(int i=0;i<m;i++)
    {
    	int x;
    	cin>>x;
    	arr2.push_back(x);
    }
    mergeTwoSortedArray(arr1,arr2);
    // cout<<arr1[5];
    for(int i=0;i<arr1.size();i++)
    {
    	cout<<arr1[i]<<" ";
    }
}