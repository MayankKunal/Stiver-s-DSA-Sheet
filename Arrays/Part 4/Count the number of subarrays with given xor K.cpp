#include<bits/stdc++.h>
using namespace std;
int countSubarray(vector<int>&arr,int k)
{
	int n=arr.size();  // size of arr
	unordered_map<int,int>mp; // declare a map to store the count result of 
	// previous xors
	mp[0]=1;  // intialy set the xor 0 to 1 beacuse an empty arr 
	// always have xor==0
	int xorEle=0;  // used to xors of element at each step
	int count=0;  // intialy the no of subarray with k xor will be 0
	for(int i=0;i<n;i++)
	{
                xorEle^=arr[i]; // take the xor of each elemet 
                int x=xorEle^k;// xor it with the ans
                /*
                why ?
                     lets take example
                     arr is 1 2 3 2  and final xor is 2

                     

                */

                if(mp.find(x)!=mp.end())
                {

                	count+=mp[x];
                }

                mp[xorEle]++;
	}
	return count;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif

    int n,k;
    cin>>n>>k;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
    	int x;
    	cin>>x;
    	arr.push_back(x);
    }
         cout<<countSubarray(arr,k)<<" ";
}