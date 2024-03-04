/*
    To find the Cycle for Direct graph using BFS we will apply topplogical
    sorting also called Khan's Algorithm

    In this we sort the nodes of graph according to their occurance means the
    parent->child

    For this we find the inDegree of each node the means the edge incident on  each 
    node and when we move the node delete all its edges means the decdrease the
    incidents of its child nodes

    Ex 0->1->2
       |     |
       \/    \/  
       3<-4<-5
       inDegree array will be 0 1 1 2 1 1
       no edges goes to node 0 is 0, 1 is 1, 2 is 1, 3 is 2, 4 is 1, 5 is 1
  
     we will maintian a queue and push the node with 0 indegree
       now when we go to to the 0 we remove edges  0->1 and 1->5 then move to 1
       as now has 0 indgeree as edge 0->1 is no more //ly for the 1->2 and so on

       at last we will check for indgree if there is means the cycle exist
    eg 0->1->2-       0->1->2-3
       /\      |         /\   |
        |______|         |____|

        no node with indegree 0 hence th cycle exist

        ingraph 2 0 has indegree 0 push to queue now the 
         1 has indree 1 even after removing node 0->1 so inIngree will always 1 
         hence cycle exist;

         Lets Code
    */




#include<bits/stdc++.h>
using namespace std;
bool BFSCycleCheckinDirectedGraph(int V,vector<int>adj[])
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

        while(!q.empty())
        {
        	int node=q.front();
        	q.pop();
        	for(auto x:adj[node])
        	{
        		inDegree[x]--;
        		if(inDegree[x]==0)
        		{
        			q.push(x);
        		}
        	}
        }

        for(int i=0;i<V;i++)
        {
        	if(inDegree[i]>0) return true;
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

  if(BFSCycleCheckinDirectedGraph(n,adj))
  cout<<"Cylce Exist";
    else
    	cout<<"Cylce not Exist";

}