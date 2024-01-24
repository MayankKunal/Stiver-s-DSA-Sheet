#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
	int n=prices.size(); // no of elements in prices vector
	int minPrevCost=INT_MAX,netProfit=0; //minimum prevcost and netProfit variable
	for(int i=0;i<n;i++)
	{
		int dayProfit=prices[i]-minPrevCost; //calculate each day profit
		netProfit=max(netProfit,dayProfit); // calculate maximum profit
		minPrevCost=min(minPrevCost,prices[i]); // calculte minimump minimum cost  as cost price	}
}
  return netProfit;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
int n;
cin>>n;
vector<int>prices;
for(int i=0;i<n;i++)
{
	int x;
	cin>>x;
	prices.push_back(x);
}
 cout<<maxProfit(prices);
}