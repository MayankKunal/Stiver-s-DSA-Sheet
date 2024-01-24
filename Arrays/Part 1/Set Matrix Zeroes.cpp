#include<bits/stdc++.h>
using namespace std;
// Set matrix to zeros
 void setZeroes(vector<vector<int>>& matrix) {
        
	int n=matrix.size(); // find no of rows
	int m=matrix[0].size(); // find no of cols
   vector<int>row(n,0); // intialized a vector row to store the row number
   // and later mark it zero
   vector<int>col(m,0);// intialized a vector col to store the col number
   // and later mark it zero


   for(int i=0;i<n;i++) // traverse through each row
   {
   	for(int j=0;j<m;j++) // taverse through each col
   	{
   		if(matrix[i][j]==0) //
   		{
   			row[i]=1; // mark the row &col as 1 for index having 0
   			col[j]=1;
   		}
   	}
   }
   for(int i=0;i<n;i++)
   {
   	for(int j=0;j<m;j++)
   	{
   		if(row[i]==1||col[j]==1) matrix[i][j]=0; // mark the matrix zero accoring to the row
   		// col vector
   	}
   }


    }
    void Approch2(vector<vector<int>>&matrix)
  {
      int n=matrix.size();
      int m=matrix[0].size();
      int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0; // to avaoid row col intersection
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
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
// cout<<n<<m;

vector<vector<int>>matrix;
for(int i=0;i<n;i++)
{vector<int>temp;
	for(int j=0;j<m;j++)
	{
        int x;
        cin>>x;
        temp.push_back(x);
	}
	matrix.push_back(temp);
}
  setZeroes(matrix);

  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{
  		cout<<matrix[i][j]<<" ";
  	}
  	cout<<endl;
  }
}