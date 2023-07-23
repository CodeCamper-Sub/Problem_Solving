#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n;
string s;
vector<vector<ll>> dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> s;
  dp.resize(2, vector<ll>(s.size(), 0));


  for(ll i = 0; i < n; i++) {
    if(s[i] == '0') {
      dp[0][i] += 1;
      if(i > 0) {
        dp[1][i] += dp[0][i - 1];
        dp[1][i] += dp[1][i - 1];
      }
    } else {
      dp[1][i] += 1;
      if(i > 0) {
        dp[0][i] += dp[1][i - 1];
        dp[1][i] += dp[0][i - 1];
      }
    }
  }

  ll answer = 0;
  for(ll i = 0; i < n; i++) {
    answer += dp[1][i];
  }

  cout << answer << '\n';
  
  return 0;
}