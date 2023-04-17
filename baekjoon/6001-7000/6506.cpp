#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k;
vector<ll> a;
vector<vector<ll>> dp;  // dp[i][j] i 번째를 마지막으로 하고, 길이가 j인 증가수열의 개수

bool init() {
  cin >> n >> k;
  if(n == 0 && k == 0) return false;
  a.assign(n, 0);
  dp.assign(n, vector<ll>(k + 1));
  for(ll& a: a) cin >> a;
  return true;
}

void solve() {
  for(ll i = 0; i < n; i++) {
    dp[i][0] = 1;
    dp[i][1] = 1;
    for(ll j = 2; j <= k; j++) {
      for(ll l = 0; l < i; l++) {
        if(a[i] > a[l]) {
          dp[i][j] += dp[l][j - 1];
        }
      }
    }
  }
  ll answer = 0;
  for(ll i = 0; i < n; i++) {
    answer += dp[i][k];
  }
  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while(true) {
    if(!init()) break;
    solve();
  }
  return 0;
}