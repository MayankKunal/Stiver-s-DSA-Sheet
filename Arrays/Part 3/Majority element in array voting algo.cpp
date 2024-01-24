#include<bits/stdc++.h>
using namespace std;
/*
Boyer-Moore Voting Algorithm 
  aim is find majority element in the array/vector
  in this we take a element if next element in array is 
  equal to current element(majority) we increase vote(count) by 1
  else decrease the count by 1 at last element in majority will be
   majority element 
*/
int majorityElement(vector<int>&nums)
{
	int n=nums.size();
	int count=1,majority=nums[0];// take 1st element as major element
	for(int i=1;i<n;i++)
	{
           if(nums[i]==majority) count++; // increase the vote if 
           //current element is equal to majority

           else
           {
           	 count--; // decease the vote count if current is not equal
           	 // to majority
           	 if(count==0)  //if vote count is zero for previous major element
           	 {
           	 	majority=nums[i]; // set majority to current element
           	 	count=1; // set count variable to 1
           	 }
           }
	}
	return majority; // return the majority element
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
    	int m;
    	cin>>m;
        nums.push_back(m);
    }

    cout<<majorityElement(nums);

}