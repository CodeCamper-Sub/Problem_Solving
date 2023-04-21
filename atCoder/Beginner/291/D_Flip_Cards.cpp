#include <bits/stdc++.h>
#define INF 999999999999
#define MOD 998244353
typedef long long ll;
using namespace std;

ll n;
vector<pair<ll, ll>> cards;
vector<vector<ll>> dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  cards.resize(n);
  dp.assign(n, vector<ll>(2, 0));
  for(ll i = 0; i < n; i++) {
    cin >> cards[i].first >> cards[i].second;
  }

  dp[0][0] = 1;
  dp[0][1] = 1;

  for(ll i = 1; i < n; i++) {
    if(cards[i - 1].first != cards[i].first) {
      dp[i][0] += dp[i - 1][0];
      dp[i][0] %= MOD;
    } 
    if(cards[i - 1].first != cards[i].second) {
      dp[i][1] += dp[i - 1][0];
      dp[i][1] %= MOD;
    }
    if(cards[i - 1].second != cards[i].first) {
      dp[i][0] += dp[i - 1][1];
      dp[i][0] %= MOD;
    }
    if(cards[i - 1].second != cards[i].second) {
      dp[i][1] += dp[i - 1][1];
      dp[i][1] %= MOD;
    }
  }

  cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << '\n';

  
  return 0;
}