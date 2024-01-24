#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int n)
{
	 /* initialized a temprory vector for taking the pascal values at

          each row;

          now intialized a vector of vector to store answer/Result
	  */
	vector<int>temp;
	vector<vector<int>>result;
    /* 
   iterate to from 0->n
   ans increase the temo size value by 1 beacuse each step
   has 1 more than its previous and intized it to 1
    */
	for(int i=0;i<n;i++)
	{
		temp.resize(i+1,1);// increasing value of temp by 1
		for(int j=1;j<i;j++)
		{
			temp[j]=result[i-1][j-1]+result[i-1][j];
			 /*
                  value of temp[j] if( j!=0 or j!=i) beacuse first and last value is
                  always 1
                      
                  and for value j=1 to j=i-1
                      
                   temp[j]=ans[i-1][j-1]+ans[i-1][j];

                   eg 6        
                               
                              i  0   1     2     3    4   5
                              j   
                   1          0  1
                   1 1        1  1    1  
                   1 2 1      2  1  (1+1)  1
                   1 3 3 1    3  1  (2+1) (1+2)  1
                   1 4 6 4 1  4  1  (3+1) (3+3) (3+1) 1
			  */
		}
		result.push_back(temp);
	}
	return result;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
    int n;
    cin>>n;
    vector<vector<int>>ans;
    ans=generate(n);

    for(auto x:ans)
    {
    	for(auto y:x)
    	{
    		cout<<y<<" ";
    	}
    	cout<<"\n";
    }

}