/*
   Deetect a cylce in undirected graph using DFS

   Intution

   funtion check cycle having parameters as node parent adjList 
   
   traverse to each node of graph adjcentNode of node is not its parent means it 
   is visited by any other node from different path means cycle exist

*/
#include<bits/stdc++.h>
using namespace std;
bool DFSCycleCheck(int node,vector<int>adj[],int parent,vector<int>&vis)
{
	vis[node]=1;
	for(auto adjacentNode:adj[node])
	{
		if(!vis[adjacentNode])
           {
			if(DFSCycleCheck(adjacentNode,adj,node,vis)) return true;
		}
		else
		{
			if(adjacentNode!=parent) return true;
		}
	}

	return false;
}

bool CycleCheck(int V,vector<int>adj[])
{
	vector<int>vis(V,0);
     for(int i=0;i<V;i++)  // for disconnected graph cycle check
     {  if(!vis[i])
     	if(DFSCycleCheck(i,adj,-1,vis)) return true;
     }

     return false;
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

  cout<<CycleCheck(n,adj);

}