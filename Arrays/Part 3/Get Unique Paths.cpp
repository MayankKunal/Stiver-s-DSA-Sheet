#include<bits/stdc++.h>
using namespace std;
//All unique paths for traversal in n*m matrix
// in this apprroch I try to backward 
// one can traverse forward as help(int idx,int idy,int n,int m,vector<vector<int>>&dp)
int help(int n,int m,vector<vector<int>>&dp)
{
	/* BASE CASE*/
	if(n==0&&m==0) return 1; //Base case 1 if my pointer reach to end return 1
	if(n<0 || m<0) return 0;// Base case 2 if pointer go out of bound return 0
	if(dp[n][m]!=-1) return dp[n][m]; // return the dp elemet if value of dp!=-1


	return dp[n][m]=help(n-1,m,dp)+help(n,m-1,dp); // reccurance relation for up and left recursion
}
int uniquePaths(int n,int m)
{
	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	return help(n-1,m-1,dp);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
  int n,m;
  cin>>n>>m;
  cout<<uniquePaths(n,m);
}