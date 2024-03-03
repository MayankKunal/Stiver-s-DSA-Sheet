#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen("KEK.inp", "r")){
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
int tests; cin >> tests; while (tests--){
    int n;
    cin >> n;
    string ans = "aaa";
    n -= 3;
    for (int i = 2; i >= 0; i--){
        int x = min(25, n);
        ans[i] += x;
        n -= x;
    }
    cout << ans << "\n";
}
}