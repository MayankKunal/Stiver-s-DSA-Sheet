#include<bits/stdc++.h>
using namespace std;
int Approch1(vector<int>&arr)
{
	unordered_map<int,int>mp; //cretae map to store index values
	for(auto x:arr)
	{
		mp[x]++; //increase the map count for that value
	}

	for(auto it:mp)
	{
		if(it.second>1) return it.first;  // if map value for an element is greater than 1 return element
	}
	return -1;
}
int Approch2(vector<int>&nums)
{

}
int findDuplicate(vector<int>&arr)
{
	//Approch 1 Using HashMap
      return Approch1(arr);
	//Approch 2 using 
	//return Approch2(arr);
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
  {  int x;
  	cin>>x;
     arr.push_back(x);
  }
    cout<<findDuplicate(arr);
}