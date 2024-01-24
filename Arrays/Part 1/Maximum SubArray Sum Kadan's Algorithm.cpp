#include<bits/stdc++.h>
using namespace std;
 /*
  Kadan's Algo is most intutive algo
  eg 1 5 -7 1 8
  take a sum variable to calculte prefix sum
  and maxSum to get maximum sum at each step
   start calculating the sum 
   1 6 -1 as soon we ecounter negative val 
   mark the sum as 0
    and keep updating max sum
   1 6 -1 1 9
  */
int maximumSubarraySum(vector<int>&nums)
{
	int sum=0,maxSum=INT_MIN;
       int n=nums.size();
	for(int i=0;i<n;i++)
	{ //iterate in array
         if(sum<0) sum=0;  // if ever sum <0  make it 0
         sum+=nums[i];  //take prefix sum
         maxSum=max(maxSum,sum); // find maxSum at each step

	}
	return maxSum;  // return maxSum
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
    int n;
    cin>>n;
    vector<int>temp;
    for(int i=0;i<n;i++)
    {
    	int val;
    	cin>>val;
         temp.push_back(val);
    }

    cout<<maximumSubarraySum(temp);

}