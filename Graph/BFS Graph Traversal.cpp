#include<bits/stdc++.h>
using namespace std;
/*
  In BFS traversal of graph 
  we explore all the adjnode of curr node before moving to its adjNode

  in bfs traversal we use queue to store the currnode and
  we will keep pushing if prevesily not visited the adjNode of currNode to q


*/
  void BFSTraversal(int src,vector<int>adj[],vector<int>&vis,vector<int>&ans)
  {
        queue<int>q;
        q.push(src);
        vis[src]=1;
        while(!q.empty())
        {
        	int node=q.front();
        	q.pop();
        	 ans.push_back(node);
        	for(int adjNode:adj[node])
        	{
        		if(!vis[adjNode])
        		{
        			vis[adjNode]=1;
        			q.push(adjNode);
        			
        		}
        	}

        }
  }

  vector<int>bfsTraversal(int V,vector<int>adj[])
  {
          vector<int>vis(V,0);
          vector<int>ans;
          for(int i=0;i<V;i++)
          {
          	if(!vis[i])
          	{
          		BFSTraversal(i,adj,vis,ans);
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
  vector<int>adj[n];
  for(int i=0;i<e;i++)
  {
  	int src,des;
  	cin>>src>>des;
  	adj[src].push_back(des);
  	adj[des].push_back(src);
  }

  vector<int>ans=bfsTraversal(n,adj);

  for(int i=0;i<n;i++)
  {
  	cout<<ans[i]<<"->";
  }

}