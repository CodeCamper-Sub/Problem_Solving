#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<ll> c;
vector<vector<ll>> dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  c.resize(n);
  for(ll& c: c) cin >> c;
  dp.resize(2, vector<ll>(n, 0));


  // 1을 반드시 넣는 경우
  dp[0][0] = 0;
  dp[1][0] = 1;
  for(ll i = 1; i < n; i++) {
    if(i < n - 1) {
      dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]) + c[i];
      dp[1][i] = dp[0][i - 1] + 1;
    } else {
      dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]) + c[i];
    }
  }

  ll answer = dp[0][n - 1];

  // 1을 안 넣는 경우
  dp[0][0] = c[0];
  dp[1][0] = 0;
  for(ll i = 1; i < n; i++) {
    dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]) + c[i];
    dp[1][i] = dp[0][i - 1] + 1;
  }

  answer = max(answer, dp[0][n - 1]);
  answer = max(answer, dp[1][n - 1]);

  cout << answer << '\n';
  
  return 0;
}