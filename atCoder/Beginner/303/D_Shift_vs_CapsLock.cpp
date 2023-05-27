#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll x, y, z;
string s;
vector<vector<ll>> dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> x >> y >> z;
  cin >> s;
  dp.assign(2, vector<ll>(s.size(), INF));
  if(s[0] == 'A') {
    dp[0][0] = y;
    dp[1][0] = z + x;
  } else if(s[0] == 'a') {
    dp[0][0] = x;
    dp[1][0] = z + y;
  }
  for(ll i = 1; i < s.size(); i++) {
    if(s[i] == 'A') {
      dp[0][i] = min(dp[0][i - 1] + y, dp[1][i - 1] + z + y);
      dp[1][i] = min(dp[0][i - 1] + z + x, dp[1][i - 1] + x);
    } else if(s[i] == 'a') {
      dp[0][i] = min(dp[0][i - 1] + x, dp[1][i - 1] + z + x);
      dp[1][i] = min(dp[0][i - 1] + z + y, dp[1][i - 1] + y);
    }
  }

  cout << min(dp[0][s.size() - 1], dp[1][s.size() - 1]) << '\n';

  
  return 0;
}