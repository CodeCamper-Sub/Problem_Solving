#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using ld = long double;
using namespace std;

ll n;
ld a, b;
vector<ld> cows, dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(14);
  
  cin >> n >> a >> b;
  cows.resize(n);
  dp.resize(n); // i 번째 소까지 와이파이가 닿도록 구성했을 때의 최소 비용
  

  for(ll i = 0; i < n; i++) cin >> cows[i];
  sort(cows.begin(), cows.end());

  dp[0] = a;
  for(ll i = 1; i < n; i++) {
    ll delta = cows[i] - cows[i - 1];
    dp[i] = dp[i - 1] + min(delta / 2.0 * b, a);
  }

  cout << dp[n - 1] << '\n';
  

  return 0;
}