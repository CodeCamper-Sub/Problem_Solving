#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

vector<vector<ll>> dp;
string a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> a >> b;
  dp.assign(ll(a.size() + 1), vector<ll>(b.size() + 1));

  for(ll i = 1; i <= a.size(); i++) {
    for(ll j = 1; j <= b.size(); j++) {
      if(a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  cout << a.size() + b.size() - dp[a.size()][b.size()] << '\n';
  
  return 0;
}