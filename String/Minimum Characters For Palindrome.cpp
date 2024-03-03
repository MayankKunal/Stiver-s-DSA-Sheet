#include<bits/stdc++.h>
using namespace std;
string help(int l,int r,string &s)
{
    while(l>=0 && r<s.size() && s[l]==s[r])
    {
        l--;
        r++;
    }

    return s.substr(l+1,r-l-1);
}
string longestPalinSubstring(string str)
{
    int n=str.size();
	if(n==1) return str;
    string ans="";
    for(int i=0;i<n-1;i++)
    {
        string oddLen=help(i,i,str);
        string evenLen=help(i,i+1,str);

        if(ans.size()<oddLen.size()) ans=oddLen;
        if(ans.size()<evenLen.size()) ans=evenLen;
    }
    return ans;
}
int minCharsforPalindrome(string str) {
	
	string ans=longestPalinSubstring(str);

	return str.size()-ans.size();
	
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
    int t;
    cin>>t;
    while(t--)
    {
    	string s;
    	cin>>s;
    	cout<<minCharsforPalindrome(s)<<"\n";
    }
    return 0;

}