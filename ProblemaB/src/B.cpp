#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 10000000LL

vector<int> primes;

void eratostenes_sieve(ll n){
    vector<ll> sieve(n+1,0);
    for (ll x = 2; x < n; x++){
        if (sieve[x]) continue;
        primes.push_back(x);
        for (ll u = 2*x; u <= n; u += x)
            sieve[u] = x;
    }
}

bool solve(){
    ll n; cin >> n;
    if (n == 0) return false;
    int l = 0, r = 0;
    ll sum = primes.front();

    bool b = false; // indica si n es endogámico o no
    while (!b){
        if (sum == n && r-l+1 >= 2) b = true;
        else if (sum < n){
            // si r sale fuera de la lista salimos del bucle
            if (r+1 == primes.size()) break; 
            sum += primes[++r];
        }
        else sum -= primes[l++];
    }
    if (b)
        cout << primes[l] << ' ' << primes[r] << '\n';
    else cout << "NO\n";
    return true;
}

int main(){
    eratostenes_sieve(MAX);
    while (solve()) ;
    return 0;
}
