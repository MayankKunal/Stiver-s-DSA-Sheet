#include<bits/stdc++.h>
using namespace std;
int LengthofSubArraywith0sum(vector<int>&arr)
{
	int n=arr.size();
   unordered_map<int,int>mp;
   mp[0]=-1;

   int preOrderSum=0,maxlen=0;
   for(int i=0;i<n;i++)
   {
   	preOrderSum+=arr[i];
   	if(mp.find(preOrderSum)!=mp.end())
   	{
   		maxlen=max(maxlen,i-mp[preOrderSum]);
   	}
   	else
   	{
   		mp[preOrderSum]=i;
   	}
   }
   return maxlen;
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

    cout<<LengthofSubArraywith0sum(arr)<<" \n";
}