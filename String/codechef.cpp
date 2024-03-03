#include<bits/stdc++.h>
using namespace std;
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
        int n;
        cin>>n;
        string plain,cipher;
        cin>>plain>>cipher;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int x=plain[i]-'A'+1;
            int y=cipher[i]-'A'+1;
            // cout<<x<<" "<<y<<"\n";
                        int k=0;
            while(((x+(k*3))%26)!=y)
            {
                k++;
            }
             cout<<k<<" ";
        }
        cout<<"\n";
        
    }
    return 0;

}