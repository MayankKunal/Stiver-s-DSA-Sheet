#include<bits/stdc++.h>
using namespace std;
// Search in A 2d Matrix
bool searchInMatrix(vector<vector<int>>&matrix,int target)
{
	int n=matrix.size();  // no of rows in matrix
	if(n==0) return false;  // if no element in matrix return false

	int m=matrix[0].size(); // no of elemets in each coloumn
  /// BASIC idea is to find the row in which our element is present
	// for this we will use a slight modified version of binary seach on row
	int l=0,r=n-1; // here is our pointer variable for traversal
	while(l<=r) // condition for traversal
	{
		int mid=l+(r-l)/2; // find mid ele similar to mid=(l+r)/2;
		if(matrix[mid][0]==target) return true; // if elemet is target return true
		else if(matrix[mid][0]<target) l=mid+1; // if row's 1st elemet is less than  target increment l
		else r=mid-1; //if row  1st element is greater than target decrement r pointer
	}

	int row=r; // we have find the affected or useful row
	/* 
	why row=r
	  let given matrix and target ele is 8
	eq            row  0 1 2   
                col 0  1 2 3
                    1  4 5 6
                    2  7 8 9

                 l=0 r=n-1=2 l=0,r=2
                 mid=1
                 matrix[1][0]=4<8
                 l=mid+1
                 l=2 r=2;
                 mid=2;
                 matrix[2][0]=7<8
                 l=mid+1=3
                 but l>r condition get false r=2
	 */
	l=0,r=m-1; // update the l & r pointer for the required row
	while(l<=r) // traverse for required row
	{
		int mid=l+(r-l)/2; // find mid ele similar to mid=(l+r)/2;
		if(matrix[row][mid]==target) return true; // if elemet is target return true
		else if(matrix[row][mid]<target) l=mid+1; // if row's 1st elemet is less than  target increment l
		else r=mid-1; //if row last element is grater than target decrement row
	}
	return false; // return false at the end
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
    int n,m,t;
    cin>>n>>m>>t;
    vector<vector<int>>matrix;
   
    for(int i=0;i<n;i++)
    { 
    	vector<int>temp;
    	for(int j=0;j<m;j++)
    	{
               int x;
               cin>>x;
               temp.push_back(x);
    	}
    	matrix.push_back(temp);
    }

    cout<<searchInMatrix(matrix,t);

}