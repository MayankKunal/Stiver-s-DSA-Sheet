/*
  Detech Cycle in undirected Graph using BFS

  1).As BFS graph traversal implement using q;

  take a queue storing a pair currNode and parent node

  check for each node it is visited or not

  if(not push the node into queue with its parent)
  if(visited preverly check is it parent of current not if not return true)
  )
*/
#include<bits/stdc++.h>
using namespace std;
bool BFSCycleCheck(int src,vector<int>adj[],int parent,vector<int>&vis)
{
   queue<pair<int,int>>q;
   q.push({src,parent});
  vis[src]=1;
   while(!q.empty())
   {
      auto it=q.front();
      q.pop();

      int node=it.first;
      
      int parent=it.second;
      for(auto adjacentNode:adj[node])
      {
         if(!vis[adjacentNode])
         {
            q.push({adjacentNode,node});
           vis[adjacentNode]=1;
         }
         else
         {
            if(parent!=adjacentNode) return true;
         }
      }
   }
   return false;
}
bool CycleCheck(int V,vector<int>adj[])
{
	vector<int>vis(V,0);
     for(int i=0;i<V;i++)  // for disconnected graph cycle check
     {  if(!vis[i])
     	if(BFSCycleCheck(i,adj,-1,vis)) return true;
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