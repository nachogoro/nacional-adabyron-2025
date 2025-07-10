#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(){
    int F, C; cin >> F >> C;
    if (!cin) return false;

    vector<vector<ll>> color(F,vector<ll>(C));
    for (auto &f : color) for (auto &x : f) cin >> x;

    vector<vector<ll>> v(F,vector<ll>(C));
    for (auto &x : v.front()) x = 1;
    for (int i = 1; i < F; i++) for (int j = 0; j < C; j++)
        v[i][j] = color[i][j] == color[i-1][j] ? 1LL+v[i-1][j] : 1LL;
    
    vector<vector<ll>> dp(F,vector<ll>(C,0));
    for (int i = 0; i < F; i++) for (int j = 0; j < C; j++){
        ll h = INT_MAX; 
        for (int k = j; k >= 0 && color[i][k]==color[i][j]; k--){
            h = min(h,v[i][k]);
            dp[i][j] += h;
        }
            
    }
    ll sum = 0;
    for (auto &f : dp) for (auto &x : f) sum += x;

    cout << sum << endl;
    return true;
}

int main(){
    while (solve()) ;
    return 0;
}