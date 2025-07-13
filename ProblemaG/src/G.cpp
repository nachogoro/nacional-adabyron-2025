#include <bits/stdc++.h>
using namespace std;
#define MAX 3001

bool solve(){
    int nA, nB;
    cin >> nA;
    if (!cin) return false;
    vector<int> A(nA);
    for (auto &x : A) cin >> x;
    cin >> nB;
    vector<int> B(nB);
    for (auto &x : B) cin >> x;

    // Precalcular primera y última carta
    vector<int> fA(MAX,-1), fB(MAX,-1), lA(MAX,-1), lB(MAX,-1);
    for (int i = 0; i < nA; i++){
        int f = A[i];
        if (fA[f] == -1) fA[f] = i;
        lA[f] = i;
    }
    for (int i = 0; i < nB; i++){
        int f = B[i];
        if (fB[f] == -1) fB[f] = i;
        lB[f] = i;
    }

    vector<vector<int>> dp(nA + 1, vector<int>(nB + 1, INT_MAX));
    dp[0][0] = 0;

    
    for (int i = 0; i <= nA; i++) for (int j = 0; j <= nB; j++){        
        // meter carta A[i]
        if (i < nA){
            int f = A[i];
            int d = dp[i][j];
            if (i == fA[f] && (fB[f] == -1 || j <= fB[f])) d -= i+j+1;  
            if (i == lA[f] && (lB[f] == -1 || j > lB[f])) d += i+j+1;
            dp[i+1][j] = min(dp[i+1][j],d);
        }
        // meter carta B[i]
        if (j < nB){
            int f = B[j];
            int d = dp[i][j];
            if (j == fB[f] && (fA[f] == -1 || i <= fA[f])) d -= i+j+1;
            if (j == lB[f] && (lA[f] == -1 || i > lA[f])) d += i+j+1;
            dp[i][j+1] = min(dp[i][j+1],d);
        }
    }

    cout << dp[nA][nB] << endl;
    return true;
}

int main(){
    while (solve()) ;
    return 0;
}