#include<bits/stdc++.h>
using namespace std;
void nextPermutaion(vector<int>&nums)
{ /*Apparoch find next permutation
	 eg  1 2 3 4 5
	  next permutaion=1 2 3 5 4
	  meaing traverse from end and find a num bigger than its right neighbour
	   */
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
           /* if ptr==-1 means arry is in desending order so no next permutation possible
                so sort the array or reverse it same thing
            */
		if(ptr1==-1)
		{
			reverse(nums.begin(),nums.end());
			return;
		}
  /* 
     if ptr!=-1 means a element is greater tha nums[ptr] exist in array 
  now let arr is 4 5 3 2 1
	    ptr1=0;
	    now swap the ptr1 value with number greater than n and farthest right from num[ptr1]
	     to clearify let take example of 3 6 5 4 2 1
	     next permutaion is 4 1 2 3 5 6

	     find value of ptr2 means value to be swapped with
	     */
		for(int i=n-1;i>=ptr1;i--)
		{
			if(nums[i]>nums[ptr1])
			{
				ptr2=i;
				break;
			}
		}
           // do swapping
		swap(nums[ptr1],nums[ptr2]);
 /*  reverse the array from ptr+1 to end
  eg 3 6 5 4 2 1
      after swaping 4 6 5 3 2 1
      but this is definatly not a next permutation 
      so sort from nums+1 to end; 
 */
		reverse(nums.begin()+ptr1+1,nums.end());
 //bingo done
	
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
  int n;
  cin>>n;
  // cout<<n;
    vector<int>nums;
  for(int i=0;i<n;i++)
  {
         int p;
         cin>>p;
         nums.push_back(p);
  }
    nextPermutaion(nums);
    
   for(int i=0;i<n;i++)
  {
         
         cout<<nums[i]<<" ";
  }
     return 0;
}