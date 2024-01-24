#include<bits/stdc++.h>
using namespace std;
void rotateImage(vector<vector<int>>&arr)
{
	int n=arr.size(); /* get Number of row and coloumns of 
    an arr here both are same as n*n matrix
	 */
 //  find transpose of matrix
	for(int i=0;i<n;i++)
	{       // traverse for each row
		for(int j=0;j<i;j++)
		{ // in each col tarverse till pos less than row number
			/*
			beacuse if we travserse for each row the transposition on matrix 
			is not happen beacuse we will undo the changes in next iteration
           eg  
                row    0 1 2   for i=0 no actions as j<i
                col 0  1 2 3
                    1  4 5 6
                    2  7 8 9

                row    0 1 2   for i=1  j->0 
                col 0  1 2 3       row   0 1 2  
                    1  4 5 6    col 0    1 4 3
                    2  7 8 9        1    2 5 6
                                    2    7 8 9

                row    0 1 2   for i=2  j->0-1 
                col 0  1 4 3       row   0 1 2  
                    1  2 5 6    col 0    1 4 7
                    2  7 8 9        1    2 5 8
                                    2    3 6 9

                 
			*/
			swap(arr[i][j],arr[j][i]);
		}
	}
   // now reverse each row to get 90* rotation
	for(int i=0;i<n;i++)
	{
		reverse(arr[i].begin(),arr[i].end());
	}
	
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
     int n,m;
     cin>>n>>m;
     vector<vector<int>>arr;
     
     for(int i=0;i<n;i++)
     {
     	vector<int>temp;
     	for(int j=0;j<m;j++)
     	{
     		int p;
     		cin>>p;
        temp.push_back(p);

     	}
     	arr.push_back(temp);
     }
   rotateImage(arr);
     for(int i=0;i<n;i++)
     {
     	for(int j=0;j<m;j++)
     	{
     		cout<<arr[i][j]<<" ";

     	}
     	cout<<"\n";
     }
}