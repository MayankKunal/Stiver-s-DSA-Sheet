/*
 Topological sort of Graph using BFS TRAVERSAL

 AS BFS traversal no guesses will need queue
     maintain a vector to store indegree of each vertex
     the graph with 0 inDegree means there is no node before that hence push to queue
     traverse in q and push the top elemet to answer array and also decrese the indegree
     of its adjacent nodes if the indgree node is 0 push to the array and so on

   //Note we can only find indegree for non Cyclic undirected graph

*/
#include<bits/stdc++.h>
using namespace std;
vector<int>BFStopoSort(int V,vector<int> adj[])
{
	
	int inDegree[V]={0};
	for(int i=0;i<V;i++)
	{
		for(auto x:adj[i])
		{
			inDegree[x]++;
		}
	}
     queue<int>q;
	for(int i=0;i<V;i++)
	{
            if(inDegree[i]==0)
            {
            	q.push(i);
            }
	}
    vector<int>ans;
	while(!q.empty())
	{
		int node=q.front();

		ans.push_back(node);
		q.pop();
		for(int adjNode:adj[node])
		{
			inDegree[adjNode]--;

			if(inDegree[adjNode]==0)
			{
				q.push(adjNode);
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
int v,e;
  cin>>v>>e;
  vector<int>adj[v];

  for(int i=0;i<e;i++)
  {
  	int src,des;
  	cin>>src>>des;
  	adj[src].push_back(des);
  }

  vector<int>ans=BFStopoSort(v,adj);

  for(int i=0;i<v;i++)
  {
  	cout<<ans[i]<<"->";
  }
  return 0;
}