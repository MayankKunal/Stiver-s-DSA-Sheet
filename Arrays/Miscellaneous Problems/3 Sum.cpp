#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ThreeSum(vector<int>&nums,int target)
{
       sort(nums.begin(),nums.end()); // sort the array
	int n=nums.size(); // size of array
	vector<vector<int>>ans; // to store the results
	/*
	intution 
	lets array be 1 2 3 4 5 6 7 8
	we have to take three element with target sum;
	  now suposse my smllest element is 2 hence
	  the other two elements will lies in 3 4 5 6 7

	  means we have to apply two sum rest part with revised target
	    target-smallest 

	*/
	for(int i=0;i<n-2;i++) 
	{
           int l=i+1,r=n-1; 
              if(i!=0 && nums[i]==nums[i-1]) continue;
              // skip the redundant number to get unique sum;
              int revised_target=target-nums[i];
           while(l<r)
           {
           	int sum=nums[l]+nums[r];

           	if(sum<revised_target) l++;
           	else if(sum>revised_target) r--;

           	else
           	{
           		vector<int>temp={nums[i],nums[l],nums[r]};
                         l++;
                         r--;
                      ans.push_back(temp);
                   while(l<r && nums[l]==nums[l-1]) l++;  // skip the redundant number to get unique sum;
                   while(l<r && nums[l]==nums[r+1]) r--;  // skip the redundant number to get unique sum;
           	}
           }
	}

   return ans;

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
  int n,target;
  cin>>n>>target;
  vector<int>nums;
  for(int i=0;i<n;i++)
  {
  	int x;
  	cin>>x;
  	nums.push_back(x);
  }
 
vector<vector<int>>ans=ThreeSum(nums,target);

int m=ans.size();
int k=ans[0].size();

for(int i=0;i<m;i++)
{
	 cout<<"[";
	for(int j=0;j<k;j++)
	{
		cout<<ans[i][j]<<",";
	}
	cout<<"]\n";
}

return 0;
}