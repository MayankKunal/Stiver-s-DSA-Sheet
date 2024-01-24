#include<bits/stdc++.h>
using namespace std;
bool possible(int row,int col,int n,vector<string>&board)
{
	int drow=row;
	int dcol=col;
	while(row>=0 && col>=0)
	{
		if(board[row][col]=='Q') return false;
		row--;
		col--;
	}
	row=drow;
	col=dcol;
	while(row>=0 && col<n)
	{
		if(board[row][col]=='Q') return false;
		row--;
		col++;
	}
	row=drow;col=dcol;
	while(row>=0)
	{
		if(board[row][col]=='Q') return false;
		row--;
	}
	return true;
}

void solve(vector<string>board,int row,int col,int n,vector<vector<string>>&ans)
{
	if(row==n)
	{
            ans.push_back(board);
            return;
	}
	for(int col=0;col<n;col++)
	{
		if(possible(row,col,n,board))
		{
			board[row][col]='Q';
			solve(board,row+1,col,n,ans);
			board[row][col]='.';
		}
	}
}
vector<vector<string>>NQueen(int n)
{
	vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
	solve(board,0,0,n,ans);

	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
    int n;
    cin>>n;

vector<vector<string>>ans=NQueen(n);
cout<<ans.size()<<endl;
for(int i=0;i<ans.size();i++)
{
	for(int j=0;j<ans[i].size();j++)
	{
		cout<<ans[i][j]<<" ";
		cout<<endl;

	}
	cout<<endl;
}

return 0;
}