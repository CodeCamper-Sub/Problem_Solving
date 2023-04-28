#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD 987654321
typedef long long ll;
using namespace std;

ll n;
vector<ll> dp;

ll divide_conquer(ll n) {
  if(dp[n] != -1) return dp[n];
  dp[n] = 0;
  for(ll i = 0; i <= n - 2; i += 2) {
    dp[n] += divide_conquer(i) * divide_conquer(n - 2 - i);
    dp[n] %= MOD;
  }
  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  dp.assign(n + 1, -1);
  dp[0] = 1;

  cout << divide_conquer(n) << '\n';
  
  return 0;
}