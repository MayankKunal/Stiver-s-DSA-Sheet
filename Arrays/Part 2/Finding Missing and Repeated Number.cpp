#include<bits/stdc++.h>
using namespace std;
pair<int,int> missingAndRepeating(vector<int>&ans)
{
	unordered_map<int,int>mp;
	int n=ans.size();
	for(int x:ans)
	{
		mp[x]++;
	}
	int missing=-1,repeating=-1;

	for(int i=1;i<=n;i++)
	{
		if(mp.find(i)==mp.end()) missing=i;
	}
	for(auto x:mp)
	{
		if(x.second>1) repeating=x.first;
	}

	return {missing,repeating};
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
    int n;
    cin>>n;
  vector<int>ans;
  for(int i=0;i<n;i++)
  {
  	int x;
  	cin>>x;
  	ans.push_back(x);
  }
  pair<int,int> missandRepeat=missingAndRepeating(ans);

  cout<<"Missing->"<<missandRepeat.first<<" Repeating->"<<missandRepeat.second;
}