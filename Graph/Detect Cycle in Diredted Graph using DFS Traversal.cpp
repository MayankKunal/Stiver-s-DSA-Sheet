/*
    Detect Cycle in Directed Graph 

    why we need different algo does the Undirected Graph not work here

    Answer is No.

    
    for undirected Graph                        For Directed Graph
    lets edges are:-
     1-2                                         1->2   
     2-4                                         2->4
     4-3                                         3->4
     1-3                                         1->3

     bool CycleCheck(int node,vector<int>adj,vector<int>&vis)
     {
        vis[src]=1;
        for(int adjNode:adj[node])
        {
	        if(!vis[adjNode])
	        if(CycleCheck(adjNode,adj,vis)) return true; 
	         //its child is returning true;
            
            else{  //means the node is alredy visited
	            if(adjNode!=parent) return true;
	            //we will check the adjNode is its parent or not if not return
	            cycle exist
            }
        }
     }
     For Undireted Graph                            For Directed Graph

	    call will go for 1                         call will go for 1
	    vis[1]=1;                                       vis[1]=1;
	    now the adjacent of 1 is 2                   call will go for 2
	    call will go for 2                          vis[2]=1;
	    adjacent of 2 is 4                         call will go for 4
	    call will go for 4                          vis[4]=1;
	    now the call we go for 3                 now the call will go 3
	    in three the adjancet is 4 and 1           adjacent of 3 is 4 &1
	    4 is its parent so ok but 1 is not hence cycle exixt;   as 1 is its parent but not 4 so it will return cycle Exist
     }

     Now what to do

     answer is simple take extra O(N) sapce for
     making the is the call for node is over or not path vis

When we go for a call mark the vis as 1 and pathVis 1
     whenever we return from a call mark the pathVis 0
     meaning we are not following that path anymore
     in Above example we return from the path 4 and 2 means call are over for 
     2 & 4
*/

#include<bits/stdc++.h>
using namespace std;
bool DFSCycleCheck(int node,vector<int>adj[],vector<int>&vis,vector<int>&pathVis)
{
	vis[node]=1;
	pathVis[node]=1;

	for(int adjNode:adj[node])
	{
		if(!vis[adjNode])
		{
			if(DFSCycleCheck(adjNode,adj,vis,pathVis))return true;
		}
		else
		{
			if(pathVis[adjNode]) return true;
		}
	}
	pathVis[node]=0;
	return false;
}
bool CycleCheckforUndirectedGraph(int v,vector<int>adj[])
{
       vector<int>vis(v,0);
       vector<int>pathVis(v,0);
       for(int i=0;i<v;i++)
       {
                 if(!vis[i])
                 {
                 	if(DFSCycleCheck(i,adj,vis,pathVis)) return true;
                 }
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
  	
  }

  if(CycleCheckforUndirectedGraph(n,adj))
  cout<<"Cylce Exist";
    else
    	cout<<"Cylce not Exist";
  	
}