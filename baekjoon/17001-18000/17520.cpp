#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MAX 100100
#define MOD 16769023
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<vector<ll>> dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  
  dp.assign(3, vector<ll>(MAX));
  dp[1][1] = 1;
  dp[0][1] = 1;
  for(ll i = 2; i < MAX; i++) {
    dp[1][i] = dp[2][i - 1];
    dp[0][i] = dp[2][i - 1];
    dp[2][i] = dp[0][i - 1] + dp[1][i - 1];
    dp[2][i] %= MOD;
  }

  ll answer = 0;
  answer += dp[0][n];
  answer += dp[1][n];
  answer %= MOD;
  answer += dp[2][n];
  answer %= MOD;
  cout << answer << '\n';
  
  return 0;
}