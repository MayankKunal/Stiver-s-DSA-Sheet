#include<bits/stdc++.h>
using namespace std;
/*
Bellaman Ford Algorithm
1. Used to find the minimum distance of all vertices from src vertex
2. Can be applicable to graph having Negative Edge
3. Not applicable on graph having negative Cycle
4. Similar to Dijkastra but edges is relaxed for V-1 times
5. Applicable to Directed Graph Only
6. Egdes can be given in any particular order

      Why edges are Relaxed V-1 times

   As edges can be given in any particular order
   consider the case
             
              edges    weights
   edges from 3->4       1
              2->3       2
              1->2       3
              0->1       4

          let src node be 0 hence but we only traverse edge in order
          in 1st step we get 0->1
          in 2nd step we get 1->2
          in 3rd step we get 2->3
          in 4th step we get 3->4
          hence we need V-1 relaxations  

       Now to detect Negative Cycle let we run the relaxation for
       Nth time if get any better disatnce for any edge means it conatin negative cylce
       beacuse all the edges are already reached with minimum distances


*/

vector<int> BellmanFord(int V,vector<vector<int>>&edges,int src)
{
	vector<int>dist(V,1e8);  
     dist[src]=0;
     for(int i=0;i<V-1;i++)
     {
     for(auto edge:edges)
     {
     	int u=edge[0];
     	int v=edge[1];
     	int dis=edge[2];

     	if(dist[u]!=1e8 && dist[v]>dist[u]+dis)
     	{
     		dist[v]=dist[u]+dis;
     	}
     }
 }

     //Check for negative Cycle

 for(auto edge:edges)
     {
     	int u=edge[0];
     	int v=edge[1];
     	int dis=edge[2];

     	if(dist[u]!=1e8 && dist[v]>dist[u]+dis)
     	{
     		return {-1};
     	}
     }

   return dist;



}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif

   int V = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int S = 0;
	
	vector<int>dist=BellmanFord(V, edges, S);
	for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;

	return 0;

}