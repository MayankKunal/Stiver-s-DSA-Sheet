#include<bits/stdc++.h>
using namespace std;
int findMstUsingPrismAlgo(int V,vector<vector<int>>adj[])
	{
	    
	    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	    //make a 
	    
	    pq.push({0,0});
	    int vis[V]={0};
	    
	    int totalDis=0;
	    while(!pq.empty())
	    {
	        auto it=pq.top();
	        pq.pop();
	        int node=it.second;
	        int dis=it.first;
	        if(vis[node]==1) continue;
	        vis[node]=1;
	        totalDis+=dis;
	        
	        for(auto x:adj[node])
	        {
	            if(!vis[x[0]])
	            {
	                pq.push({x[1],x[0]});
	            }
	        }
	        
	    }
	    return totalDis;
	    
	}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif

    int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	Solution obj;
	int sum = obj.spanningTree(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;

}