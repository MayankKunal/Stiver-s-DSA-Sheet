#include<bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int ele1=INT_MIN,ele2=INT_MIN,count1=0,count2=0;
   int n=nums.size();
       for (int i = 0; i < n; i++) {
        if (count1 == 0 && ele2 != nums[i]) {
            count1 = 1;
            ele1 = nums[i];
        }
        else if (count2 == 0 && ele1 != nums[i]) {
            count2 = 1;
            ele2 = nums[i];
        }
        else if (nums[i] == ele1) count1++;
        else if (nums[i] == ele2) count2++;
        else {
            count1--, count2--;
        }
    }
        
        int mini = int(n / 3) + 1;
     count1=0,count2=0;
        for(int i=0;i<n;i++)
        {
           if(nums[i]==ele1)count1++;
           if(nums[i]==ele2)count2++;
        }

        if(count1>=mini) ans.push_back(ele1);
        if(count2>=mini) ans.push_back(ele2);

        return ans;
    }
int majorityElement1(vector<int>&nums)
{
	int n=nums.size();
	unordered_map<int,int>mp;
	for(int x:nums)
	{
		mp[x]++;
	}

	for(auto x:mp)
	{
		if((x.second)>n/3) return x.first;
	}
	return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
int n;
cin>>n;
vector<int>nums;

for(int i=0;i<n;i++)
{
	int x;
	cin>>x;
    nums.push_back(x);
}

  nums=majorityElement(nums);

  for(int i=0;i<nums.size();i++)
  {
  	cout<<nums[i]<<" ";
  }
}