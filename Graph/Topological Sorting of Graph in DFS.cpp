/*
     Topological Sorting USING DFS
       to find topological sort of graph using DFS 
       what actually topoloogical sorting is
     Lets have a graph 
       0->1->2
       |     |
       \/    \/  
       3<-4<-5

      Topplogical sort for this graph 
      is
      0 1 2 5 4 3
      means the src node will always occur before the dest node
      //No topological sort is only possible for direct Acyclic graph

      Intutions
     lets we visit a node while returning from that node we will push that it into stack why stack
      stack store the elements is last in first out manner means
      means the dest node will lower and src will be at top;
     Example
       0->1->2
       |     |
       \/    \/  
       3<-4<-5

         lets we start traveral for 0 and check if the ajcanet node is visited or not if not then 1 then 2 then 5 then 4 then 3 now there is
         no non visited adjacent node for 3 hence return while that push it to stack then 4 will return
         and pushed to stack then 5 then 2 then 1 

         now we take the stack and store it to array
         1->2->5->4->3

         Lets Code
*/
#include<bits/stdc++.h>
using namespace std;
void DFStopoSort(int node,vector<int>adj[],vector<int>&vis,stack<int>&st)
{
	vis[node]=1;
	for(int x:adj[node])
	{
		if(!vis[x])
		{
			DFStopoSort(x,adj,vis,st);
		}
	}
	st.push(node);
}
vector<int> topoSort(int v,vector<int>adj[])
{
	vector<int>vis(v,0);
	stack<int>st;
	for(int i=0;i<v;i++)
	{
		if(!vis[i])
		{
			DFStopoSort(i,adj,vis,st);
		}
	}
	vector<int>ans;
	while(!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
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

  vector<int>ans=topoSort(v,adj);

  for(int i=0;i<v;i++)
  {
  	cout<<ans[i]<<"->";
  }
  return 0;
}