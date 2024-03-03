#include<bits/stdc++.h>
using namespace std;
void sortColors(vector<int>& nums) {

	
        int zero=0,one=0,two=0;
        for(int x:nums)
        {
            if(x==0) zero++;
            else if(x==1) one++;
            else two++;
        }
        int i=0;
        while(zero--)
        {
            nums[i++]=0;
        }
        while(one--) nums[i++]=1;
        while(two--) nums[i++]=2;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
    int n;
    cin>>n;
    // cout<<"ekko";
   vector<int>nums;
  // cout<<n;
   for(int i=0;i<n;i++)
   {
   	int x;
   	cin>>x;
   	nums.push_back(x);
   }
   // cout<<n;
   sortColors(nums);
  // cout<<"Hello";
   for(int i=0;i<n;i++)
   {
   	cout<<nums[i]<<" ";
   }
}