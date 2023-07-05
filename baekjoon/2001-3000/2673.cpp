#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n;
using Segment = pair<ll, ll>;
vector<Segment> segments;
vector<vector<ll>> dp, connected;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  connected.assign(101, vector<ll>(101, 0));
  dp.assign(101, vector<ll>(101, 0));
  while(n--) {
    ll a, b;
    cin >> a >> b;
    connected[a][b] = 1;
    connected[b][a] = 1;
  }

  for(ll i = 1; i <= 100; i++) {
    for(ll j = i - 1; j >= 1; j--) {
      for(ll k = j; k < i; k++) {
        dp[j][i] = max(dp[j][i], dp[j][k] + dp[k][i] + connected[j][i]);
      }
    }
  }
  
  cout << dp[1][100] << '\n';
  
  return 0;
}