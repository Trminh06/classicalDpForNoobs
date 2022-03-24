#include <bits/stdc++.h>
using namespace std;
#define ll long long
long n,m,v[1001],w[1001];
ll dp[1001][1001];
void inp(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
}
ll calc(int i, ll sum){
    if (sum > m)
        return LONG_MIN;
    if (i > n)
        return 0;
    if (dp[i][sum] > 0)
        return dp[i][sum];
    ll r1 = calc(i+1,sum);
    ll r2 = calc(i+1,sum+w[i])+v[i];
    dp[i][sum] = max(r1,r2);
    return dp[i][sum];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("Knapsack.inp","r",stdin);
    freopen("Knapsack.out","w",stdout);
    inp();
    cout << calc(1,0) << "\n";
    return 0;
}
