#include<bits/stdc++.h>
using namespace std;
int LongestSubstringWithoutRepeatingCharacters(string &s)
{
	int n=s.size(); // size of string 
	int left=0,right=0,ans=0; // left and right pointer and ans to store the lenght
	unordered_map<char,int>mp; // map will store the position of occurance of element
	while(right<n)  // while right pointer is smaller than size of arr
	{
		if(mp.find(s[right])!=mp.end()) // if we find the curr element in map
		{   //means if we toke the curr element threre will be redundancy
			left=max(left,mp[s[right]]+1); //
			 /* 
             why left is max(left mp[s[right]]+1)
              why not only mp[s[right]+1]

              beacuse eg abcaabcbb
                 left l=0 r=0;
                 store the value of occurance of a in map (a,0)
                 now move to r=1 or b store in map(b,1)
                 // for c map(c,2)
                 now again for r=3 a the condition become true hence the 
                   l become 1
                   now for r=4 the condition is agin true 
                   l=4;
                   VVI================>
                   now for b the condition become true hence l=2 but l is already 4

                   HENCE we take maximum

			 */
		}
         mp[s[right]]=right; // save the occurance of element with its index to map
         ans=max(ans,right-left+1); // calculate the maixmum of ans
         right++;  // increase right pointer
	}
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
string s;
cin>>s;

cout<<LongestSubstringWithoutRepeatingCharacters(s);
}