#include<bits/stdc++.h>
using namespace std;
void nextPermutaion(vector<int>&nums)
{
	int n=nums.size();
	int ptr1=-1,ptr2=-1;
	for(int i=n-1;i>=1;i--)
	{
		if(nums[i]>nums[i-1])
		{
              ptr1=i-1;
              break;
		}
	}
		if(ptr1==-1)
		{
			reverse(nums.begin(),nums.end());
			return;
		}

		for(int i=n-1;i>=ptr1;i--)
		{
			if(nums[i]>nums[ptr1])
			{
				ptr2=i;
				break;
			}
		}

		swap(nums[ptr1],nums[ptr2]);

		reverse(nums.begin()+ptr1+1,nums.end());

	
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
  int n;
  cin>>n;
  cout<<n;
  //   vector<int>nums;
  // for(int i=0;i<n;i++)
  // {
  //        int p;
  //        cin>>p;
  //        nums.push_back(p);
  // }
  //   nextPermutaion(nums);
  //   cout<<nums[0];
  //  for(int i=0;i<n;i++)
  // {
         
  //        cout<<nums[i];
  // }
     return 0;
}