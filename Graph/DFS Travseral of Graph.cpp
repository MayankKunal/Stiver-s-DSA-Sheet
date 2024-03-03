/*
  Given a graph (Adjancy list we have to perform DFS Traversal)
  1). Graph may be disconnected
  How to approch
  Given Graph we have to use a visited array to store the graph 
  nodeis prevesily visited or not
  if(!visited[node]) then be perform another dfs on that node

*/
#include<bits/stdc++.h>
using namespace std;
  void helpDfsGraph(int src,vector<int>adj[],vector<int>&vis,vector<int>&ans)
  {
  	   vis[src]=1;
  	   ans.push_back(src);
  	   for(auto adjacentNode:adj[src])
  	   {
            if(!vis[adjacentNode])
            	helpDfsGraph(adjacentNode,adj,vis,ans);
  	   }
  }
 vector<int> DFSTraversalofGraph(int V,vector<int>adj[])
 {
 	vector<int>vis(V,0); // initalised the visited vector from 0;
 	vector<int>ans; // to store the order of node visited

 	for(int i=0;i<V;i++)
 	{
 		if(!vis[i])
 		helpDfsGraph(i,adj,vis,ans);
 	}

 	return ans;
 }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
  int n,e;
  cin>>n>>e;
  vector<int>adj[n];
  for(int i=0;i<e;i++)
  {
  	int src,des;
  	cin>>src>>des;
  	adj[src].push_back(des);
  	adj[des].push_back(src);
  }

  vector<int>ans=DFSTraversalofGraph(n,adj);

  for(int i=0;i<n;i++)
  {
  	cout<<ans[i]<<"->";
  }
}