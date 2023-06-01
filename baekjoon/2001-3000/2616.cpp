#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, k;
vector<ll> a, psum;
vector<ll> dp[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.resize(n);
  psum.resize(n);
  for(ll i = 0; i < 3; i++) dp[i].assign(n, 0);
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
    psum[i] = a[i] + (i > 0 ? psum[i - 1] : 0);
  }
  cin >> k;
  for(ll i = 0; i < n - k + 1; i++) {
    dp[0][i] = psum[i + k - 1] - (i > 0 ? psum[i - 1] : 0);
  }
  priority_queue<pair<ll, ll>> q;
  for(ll i = k; i < n - k + 1; i++) {
    q.push({dp[0][i], i});
  }
  
  for(ll i = 0; i < n - 2 * k + 1; i++) {
    while(q.top().second < i + k) q.pop();
    dp[1][i] = dp[0][i] + q.top().first;
  }
  
  while(q.size()) q.pop();
  for(ll i = k; i < n - 2 * k + 1; i++) {
    q.push({dp[1][i], i});
  }
  ll answer = -INF;
  for(ll i = 0; i < n - 3 * k + 1; i++) {
    while(q.top().second < i + k) q.pop();
    dp[2][i] = dp[0][i] + q.top().first;
    answer = max(answer, dp[2][i]);
  }

  cout << answer << '\n';

  
  return 0;
}