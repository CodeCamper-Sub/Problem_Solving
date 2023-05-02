#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, answer, sum;
vector<ll> a;
vector<vector<ll>> dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  answer = sum - a[0] - a.back() + *max_element(a.begin() + 1, a.end() - 1);

  dp.assign(n, vector<ll>(3, -INF));

  dp[0][0] = a[0] * 2;
  dp[0][1] = 0;
  for(ll i = 1; i < n; i++) {
    dp[i][0] = dp[i - 1][0] + 2 * a[i];
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);
    dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
  }

  answer = max(answer, dp[n - 1][2]);

  reverse(a.begin(), a.end());

  dp.assign(n, vector<ll>(3, -INF));

  dp[0][0] = a[0] * 2;
  dp[0][1] = 0;
  for(ll i = 1; i < n; i++) {
    dp[i][0] = dp[i - 1][0] + 2 * a[i];
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);
    dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
  }

  answer = max(answer, dp[n - 1][2]);

  cout << answer << '\n';
  
  return 0;
}