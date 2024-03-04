/*
  Minimum spanning tree

   What is minimum spanning tree;

   minimum spanning tree of a graph is such that we take the edges 
   of graph with lower weights such that a graph is form with lowest sum
   of edge weight and also there must be no cylce in graph

   prism algorithm 
   In this the we start from a src vertex and find the join the edges with minimum cost/weights
   such that all the vertex is joined and there is no cylce

   if there is V vertex in graph there will be V-1 edges

   Intution
   
   take a node and find its adjacent and its weights store them in priority queue pair
   weight and adjacent node if there is node unvisited and having lower edge weigts add
   it to graph
*/
#include<bits/stdc++.h>
using namespace std;
int PrismAlgo(int V,vector<pair<int,int>>adj[],int src)
{
    vector<int>vis(V,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    int ans=0;
    while(!pq.empty())
    {
    	auto it=pq.top();
    	pq.pop();
    	int node=it.second;
    	int dis=it.first;
    	if(vis[node]) continue;
    	  vis[node]=1;
         ans+=dis;
        for(auto x:adj[node])
        {
        	  int adjNode=x.first;
        	  int d=x.second;
        	if(!vis[adjNode])
        	{
        		pq.push({d,adjNode});
        	}
        }
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
  vector<pair<int,int>>adj[n];
  for(int i=0;i<e;i++)
  {
  	int src,des,dis;
  	cin>>src>>des>>dis;
  	adj[src].push_back({des,dis});
  	adj[des].push_back({src,dis});
  }
    
    cout<<"Sum of edges of minimum spanning tree is  "<<PrismAlgo(n,adj,0);

    

}