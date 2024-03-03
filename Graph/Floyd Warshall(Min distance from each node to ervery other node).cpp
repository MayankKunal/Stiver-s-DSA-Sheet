//intution
/*
  Floyd Warshal Algo
  1). Used to find min distance from each node to ervery other node
  2). Detect Negative Cycle
  3). Implemented on adjancy matrix
  4). Multi sourrce shortest path Algo
  5). try to go via each node as intermideate node between src and destination

*/

#include<bits/stdc++.h>
using namespace std;
void FloydWarshalAlgo(vector<vector<int>>&matrix)
{
	int n=matrix.size();
	for(int src=0;src<n;src++)
	{
		for(int des=0;des<n;des++)
		{
			if(matrix[src][des]==-1) matrix[src][des]=1e9;

			if(src==des) matrix[src][des]=0;
		}
	}
    
    for(int via=0;via<n;via++)
    {
    	for(int src=0;src<n;src++)
	{
		for(int des=0;des<n;des++)
		{
			
			matrix[src][des]=min(matrix[src][des],matrix[src][via]+matrix[via][des]);

			
		}
	}
    }
    //Detection for megative Cycle

    for(int src=0;src<n;src++)
	{
		for(int des=0;des<n;des++)
		{
			
			if(src==des&&matrix[src][des]!=0)

				cout<<"Graph has Negtive cycle";
			return;

			
		}
	}

     
	for(int src=0;src<n;src++)
	{
		for(int des=0;des<n;des++)
		{
			if(matrix[src][des]==1e9) matrix[src][des]=-1;

			
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
     int n;
     cin>>n;
     vector<vector<int>>matrix;
     for(int i=0;i<n;i++)
     {  
     	vector<int>row;
     	for(int j=0;j<n;j++)
     	{  
     		int x;
     		cin>>x;
                row.push_back(x);
     	}

     	matrix.push_back(row);
     }

     FloydWarshalAlgo(matrix);
         

     for(int i=0;i<n;i++)
     {
     	for(int j=0;j<n;j++)
     	{
     		cout<<matrix[i][j]<<" ";
     	}
     	cout<<"\n";
     }
}