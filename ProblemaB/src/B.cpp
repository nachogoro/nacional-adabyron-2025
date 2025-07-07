#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 10000000LL

vector<int> primes;

void eratostenes_sieve(ll n){
    vector<int> sieve(n,0);
    for (int x = 2; x < n; x++){
        if (sieve[x]) continue;
        primes.push_back(x);
        for (int u = 2*x; u <= n; u += x)
            sieve[u] = x;
    }
}

bool solve(){
    int n; cin >> n;
    if (n == 0) return false;
    int l = 0, r = 0;
    ll sum = primes.front();

    while (sum != n){
        if (sum < n){
            // si r sale fuera de la lista salimos del bucle
            if (r+1 == primes.size()) break; 
            sum += primes[++r];
        }
        else sum -= primes[l++];
    }
    if (sum == n) cout << primes[l] << ' ' << primes[r] << '\n';
    else cout << "NO\n";
    return true;
}

int main(){
    eratostenes_sieve(MAX);
    while (solve()) ;
    return 0;
}
